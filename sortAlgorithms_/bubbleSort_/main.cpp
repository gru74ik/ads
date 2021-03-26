#include <iostream>
#include <algorithm>

void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);                 
            } 
        }
    }
}  

int main()
{
    int arr[] = { 22, 33, 11, 55, 77, 44 };
    bubbleSort(arr, std::size(arr));

    for (const auto elem : arr) {
        std::cout << elem << ' ';
    }
    std::cout << std::endl;
}