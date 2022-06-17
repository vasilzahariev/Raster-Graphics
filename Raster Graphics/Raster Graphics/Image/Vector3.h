#pragma once

#include <iostream>

template <typename T>
struct Vector3 {
public:
	T x;
	T y;
	T z;

public:
	Vector3(const std::uint16_t val = 0);
	Vector3(const std::uint16_t x, const std::uint16_t y, const std::uint16_t z);

	bool operator==(const Vector3<T>& other) const;

	void readFrom(std::istream& in = std::cin);
	void writeTo(std::ostream& out = std::cout) const;

	void transformToGrayscale();
	void normalizeByValue(const T value);
	void transformToNegative(const T value);

	friend std::istream& operator>>(std::istream& in, Vector3<T>& vector) {
		return (in >> vector.x >> vector.y >> vector.z);
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector3<T>& vector) {
		return (out << vector.x << ' ' << vector.y << ' ' << vector.z);
	}
};

template<typename T>
inline Vector3<T>::Vector3(const std::uint16_t val)
	: x(val), y(val), z(val) {
}

template<typename T>
inline Vector3<T>::Vector3(const std::uint16_t x, const std::uint16_t y, const std::uint16_t z)
	: x(x), y(y), z(z) {
}

template<typename T>
inline bool Vector3<T>::operator==(const Vector3<T>& other) const {
	return (x == other.x && y == other.y && z == other.z);
}

template<typename T>
inline void Vector3<T>::readFrom(std::istream& in) {
	in >> x >> y >> z;
}

template<typename T>
inline void Vector3<T>::writeTo(std::ostream& out) const {
	out << x << ' ' << y << ' ' << z;
}

template<typename T>
inline void Vector3<T>::transformToGrayscale() {
	std::uint16_t gray = (x + y + z) / 3;

	x = gray;
	y = gray;
	z = gray;
}

template<typename T>
inline void Vector3<T>::normalizeByValue(const T value) {
	x /= value;
	y /= value;
	z /= value;
}

template<typename T>
inline void Vector3<T>::transformToNegative(const T value) {
	x = value - x;
	y = value - y;
	z = value - z;
}


//#ifndef VECTOR3_H
//#define VECTOR3_H
//
//#include <iostream>
//
//template <typename T>
//struct Vector3 {
//public:
//	T x;
//	T y;
//	T z;
//
//public:
//	Vector3(const std::uint16_t val = 0);
//	Vector3(const std::uint16_t x, const std::uint16_t y, const std::uint16_t z);
//
//	bool operator==(const Vector3<T>& other) const;
//
//	void readFrom(std::istream& in = std::cin);
//	void writeTo(std::ostream& out = std::cout) const;
//
//	void transformToGrayscale();
//	void normalizeByValue(const T value);
//	void transformToNegative(const T value);
//};
//
//#endif // !VECTOR3_H
//
//template<typename T>
//inline Vector3<T>::Vector3(const std::uint16_t val)
//	: x(val), y(val), z(val) {
//}
//
//template<typename T>
//inline Vector3<T>::Vector3(const std::uint16_t x, const std::uint16_t y, const std::uint16_t z)
//	: x(x), y(y), z(z) {
//}
//
//template<typename T>
//inline bool Vector3<T>::operator==(const Vector3<T>& other) const {
//	return (x == other.x && y == other.y && z == other.z);
//}
//
//template<typename T>
//inline void Vector3<T>::readFrom(std::istream& in) {
//	in >> x >> y >> z;
//}
//
//template<typename T>
//inline void Vector3<T>::writeTo(std::ostream& out) const {
//	out << x << ' ' << y << ' ' << z;
//}
//
//template<typename T>
//inline void Vector3<T>::transformToGrayscale() {
//	std::uint16_t gray = (x + y + z) / 3;
//
//	x = gray;
//	y = gray;
//	z = gray;
//}
//
//template<typename T>
//inline void Vector3<T>::normalizeByValue(const T value) {
//	x /= value;
//	y /= value;
//	z /= value;
//}
//
//template<typename T>
//inline void Vector3<T>::transformToNegative(const T value) {
//	x = value - x;
//	y = value - y;
//	z = value - z;
//}
