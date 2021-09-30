#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

const int N = 2e5 + 5 , base = 1331 ;

class Sulotion {
    private :
        int a , b , Q , x , sub_len , substr_len ;
        char sub[N] , substr[N] ;
        unsigned long long Hash[N] , Hsh[N] , p[N] ;
        int ans[N] ;
    public :
        Sulotion(){}
        #define sub_value(l,r) (Hash[r] - Hash[l - 1] * p[r - l + 1])
        #define substr_value(l,r) (Hsh[r] - Hsh[l - 1] * p[r - l + 1])
        void init() {
            a = read() , b = read() , Q = read() ;
            scanf("%s%s",sub + 1,substr + 1) ;
            return void() ;
        }
        void solve() {
            p[0] = 1 ; 
            sub_len = strlen(sub + 1) ;
            substr_len = strlen(substr + 1) ;
            for (int i = 1 ; i <= sub_len ; ++i )
                Hash[i] = Hash[i - 1] * base + sub[i] - 'a' + 1 ,
                p[i] = p[i - 1] * base ;
            for (int i = 1 ; i <= substr_len ; ++i )
                Hsh[i] = Hsh[i - 1] * base + substr[i] - 'a' + 1 ;
            return void() ;
        }
        void calc() {
            for (int i = 1 ; i <= sub_len ; ++i ) {
                int Vp , Tp , l , r , mid ;
                l = 0 , r = min(sub_len - i + 1,substr_len) ;
                while (l + 1 < r) {
                    mid = l + r >> 1 ;
                    Vp = sub_value(i,i + mid - 1) ;
                    Tp = substr_value(1,mid) ;
                    // cout << Vp << ' ' << Tp << ' ' << mid << endl ;
                    if (Vp == Tp) l = mid ;
                    else r = mid ;
                }
                // cout << i << ' ' << l << ' ' << r << ' ' ;
                Vp = sub_value(i,i + r - 1) ;
                Tp = substr_value(1,r) ;
                if (Vp == Tp) ++ ans[r] ;
                else ++ ans[l] ;
            }
        }
        void query() {
            while (Q--) {
               x = read() ;
               printf("%d\n",ans[x]) ; 
            } return void() ;
        }
} ;

signed main() {
    Sulotion* Answer = new Sulotion() ;
    Answer -> init() ;
    Answer -> solve() ;
    Answer -> calc() ;
    Answer -> query() ;
    return 0 ;
}