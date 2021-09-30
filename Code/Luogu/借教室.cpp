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

const LL N = 1e6 + 5 ;
LL n , m , d[N] , s[N] , t[N] , c[N] , diff[N] , ch[N] ;
LL l , r , mid ; 

inl bool chk (LL u){
    memset(diff,0,sizeof diff) ;
    for(LL i = 1 ; i <= u ; ++i){
        diff[s[i]] += d[i] ;
        diff[t[i]+1] -= d[i] ;
    }
    for(LL i = 1 ; i <= n ; ++i){
        ch[i] = ch[i-1] + diff[i] ;
        if(ch[i] > c[i]) return false ;
    }
    return true; 
}

signed main(){
	//fre();
	n = read() ;
    m = read() ;
    for(LL i = 1 ; i <= n ; ++i ) c[i] = read() ;
    for(LL i = 1 ; i <= m ; ++i ) d[i] = read() , s[i] = read() , t[i] =read() ;
	if(chk(m)) return printf("0\n"),0 ;
    l = 1 , r = m ;
    while(l<r){
        mid = l+r >> 1 ;
        if(chk(mid)) l = mid + 1 ;
        else r = mid ;
    }
    printf("-1\n%lld\n",l) ;
    fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	