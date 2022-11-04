#pragma once
#include <iterator>     // std::iterator, std::input_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
class String 
{
public:
	String();
	String(const char* givenString);
	String(const String& string);
	String(String&& string);
	String& operator=(const String& rhs);
	String& operator=(String&& rhs);
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	char* operator+(const String& rhs);
	char* operator+(const char* rhs);
	void append(const String& stringToAppend);
	int length(const char* toLength);
	const char* c_str();
	~String();
	operator const char* () { return this->string; };
	class Iterator 
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = const char;
		using pointer = const char*;  // or also value_type*
		using reference = const char&;  // or also value_type&

		Iterator(pointer ptr) : pter(ptr) {}

		Iterator& operator=(const char* pointer);//*  removed
		void operator++();
		void operator--();
		bool operator==(const Iterator it);
		bool operator!=(const Iterator it);
		reference operator*();
		const char* operator->();
		const char* getAdress();//*  removed

		operator const char* () { return this->pter; };

	private:
		pointer pter;//*  removed
	};
	String::Iterator begin();
	String::Iterator end();
private:
	using iterator_category = std::forward_iterator_tag;
	const char* string ;
	char* add(const char* rhs);
};

