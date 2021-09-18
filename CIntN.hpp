#ifndef CIntN_hpp
#define CIntN_hpp

#include <iostream>
#include <string>
#include <algorithm>

class CIntN {
private:
	int64_t N_;
	char sign_;
	int* n_;
public:
	CIntN();
	CIntN(const int64_t N);
	~CIntN();
	int64_t get_N() const;
	char get_sign() const;
	void new_sign(const char sign);
	void new_N(const int64_t N);
	void new_n(std::string number);
	void new_n(const int64_t N, const int* number);
	const int operator[](const int64_t index) const;
	CIntN(const CIntN& x);
	CIntN& operator=(const CIntN& x);
	void output();
};

#endif