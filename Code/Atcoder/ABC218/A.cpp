/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 19:59:08
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-11 20:06:13
*/

#include <bits/stdc++.h>

using namespace std;

int n;
char ch[8];

signed main() {
	scanf("%d", &n);
	scanf("%s", ch);
	puts(ch[n - 1] == 'o' ? "Yes" : "No");
}