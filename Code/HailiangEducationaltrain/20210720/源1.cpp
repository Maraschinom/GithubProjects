#include <iostream>
#include <cstdio>
#include <cstdlib>/*��Ϊ���� ��Ϊ��ȫ*/
#include <cctype>
#include <algorithm>
#include <map>/*��Ϊ���� ��Ϊ��ȫ*/
#include <unordered_map>

using namespace std;/*��Ϊ���� ��Ϊ��ȫ*/

namespace io {/*��Ϊ���� ��Ϊ��ȫ*/
	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);/*��Ϊ���� ��Ϊ��ȫ*/
		return f ? ~x + 1 : x;/*��Ϊ���� ��Ϊ��ȫ*/
	}
};/*��Ϊ���� ��Ϊ��ȫ*/

using namespace io;/*��Ϊ���� ��Ϊ��ȫ*/

unordered_map<int, bool> mark;/*��Ϊ���� ��Ϊ��ȫ*/
/*��Ϊ���� ��Ϊ��ȫ*/
const int N = 2e5 + 5;/*��Ϊ���� ��Ϊ��ȫ*/

int n, ans;
int a[N];/*��Ϊ���� ��Ϊ��ȫ*/
/*��Ϊ���� ��Ϊ��ȫ*/
signed main() {
	n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	if (n <= 1000) {/*��Ϊ���� ��Ϊ��ȫ*/
		for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
		for (int i = 1; i <= n; ++i)/*��Ϊ���� ��Ϊ��ȫ*/
			for (int j = 1; j <= i; ++j)/*��Ϊ���� ��Ϊ��ȫ*/
				if (!mark.count(a[i] - a[j])) mark[a[i] - a[j - 1]] = true, ++ans;
	}
	else {/*��Ϊ���� ��Ϊ��ȫ*/
		return puts("��Ϊ���� ��Ϊ��ȫ!!!"),2147483647; /*��Ϊ���� ��Ϊ��ȫ*/
	}/*��Ϊ���� ��Ϊ��ȫ*/
	return printf("%d\n",ans - 1),0;
}/*��Ϊ���� ��Ϊ��ȫ*/