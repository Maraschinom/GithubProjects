#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std ;

typedef long long LL ;

const int N = 30 ;
int n , ans , k ;
LL s ;
int a[N] ;
LL fac[N] ;
unordered_map<LL,bool> num[N] ;

void dfs(int x,int ed,int use,LL sum) {
    if (use > k) return void() ;
    if (x > ed) {
        ++ num[use][sum] ;
        return void() ;
    }
    dfs(x + 1,ed,use,sum) ; 
	dfs(x + 1,ed,use,sum + 1LL * a[x]) ;
    if (a[x] <= 20) dfs(x + 1,ed,use + 1,sum + fac[a[x]]) ;
    return void() ;
}
void dfs2(int type,int x,int ed,int use,LL sum) {
    if (use > k) return void() ;
    if (sum > s) return void() ;
    if (x > ed) {
        for (int i = 0 ; i <= k - use ; ++i )
            ans += num[i][s - sum] ;
        return void() ;
    }
    dfs2(type,x + 1,ed,use,sum) ; 
	dfs2(type,x + 1,ed,use,sum + 1LL * a[x]) ;
    if (a[x] <= 20) dfs2(type,x + 1,ed,use + 1,sum + fac[a[x]]) ;
    return void() ;
}
signed main(void) {
    ios::sync_with_stdio(false) ;
    cin.tie(0) , cout.tie(0) ; fac[0] = 1LL ;
    for (int i = 1 ; i <= 20 ; ++i ) fac[i] = fac[i - 1] * (LL)i ;
	cin >> n >> k >> s ; for (int i = 1 ; i <= n ; ++i ) cin >> a[i] ; 
    int mid = (n + 1) / 2 ;
    dfs(1,mid,0,0) ; dfs2(1,mid + 1,n,0,0) ;
    return printf("%d\n",ans) , 0 ;
}
