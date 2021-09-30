#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

namespace io {
	int read(int x = 0, char ch = getchar(), bool f = false) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
};

using namespace io;

signed main() {
		
}