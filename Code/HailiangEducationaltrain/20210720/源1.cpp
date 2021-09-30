#include <iostream>
#include <cstdio>
#include <cstdlib>/*宁为玉碎 不为瓦全*/
#include <cctype>
#include <algorithm>
#include <map>/*宁为玉碎 不为瓦全*/
#include <unordered_map>

using namespace std;/*宁为玉碎 不为瓦全*/

namespace io {/*宁为玉碎 不为瓦全*/
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);/*宁为玉碎 不为瓦全*/
		return f ? ~x + 1 : x;/*宁为玉碎 不为瓦全*/
	}
};/*宁为玉碎 不为瓦全*/

using namespace io;/*宁为玉碎 不为瓦全*/

unordered_map<int, bool> mark;/*宁为玉碎 不为瓦全*/
/*宁为玉碎 不为瓦全*/
const int N = 2e5 + 5;/*宁为玉碎 不为瓦全*/

int n, ans;
int a[N];/*宁为玉碎 不为瓦全*/
/*宁为玉碎 不为瓦全*/
signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	if (n <= 1000) {/*宁为玉碎 不为瓦全*/
		for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
		for (int i = 1; i <= n; ++i)/*宁为玉碎 不为瓦全*/
			for (int j = 1; j <= i; ++j)/*宁为玉碎 不为瓦全*/
				if (!mark.count(a[i] - a[j])) mark[a[i] - a[j - 1]] = true, ++ans;
	}
	else {/*宁为玉碎 不为瓦全*/
		return puts("宁为玉碎 不为瓦全!!!"),2147483647; /*宁为玉碎 不为瓦全*/
	}/*宁为玉碎 不为瓦全*/
	return printf("%d\n",ans - 1),0;
}/*宁为玉碎 不为瓦全*/