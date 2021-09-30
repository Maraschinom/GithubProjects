#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <cstring>

using namespace std;

namespace Read {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using Read::read;

class Integer {
private:
	int len;
	int digit[100];
public:
	Integer() { len = 0; memset(digit, 0, sizeof digit); }
	Integer(int x) {
		len = 0;
		memset(digit, 0, sizeof digit);
		while (x) {
			digit[len++] = x % 10000;
			x /= 10000;
		} len -= 1;
	}
	friend Integer operator + (Integer a, Integer b) {
		Integer result;
		result.len = max(a.len, b.len);
		for (int i = 0; i <= result.len; ++i) {
			result.digit[i] += (a.digit[i] + b.digit[i]) % 10000;
			result.digit[i + 1] += (a.digit[i] + b.digit[i]) / 10000;
		}
		result.len = result.digit[result.len + 1] ? result.len + 1 : result.len;
		return result;
	}
	friend Integer operator += (Integer a, Integer b) {
		return a = (a + b);
	}
	void print() {
		printf("%d", this->digit[len]);
		for (int i = this->len - 1; ~i; --i) {
			printf("%04d", this->digit[i]);
		} return;
	}
};

const int N = 1e6 + 5;
const int mod = 1e9 + 7;

int T, n, m;
unsigned long long ans;
unsigned long long fibonacci[N];

unsigned long long gcd(unsigned long long  x, unsigned long long  y) {
	return y ? gcd(y, x % y) : x;
}

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

signed main() {
	fre(fibonacci); fibonacci[1] = 1; fibonacci[2] = 1;
	for (int i = 3; i <= 105; ++i)
		fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
	T = read();
	while (T--) {
		ans = 0;
		n = read(), m = read();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				(ans += gcd(fibonacci[i], fibonacci[j])) %= mod;
			} printf("%llu\n", ans);
	}
}
