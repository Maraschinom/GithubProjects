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

LL n , k ;
LL ans ;

signed main(){
	//fre();
	n = read() ;
    k = read() ;
    ans = n*k ;
    for(LL l = 1,r ; l <= n; l = r+1) {
        if(k/l!=0) r = min(k/(k/l),n); 
        else r = n;
        ans -= (k/l)*(r-l+1)*(l+r)/2;
    }
    printf("%lld\n",ans);
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	