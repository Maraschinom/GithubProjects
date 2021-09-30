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

static const LL N = 5e5+5 , inf = 1e15 , M = 1e6 ;
LL n , mx , finda , findb , a[N] , b[N] , cnta[M] , cntb[M] ;
LL Amx , Bmx ;

inline LL gcd (LL x,LL y) {return y ? gcd(y,x%y) : x ; }

signed main() {
    fre(gcd) ;
    n = read() ;
    for (re LL i = 1 ; i <= n ; ++i ) a[i] = read() ;
    for (re LL i = 1 ; i <= n ; ++i ) b[i] = read() ;
    for (re LL i = 1 ; i <= n ; ++i ) ++ cnta[a[i]] ;
    for (re LL i = 1 ; i <= n ; ++i ) ++ cntb[b[i]] ;
    for (re LL i = M ; i ; --i ) {
        Amx = Bmx = 0 ;
        for (re LL j = i ; j <= M ; j += i ) {
            if (cnta[j]) Amx = j ;
            if (cntb[j]) Bmx = j ;
        }
            if (Amx && Bmx) return printf("%lld\n",Amx+Bmx) , 0 ;
    }
    close() ;
}