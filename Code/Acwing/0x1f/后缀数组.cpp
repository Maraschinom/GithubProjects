#include <bits/stdc++.h>

using namespace std ;

typedef unsigned long long ull ; 

int read(int x = 0,bool f = 0,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 3e5 + 5 , base = 2007 , inf =  1e9 + 7 ;
int len ;
int a[N] ;
char str[N] ;
ull H[N] , p[N] ;

ull calc(int l,int r) {
    return H[r] - H[l - 1] * p[r - l + 1] ;
}

int max_lcs(int a,int b) {
    int l = 0 , r = min(len - a + 1,len - b + 1) ;
    while (l < r) {
        int mid = l + r + 1 >> 1 ;
        if (calc(a,a + mid - 1) == calc(b,b + mid - 1)) l = mid ;
        else r = mid - 1 ;
    }
    return l ;
}

bool cmp(int a,int b) {
    int x = max_lcs(a,b) ;
    int da = a + x > len ? - inf : str[a + x] ;
    int db = b + x > len ? - inf : str[b + x] ;
    return da < db ;
}

signed main() {
    scanf("%s",str + 1) ;
    len = strlen(str + 1) ; p[0] = 1 ;
    for (int i = 1 ; i <= len ; ++i ) {
        H[i] = H[i - 1] * base + str[i] - 'a' + 1 ;
        p[i] = p[i - 1] * base ; a[i] = i ;
    }
    sort (a + 1,a + len + 1,cmp) ;
    for (int i = 1 ; i <= len ; ++i ) printf("%d ",a[i] - 1) ; puts("") ;
    for (int i = 1 ; i <= len ; ++i ) {
        if (i == 1) printf("0 ") ;
        else printf("%d ",max_lcs(a[i],a[i - 1])) ;
    } return 0 ;
}