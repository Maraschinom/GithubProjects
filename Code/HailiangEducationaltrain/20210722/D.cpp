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

const int N = 1e5 + 5 ;

int T;

char s[N],t[N]; 

signed main() {
	T = read();
	while (T--) {
		scanf("%s%s",s + 1,t + 1);
		bool ans = false;
		int len = strlen(s + 1), len2 = strlen(t + 1);
		if (len2 > len) {
			puts("No") ;
			continue ;
		}
		int now = len + 1;
		for (int i = len2; i; --i) {
			while(now >= 2 && s[now - 1] != t[i]) now -= 2;
			if (now <= 1) { ans = true; break; }
			if (s[now - 1] == t[i]) -- now;
		} puts(!ans?"Yes":"No");
	}
	return 0;
}
