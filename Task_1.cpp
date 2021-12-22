//	Exercise
//	
//	Find such elements of two arrays that are 
//	found only in each of them.	It is advisable to use STL


#include <iostream> 
#include <vector>
#include <algorithm>
#include <random>

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	// Let's assume that the vectors are different

	std::vector<int> v1;
	for (size_t i = 0; i < 15; ++i)
	{
		v1.push_back(getRandomNumber(1, 15));
	}

	std::cout << "V1 numbres: ";
	for (auto& element : v1)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";

	std::vector<int> v2;
	for (size_t i = 0; i < 20; ++i)
	{
		v2.push_back(getRandomNumber(1, 20));
	}

	std::cout << "\nV2 numbres: ";
	for (auto& element : v2)
	{
		std::cout << element << " ";
	}
	std::cout << "\n";

	std::vector<int>::const_iterator it_v1;
	it_v1 = v1.begin();

	// here we write identical numbers with v1 and v2
	std::vector<int> identicalNumbers;	
	
	while (it_v1 != v1.end())
	{
		std::vector<int>::const_iterator it_v2;
		it_v2 = v2.begin();

		while (it_v2 != v2.end())
		{
			if (*it_v1 == *it_v2)
			{
				identicalNumbers.push_back(*it_v1);
				break;
			}
			++it_v2;
		}
		++it_v1;
	}
	std::sort(identicalNumbers.begin(), identicalNumbers.end());

	identicalNumbers.erase(std::unique(identicalNumbers.begin(), identicalNumbers.end()), identicalNumbers.end());

	if (!identicalNumbers.empty())
	{
		std::cout << "\nIdentical numbers with V1 and V2: ";
		for (auto& element : identicalNumbers)
		{
			std::cout << element << " ";
		}
	}
	else
	{
		std::cout << "\nIdentical numbers with V1 and V2: none";
	}

	return 0;
}