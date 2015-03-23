#include "String.h"
#include <stdarg.h>
#include <stdio.h>


	//Constructors

	String::String()
	{
		sizeMemory = 1;
		strng = new char[sizeMemory];
		strng = '\0';

	}

	String::String(const char* format, ...)
	{
		 sizeMemory = 0;
		if (format != NULL)
		{
			unsigned const int TMP_STRING_SIZE = 4096;
			static char tmp[TMP_STRING_SIZE];
			static va_list ap;
			va_start(ap, format);
			int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
			va_end(ap);
			if (res > 0)
			{
				sizeMemory = res + 1;
				NewString(res + 1);
				strcpy_s(strng, sizeMemory, tmp);
			}
		}
		if (sizeMemory == 0)
		{
			sizeMemory = 1;
			NewString(1);
			strng[0] = '\0';
		}
	}

	String::String(const String& c)
	{
		sizeMemory = c.Capacity();
		strng = new char[sizeMemory];
		strcpy_s(strng, sizeMemory, c.strng);
	}

	//Destructor

	String::~String(){
		delete[] strng;
	}


	//Operators

	bool String::operator==(const char* c) const{
		assert(c != NULL);
		if (strlen(c) != sizeMemory - 1)
			return false;
		if (strcmp(strng, c) != 0)
			return false;

		return true;
	}

	bool String::operator==(const String& s)const{
		if (s.sizeMemory != sizeMemory)
			return false;
		if (strcmp(strng, s.strng) != 0)
			return false;

		return true;
	}

	bool String::operator!=(const char* c) const{
		assert(c != NULL);
		if (strlen(c) != sizeMemory - 1)
			return true;
		if (strcmp(strng, c) != 0)
			return true;

		return false;
	}

	bool String::operator!=(const String& s) const{

		if (s.sizeMemory != sizeMemory)
			return true;
		if (strcmp(strng, s.strng) != 0)
			return true;

		return false;
	}

	const String String::operator=(const char* c){
		if (c != NULL)
		{
			if (sizeMemory < strlen(c) + 1)
			{
				delete[] strng;
				sizeMemory = strlen(c) + 1;
				NewString(sizeMemory);
			}
			strcpy_s(strng, sizeMemory, c);
		}
		else {
			Clear();
		}

		return *this;
	}
	const String String::operator=(const String& s){

		if (sizeMemory < s.sizeMemory)
		{
			delete[] strng;
			sizeMemory = s.sizeMemory;
			NewString(sizeMemory);
		}
		strcpy_s(strng, sizeMemory, s.strng);

		return *this;
	}

	const String String::operator+=(const char* c){
		if (c != NULL)
		{
			
				char* tmp = strng;
				strcpy_s(tmp, sizeMemory, strng);

				sizeMemory = Length() + strlen(c) + 1;
				NewString(sizeMemory);
				strcpy_s(strng, sizeMemory , tmp);
				delete[] tmp;

			
			strcat_s(strng, sizeMemory, c);
		}

		return *this;
	}

	const String String::operator+=(const String& s){
		if (sizeMemory < Length() + s.Length() + 1)
		{
			char *tmp = new char[sizeMemory];
			strcpy_s(tmp, sizeMemory, strng);

			sizeMemory = Length() + s.Length() + 1;
			NewString(sizeMemory);
			strcpy_s(strng, sizeMemory, tmp);
			delete[] tmp;
		}
		strcat_s(strng, sizeMemory, s.strng);
		return *this;
	}

	//Methods

	void String::NewString(unsigned const int sizeMemory){
			strng = new char[sizeMemory];
		}

	unsigned int String::Length() const{
			return strlen(strng);
		}

	unsigned int String::Capacity()const{
			return sizeMemory;
		}

	const char* String::GetString(){
			return strng;
		}

	void String::Clear(){
			delete[] strng;
			sizeMemory = 1;
			strng = new char[sizeMemory];
			strng[0] = '\0';
		}
	