/*
* @Author: Maraschino
* @Date:   2021-09-18 14:49:36
* @Last Modified by:   Maraschino
* @Last Modified time: 2021-09-18 14:52:23
*/

#include <bits/stdc++.h>

using namespace std;

class Sort{
	int read(int x = 0, bool f = fasle, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}

	unordered_map<int, int> hash_table;

	int a[N];
}


signed main() {
	return 0;
}