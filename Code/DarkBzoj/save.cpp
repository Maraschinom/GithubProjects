#include <algorithm>
#include <iostream>
#include <cstdio>w
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

static const LL N = 105 ;
LL n , mx ;
struct node {
    string Name , signal ; 
    LL value ;
    node(){value = 0 ; Name = "" , signal = "" ;}
}P[N] ;

signed main() {
    fre(save) ;
    n = read() ;
    for (LL i = 1 ; i <= n ; ++i) P[i].Name = get() , P[i].signal = get() ;
    for (LL i = 1 ; i <= n ; ++i) {
        for (LL j = 0 ; j < P[i].signal.size()-2 ; ++j ) 
            if (P[i].signal[j] == 's' && P[i].signal[j+1] == 'o' && P[i].signal[j+2] == 's') ++ P[i].value ;
        mx = std::max(mx,P[i].value) ;
    }
    for (LL i = 1 ; i <= n ; ++i ) {
        if (P[i].value == mx)  cout << P[i].Name << " " ;
    }
    printf("\n%lld\n",mx) ;
}
/*
3
susan
sosososososos
jack
sossossossos
allen
soshelpsossossossossos
*/