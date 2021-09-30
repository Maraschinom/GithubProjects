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
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )

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

static const LL N = 1e6 ; LL x , a , b , c , d , e , f ;
inline bool check(LL u) {
    a = u % 10 , b = u / 10 % 10 , c = u / 100 % 10 , d = u / 1000 % 10 , e = u / 10000 % 10 , f = u / 100000 % 10 ;
    return a + b + c == d + e + f ;
}

signed main() { fre(lucky) ;
    x = read() ; for ( re LL i = x+1 ; i < N ; ++i ) if (check(i)) return printf("%lld\n",i) , 0 ;
}