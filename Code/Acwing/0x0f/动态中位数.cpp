#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;

inline int read(register int x = 0 , register char ch = getchar() , register bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;
int T , n , cnt , a[N] ;
int ans ;
priority_queue<int> G ;
priority_queue<int,vector<int>,greater<int>> L ;

signed main() {
    T = read() ;
    for (int _ = 1 ; _ <= T ; ++_ ) {
        read() ;
        n = read() ;
        printf("%d %d\n",_,(n + 1) >> 1) ;
        while(G.size()) G.pop() ;
        while(L.size()) L.pop() ;
        ans = 0 , cnt = 0 ;
        for (int i = 1 ; i <= n ; ++i ) {
            a[i] = read() ;
            if (L.empty()) L.push(a[i]) ;
            else {
                if(a[i] > L.top()) L.push(a[i]) ;
                else G.push(a[i]) ;
                while (L.size() < G.size())
                    L.push(G.top()) , G.pop() ;
                while (L.size() > G.size() + 1)
                    G.push(L.top()) , L.pop();
            }
            if(i&1) {
                if (cnt == 10) cnt = 0 , putchar('\n') ;
                printf("%d ",L.top()) ; ++ cnt ;
            }
        } puts("") ;
    } return 0 ;
}