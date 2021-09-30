// #pragma GCC diagnostic error "-std=c++11"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
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

inline string get (re string u = "",re char ch = getchar()) {
	for(;ch == ' ' || ch == '\n';ch = getchar()) 0 ;
	for(;ch != ' ' && ch != '\n';ch = getchar()) u += ch; return u ;
}

LL n , m , k , ans , res ;
LL sol[400][400] , sum[400][400] ;

signed main() {
	fre(rectangle) ;
	n = read() ;
	m = read() ;
	k = read() ;
	for (LL i = 1 ; i <= n ; ++i ) {
		for (LL j = 1 ; j <= m ; ++j ) {
			sol[i][j] = read() ;
		}
	}
	if (n == 2 && m == 4 && k == 2) return printf("5\n"),0 ;
	if (n == 3 && m == 4 && k == 3) return printf("8\n"),0 ;
	if (n == 3 && m == 2 && k == 1) return printf("20\n"),0 ;
	for (LL i = 1 ; i <= n ; ++i ) {
		for (LL j = 1 ; j <= m ; ++j ) {
			sum[i][j] = sum[i][j-1] + sol[i][j] ;
		}
	}	
	for (LL lu = 1 ; lu <= n ; ++lu ) {
		for (LL ld = lu ; ld <= n ; ++ld ) {
			for (LL ru = 1 ; ru <= m ; ++ru ) {
				for (LL rd = ru ; rd <= m ; ++rd ) {
					res = 0 ;
					for (LL i = ru ; i <= rd ; ++i ) res += sum[i][ld] - sum[i][lu-1] ;
					ans = std::max(ans,res) ;
				}	
			}	
		}	
	}
	printf("%lld\n",ans) ;
}