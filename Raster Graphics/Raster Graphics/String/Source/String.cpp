#pragma warning(disable: 4996)

#include "../String.h"

String::String()
		 : m_data(nullptr), nSize(0), nCapacity(0) {
	allocData(2);
}

String::String(const size_t initialCapacity)
		 : m_data(nullptr), nSize(0), nCapacity(0) {
	allocData(initialCapacity);
}

String::String(const char* str)
		  : m_data(nullptr), nSize(0), nCapacity(0) {
	allocData(strlen(str) + 1);
	strcpy(m_data, str);
	nSize = strlen(str);
}

String::String(const String& other)
		 : m_data(nullptr), nSize(0), nCapacity(0) {
	copy(other);
}

String::~String() {
	deleteData();
}

void String::push_back(const char c) {
	if (nSize >= nCapacity) allocData(nCapacity * 2);

	m_data[nSize++] = c;
}

void String::pop_back() {
	std::swap(m_data[nSize - 1], m_data[--nSize]);
}

void String::append(const char* str) {
	*this += str;
}

size_t String::size() const {
	return nSize;
}

size_t String::capacity() const {
	return nCapacity;
}

bool String::empty() const {
	return nSize == 0;
}

void String::shrinkToFit() {
	char* blockOfData = new char[nSize] { '\0' };

	for (size_t index = 0; index < nSize; ++index)
		blockOfData[index] = m_data[index];

	deleteData();
	strcpy(m_data, blockOfData);
	nCapacity = nSize;
}

void String::clear() {
	deleteData();
	nSize = 0;
	nCapacity = 0;
}

String String::operator+(const char c) const {
	String result(*this);

	result.push_back(c);

	return result;
}

String String::operator+(const char* str) const {
	return String(getStrSum(m_data, nSize, str, strlen(str)));
}

String& String::operator+=(const char c) {
	push_back(c);

	return *this;
}

String& String::operator+=(const char* str) {
	String sum = *this + str;

	deleteData();
	nCapacity = 0;
	nSize = 0;
	allocData(strlen(sum.m_data) + 1);
	strcpy(m_data, sum.m_data);
	nSize = sum.nSize;

	return *this;
}

char& String::operator[](const int index) {
	return getElementAtIndex(index);
}

const char& String::operator[](const int index) const {
	return getElementAtIndex(index);
}

String::operator char* () const {
	return m_data;
}

String::operator const char* () const {
	return m_data;
}

String& String::operator=(const String& other) {
	if (this != &other) copy(other);

	return *this;
}

void String::deleteData() {
	delete[] m_data;
	m_data = nullptr;
}

void String::allocData(size_t newCapacity) {
	if (nSize >= newCapacity) newCapacity = nSize + 1;

	char* blockOfMem = new char[newCapacity] { '\0' };

	for (size_t index = 0; index < nSize; ++index)
		blockOfMem[index] = m_data[index];

	deleteData();
	m_data = blockOfMem;
	nCapacity = newCapacity;
}

void String::copy(const String& other) {
	deleteData();
	nSize = other.nSize;
	nCapacity = other.nCapacity;

	m_data = new char[nCapacity] { '\0' };
	strcpy(m_data, other.m_data);
}

char* String::getStrSum(const char* first, const size_t firstSize, const char* second, const size_t secondSize) const {
	char* sum = new char[firstSize + secondSize + 1]{ '\0' };

	for (size_t index = 0; index < firstSize; ++index)
		sum[index] = first[index];

	for (size_t index = 0; index < secondSize; ++index)
		sum[firstSize + index] = second[index];

	return sum;
}

char& String::getElementAtIndex(const int index) const {
	if (index < 0 || index >= nSize)
		throw OutOfBoundsException("Index out of bounds");

	return m_data[index];
}

std::ostream& operator<<(std::ostream& out, const String& str) {
	for (size_t index = 0; index < str.nSize; ++index)
		out << str[index];

	return out;
}
