#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,char ch = getchar(),bool f = false) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 ;
int mx , idx , len ;
int a[N] ;
char str[N] ;

signed main() {
    scanf("%s",str + 1) ;
    len = strlen(str + 1) ;
    for (int i = 1 ; i <= len ; ++i ) {
        if (str[i] == ')' && str[i - a[i] - 1] == '(' ||
        str[i] == ']' && str[i - a[i] - 1] == '[' || 
        str[i] == '}' && str[i - a[i] - 1] == '{')
        a[i] = a[i - 1] + 2 - a[i - a[i] - 2] ;
        if (a[i] > mx) mx = a[i] , idx = i ;
    }
    for (int i = idx - a[idx] + 1 ; i <= idx ; ++i ) printf("%c",str[i]) ;
    return 0 ;
}