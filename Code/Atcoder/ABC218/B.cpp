/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 19:59:14
* @Email: marachino@vip.qq.com
* @Last Modified by:   Maraschino
* @Last Modified time: 2021-09-18 20:56:24
*/

#include "bits/stdc++.h"

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f? ~x + 1 : x;
}

const int N = 30;

int a[N];

signed main() {
	for (int i = 1; i <= 26; ++i) a[i] = read();
	for (int i = 1; i <= 26; ++i) putchar(a[i] + 'a' - 1);
}