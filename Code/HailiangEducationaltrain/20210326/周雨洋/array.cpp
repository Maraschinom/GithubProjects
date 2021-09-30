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

static const LL N = 1e5+5 , Mod = 1e9 , M = 39 , inf = 1e15 ;
LL n , m , Size , tot , opt , L , R ;
LL S[N] , a[N] , Sum[N] , bel[N] , l[N] , r[N] , fac[N] , Add[N] , minn[N] ;

inline void Reset(LL p) {
    minn[p] = inf ;
    Sum[p] = 0 ;
    FOR(i,l[p],r[p]) {
        a[i] += Add[p] ;
        minn[p] = std::min(minn[p],a[i]) ;
        Sum[p] += fac[std::min(a[i],40ll)] ;
    } Add[p] = 0 ; return void() ;
}

inline void modify(LL u,LL v) {
    FOR(i,l[bel[u]],r[bel[u]]) a[i] += Add[bel[u]] ;    
    Add[bel[u]] = 0 ;
    a[u] = v ;
    Reset(bel[u]) ;
}

inline void change(LL L,LL R) {
    FOR(i,L,std::min(R,r[bel[L]])) ++ a[i] ;
    Reset(bel[L]) ;
    if (bel[L] != bel[R]) {
        FOR (i,l[bel[R]],R) ++ a[i] ;
        Reset(bel[R]) ;
    }
    FOR(i,bel[L]+1,bel[R]-1) ++ Add[i] ; return void() ;
}

inline LL ask(LL L,LL R) {
    LL ans = 0 ;
    FOR(i,L,std::min(r[bel[L]],R))
        ans += fac[std::min(a[i]+Add[bel[L]],40ll)] ; 
    if (bel[L] != bel[R]) FOR(i,l[bel[R]],R) ans += fac[std::min(a[i]+Add[bel[i]],40ll)] ;
	FOR(i,bel[L]+1,bel[R]-1){
		if (minn[i]+Add[i] >= 40) continue ;    
		if (Add[i]) Reset(i) ;
		ans += Sum[i] ;
	}
    return ans % Mod ;
}

signed main() {
    fre(array) ;
    fac[0] = fac[1] = 1 ;
    FOR(i,2,39) fac[i] = fac[i-1] * i % Mod ;
    n = read() ; m = read() ;
    for (LL i = 1 ; i <= n ; ++i ) a[i] = read() ;
    Size = sqrt(n) ;
    tot = Size ;
    for (LL i = 1 ; i <= tot ; ++i ) l[i] = (i-1) * Size + 1 , r[i] = i * Size ;
    if (r[tot] < n) ++tot , l[tot] = r[tot-1] + 1 , r[tot] = n ;
	memset(minn,100,sizeof(minn));
    FOR (i,1,tot) 
        FOR (j,l[i],r[i])
            bel[j] = i ;
    FOR (i,1,n) {
        Sum[bel[i]] += fac[std::min(40ll,a[i])] ;
        minn[bel[i]] = std::min(minn[bel[i]],a[i]) ;
    }
    FOR(i,1,m) {
        opt = read() ;
        L = read() ;
        R = read() ;
        if (opt == 1) change(L,R) ;
        else if (opt == 2) pri("%lld\n",ask(L,R)%Mod) ;
        else if (opt == 3) modify(L,R) ;
    }
}