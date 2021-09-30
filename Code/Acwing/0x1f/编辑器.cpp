#include <bits/stdc++.h>
using namespace std ;

const int N = 1e6 + 5 ;
int Q , x , k , len , lenr ;
int Max[N] , sum[N] , stl[N] , str[N] ;
char chk[2] ;

signed main() {
    Max[0] = -1e9 ; scanf("%d",&Q) ;
    while (Q --) {
        scanf("%s",chk) ;
        if (chk[0] == 'I') {
            scanf("%d",&x) ;
            stl[++ len] = x ;
            sum[len] = sum[len - 1] + stl[len] ;
            Max[len] = max(Max[len - 1],sum[len]) ;
        } else if (chk[0] == 'D') {
            if (len)
                -- len ;
        } else if (chk[0] == 'R') {
            if (lenr) {
                stl[++ len] = str[lenr --] ;
                sum[len] = sum[len - 1] + stl[len] ;
                Max[len] = max(Max[len - 1],sum[len]) ;
            }
        } else if (chk[0] == 'L') {
            if (len)
                str[++ lenr] = stl[len --] ;
        } else {
            scanf("%d",&k) ;
            printf("%d\n",Max[k]) ;
        }
    }
}