#pragma once

#include <Enlivengine/Math/Vector3.hpp>

// TODO : Constexpr Sqrt => GetLength, SetLength, Normalize, Normalized

namespace en
{

template <typename T>
class Vector4
{
public:
	static constexpr I32 Dim = 4;

	constexpr Vector4() : x(T(0)), y(T(0)), z(T(0)), w(T(0)) {}
	constexpr Vector4(const Vector4<T>& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}
	template <typename U>
	constexpr Vector4(const Vector4<U>& v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z)), w(static_cast<T>(v.w)) {}
	constexpr Vector4(const T& s) : x(s), y(s), z(s), w(s) {}
	constexpr Vector4(const T& s1, const T& s2, const T& s3, const T& s4) : x(s1), y(s2), z(s3), w(s4) {}
	constexpr Vector4(const Vector3<T>& v123, const T& s4) : x(v123.x), y(v123.y), z(v123.z), w(s4) {}
	~Vector4() = default;

	constexpr Vector4<T>& Set(const Vector4<T> & v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; }
	template <typename U>
	constexpr Vector4<T>& Set(const Vector4<U> & v) { x = static_cast<T>(v.x); y = static_cast<T>(v.y); z = static_cast<T>(v.z); w = static_cast<T>(v.w); return *this; }
	constexpr Vector4<T>& Set(const T & s) { x = s; y = s; z = s; w = s; return *this; }
	constexpr Vector4<T>& Set(const T * a) { x = a[0]; y = a[1]; z = a[2]; w = a[3]; return *this; }
	constexpr Vector4<T>& Set(const T & s1, const T & s2, const T & s3, const T & s4) { x = s1; y = s2; z = s3; w = s4; return *this; }
	constexpr Vector4<T>& Set(const Vector3<T> & v123, const T & s4) { x = v123.x; y = v123.y; z = v123.z; w = s4; return *this; }

	constexpr T& operator()(U32 i) { if (i == 0) return x; else if (i == 1) return y; else if (i == 2) return z; return w; }
	constexpr const T& operator()(U32 i) const { if (i == 0) return x; else if (i == 1) return y; else if (i == 2) return z; return w; }
	constexpr T& operator[](U32 i) { if (i == 0) return x; else if (i == 1) return y; else if (i == 2) return z; return w; }
	constexpr const T& operator[](U32 i) const { if (i == 0) return x; else if (i == 1) return y; else if (i == 2) return z; return w; }

	constexpr Vector4<T>& operator=(const Vector4<T> & vec) { x = vec.x; y = vec.y; z = vec.z; w = vec.w; return *this; }
	constexpr const Vector4<T>& operator+() const { return *this; }
	constexpr Vector4<T> operator-() const { return Vector4<T>(-x, -y, -z, -w); }

	constexpr Vector4<T> operator+(const Vector4<T> & vec) const { return Vector4<T>(x + vec.x, y + vec.y, z + vec.z, w + vec.w); }
	constexpr Vector4<T> operator-(const Vector4<T> & vec) const { return Vector4<T>(x - vec.x, y - vec.y, z - vec.z, w - vec.w); }
	constexpr Vector4<T> operator*(const Vector4<T> & vec) const { return Vector4<T>(x * vec.x, y * vec.y, z * vec.z, w * vec.w); }
	constexpr Vector4<T> operator/(const Vector4<T> & vec) const { return Vector4<T>(x / vec.x, y / vec.y, z / vec.z, w / vec.w); }
	constexpr Vector4<T>& operator+=(const Vector4<T> & vec) { x += vec.x; y += vec.y; z += vec.z; w += vec.w; return *this; }
	constexpr Vector4<T>& operator-=(const Vector4<T> & vec) { x -= vec.x; y -= vec.y; z -= vec.z; w -= vec.w; return *this; }
	constexpr Vector4<T>& operator*=(const Vector4<T> & vec) { x *= vec.x; y *= vec.y; z *= vec.z; w *= vec.w; return *this; }
	constexpr Vector4<T>& operator/=(const Vector4<T> & vec) { x /= vec.x; y /= vec.y; z /= vec.z; w /= vec.w; return *this; }

	constexpr Vector4<T> operator+(T scalar) const { return Vector4<T>(x + scalar, y + scalar, z + scalar, w + scalar); }
	constexpr Vector4<T> operator-(T scalar) const { return Vector4<T>(x - scalar, y - scalar, z - scalar, w - scalar); }
	constexpr Vector4<T> operator*(T scalar) const { return Vector4<T>(x * scalar, y * scalar, z * scalar, w * scalar); }
	constexpr Vector4<T> operator/(T scalar) const { const T inv = T(1) / scalar; return Vector4<T>(x * inv, y * inv, z * inv, w * inv); }
	constexpr Vector4<T>& operator+=(T scalar) { x += scalar; y += scalar; z += scalar; w += scalar; return *this; }
	constexpr Vector4<T>& operator-=(T scalar) { x -= scalar; y -= scalar; z -= scalar; w -= scalar; return *this; }
	constexpr Vector4<T>& operator*=(T scalar) { x *= scalar; y *= scalar; z *= scalar; w *= scalar; return *this; }
	constexpr Vector4<T>& operator/=(T scalar) { const T inv = T(1) / scalar; x *= inv; y *= inv; z *= inv; w *= inv; return *this; }

	constexpr bool IsZero() const { return operator==(Zero()); }
	constexpr bool operator==(const Vector4<T> & vec) const { return Math::Equals(x, vec.x) && Math::Equals(y, vec.y) && Math::Equals(z, vec.z) && Math::Equals(w, vec.w); }
	constexpr bool operator!=(const Vector4<T> & vec) const { return !operator==(vec); }
	constexpr bool operator<(const Vector4<T> & vec) const { return x < vec.x&& y < vec.y&& z < vec.z&& w < vec.w; }
	constexpr bool operator<=(const Vector4<T> & vec) const { return x <= vec.x && y <= vec.y && z <= vec.z && w <= vec.w; }
	constexpr bool operator>(const Vector4<T> & vec) const { return !operator<=(vec); }
	constexpr bool operator>=(const Vector4<T> & vec) const { return !operator<(vec); }
	static constexpr bool Equals(const Vector4<T> & v1, const Vector4<T> & v2, const T & epsilon = T(Math::Epsilon)) { return Math::Equals(v1.x, v2.x, epsilon) && Math::Equals(v1.y, v2.y, epsilon) && Math::Equals(v1.z, v2.z, epsilon) && Math::Equals(v1.w, v2.w, epsilon); }

	constexpr Vector3<T> xyz() const { return Vector3<T>(x, y, z); }
	constexpr Vector2<T> xy() const { return Vector2<T>(x, y); }
	constexpr Vector2<T> xz() const { return Vector2<T>(x, z); }
	constexpr Vector2<T> yz() const { return Vector2<T>(y, z); }

	constexpr T DotProduct(const Vector4<T> & v) const { return x * v.x + y * v.y + z * v.z + w * v.w; }
	static constexpr T DotProduct(const Vector4<T> & v1, const Vector4<T> & v2) { return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w; }

	constexpr T GetSquaredLength() const { return DotProduct(*this); }
	inline T GetLength() const { return Math::FastSqrt(GetSquaredLength()); }
	inline Vector4<T>& SetLength(const T & length, T * oldLength = nullptr)
	{
		const T currentLength = GetLength();
		if (oldLength != nullptr)
		{
			*oldLength = currentLength;
		}
		const T factor = length / currentLength;
		x *= factor;
		y *= factor;
		z *= factor;
		w *= factor;
		return *this;
	}

	constexpr bool IsNormalized() const { return Math::Equals(GetSquaredLength(), T(1)); }
	inline Vector4<T>& Normalize(T * oldLength = nullptr) { return SetLength(T(1), oldLength); }
	inline Vector4<T> Normalized(T * oldLength = nullptr) const { return Vector4<T>(*this).Normalize(oldLength); }

	static constexpr Vector4<T> Lerp(const Vector4<T> & v1, const Vector4<T> & v2, const T & percent) { const T one_minus_percent = T(1) - percent; return Vector4<T>(one_minus_percent * v1.x + percent * v2.x, one_minus_percent * v1.y + percent * v2.y, one_minus_percent * v1.z + percent * v2.z, one_minus_percent * v1.w + percent * v2.w); }

	constexpr Vector4<T>& Maximize(const Vector4<T> & v) { if (v.x > x) x = v.x; if (v.y > y) y = v.y; if (v.z > z) z = v.z; if (v.w > w) w = v.w; return *this; }
	static constexpr Vector4<T> Maximum(const Vector4<T> & v1, const Vector4<T> & v2) { return Vector4<T>(Math::Max(v1.x, v2.x), Math::Max(v1.y, v2.y), Math::Max(v1.z, v2.z), Math::Max(v1.w, v2.w)); }

	constexpr Vector4<T>& Minimize(const Vector4<T> & v) { if (v.x < x) x = v.x; if (v.y < y) y = v.y; if (v.z < z) z = v.z; if (v.w < w) w = v.w; return *this; }
	static constexpr Vector4<T> Minimum(const Vector4<T> & v1, const Vector4<T> & v2) { return Vector4<T>(Math::Min(v1.x, v2.x), Math::Min(v1.y, v2.y), Math::Min(v1.z, v2.z), Math::Min(v1.w, v2.w)); }

	static constexpr Vector4<T> Unit() { return Vector4<T>(1, 1, 1, 1); }
	static constexpr Vector4<T> UnitX() { return Vector4<T>(1, 0, 0, 0); }
	static constexpr Vector4<T> UnitY() { return Vector4<T>(0, 1, 0, 0); }
	static constexpr Vector4<T> UnitZ() { return Vector4<T>(0, 0, 1, 0); }
	static constexpr Vector4<T> UnitW() { return Vector4<T>(0, 0, 0, 1); }
	static constexpr Vector4<T> Zero() { return Vector4<T>(0, 0, 0, 0); }

	bool Serialize(Serializer& serializer, const char* name);
	bool Edit(ObjectEditor& objectEditor, const char* name);

	T x;
	T y;
	T z;
	T w;
};

template <typename T>
bool Vector4<T>::Serialize(Serializer& serializer, const char* name)
{
	if (serializer.BeginClass(name, TypeInfo<Vector4<T>>::GetName(), TypeInfo<Vector4<T>>::GetHash()))
	{
		bool ret = true;
		ret = GenericSerialization(serializer, "x", x) && ret;
		ret = GenericSerialization(serializer, "y", y) && ret;
		ret = GenericSerialization(serializer, "z", z) && ret;
		ret = GenericSerialization(serializer, "w", w) && ret;
		ret = serializer.EndClass() && ret;
		return ret;
	}
	else
	{
		return false;
	}
}

template <typename T>
bool Vector4<T>::Edit(ObjectEditor& objectEditor, const char* name)
{
#ifdef ENLIVE_ENABLE_IMGUI
	if (objectEditor.IsImGuiEditor())
	{
		if constexpr (Traits::IsFloatingPoint<T>::value)
		{
			float vector[4];
			vector[0] = static_cast<float>(x);
			vector[1] = static_cast<float>(y);
			vector[2] = static_cast<float>(z);
			vector[3] = static_cast<float>(w);
			if (ImGui::InputFloat4(name, vector))
			{
				Set(static_cast<T>(vector[0]), static_cast<T>(vector[1]), static_cast<T>(vector[2]), static_cast<T>(vector[3]));
				return true;
			}
			return false;
		}
		else
		{
			int vector[4];
			vector[0] = static_cast<int>(x);
			vector[1] = static_cast<int>(y);
			vector[2] = static_cast<int>(z);
			vector[3] = static_cast<int>(w);
			if (ImGui::InputInt4(name, vector))
			{
				// TODO : NumericLimits<T> Min
				// TODO : NumericLimits<T> Max
				Set(static_cast<T>(vector[0]), static_cast<T>(vector[1]), static_cast<T>(vector[2]), static_cast<T>(vector[3]));
				return true;
			}
			return false;
		}
	}
	else
#endif // ENLIVE_ENABLE_IMGUI
	{
		bool ret = false;
		if (objectEditor.BeginClass(name, TypeInfo<Vector4<T>>::GetName(), TypeInfo<Vector4<T>>::GetHash()))
		{
			ret = GenericEdit(objectEditor, "x", x) || ret;
			ret = GenericEdit(objectEditor, "y", y) || ret;
			ret = GenericEdit(objectEditor, "z", z) || ret;
			ret = GenericEdit(objectEditor, "w", w) || ret;
			objectEditor.EndClass();
		}
		return ret;
	}
}

template <typename T> constexpr Vector4<T> operator+(const T& scalar, const Vector4<T>& vector) { return vector + scalar; }
template <typename T> constexpr Vector4<T> operator-(const T& scalar, const Vector4<T>& vector) { return scalar + (-vector); }
template <typename T> constexpr Vector4<T> operator*(const T& scalar, const Vector4<T>& vector) { return vector * scalar; }
template <typename T> constexpr Vector4<T> operator/(const T& scalar, const Vector4<T>& vector) { return Vector4<T>(scalar / vector.x, scalar / vector.y, scalar / vector.z, scalar / vector.w); }

typedef Vector4<F32> Vector4f;
typedef Vector4<F64> Vector4d;
typedef Vector4<I32> Vector4i;
typedef Vector4<U32> Vector4u;

typedef Vector4f vec4; // GLSL-like

} // namespace en

ENLIVE_DEFINE_TYPE_INFO_TEMPLATE(en::Vector4, en::Type_CustomSerialization, en::Type_CustomEditor)