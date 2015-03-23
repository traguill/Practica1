#ifndef __String_H__
#define __String_H__

#include <stdio.h>
#include <string.h>
#include <assert.h>

class String
{

private:

	//Attributes
	char* strng;
	unsigned int sizeMemory;

public:
	//Constructors
	String();
	String(const char* format, ...);
	String(const String& c);

	//Destructor
	~String();

	//Operators
	bool operator==(const char* c) const;
	bool operator==(const String& s)const;

	bool operator!=(const char* c) const;
	bool operator!=(const String& s) const;

	const String operator=(const char* c);
	const String operator=(const String& s);

	const String operator+=(const char* c);
	const String operator+=(const String& s);

	//Methods

	unsigned int Length() const;

	unsigned int Capacity()const;

	const char* GetString();

	void Clear();
	
private:

	void NewString(unsigned const int sizeMemory);

	

};
#endif