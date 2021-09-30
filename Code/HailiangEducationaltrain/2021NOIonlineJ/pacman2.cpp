#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

#define re register
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )

typedef long long LL ; typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (re string s = "",re char ch = getchar()) {
	for(;!isalpha(ch);ch = getchar()) 0 ;
	for(;isalpha(ch);ch = getchar()) s.push_back(ch) ; return s ;
}

const LL N = 1e3+5 ;

struct Node {
    LL xx , yy ;
    LL val ;
    friend bool operator == (Node a,Node b) {
        return a.xx == b.xx && a.yy == b.yy ;
    }
    friend bool operator < (Node a,Node b) {
        return a.val < b.val ;
    }
    friend bool operator > (Node a,Node b) {
        return a.val > b.val ;
    }
} ;

LL n , ans , tot = 1 , res ;
LL Siz[N] ;
LL map[N][N] ;
vector <Node> member[N] , st ;
bool vis[N][N][4] ;

inline void sub() {
    LL Dial1 , Dial2 , Sqare ;
    Dial1 = map[1][1] + map[2][2] + map[3][3] ;
    Dial2 = map[3][1] + map[2][2] + map[1][3] ;
    Sqare = map[1][2] + map[2][1] + map[2][3] + map[3][2] ;
    ans = std::max(Dial1+Dial2-map[2][2],std::max(Dial1,Dial2)+Sqare) ;
    return printf("%lld\n",ans),void() ; 
}

const LL dx[] = {1,-1,1,-1} ;
const LL dy[] = {1,-1,-1,1} ;

inline bool isok (LL x,LL y) {return x <= n && x >= 1 && y <= n && y >= 1 ;}

inline void search(LL x,LL y,LL dir) {
    LL step = 0 ;
    Siz[tot] += map[x][y] ; member[tot].push_back((Node){x,y,map[x][y]}) ;
    for(;isok(x,y);x+=dx[dir],y+=dy[dir]) {
        if (vis[x][y][dir]) break ;
        else ++step , vis[x][y][dir] = true , Siz[tot] += map[x][y] , member[tot].push_back((Node){x,y,map[x][y]});
    }
    FOR(i,1,step) x-=dx[dir] , y-=dy[dir] , vis[x][y][dir] = false ;
}

inline void task() {
    // #pragma GCC diagnostic error "-std=c++11"
    FOR(i,1,n)
        FOR(j,1,n)
            FOR(opt,1,4) if (!vis[i][j][opt] ) ++tot , search(i,j,opt) ;
    FOR(i,1,tot) FOR(j,i+1,tot) {
        res = Siz[i] + Siz[j] ;
        FOR(k,0,member[j].size()-1) member[i].push_back(member[j][k]) ;
        vector<Node>::iterator it,it2 = unique(member[i].begin(),member[i].end()) ;
        for(it = it2 ; it != member[i].end() ; ++it ) {
            res -= (*it).val ;
        }
        member[i].erase(it2,member[i].end()) ;
        // puts("") ;
        // for(auto k : member[i]) printf("%lld %lld ",k.xx,k.yy) ;
        // puts("") ;
        // for(auto k : member[j]) printf("%lld %lld ",k.xx,k.yy) ;
        // puts("") ;
        ans = std::max(ans,res+1) ;
    }
    printf("%lld\n",ans) ; return void() ;
}

signed main() {
	fre(pacman) ;
    n = read() ;
    FOR(i,1,n) FOR(j,1,n) map[i][j] = read() ;
    if (n == 3) sub() ;    
    else task() ;
    fclose(stdin) , fclose(stdout) ; return 0 ; 
}
/*
Input :
4
20 1 19 2
3 18 4 17
16 5 15 6
7 14 8 13
*/