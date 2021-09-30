/*
* @Copyright: Copyright © 2021 昕橘玥
* @Powered: Powered by .NET 5.0 on Kubernetes
* @Author: JuyueXin.
* @Date:   2021-09-11 20:32:18
* @Email: 8950466@qq.com
* @Last Modified by:   JuyueXin.
* @Last Modified time: 2021-09-12 19:29:00
*/

#include <bits/stdc++.h>

using namespace std;

int read(int x = 0, bool f = false, char ch = getchar()) {
	for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	return f ? ~x + 1 : x;
}

struct node {
	int id;
	set<int> path;
}

void bfs(int x) {
	queue<node> que; set<int> s;
	que.push(node{x, s});
	while(que.size()) {
		node u = que.front();
		que.pop();
		for (auto v : G[u]) 
			if (!vis[v.first])
				vis[v.first] = true, que.push(v.first, );
	}
}

signed main() {

}