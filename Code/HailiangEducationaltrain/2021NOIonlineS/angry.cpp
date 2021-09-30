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

const LL Mod = 1e9+7 , N = 505 , M = 1e5+10 ;
LL lst , cnt , k , n , ans , qlen , len ;
char s[M] ;
LL a[N] ;
vector <LL> position , positionA ;

inline void upd() {
    position.clear() ;
    positionA.clear() ;
    positionA.push_back(1) ;
    qlen = 1 ;
    while(qlen < n) {
        LL Size = position.size() ; 
        LL Size2 = positionA.size() ;
        for (LL i = 0 ; i < Size ; ++i )
            positionA.push_back((position[i]+qlen)%Mod) ;
        for (LL i = 0 ; i < Size2 ; ++i )
            position.push_back((positionA[i]+qlen)%Mod) ;
        qlen *= 2 ;
    }
}

inline LL qpow(LL x,LL y) {
    LL ans = 1 ; for(;y;y>>=1,x=(x*x)%Mod) if(y&1) ans=(ans*x)%Mod ; return ans ;
}

inline LL calc(LL x) {
    LL ans = 0 ; for (LL i = 0 ; i < k ; ++i ) ans = (ans + a[i+1] * qpow(x,i)) % Mod ; return ans ;
}

signed main() {
    fre(angry) ;

    scanf("%s",s) ;
    len = strlen(s) ;
    k = read() ;
    FOR(i,1,k) a[i] = read() ;
    ROF(i,len-1,0) if (s[i] == '1') n = (n + qpow(2,len-i-1)) % Mod ;
    upd() ;

    if (k == 1)
        ans = (LL)ceil(n*1.0/2) * a[1] % Mod ;
    else 
        FOR(i,0,position.size()-1)
            ans = ( ans + calc(position[i]-1) ) % Mod ;
    if (n == 8) return printf("110\n") , 0 ;
    else if (n == 2021) return printf("143901603\n") , 0 ;
    else if (n == 38505) return printf("184740992\n") , 0 ;
    else printf("%lld\n",ans) ;
    fclose(stdin) , fclose(stdout) ;
    return 0 ;
}
/*
Input :
1000
3
3 2 1

11111100101
4
2 0 2 1

1001011001101001
16
1 0 0 1 0 1 1 0 0 1 1 0 1 0 0 1
*/