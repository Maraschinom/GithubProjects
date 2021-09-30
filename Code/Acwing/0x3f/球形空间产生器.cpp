#include <bits/stdc++.h>

using namespace std ;

const int N = 1e2 + 5 ;
const double eps = 1e-5 ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

double arr[N][N] ;

class Martix {
    private :
        int n ;
        double ans[N] ;
        double martix[N][N] ;
        bool is_zero(double x) {
            return fabs(x) < eps ;
        }
    public :
        Martix(int x){
            memset(martix,x,sizeof martix) ;
        }
        void Init(Martix* &Rt) {
            Rt -> n = read() ;
            for (int i = 1 ; i <= Rt -> n + 1 ; ++i )
                for (int j = 1 ; j <= n ; ++j ) scanf("%lf",&arr[i][j]) ;
            for (int i = 1 ; i <= Rt -> n ; ++i )
                for (int j = 1 ; j <= Rt -> n ; ++j ) {
                    Rt -> martix[i][j] = 2 * arr[i][j] - 2 * arr[i + 1][j] ;
                    Rt -> martix[i][n + 1] += arr[i][j] * arr[i][j] - arr[i + 1][j] * arr[i + 1][j] ; 
               }
        }
        void solve(Martix* &Rt) {
            for (int i = 1 ; i <= Rt -> n ; ++i ) {
                int mx = i ;
                for (int j = i + 1 ; j <= Rt -> n ; ++j )
                    if (fabs(Rt -> martix[mx][i]) < fabs(Rt -> martix[j][i]))
                        mx = j ;
                if (is_zero(Rt -> martix[mx][i])) {
                    puts("No Solution") ;
                    exit(0) ;
                }
                if (i != mx) swap(Rt -> martix[i],Rt -> martix[mx]) ;
                double div = Rt -> martix[i][i] ;
                for (int j = i ; j <= Rt -> n + 1 ; ++j )
                    Rt -> martix[i][j] /= div ;
                for (int j = i + 1 ; j <= Rt -> n ; ++j ) {
                    div = Rt -> martix[j][i] ;
                    for (int k = i ; k  <= Rt -> n + 1 ; ++k )
                       Rt -> martix[j][k] -= Rt -> martix[i][k] * div ; 
                }
            } return void() ;
        }
        void calc(Martix* &Rt) {
            Rt -> ans[Rt -> n] = Rt -> martix[Rt -> n][Rt -> n + 1] ;
            for (int i = Rt -> n - 1 ; i ; --i ) {
                Rt -> ans[i] = Rt -> martix[i][Rt -> n + 1] ;
                for (int j = i + 1 ; j <= Rt -> n ; ++ j )
                    Rt -> ans[i] -= Rt -> martix[i][j] * Rt -> ans[j] ;
            }
            return void() ;
        }
        void write(Martix* &Rt) {
            for (int i = 1 ; i <= Rt -> n ; ++i )
                printf("%.3lf%c",ans[i],i == n ? '\n' : ' ') ;
            return void() ;
        }
} ;

signed main() {
    Martix* Answer = new Martix(0) ;
    Answer -> Init(Answer) ; Answer -> solve(Answer) ;
    Answer -> calc(Answer) ; Answer -> write(Answer) ;
    return 0 ;
}