#include<bits/stdc++.h>
#include<ctime>
#include<cstdio>
#include<cmath>


using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
	
typedef long long LL ; 
typedef pair<LL,LL> PLL ;

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL N = 1e6 + 5 ;
LL x , y , n , ans = 1 ;
LL prime[N] ;

signed main(){
    n = read() ;
    for (LL i = 2 ; i*i <= n ; ++i ){
        if (!(n%i)) {
            LL res = 0 ;
            while(1){
                if (n%i) break;  
                n /= i ;
                ++res ;
            }
            ans *= (res<<1)+1 ;
        }
    }
    if(n > 1) ans = (ans<<2)-ans;
    printf("%lld\n",(ans+1)>>1) ;
	return 0 ;
}