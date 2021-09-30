#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std ;

typedef long long LL ;

inline LL read(register LL x = 0,register char ch = getchar(),register bool f = false) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ; 
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;
LL n , top , ans ;
LL h[N] , st[N] , width[N] ;

signed main() {
    while(1) {
        n = read() ; ans = 0LL ; top = 0LL ;
        if (!n) break ;
        memset(st,-1,sizeof st) ;
        for (int i = 1 ; i <= n ; ++i ) h[i] = read() ; h[n + 1] = 0LL ;
        for (int i = 1 ; i <= n + 1; ++i ) {
            if (h[i] > st[top]) st[++ top] = h[i] , width[top] = 1LL ;
            else {
                LL cnt = 0LL ;
                while (h[i] <= st[top]) {
                    ans = max(ans,st[top] * (width[top] + cnt)) ;
                //  cout << st[top] * (width[top] + cnt) << endl ;
                    cnt += width[top --] ;
                } 
                st[++ top] = h[i] ;
                width[top] = cnt + 1LL ;
            }
        } printf("%lld\n",ans) ;
    } return 0 ;
} 