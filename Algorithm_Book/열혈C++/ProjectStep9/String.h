#pragma once
#include <iostream>
using namespace std;

class String {
private:
	char* str;
	int len;
public :
	String();
	String(const char* str);
	String(const String& ref);
	~String();
	String& operator=(const String& op);
	String operator+(const String& op);
	String& operator+=(const String& op);
	bool operator==(const String& op);

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);
};