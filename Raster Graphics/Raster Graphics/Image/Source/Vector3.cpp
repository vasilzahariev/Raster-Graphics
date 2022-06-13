#include "../Vector3.h"

template <typename T>
std::istream& operator>>(std::istream& in, Vector3<T>& vector) {
	return (in >> vector.x >> vector.y >> vector.z);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, Vector3<T>& vector) {
	return (out << vector.x << ' ' << vector.y << ' ' << vector.z << '\n');
}
