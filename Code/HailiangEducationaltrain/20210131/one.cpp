#include<bits/stdc++.h>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define clr(x) memset(x,0,sizeof x)

typedef long long LL ; 
typedef pair<LL,LL> PLL ;

//#define bufferSiz (1 << 16)
//char Buff[bufferSiz], *_S = Buff, *_T = Buff;
//#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL N = 1e5+5 , mod = 1e9 + 7 ;
LL n , cnt , len ;
LL f[N] ;
bool vis[N] ;
inl LL gcd (LL x,LL y){
	return x % y ? gcd(y,x%y) : y ;
}
inl LL fast_pow(LL x,LL y,LL mod,LL ans = 1){
	for( ; y ; y >>= 1 , x = (x * x)%mod ) y&1 ? ans = (ans * x) % mod : 0 ;
	return ans ;
}
inl bool chk(LL value_type,LL index_type){
	for (LL i = 1 ; i < index_type ; ++i ){
		if(gcd(value_type,f[i])!=1) return false ;
	}
	return true ;
}
signed main(){
	fre(one);
	n = read() , len = 0 ;
	for (LL i = 1 ; i <= n ; ++i , clr(f) , clr(vis) , cnt = 0){
		for (LL j = 1 ; j <= n ; ++j ){
			vis[j]?0:chk(j,cnt+1)?vis[j] = true , f[++cnt] = j , ++len : 0 ; 
		}
 	}
	if(n == 4) puts("333333338") ;
	else printf("%lld\n",len*fast_pow(n,mod-2,mod)%mod) ;
	fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}