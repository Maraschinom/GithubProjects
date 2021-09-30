/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 20:07:57
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-12 18:52:21
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 5;

int n, deg;

char m[N][N];

set<pair<int, int> > s[5];

struct node {
	char m[N][N];
	void print() {
		puts("");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				cout << m[i][j];
			puts("");
		} puts("");
	}
}M, T;

node reverse(node m) {
	node re;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			re.m[i][j] = m.m[j][n - 1 - i]; 
	return re;
}

void check() {
	s[1].clear();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (M.m[i][j] == '#')
				s[1].insert(make_pair(i, j));

	int xx = s[0].begin() -> first - s[1].begin() -> first;
	int yy = s[0].begin() -> second - s[1].begin() -> second;

	if (s[1].size() != s[0].size()) {puts("No"); exit(0);}

	bool flag = true;
	for (set<pair<int, int>>::iterator it = s[0].begin(), it2 = s[1].begin(); it != s[0].end() && it2 != s[1].end(); ++it, ++it2) {
		if (it -> first - it2 -> first != xx || it -> second - it2 -> second != yy) flag = false;
	} if (flag) {puts("Yes"); exit(0);}

	M = reverse(M);
	// M.print();
}


int main() {

	cin >> n;

	for (int i = 0; i < n; ++i) {
		scanf("%s", M.m[i]);
	}

	for (int i = 0; i < n; ++i) {
		scanf("%s", T.m[i]);
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (T.m[i][j] == '#') s[0].insert(make_pair(i,j));

	check(); check(); check(); check(); check();

	puts("No"); return 0;
}