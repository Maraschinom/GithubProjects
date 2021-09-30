/*
* * * * * * * * * *
 @Author : Mukrus
 @Date : 2121-7-14
* * * * * * * * * *

˵���ڵ�δ�� ʱ����˥�� 

*/
#pragma GCC diagnostic error "-std=c++11"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

int read(int x = 0, char ch = getchar(), bool f = false) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}		

typedef long long LL;
typedef pair<int, int> PII;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

const int N = 4e4 + 5;
int n, m, x, idx, ans;
bool vis[N];
vector<int> G[N];
char s[10];

void f(int x, int y) {
	for (int i = 1 ; i <= n * m; ++i) vis[i] = false ;
	queue<int> Q ;
	for (int i = (x - 1) * m + 1 ; i <= x * m ; ++i) {
		Q.push(i) ;
	}
	while (Q.size()) {
		int u = Q.front() ; Q.pop() ;
		if (vis[u]) continue ;
		vis[u] = true ;
		if ((y - 1) * m + 1 <= u && u <= y * m) {
			++ ans ;
			continue ;
		}
		for (auto v : G[u]) if(!vis[v]) Q.push(v) ;
	}
	return ;
}

signed main(int argc, char* argv[]) {
	fre(d) ;
	n = read(), m = read();
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			scanf("%s", s + 1);
			for (int it = 1; it <= m; ++it) {
				x = s[it] ^ 48;
				if (!x) continue;
				G[(i - 1) * m + j].push_back(i * m + it) ;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			f(i,j) ; 
		}
	} return printf("%d\n", ans), 0;
}

/*
Input:
4 4
1000
1100
0110
0011
0100
1100
0010
0001
1000
1100
0000
0011
Output:
21
*/
