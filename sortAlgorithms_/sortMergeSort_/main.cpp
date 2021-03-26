#include <iostream>
#include <cstddef>
#include <vector>

template <typename Container>
void merge(
	Container & arr,
	std::size_t lowerBound,
	std::size_t middle,
	std::size_t upperBound)
{
	const std::size_t LEFT_CHUNK_LAST_ELEM_INDEX = middle - lowerBound + 1;
	const std::size_t RIGHT_CHUNK_LAST_ELEM_INDEX = upperBound - middle;

	std::vector<int> leftChunk;
	std::vector<int> rightChunk;

	for (std::size_t i = 0; i < LEFT_CHUNK_LAST_ELEM_INDEX; ++i)
		leftChunk.push_back(arr[lowerBound + i]);

	for (std::size_t i = 0; i < RIGHT_CHUNK_LAST_ELEM_INDEX; ++i)
		rightChunk.push_back(arr[middle + i + 1]);

	for (std::size_t i = 0, j = 0, k = lowerBound; k <= upperBound; ++k)
		if (i < LEFT_CHUNK_LAST_ELEM_INDEX && j < RIGHT_CHUNK_LAST_ELEM_INDEX)
			if (leftChunk[i] <= rightChunk[j])
				arr[k] = leftChunk[i++];
			else
				arr[k] = rightChunk[j++];
		else if (i < LEFT_CHUNK_LAST_ELEM_INDEX)
			arr[k] = leftChunk[i++];
		else
			arr[k] = rightChunk[j++];
}

template <typename Container>
void mergeSort(
	Container & arr,
	std::size_t lowerBound,
	std::size_t upperBound)
{
	if (lowerBound < upperBound)
	{
		std::size_t middle = lowerBound + (upperBound - lowerBound) / 2;
		mergeSort(arr, lowerBound, middle);
		mergeSort(arr, middle + 1, upperBound);
		merge(arr, lowerBound, middle, upperBound);
	}
}

template <typename Container>
void mergeSort(Container & arr)
{
	mergeSort(arr, 0, std::size(arr) - 1);
}

template <typename Container>
void show(const Container & arr)
{
	for (const auto elem : arr)
		std::cout << elem << ' ';
	std::cout << '\n';
}

int main()
{
	int arr[]{ 5, 2, 4, 6, 1, 3, 2, 6 };
	mergeSort(arr);
	show(arr);

	std::vector<int> vec{ 9, 2, 4, 8, 1, 3, 7 };
	mergeSort(vec);
	show(vec);
}