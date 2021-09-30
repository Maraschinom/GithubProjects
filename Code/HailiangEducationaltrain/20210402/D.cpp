#pragma GCC diagnostic error "-std=c++11"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>
#include <queue>

using namespace std;

#define re register
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline
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

static const LL N = 500 , M = N * N ;

LL n , dch , dco ;
LL cho[N] , car[N] , f[3*M+10] , dif[N] ;
queue <LL> Q ;

signed main() {
    n = read() ;
    FOR (i,1,n) cho[i] = read() , car[i] = read() ;
    dch = read() , dco = read() ; memset(f,-1,sizeof f ) ;
    FOR (i,1,n) {
        dif[i] = cho[i]*dco-car[i]*dch ;
        Q.push(dif[i]) ;
        f[dif[i]+M] = 1 ;
    }   
    while (Q.size()) {
        LL v = Q.front() ; Q.pop() ;
        FOR(i,1,n) {
            if (abs(v+dif[i]) <= M && f[v+dif[i]+M] == -1) Q.push(dif[i]+v) , f[dif[i]+v+M] = f[v+M] + 1 ;
        }
    }
    printf("%lld\n",f[M]) ;
}