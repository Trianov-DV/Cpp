#include <iostream>
#include <vector>
#include <memory>
#include <exception>

#include "class.h"

void isSandwich(String& str)
{
	std::string test;

	if (str.getLength() < 3)
	{
		throw std::runtime_error("(Bad string, < 3)");
	}

	for (size_t i = str.getLength(); i >= 0; --i)
	{
		test += str[i];
	}

	if (memcmp(str.getString().data(), test.data(), str.getLength()) == 0)
		std::cout << "The strings are SENDWICH";
	else
		std::cout << "The strings are not SENDWICH";
}

int main() 
{
	String str1;

	std::string sstr("AAVAA");
	String str2(sstr);

	String str3;
	String str4;
	String str5;

	try
	{
		isSandwich(str1);
		isSandwich(str2);
		isSandwich(str3);
		isSandwich(str4);
		isSandwich(str5);
	}
	catch (std::exception& exception)
	{
		std::cerr << "An exception (" << exception.what() << ")\n";
	}

	return 0;
}