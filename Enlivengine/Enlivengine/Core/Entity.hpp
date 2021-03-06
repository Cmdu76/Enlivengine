#pragma once

#include <entt/entt.hpp>

#include <Enlivengine/Utils/Assert.hpp>
#include <Enlivengine/Utils/TypeTraits.hpp>

#include <Enlivengine/Math/Vector3.hpp>

#include <Enlivengine/Core/ComponentTraits.hpp>

namespace en
{

class EntityManager;
class World;

class Entity
{
public:
	Entity();
	Entity(EntityManager& manager, entt::entity entity);
	Entity(World& world, entt::entity entity);

	bool operator==(const Entity& other) const;
	bool operator!=(const Entity& other) const;

	bool IsValid() const;
	U32 GetID() const;
	U32 GetIndex() const;
	U32 GetVersion() const;
	U32 GetUID() const;
	void Destroy();

	const char* GetName() const;
	Vector3f GetPosition() const;

	template <typename T> 
	decltype(auto) Add();

	template <typename T, typename ...Args> 
	decltype(auto) Add(Args&&  ...args);

	template <typename ...Components> 
	bool Has() const;

	template <typename T> 
	void Remove();

	template <typename T> 
	T& Get();

	template <typename T> 
	const T& Get() const;

	bool HasManager() const;
	EntityManager& GetManager();
	const EntityManager& GetManager() const;
	World& GetWorld();
	const World& GetWorld() const;

	bool Serialize(Serializer& serializer, const char* name);
	bool Edit(ObjectEditor& objectEditor, const char* name);

	// TODO : Try to remove/hide these
	const entt::entity& GetEntity() const;
	entt::registry& GetRegistry();
	const entt::registry& GetRegistry() const;

private:
	friend class EntityManager;

private:
	EntityManager* mManager;
	entt::entity mEntity;
};

template <typename T> 
decltype(auto) Entity::Add()
{
	enAssert(IsValid());

	if constexpr (Traits::IsEmpty<T>::value)
	{
		GetRegistry().emplace<T>(mEntity);
	}
	else
	{
		T& component = GetRegistry().emplace<T>(mEntity);
		if constexpr (ComponentHasCustomInitialization<T>::value)
		{
			component.Initialize(*this);
		}
		return component;
	}
}

template <typename T, typename ...Args>
decltype(auto) Entity::Add(Args&& ...args)
{
	enAssert(IsValid());

	if constexpr (Traits::IsEmpty<T>::value)
	{
		GetRegistry().emplace<T>(mEntity);
	}
	else
	{
		T& component = GetRegistry().emplace<T>(mEntity, std::forward<Args>(args)...);
		if constexpr (ComponentHasCustomInitialization<T>::value)
		{
			component.Initialize(*this);
		}
		return component;
	}
}

template <typename ...Components> 
bool Entity::Has() const 
{ 
	enAssert(IsValid());

	return GetRegistry().has<Components...>(mEntity); 
}

template <typename T> 
void Entity::Remove()
{
	enAssert(IsValid());
	enAssert(Has<T>());
	
	GetRegistry().remove<T>(mEntity); 
}

template <typename T> 
T& Entity::Get()
{
	enAssert(IsValid());
	enAssert(Has<T>());

	return GetRegistry().get<T>(mEntity); 
}

template <typename T> 
const T& Entity::Get() const 
{
	enAssert(IsValid());
	enAssert(Has<T>());

	return GetRegistry().get<T>(mEntity); 
}

} // namespace en

ENLIVE_META_CLASS_BEGIN(en::Entity, en::Type_CustomSerialization, en::Type_CustomEditor)
ENLIVE_META_CLASS_END()