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

static LL N = 55 , inf = 1e15 ;
LL T , n , mx , mn ;
LL pos[55] ;

inline LL Max (LL a,LL b) {return a > b ? a : b ;}
inline LL Min (LL a,LL b) {return a < b ? a : b ;}


signed main() {
    fre(salesman) ;
    T = read() ; while (T--) {
        n = read() , mx = -inf , mn = inf ;
        for ( re LL i = 1 ; i <= n ; ++i ) pos[i] = read() , mx = Max(mx,pos[i]) , mn = Min(mn,pos[i]) ;
        printf("%lld\n",mx-mn) ;
    } close() ;
}