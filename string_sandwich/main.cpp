#include <iostream>
#include <memory>
#include <exception>

#include "class.h"

bool isSandwich(String& str)
{
	if (str.getLength() < 3)
	{
		throw std::runtime_error("bad example for test , length < 3\n");
	}
	
	// we immediately exclude such sandwich options
	// AAAA  AABBAABBAA 
	int count = 0;
	for (int i = 0; i < str.getLength() - 1; ++i)
	{
		if (str[i] != str[i + 1])
		{
			++count;
		}
	}
	if (count != 2)
	{
		std::cout << str.getString() << " - this string is't a sandwich\n";
		return false;
	}

	// Checking all other variants
	int startIndex = 0;
	int endIndex = str.getLength() - 1;

	while (startIndex != str.getLength() - 1)
	{
		if (str[startIndex] == str[endIndex])
		{
			++startIndex;
			--endIndex;
		}
		else {
			std::cout << str.getString() << " - this string is't a sandwich\n";
			return false;
		}
	}
	std::cout << str.getString() << " - this string is a sandwich\n";
	return true;
}

int main()
{
	while (true)
	{
		String str1;

		try
		{
			isSandwich(str1);
		}
		catch (std::exception& exception)
		{
			std::cerr << "An exception (" << exception.what() << ")\n";
		}
	}
	

	return 0;
}