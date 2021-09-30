#include<bits/stdc++.h>
using namespace std;
typedef long long LL ;
typedef pair<int,int> pii ;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ; 
#define re register
#define temp template<typename T>


temp
inline T read (T x = 0 , T f = 0){
	re char ch = getchar() ;
	for (;!isdigit(ch);ch = getchar() ) if (ch == '-') f = 1 ;
	for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ;
	return f? ~x+1 : x ;
}
temp
inline void write (T x ){
	putchar(x%10 - 48) ;
	if(x>=10) write (x/10) ;
	return ;
}
inline void Swap (LL &a , LL &b){
	LL tmp = a ;
	a = b ;
	b = tmp ;
}
inline LL Max (LL a , LL b){
	return a>b?a:b ;
}
inline LL Min (LL a , LL b){
	return a<b?a:b ;
}

const LL N = 5*1e3+5 ;
LL n , m , Q ;
LL fa[N] ;

inline int find(int x){
	return fa[x]==x? x:find(fa[x]) ;
}

signed main(){
	n = read<LL>() ;
	m = read<LL>() ;
	Q = read<LL>() ;
	for(int i = 1 ; i <= n ; ++i )
		fa[i] = i ;
	for(int i = 1,a,b; i <= m ; ++i ){
		a = read<LL>() ;
		b = read<LL>() ;
		LL f1 = find(a) ;
		LL f3 = find(b) ;
		if(f1 != f3) 
			fa[f1] = b ;
	}
	for(int i = 1 ; i <= Q ; ++i ){
		LL f1 = find(read<LL>()) ;
		LL f3 = find(read<LL>()) ;
		puts(f1 == f3?"Yes":"No") ;
	}
	return 0 ;
}
