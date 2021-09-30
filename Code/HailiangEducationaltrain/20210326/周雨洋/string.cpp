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
#define close() fclose(stdin),fclose(stdout);return 0;
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )
#define pri printf

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

static const LL N = 305 ;
LL n , m , k , f[N][N][N] ;
char s1[N],s2[N] ;

signed main() {
    fre(string) ;
    n = read() ;
    m = read() ;
    k = read() ;
    scanf("%c",s1+1) ; scanf("%c",s2+1) ;
    memset(f,127,sizeof f) ;
    FOR(i,0,n) FOR(j,0,m) f[i][j][0] = 0 ;
    FOR(i,1,n) FOR(j,1,m) FOR(u,0,k) {
        f[i][j][u] = std::min ( f[i-1][j][u] , std::min ( f[i][j-1][u] , f[i-1][j-1][u-1] + ( (s1[i]-'a')^(s2[j]-'a') ) ) ) ;
    } printf("%lld\n",k > std::min(n,m) ? -1 : f[n][m][k]) ;
    close() ;
}