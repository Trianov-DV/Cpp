#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <exception>
#include <initializer_list>


class Season
{
private:
	int m_season;
	std::string m_seasons[12] { "winter-January", "winter-February ", "spring-March", "spring-April", "spring-May", "summer-Jun", "summer-July", "summer-August", "autumn-September", "autumn-October", "autumn-November", "winter-December" };

public:

	Season(int season)
		: m_season(season)
	{
		if (season > 12 || season <= 0)
			{
				throw std::runtime_error("Bad season month");
			}
	}

	~Season() {}

	std::string& operator[] (const int index)
	{
		return m_seasons[index];
	}

	friend std::ostream& operator<< (std::ostream& out, const Season& s)
	{
		out << s.m_seasons[s.m_season];
		return out;
	}
};


int main()
{
	std::cout << "Enter you month: (1-12)\n";
	int month;
	std::cin >> month;

	try
	{
		Season season(month);
		std::cout << season[month-1];
	}
	catch(std::exception &exception)
	{
		std::cerr << "An exception (" << exception.what() << ")\n";
	}

	

	return 0;
}
