#include "AutoTest.hpp"
#include "head.hpp"

bool AutoTest1() {
	CIntN a, b; a.new_n("-123"); b.new_n("124");
	CIntN ans; ans = a + b;
	if (ans.get_N() == 1 && ans[0] == 1) return 1;
	else return 0;
}

bool AutoTest2() {
	CIntN a, b; a.new_n("123"); b.new_n("125");
	CIntN ans; ans = a - b;
	if (ans.get_N() == 1 && ans[0] == 2 && ans.get_sign() == '-') return 1;
	else return 0;
}

bool AutoTest() {
	bool all = 1;
	if (!AutoTest1()) {
		all = 0;
		std::cout << "AutoTest1 failed." << std::endl;
	}
	if (!AutoTest2()) {
		all = 0;
		std::cout << "AutoTest1 failed." << std::endl;
	}
	return all;
}