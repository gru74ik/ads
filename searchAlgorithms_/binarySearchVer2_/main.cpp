#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <random>
#include <ctime>

template <typename RandomAccessIter, typename ValueType>
bool binarySearch(RandomAccessIter begin, RandomAccessIter end, const ValueType target)
{
	bool result = false;
	std::size_t numberOfElements = end - begin;

	if (numberOfElements < 1)
	{
		// do nothing
	}
	else if (numberOfElements == 1)
	{
		if (target == *begin)
		{
			result = true;
		}
	}
	else
	{
		auto middle = begin + numberOfElements / 2;

		if (target == *middle)
		{
			result = true;
		}
		else if (target < *middle)
		{
			result = binarySearch(begin, middle, target);
		}
		else
		{
			result = binarySearch(middle, end, target);
		}
	}

	return result;
}

template <typename T>
T randomNumber(const T begin, const T end)
{
	static std::mt19937 generator((std::size_t)time(0));
	std::uniform_int_distribution<T> distribution(begin, end);
	return distribution(generator);
}

template <typename Container, typename ValueType>
void fillSequenceRand(Container & seq, const ValueType fromNum, const ValueType toNum)
{
	for (auto & elem : seq)
		elem = randomNumber(fromNum, toNum);
}

template <typename Container>
void show(const Container & seq)
{
	for (const auto elem : seq)
		std::cout << elem << ' ';
	std::cout << "\n\n";
}

void binarySearchTest()
{
	constexpr std::size_t NUMBER_OF_TESTS = 100000;

	using ElemType = int;
	constexpr ElemType SEARCHING_TARGET = 11;
	constexpr ElemType LOWER_BOUND = 1;
	constexpr ElemType UPPER_BOUND = 20;

	std::vector<ElemType> arr;
	bool testPassedSuccessfully = true;

	for (std::size_t i = 0; i < NUMBER_OF_TESTS; ++i)
	{
		arr.clear();
		arr.resize(randomNumber(LOWER_BOUND, UPPER_BOUND));
		fillSequenceRand(arr, LOWER_BOUND, UPPER_BOUND);
		std::sort(arr.begin(), arr.end()); // binary search does make sense for sorted sequences only

		if (binarySearch(arr.begin(), arr.end(), SEARCHING_TARGET))
		{
			if (std::find(arr.begin(), arr.end(), SEARCHING_TARGET) == arr.end())
			{
				std::cout
					<< "Expected that this sequence contains "
					<< SEARCHING_TARGET << ", but it doesn't:\n";
				show(arr);
				testPassedSuccessfully = false;
				break;
			}
		}
		else
		{
			if (std::find(arr.begin(), arr.end(), SEARCHING_TARGET) != arr.end())
			{
				std::cout
					<< "Expected that this sequence not contains "
					<< SEARCHING_TARGET << ", but it does:\n";
				show(arr);
				testPassedSuccessfully = false;
				break;
			}
		}
	}

	if (testPassedSuccessfully)
	{
		std::cout << "All tests have been successfully passed.\n";
	}
}

int main()
{
	binarySearchTest();
}