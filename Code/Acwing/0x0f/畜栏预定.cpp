#include <bits/stdc++.h>

using namespace std ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 5e4 + 5 , M = 1e6 + 5 , m = 1e6 ;
int n , ans , tot , lst , d[M] , id[N] ;
struct Node {
    int st , ed , idx ;
    inline bool operator < (const Node& o) const {
        return st < o.st ;
    }
} T[N] ;

priority_queue<int,vector<int>,greater<int> > heap ;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > cow ;

signed main() {
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) 
        T[i].st = read() , T[i].ed = read() , T[i].idx = i , ++ d[T[i].st] , -- d[T[i].ed + 1] ;
    for (int i = 1 ; i <= m ; ++i ) d[i] += d[i-1] , ans = max(ans,d[i]) ; printf("%d\n",ans) ;
    sort(T + 1,T + 1 + n) ; 
    for (int i = 1 ; i <= ans ; ++i ) heap.push(i) ;
    T[0].ed = 1e9 + 7 ; lst = 1 ;
    for (int i = 1 ; i <= n ; ++i ) {
        while (cow.size() && T[i].st > cow.top().first) heap.push(id[T[cow.top().second].idx]) , cow.pop() ;
        id[T[i].idx] = heap.top() , heap.pop() , cow.push(make_pair(T[i].ed,i)) ;
    }
    for (int i = 1 ; i <= n ; ++i ) printf("%d\n",id[i]) ;
}