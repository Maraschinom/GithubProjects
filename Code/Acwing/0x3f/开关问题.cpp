#include <bits/stdc++.h>

using namespace std ;

const int N = 1e2 + 5 ;
const double eps = 1e-5 ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

int T ;

class Martix {
    private :
        int n ;
        int martix[N][N] ;
    public :
        Martix(int x){
            memset(martix,x,sizeof martix) ;
        }
        void Init(Martix* &Rt) {
            int x , y ;
            Rt -> n = read() ;
            for (int i = 1 ; i <= Rt -> n ; ++i ) Rt -> martix[i][Rt -> n + 1] = read() ;
            for (int i = 1 ; i <= Rt -> n ; ++i ) {
                x = read() ;
                Rt -> martix[i][Rt -> n + 1] ^= x ;
                Rt -> martix[i][i] = 1 ;
            }
            while (x = read(),y = read(),x || y) Rt -> martix[y][x] = 1 ;
        }
        int solve(Martix* &Rt) {
            int ans = 1 , r = 1 ;
            for (int i = 1 ; i <= Rt -> n ; ++i ) {
                int mx = i ;
                for (int j = r + 1 ; j <= Rt -> n ; ++j )
                    if (Rt -> martix[j][i])
                        mx = j ;
                if (!(Rt -> martix[mx][i])) continue ;
                for (int j = i ; j <= Rt -> n + 1 ; ++j ) swap(Rt -> martix[mx][j],Rt -> martix[r][j]) ;
                for (int j = r + 1 ; j <= Rt -> n ; ++j )
                    for (int k = Rt -> n + 1 ; k >= i ; --k )
                        Rt -> martix[j][k] ^= Rt -> martix[j][i] & Rt -> martix[r][k] ;
                ++ r ;
            }
            if (r < Rt -> n + 1) {
                for (int i = r ; i <= Rt -> n ; ++i )
                    if (Rt -> martix[i][Rt -> n + 1]) return -1 ;
                    else ans <<= 1 ;
            } return ans ;
        }
} ;

signed main() {
    T = read() ;
    while (T --) {
        Martix* Answer = new Martix(0) ;
        Answer -> Init(Answer) ;
        int ans = Answer -> solve(Answer) ;
        if (ans == -1) puts("Oh,it's impossible~!!") ;
        else printf("%d\n",ans) ;
    }
    return 0 ;
}