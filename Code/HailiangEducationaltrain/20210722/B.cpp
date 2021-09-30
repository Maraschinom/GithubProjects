#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

namespace io {
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}
}

using namespace io;

const int N = 1000;

int T;
string s, ss, str, suffix[N][N], sum[N][N];
bool ans;

string get(int x, int y, int z) {
	string ans = sum[x][x + y] ;
	if (x + y - max(1,z) >= 0) ans += suffix[x + y - z][x + y - 1];
	return ans;
}

signed main() {
	T = read();
	while (T--) {
		ans = false;
		cin >> s >> ss;
		int len1 = s.length(), len2 = ss.length();
		for (int i = 0; i < len1; ++i) {
			for (int j = i; j < len1; ++j) {
				sum[i][j] = suffix[i][j] = "";
			}
		}
		for (int i = 0; i < len1; ++i) {
			for (int j = i; j < len1; ++j) {
				for (int k = i; k <= j; ++k) {
					sum[i][j] += s[k];
				}
				for (int k = j; k >= i; --k) {
					suffix[i][j] += s[k];
				}
			}
		}
		for (int i = 0; i < len1; ++i)
			if (s[i] == ss[0])
			for (int j = 0; j < len1 - i; ++j) {
				int k = len2 - j - 1;
				str = get(i,j,k) ;
				if (str == ss) {
					ans = true ;
					break ;
				}
			} puts(ans ? "Yes" : "No");
	}
	return 0;
}
