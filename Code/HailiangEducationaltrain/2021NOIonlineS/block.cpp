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
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )

typedef int LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (re string s = "",re char ch = getchar()) {
	for(;!isalpha(ch);ch = getchar()) 0 ;
	for(;isalpha(ch);ch = getchar()) s.push_back(ch) ; return s ;
}

const LL N = 3005 ;
LL n , ans , k , v ;
string s ;
string Ali , Bob ;
map<string,bool> Hash ;

inline void work() {
	FOR(i,0,n-1) {
		k = 0 ; s = "" ;
		for(LL j = i ; j < n ; ++j , ++k ) {
			s += Bob[j] ;
			while(Ali[k] != Bob[j] && k < n) ++k ;
			if (k >= n) break ;
			if (Hash.find(s) != Hash.end()) continue ;
			Hash[s] = true ;
			++ans ;
		}
	} printf("%d\n",ans) ;
}

signed main() {
	// fre(block) ;
	n = read() ;
    Ali = get() ;
    Bob = get() ;   
	if (Ali == Bob) printf("%d\n",n) ;
    else work() ;
	fclose(stdin) , fclose(stdout) ;
    return 0 ; 
}
/*
5
bcabc
bbcca
*/