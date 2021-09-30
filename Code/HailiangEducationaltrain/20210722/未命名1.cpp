#include <set>   
#include <queue>   
#include <cstdio> 
#include <vector>    
#include <algorithm>  
#define N 2000003  
#define ll long long 
#define setIO(s) freopen(s".in","r",stdin)   , freopen(s".out","w",stdout)    
using namespace std;
ll answer;
priority_queue<int>q;
vector<int>G[N], F[N], go[N];
int edges, n, root, sn, tmp, len, tt, m, flag;
int hd[N], nex[N << 1], to[N << 1], val[N << 1];
int siz[N], mx[N], vis[N];
bool cmp(int a, int b)
{
	return a > b;
}
void add(int u, int v, int c)
{
	nex[++edges] = hd[u], hd[u] = edges, to[edges] = v, val[edges] = c;
}
void getroot(int u, int ff)
{
	siz[u] = 1, mx[u] = 0;
	for (int i = hd[u]; i; i = nex[i])
		if (to[i] != ff && !vis[to[i]])
			getroot(to[i], u), siz[u] += siz[to[i]], mx[u] = max(mx[u], siz[to[i]]);
	mx[u] = max(mx[u], sn - siz[u]);
	if (mx[u] < mx[root]) root = u;
}
void getdis(int u, int ff, int dep)
{
	F[tmp].push_back(dep);
	for (int i = hd[u]; i; i = nex[i])
		if (to[i] != ff && !vis[to[i]])
			getdis(to[i], u, dep + val[i]);
}
void prepare(int u)
{
	printf("%d\n",u);
	vis[u] = 1, G[u].push_back(++tmp), getdis(u, 0, 0);
	for (int i = hd[u]; i; i = nex[i])
		if (!vis[to[i]])
		{
			printf("%d\n",to[i]);
			G[u].push_back(++tmp), getdis(to[i], u, val[i]);
			root = 0, sn = siz[to[i]], getroot(to[i], u), go[u].push_back(root), prepare(root);
		}
}
ll calc(int u, int t)
{
	int l = 0, r = F[u].size() - 1;
	if (r <= 0) return 0;
	ll sum = ((ll)(r + 1)*r) / 2;
	while (l < r)
	{
		if (F[u][l] + F[u][r] < t)
		{
			sum -= (ll)(r - l);
			--r;
		}
		else
		{
			++l;
		}
	}
	// printf("%lld\n",sum);    
	return sum;
}
void dfs(int u, int t)
{
	int i;
	if (!G[u].empty()) answer += calc(G[u][0], t);
	for (i = 1; i < (int)G[u].size(); ++i) answer -= calc(G[u][i], t);
	for (i = 0; i < (int)go[u].size(); ++i) dfs(go[u][i], t);
}
ll check(int t)
{
	answer = 0, dfs(tt, t);
	return answer;
}
multiset<int>S;
multiset<int>::iterator it;
// 长度大于 len 即可
void solve(int u)
{
	int i, j;
	if (!G[u].empty())
	{
		for (j = 0; j < F[G[u][0]].size(); ++j)
		{
			if (F[G[u][0]][j] > len) q.push(F[G[u][0]][j]);
		}
		if (G[u].size() >= 2)
		{
			int t = G[u][1];
			for (j = 0; j < F[t].size(); ++j) S.insert(-F[t][j]);
		}
	}
	for (i = 2; i < G[u].size(); ++i)
	{
		int t = G[u][i];
		// F[t] 与 S 结合 
		it = S.begin();
		for (j = 0; j<F[t].size() && (-(*S.begin()) + F[t][0])>len; ++j)
		{
			for (it = S.begin(); it != S.end(); it++)
			{
				if (-(*it) + F[t][j] > len)
				{
					q.push(-(*it) + F[t][j]);
				}
				else break;
			}
		}
		for (j = 0; j < F[t].size(); ++j)
			S.insert(-F[t][j]);
	}
	S.clear();
	for (int i = 0; i < go[u].size(); ++i) solve(go[u][i]);
}
int main()
{
	int i, tot = 0;
	//   setIO("input"); 
	scanf("%d%d", &n, &m);
	for (i = 1; i < n; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c), add(a, b, c), add(b, a, c), tot += c;
	}
	
	mx[root = 0] = sn = n, getroot(1, 0), tt = root, prepare(root);
	for (i = 1; i <= tmp; ++i) sort(F[i].begin(), F[i].end(), cmp);
//	for (int i = 1; i <= tmp ; ++i) {
//		for (auto v : F[i]) printf("%d ",v);
//		puts("");
//	}
	int l = 0, r = tot, mid, ans = 0;

	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (check(mid) >= 1ll * m) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
    len=ans,solve(tt);      
    while(q.size()<m) q.push(len);    
    while(!q.empty()) printf("%d\n",q.top()), q.pop(); 
	return 0;
}
