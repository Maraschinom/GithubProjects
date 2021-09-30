	#include <bits/stdc++.h>

	using namespace std;

	#define int long long

	int read(int x = 0, bool f = false, char ch = getchar()) {
		for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
		for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
		return f ? ~x + 1 : x;
	}

	const int N = 3e5 + 5;

	int n, s, tail, head;
	int f[N], g[N], T[N], cost[N], q[N];

	signed main() {
		n = read(), s = read();
		for (int i = 1; i <= n; ++i) {
			T[i] = T[i - 1] + read();
			cost[i] = cost[i - 1] + read();
		} f[0] = 0; q[head] = 0;
		for (int i = 1; i <= n; ++i) {
		    
		    int l = head, r = tail;
		    
		    while(l < r) {
		        int mid = l + r >> 1;
		        if ((double)f[q[mid + 1]] - f[q[mid]] > (double)(T[i] + s) * (cost[q[mid + 1]] - cost[q[mid]])) r = mid;
		        else l = mid + 1;
		    }
		    
		    int pos = q[r];
		    
			f[i] = f[pos] - (T[i] + s) * cost[pos] + T[i] * cost[i] + cost[n] * s;
	 		
	 		while(head < tail && (double)(f[q[tail]] - f[q[tail - 1]]) * (cost[i] - cost[q[tail - 1]]) >= (double)(f[i] - f[q[tail - 1]]) * (cost[q[tail]] - cost[q[tail - 1]])) -- tail;
			
			q[++ tail] = i;
		} return printf("%lld\n", f[n]), 0;
	}	