#include <Enlivengine/Math/Transform.hpp>

#include <Enlivengine/Utils/Assert.hpp>

namespace en
{

Transform::Transform()
	: mMatrix(Matrix4f::Identity())
{
}

Vector3f Transform::GetPosition() const
{
	return mMatrix.GetTranslation();
}

void Transform::SetPosition(const Vector3f& position)
{
	mMatrix.SetTranslation(position);
}

void Transform::Move(const Vector3f& movement)
{
	mMatrix.ApplyTranslation(movement);
}

Matrix3f Transform::GetRotation() const
{
	return mMatrix.GetRotation();
}

void Transform::SetRotation(const Matrix3f& rotation)
{
	mMatrix.SetRotation(rotation);
}

void Transform::Rotate(const Matrix3f& rotation)
{
	mMatrix.ApplyRotation(rotation);
}

Vector3f Transform::GetScale() const
{
	return mMatrix.GetScale();
}

void Transform::SetScale(const Vector3f& scale)
{
	mMatrix.SetScale(scale);
}

void Transform::SetUniformScale(F32 uniformScale)
{
	mMatrix.SetScale(uniformScale);
}

void Transform::Scale(const Vector3f& scale)
{
	mMatrix.ApplyScale(scale);
}

void Transform::Scale(F32 uniformScale)
{
	mMatrix.ApplyScale(uniformScale);
}

void Transform::SetTransform(const Vector3f& translation, const Matrix3f& rotation, const Vector3f& scale /*= Vector3f(1.0f)*/)
{
	mMatrix = Matrix4f::Transform(translation, rotation, scale);
}

const Matrix4f& Transform::GetMatrix() const
{
	return mMatrix;
}

} // namespace en