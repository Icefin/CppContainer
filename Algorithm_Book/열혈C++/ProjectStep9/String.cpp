#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "String.h"

const int MAX_INPUT = 100;


String::String()
{
	len = 0;
	str = nullptr;
}
String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}
String::String(const String& ref)
	: len(ref.len)
{
	str = new char[strlen(ref.str) + 1];
	strcpy(str, ref.str);
}
String::~String()
{
	if(str != nullptr) delete[] str;
}
String& String::operator=(const String& op)
{
	len = op.len;
	if (str != nullptr) delete[] str;
	str = new char[len];
	strcpy(str, op.str);
	return *this;
}
String String::operator+(const String& op)
{
	char* temp = new char[len + op.len + 1];
	strcpy(temp, str);
	strcat(temp, op.str);

	String ret(temp);
	delete[] temp;
	return ret;
}
String& String::operator+=(const String& op)
{
	len += op.len;
	char* temp = new char[len + op.len + 1];
	strcpy(temp, str);
	strcat(temp, op.str);
	
	if (str != nullptr) delete[] str;
	strcpy(str, temp);
	delete[] temp;
	return *this;
}
bool String::operator==(const String& op)
{
	if (len != op.len) return false;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != op.str[i]) return false;
	}
	return true;
}

ostream& operator<< (ostream& os, const String& s)
{
	os << s.str;
	return os;
}
istream& operator>> (istream& is, String& s)
{
	char str[MAX_INPUT];
	is >> str;
	s = String(str);
	return is;
}