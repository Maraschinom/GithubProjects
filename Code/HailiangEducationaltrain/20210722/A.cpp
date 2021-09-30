#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

namespace io{
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

int T, n;

signed main() {
	T = read();
	for (int _ = 1; _ <= T; ++_) {
		n = read();
		cout << (n + 1) / 10 << endl;
	}
	return 0;
}