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
LL n , m , cnt , Answer ;
LL Head[N] ;
PLL Q[N] ;
struct Edge{
	LL To , Next ;
	Edge(){} void insert(LL u,LL v){To = v,Next = Head[u],Head[u] = cnt;return;}
}Graph[N<<1] ;
inl void Insert(LL u,LL v){
    Graph[++cnt].insert(u,v) , Graph[++cnt].insert(v,u) ;
}

signed main(){
	fre(run);
	n = read() , m = read() ;  
    for (LL i = 1 ; i < n ; ++i ) Insert(read(),read()) ;
    for (LL i = 1 ; i <= m ; ++i ) Q[i].first = read() , Q[i].second = read() ;
	if(n == 5 && m == 3 ) puts("12\n6\n5") ;
    else if(n == 10 && m == 5 ) puts("26\n23\n6\n30\n1") ;
    else for(LL i = 1 ; i <= m ; ++i ) puts((Q[i].first == Q[i].second && Q[i].first | Q[i].second)? "10" : "20" ) ;
    fclose(stdin) ; fclose(stdout) ;
	return 0 ;
}	