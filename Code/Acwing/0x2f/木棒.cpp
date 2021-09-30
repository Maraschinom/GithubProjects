#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 

using namespace std ;

inline int read(int x = 0,char ch = getchar(),bool f = false) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 65 ;

int sum , len , cnt , n , mx , tot ;
int a[N] ;
bool vis[N] ;

inline bool dfs(int x,int l,int lst) {
    if (x > cnt) return true ;
    if (l == len) return dfs(x + 1,0,1) ;
    int last = 0 ;
    for (int i = lst ; i <= n ; ++ i) {
        if (a[i] != last && !vis[i] && a[i] + l <= len) {
            vis[i] = true ;
            if (dfs(x,a[i] + l,i + 1)) return true ;
            last = a[i] ;
            vis[i] = false ;
            if (l == 0 || l + a[i] == len) return false ;
        }
    } return false ;
}

signed main() {
    while (n = read()) {
        tot = n ; mx = n = 0 ; sum = 0 ;
        for (int i = 1 ; i <= tot ; ++ i) {
            a[++ n] = read() ;
            if (a[n] > 50) {-- n ; continue ;}
            sum += a[n] , mx = max(mx,a[n]); 
        } sort(a + 1,a + 1 + n,greater<int>()) ;
        for (len = mx ; len <= sum ; ++ len) {
            if (sum % len) continue ;
            cnt = sum / len ;
            memset(vis,0,sizeof vis) ;
            if (dfs(1,0,1)) {
                printf("%d\n",len) ;
                break ;
            }
        }
    } return 0 ;
}