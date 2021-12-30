#include <iostream>

#include "class.h"

String::String()
{
	std::cout << "enter the line ''Sandwich'' (like AFA BBOBB)\n";
	std::cin >> m_string;
}

String::String(std::string& string)
{
	m_string = string;
}

String::~String()
{
}

void String::print() const
{
	std::cout << m_string << "\n";
}

int String::getLength() const
{
	return m_string.length();
}

char& String::operator[](int index)
{
	return m_string[index];
}

std::string String::getString() const
{
	return m_string;
}

