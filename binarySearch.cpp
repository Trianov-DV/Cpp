#include <iostream>
#include <vector>

bool binarySearch(std::vector<int>& vec, int target)
{
	int leftIndex = 0, rightIndex = vec.size() - 1;
	int midIndex = vec.size() / 2;
	int count = 1;

	while (true)
	{
		if (vec[midIndex] < target)
		{
			leftIndex = midIndex;
			midIndex = (midIndex + rightIndex) / 2;
			++count;
		}
		else if (vec[midIndex] > target)
		{
			rightIndex = midIndex;
			midIndex = (leftIndex + midIndex) / 2;
			++count;
		}
		else if (vec[midIndex] == target)
		{
			std::cout << "The required number is found: " << vec[midIndex] << "\n";
			std::cout << "for " << count << " operations";
			
			return true;
		}
		else
		{
			std::cout << "Target number is not found\n";
			return false;
		}
	}

}

int main()
{
	std::vector<int> vector;

	for (size_t i = 1; i <= 100; i++)
	{
		vector.push_back(i);
	}

	int target = 12;

	binarySearch(vector, target);

	return 0;
}