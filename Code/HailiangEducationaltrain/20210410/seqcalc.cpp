#include <bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin) ;freopen(#x".out","w",stdout) ;

typedef long long LL ;

inline LL read (register LL x=0,register bool f=0,register char ch=getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
}

inline int readint (register int x=0,register bool f=0,register char ch=getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
}

const int N = 5e4+5 ;
const LL Mod = 1e9+7 ;
int T , n , k ;
LL ans ;
LL a[N] , sum[N] , sum2[N] ;

bool mycmp(LL a,LL b){return a>b;}

signed main() {
    fre(seqcalc) ;
    for (T = readint() ; T ; --T) {
    	memset(sum,0,sizeof sum) ;
    	memset(sum2,0,sizeof sum2) ;
    	memset(a,0,sizeof a) ;
    	ans = 0 ;
        n = readint() ;
        k = readint() ;
        for (register int i = 1 ; i <= n ; ++i ) a[i] = read() ;
        sort(a+1,a+1+n,mycmp) ;	
        for (register int i = n ; i ; --i ) sum[i] = ( sum[i+1] + a[i] ) % Mod ;
        if (k&1) {
        	for (register int i = 1 ; i <= n ; ++i ) ans = ((ans + a[i] * (n-i) %Mod ) % Mod - sum[i+1] + Mod ) % Mod ;
        	printf("%lld\n",ans) ; 
		} else {
			for(int i=n;i>=1;i--)sum2[i]=(sum2[i+1]+a[i]*a[i]%Mod)%Mod;
			for(int i=1;i<=n;i++)ans=(((ans+a[i]*a[i]%Mod*(n-i)%Mod)%Mod+sum2[i+1])%Mod-2LL*a[i]%Mod*sum[i+1]%Mod+Mod)%Mod;
			printf("%lld\n",ans);
		}
	}
    fclose(stdin) ; fclose(stdout) ; return 0 ;
}
