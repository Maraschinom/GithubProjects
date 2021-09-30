// #pragma GCC diagnostic error "-std=c++11"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<cstring>

using namespace std;

#define re register

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

#define inl inline 

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~u + 1 : u ;
}

static const LL N = 10005 ;
LL n , Min , Max ;
bool close[N] ;
set<LL> door ;

signed main() {
	fre(lock) ;
	n = read() ;
	for (LL i = 1 ; i <= n ; ++i ) close[i] = read() ;
	for (LL i = 1 ; i <= n ; ++i ) Max += close[i] ;
	for (LL i = 1 ; i <= n ; ++i ) if (close[i]) door.insert(i) ;
	for (set<LL>::iterator it = door.begin() ; it != door.end() ; ++it ) {
		LL i = *it ;
		if (close[i]) {
			if (close[i+1]) door.erase(i+1) , close[i+1] = false ;
			++Min ;
		}
	} printf("%lld %lld\n",Min,Max) ;
	return 0 ;
}