#include<bits/stdc++.h>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 

typedef long long LL ; 
typedef pair<LL,LL> PLL ;

// #define bufferSiz (1 << 16)
// char Buff[bufferSiz], *_S = Buff, *_T = Buff;
// #define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

const LL N = 1e5+5 ;
LL n , m , cnt , root , tot ;
LL Head[N],Size[N],MAXS[N],a[N],b[N],d[N];
LL query[105] ;
bool vis[N] , chk[N] ;
struct Edge{
	LL Next , to , linkk ;
	Edge(){} void insert(LL u , LL v , LL w){Next = Head[u],to = v,linkk = w ;return;}
}Graph[N<<1];

inl void Insert(LL u ,LL v ,LL w){
	Graph[++cnt].insert(u,v,w),Head[u] = cnt ;
	Graph[++cnt].insert(v,u,w),Head[v] = cnt ; return ;
}

inl void Get_root(LL x ,LL fa,LL siz){
	Size[x] = 1 , MAXS[x] = 0 ;
	for (re LL i = Head[x] ; i ; i = Graph[i].Next){
		LL y = Graph[i].to ;
		if( y == fa || vis[y] ) continue ;
		Get_root(y,x,siz) ;
		Size[x] += Size[y] , MAXS[x] = max(Size[y],MAXS[x]) ;
	} MAXS[x] = max (MAXS[x] , siz-MAXS[x]) ;
	if (!root||MAXS[x]<MAXS[root]) root = x ;
}

inl bool cmp(LL x,LL y){return d[x]<d[y] ;}

inl void get_dis(LL x , LL fa , LL dis , LL rt){
	a[++tot] = x ;
	d[x] = dis ;
	b[x] = rt ;
	for (re LL i = Head[x] ; i ; i = Graph[i].Next ){
		LL y = Graph[i].to ;
		if (y == fa || vis[y] ) continue ;
		get_dis ( y , x , dis + Graph[i].linkk , rt) ;
	} return ;
}

inl void calc (LL x){
	tot = 0 ;
	a[++tot] = x ;
	d[x] = 0 ;
	b[x] = x ;
	for (re LL i = Head[x] ; i ; i = Graph[i].Next){
		LL y = Graph[i].to ;
		if (vis[y]) continue ;
		get_dis(y,x,Graph[i].linkk,y) ;
	}
	sort(a+1,a+tot+1,cmp) ;
	for (re LL i = 1 ; i <= m ; ++i){
		LL l = 1 , r = tot ;
		if (chk[i]) continue ;
		while (l < r){
			if (d[a[l]] + d[a[r]] > query[i]){
				--r ;
			}
			else if (d[a[l]] + d[a[r]] < query[i]){
				++l ;
			}
			else if (b[a[l]] == b[a[r]]){
				if (d[a[r]] == d[a[r-1]]) -- r;
				else ++l ;
			}
			else {
				chk[i] = true ;
				break ;
			}
		}
	}
}

inl void Solve(LL x){
	vis[x] = true , calc(x) ;
	for (re LL i = Head[x] ; i ; i = Graph[i].Next){
		LL y = Graph[i].to ;
		if (vis[y]) continue ;
		root = 0 ;
		Get_root(y,0,Size[y]) ;
		Solve(root) ;
	} return ;
}

signed main(void){
	//fre();
	n = read() ; m = read() ;
	for (re LL i = 1 ; i <= n - 1 ; ++i ){
		LL u , v , w ;
		u = read() ; v = read() ; w = read() ;
		Insert(u,v,w) ;
	}
	MAXS[0] = 0 ;
	Get_root(1,0,n) ;
	Solve(root) ;
	for (re LL i = 1 ; i <= m ; ++i ){
		puts(chk[i]?"AYE":"NAY") ;
	}
	fclose(stdin) ; fclose(stdout) ; return 0 ;
}