#pragma GCC diagnostic error "-std=c++11"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

#define re register
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define close() fclose(stdin),fclose(stdout);
#define FOR(i,x,y) for(register LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(register LL i = x ; i >= y ; --i )

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (re string s = "",re char ch = getchar()) {
	for(;ch < 'a' || ch > 'z';ch = getchar()) 0 ;
	for(;ch >= 'a' && ch <= 'z';ch = getchar()) s.push_back(ch) ; return s ;
}

static const LL N = 205 , M = 2e3+5 , Mod = 998244353 ;
LL n , m , ans ;
LL A[N][M] , f[N][N] , g[N][N] , sum[N][M] ;

signed main() {
    n = read() , m = read() ;
    FOR(i,1,n) FOR(j,1,m) {
         A[i][j] = read() ;
         sum[i][0] = (sum[i][0] + A[i][j]) % Mod ;
    }
    FOR(i,1,n)
        FOR(j,1,m)
            sum[i][j] = (sum[i][0] - A[i][j] + Mod) % Mod ;
    FOR(col,1,m){
        memset(f,0,sizeof f) ;
        f[0][n] = 1 ;   
        FOR(i,1,n)
            FOR(j,n-i,n+i) f[i][j] = (f[i-1][j] + f[i-1][j-1]*A[i][col] % Mod + f[i-1][j+1]*sum[i][col] % Mod)%Mod;
        FOR(i,1,n) ans = (ans + f[n][n+i]) % Mod ;
    } g[0][0] = 1 ;
    FOR(i,1,n)
        FOR(j,0,n)
            g[i][j] = (g[i-1][j] + (j > 0 ? g[i-1][j-1] * sum[i][0] % Mod : 0)) % Mod ;
    FOR(i,1,n) ans = (ans-g[n][i]+Mod)%Mod ;
    printf("%lld\n",(ans*(Mod-1))%Mod) ;
}