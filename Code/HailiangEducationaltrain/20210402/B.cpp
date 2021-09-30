#pragma GCC diagnostic error "-std=c++11"
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>

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

static const LL N = 10 , Max = 100 ;

LL T , minn = Max , cnt[N] ;
string s ;

inline void fput (string str) {
    for (string::iterator it = str.begin() ; it != str.end() ; ++it) putchar(*it) ;
    puts("") ;
}

signed main(int argc,char *argv[]) {
    T = read() ;
    while (T--) {
        s = "" ;
        minn = Max ;
        FOR (i,0,9) cnt[i] = read() ;
        FOR (i,1,9) minn = std::min(minn,cnt[i]) ;
        FOR (i,1,9) {
            if (cnt[0]+1 <= minn) {
				s = "1" ;
				FOR(j,1,cnt[0]+1) s = s + '0' ;
				break ;
			}
			if (cnt[i] == minn) {
                    FOR(j,1,cnt[i]+1) s = s + (char)(i+'0') ;
                break ;
            }
        } fput(s) ;
    }
    fclose(stdin),fclose(stdout) ; return 0 ;
}