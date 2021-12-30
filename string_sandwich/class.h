#pragma once

#include <string>

class String
{
private:
	std::string m_string;

public:
	String();

	String(std::string&);

	~String();

	void print() const;

	int getLength() const;

	char& operator[](int index);

	std::string getString() const;
};