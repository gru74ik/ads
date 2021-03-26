#include <iostream>

int main()
{
	unsigned int x = 218;		 //11011010
	unsigned int ODD_MASK = 170; //10101010
	unsigned int EVEN_MASK = 85; //01010101
	unsigned int y = ((x & ODD_MASK) >> 1) | ((x & EVEN_MASK) << 1); // 229 (11100101)

	std::cout << y << "\n\n";

	return 0;
}