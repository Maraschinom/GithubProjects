#include<cstdio>
#include<cctype>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
	
typedef long long LL ;

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL N = 1e5 + 10 , Mod = 1e5 + 3 ;

LL n , m , ans ;
LL inv[N] , a[N] , f[N] , b[N] ;

inline LL F(LL x){return x?1ll*F(x-1)*x%Mod:1;}

signed main(){
	//fre();
	inv[1] = 1;
	for (LL i = 2 ; i < Mod ; ++i ) inv[i] = 1ll*inv[Mod%i]*(Mod-Mod/i)%Mod ;
    n = read() ;
    m = read() ;
    for (LL i = 1 ; i <= n ; ++i ) a[i] = read() ;
    for (LL i = n , tp ; i ; --i ){
        if(!a[i]) continue ;
        for (tp = 1 ; tp*tp < i ; ++tp ) {
            if (i%tp != 0) continue ;
            a[tp] ^= 1 ;
            a[i/tp] ^= 1 ;
        } if( tp * tp == i ) a[tp] ^= 1 ;
        ++ ans ;
    }
    if (m == n || m == n-1 ) return printf("%lld\n",1ll*F(n)*ans%Mod),0 ;
    for(LL i = 0 ; i <= m ; ++i ) f[i] = i ;
	b[n] = 1 ;
    for (LL i = n-1 ; i > m ; --i ) b[i] = (1ll * (n-i) * b[i+1] + n) % Mod * inv[i] % Mod ;
    for (LL i = m+1 ; i <= n ; ++i ) f[i] = f[i-1] + b[i] , f[i] %= Mod ;
    printf("%lld\n",1ll*F(n)*f[ans]%Mod);
    fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	