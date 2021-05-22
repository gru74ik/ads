#include <iostream>
#include <string>

void swap_two_ints(int & a, int & b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void print_two_ints(const std::string & message, int a, int b) {
    std::cout
        << message
        << "\tx: " << a << "\n"
        << "\ty: " << b << "\n\n";
}

int main()
{
	int x = 15; //1111
	int y = 10; //1010

    print_two_ints("Before swap:\n", x, y);
    swap_two_ints(x, y);
	print_two_ints("After swap:\n", x, y);

	return 0;
}