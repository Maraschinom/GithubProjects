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

int T , ans;
int a[11] ;
char ch[11]; 

void dfs(int x,int wl,int wr) {
	if (x == 11) {
		ans = min(ans,10);
		return;
	}
	if (x & 1) {
		if ((10 - x + 1) / 2 < abs(wr - wl)) {
			ans = min(ans,x - 1) ;
			return void();
		}
	} else {
		if ((wl - wr) > (10 - x + 2) / 2) return ans = min(ans,x - 1),void() ;
		else if ((wr - wl) > (10 - x) / 2) return ans = min(ans,x - 1),void() ;
	}
	if (ch[x] == '0') dfs(x + 1,wl,wr) ;
	else if (ch[x] == '1') dfs(x + 1,wl + (x & 1),wr + ((x + 1) & 1)) ;
	else dfs(x + 1,wl,wr) , dfs(x + 1,wl + (x & 1),wr + ((x + 1) & 1));
}

signed main() {
	T = read();
	while (T--) {
		ans = 11;
		scanf("%s",ch + 1);
		dfs(1,0,0) ;
		printf("%d\n",ans);
	}
	return 0;
}
