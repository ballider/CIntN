#include "CIntN.hpp"
#include <iostream>

CIntN::CIntN() {
	n_ = NULL;
	sign_ = '+';
	N_ = 0;
}

CIntN::CIntN(const int64_t N) {
	if (N <= 0) {
		std::cout << "Error! N is not positive." << std::endl;
		exit(-1);
	}

	N_ = N;
	sign_ = '+';
	n_ = new int[N_];
	for (int64_t i = 0; i < N_; i++) {
		n_[i] = 0;
	}
}

CIntN::~CIntN() {
	delete[] n_;
}

int64_t CIntN::get_N() const {
	return N_;
}

char CIntN::get_sign() const {
	return sign_;
}

void CIntN::new_sign(const char sign) {
	sign_ = sign;
}

void CIntN::new_N(const int64_t N) {
	if (N <= 0) {
		std::cout << "Error! N is not positive." << std::endl;
		exit(-1);
	}

	N_ = N;
	if (n_) delete[] n_;
	n_ = new int[N_];
	for (int64_t i = 0; i < N_; i++) {
		n_[i] = 0;
	}
}

void CIntN::new_n(std::string number) {
	if (number[0] == '-') { sign_ = '-'; number.erase(0, 1); }
	else sign_ = '+';
	N_ = number.size();
	if (n_) delete[] n_;
	n_ = new int[N_];
	for (int64_t i = 0; i < N_; i++) {
		n_[i] = stoi(number.substr(i, 1));
	}
}

void CIntN::new_n(const int64_t N, const int* number) {
	if (N <= 0) {
		std::cout << "Error! N is not positive." << std::endl;
		exit(-1);
	}
	if (n_) delete[] n_;
	N_ = N;
	n_ = new int[N_];
	for (int64_t i = 0; i < N_; i++) {
		n_[i] = number[i];
	}
}

const int CIntN::operator[](const int64_t index) const {
	if (index >= 0 && index <= N_) {
		return n_[index];
	}
	else {
		std::cout << "Error! Index is not correct." << std::endl;
		exit(-3);
	}
}

CIntN::CIntN(const CIntN& x) {
	N_ = x.N_;
	sign_ = x.sign_;
	n_ = new int[N_];
	for (int64_t i = 0; i < N_; i++) {
		n_[i] = x.n_[i];
	}
}

CIntN& CIntN::operator=(const CIntN& x) {
	if (this == &x) return *this;

	sign_ = x.sign_;
	N_ = x.N_;

	if (n_) delete[] n_;
	n_ = new int[N_];
	for (int64_t i = 0; i < N_; i++) {
		n_[i] = x.n_[i];
	}

	return *this;
}

void CIntN::output() {
	if (sign_ == '-') std::cout << sign_;
	for (int64_t i = 0; i < N_; i++) {
		std::cout << n_[i];
	}
	std::cout << std::endl;
}

CIntN operator-(CIntN, CIntN);

CIntN operator+(CIntN x, CIntN y) {
	CIntN z;
	int64_t i = x.get_N();
	int64_t j = y.get_N();

	if (x.get_sign() == '-' && y.get_sign() == '-') z.new_sign('-');
	if (x.get_sign() == '+' && y.get_sign() == '-') {
		CIntN tmp; tmp = y; tmp.new_sign('+');
		z = x - tmp;
		return z;
	}
	if (x.get_sign() == '-' && y.get_sign() == '+') {
		CIntN tmp; tmp = x; tmp.new_sign('+');
		z = y - tmp;
		return z;
	}

	z.new_N(std::max(i, j));

	i--; j--;

	int* bar = new int[z.get_N() + 1];
	for (int64_t k = 0; k < z.get_N() + 1; k++) {
		bar[k] = 0;
	}

	int64_t k = z.get_N();
	if (i >= j) {
		int r = 0;
		while (j >= 0) {
			int tmp = x[i] + y[j] + r;
			bar[k] = tmp % 10;
			r = tmp / 10;
			i--; j--; k--;
		}
		while (i >= 0) {
			int tmp = x[i] + r;
			bar[k] = tmp % 10;
			r = tmp / 10;
			i--; k--;
		}

		if (r != 0) {
			bar[0] = r;
		}

		if (bar[0] == 0) {
			int* f = new int[z.get_N()];
			for (int64_t q = 0; q < z.get_N(); q++) {
				f[q] = bar[q + 1];
			}
			delete[] bar;

			z.new_n(z.get_N(), f);
			delete[] f;
		}
		else {
			z.new_n(z.get_N() + 1, bar);
			delete[] bar;
		}

	}
	else if (i < j) {
		int r = 0;
		while (i >= 0) {
			int tmp = y[j] + x[i] + r;
			bar[k] = tmp % 10;
			r = tmp / 10;
			i--; j--; k--;
		}
		while (j >= 0) {
			int tmp = y[j] + r;
			bar[k] = tmp % 10;
			r = tmp / 10;
			j--; k--;
		}

		if (r != 0) {
			bar[0] = r;
		}

		if (bar[0] == 0) {
			int* f = new int[z.get_N()];
			for (int64_t q = 0; q < z.get_N(); q++) {
				f[q] = bar[q + 1];
			}
			delete[] bar;

			z.new_n(z.get_N(), f);
			delete[] f;
		}
		else {
			z.new_n(z.get_N() + 1, bar);
			delete[] bar;
		}

	}

	return z;
}

CIntN operator-(CIntN x, CIntN y) {
	CIntN z;

	if (x[0] == 0 && y[0] == 0) {
		int* a = new int[1];
		a[0] = 0;
		z.new_n(1, a);
		delete[] a;
		return z;
	}

	if (x.get_sign() == '+' && y.get_sign() == '-') {
		CIntN tmp; tmp = y; tmp.new_sign('+');
		z = x + tmp;
		return z;
	}
	if (x.get_sign() == '-' && y.get_sign() == '+') {
		CIntN tmp = y; tmp.new_sign('-');
		z = x + tmp;
		return z;
	}
	if (x.get_sign() == '-' && y.get_sign() == '-') {
		CIntN tmp = x; tmp.new_sign('+');
		x = y; x.new_sign('+');
		y = tmp;
	}

	// sing(x) = sign(y) = +

	// сравнить x и y чтобы понять что больше и вычитать из большего меньшее

	if (x.get_N() < y.get_N()) {
		CIntN tmp; tmp = x;
		x = y;
		y = tmp;
		z.new_sign('-');
	}
	else if (x.get_N() == y.get_N()) {
		bool ok = 1;
		for (int64_t i = 0; i < x.get_N(); i++) {
			if (x[i] > y[i]) break;
			if (x[i] < y[i]) {
				ok = 0;
				break;
			}
		}
		if (ok == 0) {
			CIntN tmp; tmp = x;
			x = y;
			y = tmp;
			z.new_sign('-');
		}
	}
	int64_t i = x.get_N() - 1;
	int64_t j = y.get_N() - 1;

	int* temp = new int[i + 1];
	for (int64_t q = 0; q < i + 1; q++) {
		temp[q] = 0;
	}

	int* xn = new int[x.get_N()];
	for (int64_t q = 0; q < x.get_N(); q++) {
		xn[q] = x[q];
	}

	int* yn = new int[y.get_N()];
	for (int64_t q = 0; q < y.get_N(); q++) {
		yn[q] = y[q];
	}


	while (j >= 0) {
		if (xn[i] >= yn[j]) {
			temp[i] = xn[i] - yn[j];
		}
		else {
			int64_t k = i - 1;
			while (true) {
				if (xn[k] == 0) xn[k] = 9;
				else {
					xn[k]--;
					temp[i] = xn[i] + 10 - yn[j];
					break;
				}
				k--;
			}
		}
		i--; j--;
	}


	while (i >= 0) {
		temp[i] = xn[i];
		i--;
	}

	delete[] xn;
	delete[] yn;
	
	int64_t index_zero = 0;
	while (temp[index_zero] == 0) index_zero++;
	int* f = new int[x.get_N() - index_zero];
	for(int64_t q = 0; q < x.get_N() - index_zero; q++) {
		f[q] = temp[q + index_zero];
	}
	
	z.new_n(x.get_N()-index_zero, f);

	delete[] f;
	delete[] temp;

	return z;
}