#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std ;

int read(int x = 0 , char ch = getchar() , bool f = false ) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e6 + 5 , base = 131 ;

int m , l , r , l2 , r2 ;
unsigned long long ans1 , ans2 ; 
char str[N] ;
unsigned long long Hash[N] ;
unsigned long long base_pow[N] ;

signed main() {
    scanf("%s",str) ;
    int len = strlen(str) ;
    base_pow[0] = 1LL ;
    for (auto i = 1 ; i <= len ; ++i ) {
        Hash[i] = str[i - 1] + Hash[i - 1] * base ;
        base_pow[i] = base_pow[i - 1] * base ;
    } m = read() ;
    // for (auto i = 1 ; i < len ; ++i ) cout << Hash[i] << endl ;
    for (auto i = 1 ; i <= m ; ++i ) {
        l = read() , r = read() , l2 = read() , r2 = read() ;
        ans1 = Hash[r] - Hash[l - 1] * base_pow[r - l + 1] ;
        ans2 = Hash[r2] - Hash[l2 - 1] * base_pow[r2 - l2 + 1] ;
        if (ans1 == ans2) puts("Yes") ;
        else puts("No") ;
    }
}