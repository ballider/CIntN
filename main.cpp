#include "head.hpp"
#include "AutoTest.hpp"

int main() {

	if (!AutoTest()) return 0;

	std::cout << "Input 1 if you want sum two number." << std::endl;
	std::cout << "Input 2 if you want difference two number." << std::endl;
	std::cout << "Input -1 to break." << std::endl;

	while (true) {
		int key; std::cin >> key;
		if (key == -1) break;
		if (key == 1) {
			CIntN a, b;
			std::cout << "Input two numbers: " << std::endl;
			std::string x, y; std::cin >> x >> y;
			a.new_n(x); b.new_n(y);
			CIntN ans; ans = a + b;
			ans.output();
		}
		if (key == 2) {
			CIntN a, b;
			std::cout << "Input two numbers: " << std::endl;
			std::string x, y; std::cin >> x >> y;
			a.new_n(x); b.new_n(y);
			CIntN ans; ans = a - b;
			ans.output();
		}
	}
	return 0;
}