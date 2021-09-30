#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = 0,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 8e6 + 5 , M = 8e6 + 5 , inf = 2147483647 ;
int n , m , q , u1 , v1 , t , res , base , cnt ;
int u , v , w ;
int s[N] , ans[M + N] ;
int seq[N] , cut_Front[N] , cut_Back[N] ;
int l = 1 , l1 = 1 , r1 , l2 = 1 , r2 ;
double p ;

void get_max() {
    if (l > n && cut_Front[l1] > cut_Back[l2])
        res = cut_Front[l1 ++] ;
    else if (l > n && cut_Front[l1] <= cut_Back[l2])
        res = cut_Back[l2 ++] ;
    else if (seq[l] >= cut_Front[l1] && seq[l] >= cut_Back[l2])
        res = seq[l ++] ;
    else if (cut_Front[l1] >= seq[l] && cut_Front[l1] >= cut_Back[l2])
        res = cut_Front[l1 ++] ;
    else
        res = cut_Back[l2 ++] ;
}

void solve() {
    for (int i = l ; i <= n ; ++i ) ans[++ cnt] = seq[i] ;
    for (int i = l1 ; i <= r1 ; ++i ) ans[++ cnt] = cut_Front[i] ;
    for (int i = l2 ; i <= r2 ; ++i ) ans[++ cnt] = cut_Back[i] ;
    sort(ans + 1,ans + 1 + cnt,greater<int>()) ;
    return void() ;
}

bool cmp(int a,int b) {return a > b ;}

signed main() {
    n = read() , m = read() , q = read() , u1 = read() , v1 = read() , t = read() ;
    p = 1.0 * u1 / v1 ;
    for (int i = 1 ; i <= n ; ++i ) seq[i] = read() ;
    sort(seq + 1,seq + 1 + n,greater<int>()) ;
    for (int i = 1 ; i <= m ; ++i ) {
        get_max() ; 
        res += base ; base += q ;
        int len1 = floor(1.0 * res * p) ;
        int len2 = res - len1 ;
        len1 -= base , len2 -= base ;
        cut_Front[++ r1] = len1 ; cut_Back[++ r2] = len2 ;
        if (i % t == 0) printf("%d ",res) ;
    } puts("") ;
    solve() ;
    for (int i = 1 ; i <= cnt ; ++i ) if (i % t == 0) printf("%d ",ans[i] + base) ;
    return 0 ;
}