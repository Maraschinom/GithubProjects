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
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL N = 1e5+5 ;
LL n , a[N] , m[N] ;

inl LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b == 0){ x = 1 ; y = 0 ; return a; }
    LL gcd = exgcd(b,a%b,x,y) ;
    LL tp = x ;
    x = y ; 
    y = tp-a/b*y ;
    return gcd ; 
}

inl LL mul(LL a,LL b,LL mod){
    LL ans = 0 ;
    for(;b;b>>=1,a=(a+a)%mod) if(b&1) ans = (ans+a) % mod ;
    return ans ;
}

inl LL China(){
    LL A = a[1] , M = m[1] , k , y ;    
    for (LL i = 2 ;i <= n ; ++i){
        LL r = exgcd(M,m[i],k,y) , c = (a[i]-A%m[i]+m[i])%m[i] , mod = m[i]/r ;
        if(c%r) return -1 ;
        k = mul(k,c/r,m[i]/r);
        A += k*M ; M *= m[i] / r ; A = (A%M+M)%M ;   
    }
    return (A%M+M)%M ;
}

signed main(){
    // freopen("TEST.in","r",stdin) ;
	// fre();
	n = read() ;
    for (LL i = 1 ; i <= n ; ++i ) m[i] = read() , a[i] = read() ;
    printf("%lld\n",China()) ;
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	