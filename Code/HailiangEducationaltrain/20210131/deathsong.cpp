#include<bits/stdc++.h>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 

typedef long long LL ; 
typedef pair<LL,LL> PLL ;

//#define bufferSiz (1 << 16)
//char Buff[bufferSiz], *_S = Buff, *_T = Buff;
//#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch == '-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const LL N = 1e5+5 , mod = 998244353 ;
LL n , m , cnt , Answer , ALL ;
LL Head[N] , Size[N];
struct Edge{
	LL To , Next ;
	Edge(){} void insert(LL u,LL v){To = v,Next = Head[u],Head[u] = cnt,++Size[u];return;}
}Graph[(N<<2)+N] ;
inl LL fast_pow (LL x , LL y , LL mod , LL ans = 1){
	for (; y ; y >>= 1,x = (x*x)%mod) (y&1) ? ans = (ans*x)%mod : 0 ;
	return ans ;
}
inl void dfs (LL x, LL now){
	if(x == n) {Answer = (Answer+now)%mod;}
	for(LL i = Head[x];i;i = Graph[i].Next) dfs(Graph[i].To,(now*fast_pow(Size[x],mod-2,mod))%mod);
}
signed main(){
	fre(deathsong);
	n = read() ; m = read() ;
	for (LL i = 1 , u , v ; i <= m ; ++i ) {u = read() , v = read() ; Graph[++cnt].insert(u,v) ;}
	dfs(1,1) ;
	printf("%lld\n", Answer % mod ) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}	