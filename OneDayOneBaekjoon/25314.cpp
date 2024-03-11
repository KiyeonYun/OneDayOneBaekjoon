#include <iostream>

int main()
{
	int number;

	std::cin >> number;

	for (int i = 0; i < number; i += 4) {
		std::cout << "long ";
	}
	std::cout << "int";
}