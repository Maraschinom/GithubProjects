#include<iostream>
#include<cstdio>
#include<set>
#include<map>

using namespace std ;

typedef long long LL;
typedef pair<LL,LL> pii ;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define re register
#define temp template<typename T>

temp
inline T read (T x = 0 , T f = 0){
	re char ch = getchar() ;
	for (;!isdigit(ch);ch = getchar() ) if (ch == '-') f = 1 ;
	for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ;
	return f? ~x+1 : x ;
}

#define lowbit(x) (x)&(-x)
const LL N = 1e5+5 ;
struct point{
	LL x , y , col ;
	friend bool operator < (const point a , const point b){if(a.y != b.y )return a.y < b.y ; else return a.x < b.x ;}
}P[N];
LL n , m ; 
LL s[N] , level[N] , id[N] ;

inline void update(LL x){for(;x <= n;x += lowbit(x) ) ++s[x] ; return ;}
inline LL query(LL x){LL ans = 0 ; for(;x;x -= lowbit(x) ) ans += s[x] ; return ans ;}
set<LL> ss ;
set<LL>::iterator it ;
map<LL,LL> mp ;

signed main(){
//	fre(stars) ;
	n = read<LL>() ;
	for(LL i = 1 ;i <= n ; ++i){
		P[i].x = read<LL>() ;
		P[i].y = read<LL>() ;
		P[i].col = i ;
		mp[P[i].x] = i ;
	}
	sort(P+1,P+1+n) ;
	level[1] = 0 ;
	ss.insert(P[1].x) ;
	cout << P[1].x << endl ;
	for(LL i = 2 ;i <= n ; ++i){
//		it = ss.lower_bound(P[i].x) ;
//		set<LL>::iterator it2 ;
//		it2 = ss.lower_bound(0) ;
//		cout << *it << endl ;
//		cout << *it2 << endl ;
		level[P[i].col] = query(level[mp[*it]]) ;
		ss.insert(P[i].x) ;
		update(P[i].x) ;
	}
	m = read<LL>() ;
	for(LL i = 1 ;i <= m ; ++i){
		id[i] = read<LL>() ;
	}
	for(LL i = 1 ;i <= m ; ++i){
		printf("%LLd\n",level[id[i]]) ;
	}

	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}  
/*
5
0 0
2 0
3 0
1 1
2 2
2 
4 5
*/
