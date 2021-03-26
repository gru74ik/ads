#include <iostream>
#include <vector>
#include <compare>

namespace my
{
	template<typename RandomIter>
	constexpr RandomIter find_middle(RandomIter first, RandomIter last) {
		return first + (last - first) / 2;
	}

	template<typename RandomIter, typename T>
	constexpr bool binary_search(RandomIter first, RandomIter last, const T& needle) {
		if (first == last) {
			return false;
		}
		for (auto range_size = last - first; range_size > 1; range_size = last - first) {
			auto middle = find_middle(first, last);
			const auto comparison_result = needle <=> *middle;
			if (std::is_lt(comparison_result)) {
				last = middle;
			}
			else if (std::is_gt(comparison_result)) {
				first = middle;
			}
			else {
				return true;
			}
		}
		return *first == needle;
	}

	template<typename Container, typename T>
	void test_one_value(const Container& haystack, const T& needle)
	{
		if (my::binary_search(haystack.begin(), haystack.end(), needle)) {
			std::cout << "OK, " << needle << " has been found in the vector.\n";
		}
		else {
			std::cout << "NOK, " << needle << " has not been found in the vector.\n";
		}
	}

	template<typename Container, typename T>
	void test_several_values(const Container& haystack, const T& addition)
	{
		for (T needle; const auto elem : haystack) {
			needle = elem + addition;
			if (my::binary_search(haystack.begin(), haystack.end(), needle)) {
				std::cout << "OK, " << needle << " has been found in the vector.\n";
			}
			else {
				std::cout << "NOK, " << needle << " has not been found in the vector.\n";
			}
		}
	}
}

int main()
{
	using Item = int;
	std::vector<Item> empty_vec{ };
	my::test_one_value(empty_vec, 666);

	std::vector<Item> haystack{ 15, 25, 35, 45, 55, 65, 75, 85, 95};
	my::test_several_values(haystack, 0);
	my::test_several_values(haystack, -1);
	my::test_one_value(haystack, 99);
}