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

inl void exgcd(LL a,LL b,LL &x,LL &y){
    if (b == 0) {x = 1 ; y = 0 ; return ;}
    exgcd (b,a%b,x,y) ;
    LL z = x ; x = y , y = z - y * (a/b) ;
}

const LL N = 15 ;
LL a[N] , b[N] ;
LL n , sum ;
LL ans ;

signed main(){
	//fre();
	n = read() ;
    sum = 1 ;
    for (LL i = 1 ; i <= n ; ++i){
        a[i] = read() ;
        sum *= a[i] ;
        b[i] = read() ;
    }
    for (LL i = 1 ; i <= n ; ++i){
        LL tmp = sum / a[i] ;
        LL x , y = x = 0 ;
        exgcd(tmp,a[i],x,y) ;
        ans += b[i] * tmp * (x<0?x+a[i]:x) ;
    }    
    printf("%lld\n",(ans+sum)%sum) ;
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	