#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

/*!
* Имплементация на основните функционалности на един String
*/
class String {
public:
	/*!
	* Конструктор по подозиране
	*/
	String();
	/*!
	* Конструктор с параметри, който приема начално ... TODO: ДОВЪРШИ
	* @param str - низ
	*/
	String(const size_t initialCapacity);
	/*!
	* Конструктор с параметри, който приема някакъв низ
	* @param str - низ
	*/
	String(const char* str);
	/*!
	* Конструктор за копиране
	*/
	String(const String& other);
	/*!
	* Деструктор
	*/
	~String();

	void push_back(const char c);
	void pop_back();
	void append(const char* str);

	size_t size() const;
	size_t capacity() const;
	bool empty() const;

	void shrinkToFit();
	void clear();

	String operator+(const char c) const;
	String operator+(const char* str) const;

	String& operator+=(const char c);
	String& operator+=(const char* str);

	char& operator[](const int index);
	const char& operator[](const int index) const;

	operator char*() const;
	operator const char* () const;

	/*!
	* Предеифиниране на оператор "="
	*/
	String& operator=(const String& other);

	friend std::ostream& operator<<(std::ostream& out, const String& str);

private:
	char* m_data;
	size_t nSize;
	size_t nCapacity;

	void deleteData();
	void allocData(size_t newCapacity);
	void copy(const String& other);

	char* getStrSum(const char* first, const size_t firstSize, const char* second, const size_t secondSize) const;

	char& getElementAtIndex(const int index) const;
};

#endif // !STRING_H
