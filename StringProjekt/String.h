#pragma once
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
	size_t length();
	const char* c_str();
	~String();
	operator const char* () { return this->string; };
	class Iterator 
	{
	public:
		Iterator(const char* adress);
		Iterator(const Iterator& it);
		Iterator& operator=(const char* pointer);//*  removed
		void operator++();
		void operator--();
		bool operator==(const Iterator it);
		bool operator!=(const Iterator it);
		const char& operator*();
		const char* operator->();
		const char* getAdress();//*  removed
		operator  const char*() const{ return this->currentAdress; };

	private:
		const char* currentAdress = nullptr;//*  removed
	};
	String::Iterator begin();
	String::Iterator end();
private:
	const char* string ;
	char* add(const char* rhs);
};

