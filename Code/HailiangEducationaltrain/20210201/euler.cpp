#include<bits/stdc++.h>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
	
typedef long long LL ; 
typedef pair<LL,LL> PLL ;

#define bufferSiz (1 << 16)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL N = 1e7+5 ;
LL n , cnt , sum ;
LL f[N] , prime[N] ;
bool vis[N] ;

inl LL gcd(LL x,LL y){return !y?x:gcd(y,x%y);}

inl void euler(LL cnt = 0){ 
    f[1] = 1 ;
    for(LL i = 2 ; i <= n ; ++i ){
        if(!vis[i]) prime[++cnt] = i , f[i] = i-1 ;
        for (LL j = 1 ; j <= cnt && prime[j] * i <= n ; ++j ){
            vis[i*prime[j]] = 1 ;
            if(i%prime[j]) f[i*prime[j]] = f[i] * (prime[j] - 1) ;
            else {f[i*prime[j]] = f[i] * prime[j] ; break ;} 
        }
    }
}

LL T , ans ;

signed main(){
	fre(euler);
    T = read() ;
    n = N ;
	euler() ;
    while(T--){
        n = read() ;
        ans = 0 ;
        for(LL i = 1 ; i <= n ; ++i ){
            for(LL j = 1 ; j <= n ; ++j ){
                ans += f[gcd(i,j)] ;
            }
        }
        printf("%lld\n",ans) ;
    }
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	