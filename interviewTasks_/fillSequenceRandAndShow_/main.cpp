#include <iostream>
#include <vector>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <random>
#include <ctime>

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

int main()
{
    using ElemType = int;
	constexpr ElemType LOWER_BOUND = 1;
	constexpr ElemType UPPER_BOUND = 20;

	std::vector<ElemType> arr;
    arr.clear();
    arr.resize(randomNumber(LOWER_BOUND, UPPER_BOUND));
    fillSequenceRand(arr, LOWER_BOUND, UPPER_BOUND);
    show(arr);
}