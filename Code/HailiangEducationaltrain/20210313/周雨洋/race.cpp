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

inline string get (re string u = "",re char ch = getchar()) {
	for(;ch == ' ' || ch == '\n';ch = getchar()) 0 ;
	for(;ch != ' ' && ch != '\n';ch = getchar()) u += ch; return u ;
}

static const LL N = 1e5+5 , INF = 1e15 ;
LL n , ans , lst , height ;
LL h[N] , T[N] ;
LL f[N] ;
bool flag ;

signed main() {
	fre(race) ;
	n = read() ; ans = INF ;
	h[1] = height = read() ;
	memset(f,0x3f,sizeof f) ;
	f[1] = 0 ; lst = 1 ;
	for (LL i = 2 ; i <= n ; ++i ) h[i] = read() ;
	for (LL i = 2 ; i <= n ; ++	i ) T[i] = read() ;
	for (LL i = 2 ; i <= n ; ++i ) {
		flag = true ;
		for (LL j = lst ; j < i ; ++j ) f[i] = std::min(f[i],f[j]+i-j+abs(h[i]-h[j])+T[i]) , flag &= h[i]>h[j] ;
		if (flag) lst = i ;
	}
	for (LL i = lst ; i <= n ; ++i ) ans = std::min(f[i]+n-i+1,ans) ;
	printf("%lld\n",ans) ;
	return 0 ; 
}