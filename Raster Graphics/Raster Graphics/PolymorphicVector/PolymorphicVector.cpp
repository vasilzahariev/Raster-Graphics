//#include "PolymorphicVector.h"
//
//PolymorphicVector::PolymorphicVector()
//					: m_data(nullptr), nSize(0), nCapacity(0) {
//	allocData(2);
//}
//
//PolymorphicVector::PolymorphicVector(const PolymorphicVector& other)
//					: m_data(nullptr), nSize(0), nCapacity(0) {
//	copy(other);
//}
//
//PolymorphicVector::~PolymorphicVector() {
//	deleteData();
//}
//
//void PolymorphicVector::push_back(ICloneable* element) {
//	if (nSize >= nCapacity) allocData(nCapacity * 2);
//
//	m_data[nSize++] = element;
//}
//
//void PolymorphicVector::remove_at(const int index) {
//	if (index < 0 || index >= nSize)
//		throw std::exception("Index out of bounds!");
//
//	std::swap(m_data[index], m_data[--nSize]);
//}
//
//PolymorphicVector& PolymorphicVector::operator=(const PolymorphicVector& other) {
//	if (this != &other) copy(other);
//
//	return *this;
//}
//
//void PolymorphicVector::deleteData() {
//	for (size_t index = 0; index < nSize; ++index) {
//		delete m_data[index];
//		m_data[index] = nullptr;
//	}
//
//	delete[] m_data;
//	m_data = nullptr;
//}
//
//void PolymorphicVector::allocData(size_t newCapacity) {
//	if (nSize >= newCapacity) newCapacity = nSize + 1;
//
//	ICloneable** blockOfData = new ICloneable * [newCapacity]{ nullptr, };
//
//	for (size_t index = 0; index < nSize; ++index)
//		blockOfData[index] = m_data[index]->clone();
//
//	deleteData();
//	m_data = blockOfData;
//	nCapacity = newCapacity;
//}
//
//void PolymorphicVector::copy(const PolymorphicVector& other) {
//	deleteData();
//	nCapacity = other.nCapacity;
//	m_data = new ICloneable*[nCapacity] {nullptr, };
//	nSize = other.nSize;
//
//	for (size_t index = 0; index < nSize; ++index)
//		m_data[index] = other.m_data[index]->clone();
//}
