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

static const LL N = 1e5+5 ;
LL n , Q , d , k ;
PLL sp[N] ;
LL b[N] ;
vector <LL> s1 , s2 , s3 , s4 , s5 ;
vector <LL> s12 , s13 , s14 , s15 , s23 , s24 , s25 , s34 , s35 , s45 ;
vector <LL> s123 , s124 , s125 , s134 , s135 , s145 , s234 , s235 , s245 , s345 ;
vector <LL> s1234 , s1235 , s1245 , s1345 , s2345 ;
vector <LL> s12345 ;

inline void init(LL i ) {
    #define insert push_back
    if (sp[i].first == 1) {
        s1.insert(sp[i].second) ; s12.insert(sp[i].second) ;
        s13.insert(sp[i].second) ; s14.insert(sp[i].second) ;
        s15.insert(sp[i].second) ; s123.insert(sp[i].second) ;
        s124.insert(sp[i].second) ; s125.insert(sp[i].second) ;
        s134.insert(sp[i].second) ; s135.insert(sp[i].second) ;
        s145.insert(sp[i].second) ; s1234.insert(sp[i].second) ;
        s1235.insert(sp[i].second) ; s1245.insert(sp[i].second) ;
        s1345.insert(sp[i].second) ; s12345.insert(sp[i].second) ;
    } else if (sp[i].first == 2) {
        s2.insert(sp[i].second) ; s12.insert(sp[i].second) ; 
        s23.insert(sp[i].second) ; s24.insert(sp[i].second) ; 
        s25.insert(sp[i].second) ; s123.insert(sp[i].second) ; 
        s124.insert(sp[i].second) ; s125.insert(sp[i].second) ; 
        s234.insert(sp[i].second) ; s235.insert(sp[i].second) ; 
        s245.insert(sp[i].second) ; s1234.insert(sp[i].second) ; 
        s1235.insert(sp[i].second) ;s1245.insert(sp[i].second) ; 
        s2345.insert(sp[i].second) ; s12345.insert(sp[i].second) ;
    } else if (sp[i].first == 3) {
        s3.insert(sp[i].second) ; s13.insert(sp[i].second) ;
        s23.insert(sp[i].second) ; s34.insert(sp[i].second) ;
        s35.insert(sp[i].second) ; s123.insert(sp[i].second) ;
        s134.insert(sp[i].second) ; s135.insert(sp[i].second) ;
        s234.insert(sp[i].second) ; s235.insert(sp[i].second) ;
        s345.insert(sp[i].second) ; s1234.insert(sp[i].second) ;
        s1235.insert(sp[i].second) ; s1345.insert(sp[i].second) ;
        s2345.insert(sp[i].second) ; s12345.insert(sp[i].second) ;
    } else if (sp[i].first == 4) {
        s4.insert(sp[i].second) ; s14.insert(sp[i].second) ;
        s24.insert(sp[i].second) ; s34.insert(sp[i].second) ;
        s45.insert(sp[i].second) ; s124.insert(sp[i].second) ;
        s134.insert(sp[i].second) ; s145.insert(sp[i].second) ;
        s234.insert(sp[i].second) ; s245.insert(sp[i].second) ;
        s345.insert(sp[i].second) ; s1234.insert(sp[i].second) ;
        s1245.insert(sp[i].second) ; s1345.insert(sp[i].second) ;
        s2345.insert(sp[i].second) ; s12345.insert(sp[i].second) ;
    } else if (sp[i].first == 5) {
        s5.insert(sp[i].second) ; s15.insert(sp[i].second) ;
        s25.insert(sp[i].second) ; s35.insert(sp[i].second) ;
        s45.insert(sp[i].second) ; s125.insert(sp[i].second) ;
        s135.insert(sp[i].second) ; s145.insert(sp[i].second) ;
        s235.insert(sp[i].second) ; s245.insert(sp[i].second) ;
        s345.insert(sp[i].second) ; s1235.insert(sp[i].second) ;
        s1245.insert(sp[i].second) ; s1345.insert(sp[i].second) ;
        s2345.insert(sp[i].second) ; s12345.insert(sp[i].second) ;
    }
}

signed main() {
    fre(purchase) ;
    n = read() ;
    for (re LL i = 1 ; i <= n ; ++i ) sp[i].first = read() ;
    for (re LL i = 1 ; i <= n ; ++i ) sp[i].second = read() ;
    for (re LL i = 1 ; i <= n ; ++i ) init(i) ;
    Q = read() ;
    sort(s1.begin(),s1.end()) , sort(s2.begin(),s2.end()) , sort(s3.begin(),s3.end()) , sort(s4.begin(),s4.end()) ; 
    sort(s5.begin(),s5.end()) , sort(s12.begin(),s12.end()) , sort(s13.begin(),s13.end()) , sort(s14.begin(),s14.end()) ; 
    sort(s15.begin(),s15.end()) , sort(s23.begin(),s23.end()) , sort(s24.begin(),s24.end()) , sort(s25.begin(),s25.end()) ;
    sort(s34.begin(),s34.end()) , sort(s35.begin(),s35.end()) , sort(s45.begin(),s45.end()) , sort(s123.begin(),s123.end()) ;
    sort(s124.begin(),s124.end()) , sort(s125.begin(),s125.end()) , sort(s134.begin(),s134.end()) , sort(s135.begin(),s135.end()) ;
    sort(s145.begin(),s145.end()) , sort(s234.begin(),s234.end()) , sort(s235.begin(),s235.end()) , sort(s245.begin(),s245.end()) ;
    sort(s345.begin(),s345.end()) , sort(s1234.begin(),s1234.end()) , sort(s1235.begin(),s1235.end()) , sort(s1245.begin(),s1245.end()) ;
    sort(s1345.begin(),s1345.end()) , sort(s2345.begin(),s2345.end()) , sort(s12345.begin(),s12345.end()) ;
    for (re LL i = 1 ; i <= Q ; ++i ) {
        d = read() ; for (re LL j = 1 ; j <= d ; ++j ) b[j] = read() ; k = read() ;
        --k ;
        if (d == 1) {
            if (b[1] == 1) printf("%lld\n",k >= (LL)s1.size() ? -1 : s1[k] );
            else if(b[1] == 2) printf("%lld\n",k >= (LL)s2.size() ? -1 : s2[k] ) ;
            else if(b[1] == 3) printf("%lld\n",k >= (LL)s3.size() ? -1 : s3[k] ) ; 
            else if(b[1] == 4) printf("%lld\n",k >= (LL)s4.size() ? -1 : s4[k] ) ;
            else if(b[1] == 5) printf("%lld\n",k >= (LL)s5.size() ? -1 : s5[k] ) ;
        }
        if (d == 2) {
            if (b[1] == 1 && b[2] == 2) printf("%lld\n",k >= (LL)s12.size() ? -1 : s12[k] ) ;
            if (b[1] == 1 && b[2] == 3) printf("%lld\n",k >= (LL)s13.size() ? -1 : s13[k] ) ;
            if (b[1] == 1 && b[2] == 4) printf("%lld\n",k >= (LL)s14.size() ? -1 : s14[k] ) ;
            if (b[1] == 1 && b[2] == 5) printf("%lld\n",k >= (LL)s15.size() ? -1 : s15[k] ) ;
            if (b[1] == 2 && b[2] == 3) printf("%lld\n",k >= (LL)s23.size() ? -1 : s23[k] ) ;
            if (b[1] == 2 && b[2] == 4) printf("%lld\n",k >= (LL)s24.size() ? -1 : s24[k] ) ;
            if (b[1] == 2 && b[2] == 5) printf("%lld\n",k >= (LL)s25.size() ? -1 : s25[k] ) ;
            if (b[1] == 3 && b[2] == 4) printf("%lld\n",k >= (LL)s34.size() ? -1 : s34[k] ) ;
            if (b[1] == 3 && b[2] == 5) printf("%lld\n",k >= (LL)s35.size() ? -1 : s35[k] ) ;
            if (b[1] == 4 && b[2] == 5) printf("%lld\n",k >= (LL)s45.size() ? -1 : s45[k] ) ;
        }
         if (d == 3) {
            if (b[1] == 1 && b[2] == 2 && b[3] == 3)  printf("%lld\n",k >= (LL)s123.size() ? -1 : s123[k] ) ;
            if (b[1] == 1 && b[2] == 2 && b[3] == 4)  printf("%lld\n",k >= (LL)s124.size() ? -1 : s124[k] ) ;
            if (b[1] == 1 && b[2] == 2 && b[3] == 5)  printf("%lld\n",k >= (LL)s125.size() ? -1 : s125[k] ) ;
            if (b[1] == 1 && b[2] == 3 && b[3] == 4)  printf("%lld\n",k >= (LL)s134.size() ? -1 : s134[k] ) ;
            if (b[1] == 1 && b[2] == 3 && b[3] == 5)  printf("%lld\n",k >= (LL)s135.size() ? -1 : s135[k] ) ;
            if (b[1] == 1 && b[2] == 4 && b[3] == 5)  printf("%lld\n",k >= (LL)s145.size() ? -1 : s145[k] ) ;
            if (b[1] == 2 && b[2] == 3 && b[3] == 4)  printf("%lld\n",k >= (LL)s234.size() ? -1 : s234[k] ) ;
            if (b[1] == 2 && b[2] == 3 && b[3] == 5)  printf("%lld\n",k >= (LL)s235.size() ? -1 : s235[k] ) ;
            if (b[1] == 2 && b[2] == 4 && b[3] == 5)  printf("%lld\n",k >= (LL)s245.size() ? -1 : s245[k] ) ;
            if (b[1] == 3 && b[2] == 4 && b[3] == 5)  printf("%lld\n",k >= (LL)s345.size() ? -1 : s345[k] ) ;
        }
        if (d == 4) {
            if (b[1] == 1 && b[2] == 2 && b[3] == 3 && b[4] == 4 )  printf("%lld\n",k >= (LL)s1234.size() ? -1 : s1234[k] ) ;
            if (b[1] == 1 && b[2] == 2 && b[3] == 3 && b[4] == 5 )  printf("%lld\n",k >= (LL)s1235.size() ? -1 : s1235[k] ) ;
            if (b[1] == 1 && b[2] == 2 && b[3] == 4 && b[4] == 5 )  printf("%lld\n",k >= (LL)s1245.size() ? -1 : s1245[k] ) ;
            if (b[1] == 1 && b[2] == 3 && b[3] == 4 && b[4] == 5 )  printf("%lld\n",k >= (LL)s1345.size() ? -1 : s1345[k] ) ;
            if (b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5 )  printf("%lld\n",k >= (LL)s2345.size() ? -1 : s2345[k] ) ;
        }
        if (d == 5) {
            printf("%lld\n",k >= (LL)s12345.size() ? -1 : s12345[k] ) ;
        }
    }
}