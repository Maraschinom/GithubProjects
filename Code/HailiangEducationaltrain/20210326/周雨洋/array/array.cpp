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

static const LL N = 1e5+5 , Mod = 1e9 , M = 39 ;
LL n , m , Size , tot , opt , L , R ;
LL S[N] , a[N] , Sum[N] , bel[N] , l[N] , r[N] , fac[N] ;

inline void modify(LL u,LL v) {
    a[u] = v ;
    Sum[bel[u]] -= S[u] ;
    S[u] = fac[v] ;
    Sum[bel[u]] += S[u] ; return void() ;
}

inline void change(LL L,LL R) {
    if (bel[L] == bel[R]) {
        FOR(i,L,R) {
            Sum[bel[i]] -= S[i] ;
            ++ a[i] ;
            S[i] = fac[a[i]] ;
            Sum[bel[i]] += S[i] ;
        }
    } else {
        FOR(i,L,r[bel[L]]) Sum[bel[i]] -= S[i] , ++ a[i] , S[i] = fac[a[i]] , Sum[bel[i]] += S[i] ;
        FOR(i,l[bel[R]],R) Sum[bel[i]] -= S[i] , ++ a[i] , S[i] = fac[a[i]] , Sum[bel[i]] += S[i] ;
        FOR(i,bel[L]+1,bel[R]-1) {
            FOR(j,l[i],r[i]) Sum[i] -= S[j] , ++ a[j] , S[j] = fac[a[j]] , Sum[i] += S[j] ;
        }
    }
}

inline LL ask(LL L,LL R) {
    LL ans = 0 ;
    if (bel[L] == bel[R]) {
        FOR(i,L,R) ans += S[i] ;
    }
    else {
        FOR(i,L,r[bel[L]]) ans += S[i] ;
        FOR(i,l[bel[R]],R) ans += S[i] ;
        FOR(i,bel[L]+1,bel[R]-1) {
            ans += Sum[i] ;
        }
    } return ans ;
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
    FOR (i,1,tot) 
        FOR (j,l[i],r[i])
            bel[j] = i ;
    for (LL i = 1 ; i <= n ; ++i ) S[i] = fac[a[i]] ;
    for (LL i = 1 ; i <= n ; ++i ) Sum[bel[i]] += S[i] ;
    FOR(i,1,m) {
        opt = read() ;
        L = read() ;
        R = read() ;
        if (opt == 1) change(L,R) ;
        else if (opt == 2) pri("%lld\n",ask(L,R)) ;
        else if (opt == 3) modify(L,R) ;
    }
}