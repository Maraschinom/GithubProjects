#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;

typedef pair<int,int> PII ;

const int N = 20 ;

int n , w , dep , sum , cnt ;
int c[N] , use[N] ;

bool dfs(int x) {
    if (x == n + 1) return true ;
    for (int i = 1 ; i <= dep ; ++ i) {
        if (c[x] + use[i] <= w)
            use[i] += c[x] ;
        if (dfs(x + 1)) return true ;
        use[i] -= c[x] ;
    } return false ;
}

signed main(int argc,char *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> n >> w ;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> c[i] ; sum += c[i] ; 
    } sort(c + 1,c + 1 + n,greater<int>()) ;
    for (dep = ceil(sum * 1.0 / w) ; dep <= n ; ++ dep) {
        if (dfs(1)) return printf("%d\n",dep) , 0 ;
    }
    return 0 ; 
}