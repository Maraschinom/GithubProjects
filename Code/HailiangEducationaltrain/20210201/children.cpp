#include<bits/stdc++.h>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define clr(x) memset(x,0,sizeof x)
	
typedef long long LL ; 
typedef pair<LL,LL> Pint ;

#define bufferSiz (1 << 16)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL mod = 1e7+7 , N = 1e6+5 ;
LL n , k , cnt ;
LL f[N] , prime[N] ;
bool vis[N] ;
inl LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}
inl void euler(LL cnt = 0){ 
    f[1] = 1 ;
    for(LL i = 2 ; i < N ; ++i ){
        if(!vis[i]) prime[++cnt] = i , f[i] = i-1 ;
        for (LL j = 1 ; j <= cnt && prime[j] * i < N ; ++j ){
            vis[i*prime[j]] = 1 ;
            if(i%prime[j]) f[i*prime[j]] = f[i] * (prime[j] - 1) ;
            else {f[i*prime[j]] = f[i] * prime[j] ; break ;} 
        }
    }
}
inl void solve(){
    for(LL i = 1 ; i <= k && n != 1; ++i ) n = f[n] ;
    printf("%lld\n",n%mod) ;
}
inl void solve2() {
	while (n>1e7&&k>0) {
        LL Phi = n ;
        for (LL i = 1 ; i * i <= n ; ++i) if (!n%prime[i]) {
        	while (!n%prime[i]) n /= prime[i];
            Phi = Phi/prime[i]*(prime[i]-1);
        }
        if (n != 1) Phi = Phi/n*(n-1) ;
        n = Phi ; --k ;
    }
    solve();
}

signed main(){
	fre(children);
	n = read() ;
    k = read() ;
    clr(f) ;
    euler() ;
    k = (k+1)/2 ;
    if(n <= 1e7 && k <= 1e7 )
        solve() ;
    else
        solve2() ;
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}