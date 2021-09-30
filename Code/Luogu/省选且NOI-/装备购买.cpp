#include <bits/stdc++.h>

using namespace std;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 5e2 + 5 ;
const long double eps = 1e-7 ;
int n , m , ans , tot ;
int p[N] ;

struct equip {
    long double attribute[N] ;
    int price ;
    friend bool operator < (const equip a,const equip b) {
        return a.price < b.price ;
    }
} Equip[N] ;

signed main() {
    n = read() , m = read() ;
    for (int i = 1 ; i <= n ; ++i )
        for (int j = 1 ; j <= m ; ++j )
            scanf("%llf",&Equip[i].attribute[j]) ;
    for (int i = 1 ; i <= n ; ++i )
        Equip[i].price = read() ;
    sort(Equip + 1,Equip + 1 + n) ;
    for (int i = 1 ; i <= n ; ++i )
        for (int j = 1 ; j <= m ; ++j )
            if (fabs(Equip[i].attribute[j]) > eps) {
                if (!p[j]) {
                    p[j] = i ;
                    ++ tot , ans += Equip[i].price ;
                    break ;
                } else {
                    long double div = Equip[i].attribute[j] / Equip[p[j]].attribute[j] ;
                    for (int k = j ; k <= m ; ++k )
                        Equip[i].attribute[k] -= Equip[p[j]].attribute[k] * div ;
                }
            }
    printf("%d %d\n",tot,ans) ;
}