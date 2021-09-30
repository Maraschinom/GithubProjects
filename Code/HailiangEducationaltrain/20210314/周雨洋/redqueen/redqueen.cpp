// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>

using namespace std ;

#define re register

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

#define inl inline 

#define FOR(i,x,y) for(int i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(int i = x ; i >= y ; --i )

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

queue < pair < LL ,pair <LL,LL> > > Q ;

const LL N = 205 ;

const LL dx[] = {-1,+1,+2,+1,-1,-2} ;
const LL dy[] = {-2,-2,+0,+2,+2,+0} ;
const string Name[] = {"UL","UR","R","LR","LL","L"} ;

LL n , x_start , y_start , x_end , y_end , xx , yy , ans ;
bool vis[N][N] , isok = false ;
vector <LL> a ;
stack <LL> st ;

inline bool check(PLL x) {
	return x.first == x_end && x.second == y_end ;
}

inline void print(string s) {
	for (string::iterator it = s.begin() ; it != s.end() ; ++it ) 
		putchar(*it) ;
}	

inline void write() {
	printf("%lld\n",ans) ;
	while (st.size()) {
		a.push_back(st.top()) ; st.pop() ;
	}
	reverse(a.begin(),a.end()) ;
	for (vector<LL>::iterator it = a.begin() ; it != a.end() ; ++it ) {
		LL i = *it ; print(Name[i]+" ") ;
	}
}

inline void bfs() {
	Q.push(make_pair(0,make_pair(x_start,y_start))) ;
	vis[x_start][y_start] = true ;
	while (Q.size()) {
		pair<LL,pair<LL,LL> > u = Q.front() ; Q.pop() ;
//		cout << u.second.first << ' ' << u.second.second << endl ;
		if (check(u.second)) {
			ans = u.first ;
			isok = true ;
			return ;
		}
		FOR(i,0,5) {
			xx = u.second.first + dx[i] ;
			yy = u.second.second + dy[i] ;
//			printf("%lld %lld\n",xx,yy) ;
			if (xx <= 0 || xx > n || yy <= 0 || yy > n || vis[xx][yy] ) continue ;
//			printf("%lld %lld\n",xx,yy) ;
			vis[xx][yy] = true ;
			Q.push(make_pair(u.first+1,make_pair(xx,yy))) ;
		}
//		puts("") ;
	}
}

inline void find(LL step,PLL x) {
//	printf("%lld %lld\n",x.first,x.second) ;
//	stack<LL> st2(st) ;
//	while(st2.size()) {
//		print(Name[st2.top()]+" ") ; st2.pop();
//	}
//	printf("\n\n") ;
	if (step == ans && check(x)) {
		write() ;
		exit(0) ;
	}
	if (step == ans) return ;
	FOR(i,0,5) {
		xx = x.first + dx[i] ;
		yy = x.second + dy[i] ;
		if (xx <= 0 || xx > n || yy <= 0 || yy > n) continue ;
		st.push(i) ;
		find(step+1,make_pair(xx,yy)) ;
		st.pop() ;
	}
}

signed main() {
	fre(redqueen) ;
	n = read() ;
	y_start = read() ;
	x_start = read() ;
	y_end = read() ;
	x_end = read() ;
	++x_start ;
	++y_start ;
	++x_end ;
	++y_end ;
	bfs() ;
//	cout << isok << endl ;
	if (!isok) return puts("Impossible"),0 ;
	else find(0,make_pair(x_start,y_start)) ;
}
