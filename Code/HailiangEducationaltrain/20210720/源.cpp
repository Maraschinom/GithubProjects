#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using io::read;

const int N = 3e5 + 5;

const double pi = acos(-1);

int n, m;

class complex {
public:
	double imag, element;
	complex(double _a = 0, double _b = 0) : imag(_a), element(_b) {}
	complex operator + (complex a) {
		return complex(imag + a.imag, element + a.element);
	}
	complex operator - (complex a) {
		return complex(imag - a.imag, element - a.element);
	}
	complex operator * (complex a) {
		return complex(imag * a.imag - element * a.element, imag * a.element + element * a.imag);
	}
	void operator += (complex a) {
		*this = *this + a;
	}
	void operator *= (complex a) {
		*this = *this * a;
	}
};

complex a[N], b[N];

void FFT(complex *a, int n, int type) {
	if (n == 1) return;
	complex l[n >> 1], r[n >> 1];
	for (int i = 0; i < n; i += 2) l[i >> 1] = a[i], r[i >> 1] = a[i + 1];
	FFT(l, n >> 1, type); FFT(r, n >> 1, type);
	complex wn(cos(2 * pi / n), sin(2 * type * pi / n)), w(1, 0), t;
	for (int i = 0; i < n >> 1; ++i, w *= wn) {
		t = w * r[i], a[i] = l[i] + t, a[i + (n >> 1)] = l[i] - t;
	} return;
}

signed main() {
	n = read(), m = read();
	for (int i = 0, x; i <= n; ++i) x = read(), a[i] = x;
	for (int i = 0, x; i <= m; ++i) x = read(), b[i] = x;
	m += n; for (n = 1; n <= m; n <<= 1);
	FFT(a, n, 1); FFT(b, n, 1);
	for (int i = 0; i <= n; ++i) a[i] *= b[i]; FFT(a, n, -1);
	for (int i = 0; i < n; ++i) a[i].imag /= n;
	for (int i = 0; i <= m; ++i) printf("%d ", (int)(a[i].imag + 0.5));
}