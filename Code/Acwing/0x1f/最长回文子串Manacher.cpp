#include <bits/stdc++.h>

using namespace std;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e6 + 5 ;

char str[N] , substr[N << 1] ;
int len , cnt , id , r , T , ans ;
int Ma[N << 1] ;

int Manacher(char ch[],int len) {
    ans = r = id = cnt = 0 ;
    substr[cnt ++] = '$' , substr[cnt ++] = '#' ;
    for (int i = 0 ; i < len ; ++i )
        substr[cnt ++] = ch[i] , substr[cnt ++] = '#' ;
    substr[cnt] = 0 ;
    for (int i = 1 ; i < cnt ; ++i ) {
        Ma[i] = r > i ? min(Ma[2 * id - i],r - i) : 1 ;
        while (substr[i + Ma[i]] == substr[i - Ma[i]]) ++ Ma[i] ;
        if (Ma[i] + i > r) r = Ma[i] + i , id = i , ans = max(ans,Ma[i] - 1) ;
    } return ans ;
}


signed main() {
    while (scanf("%s",str) && str[0] != 'E') {
        printf("Case %d: %d\n",++ T,Manacher(str,strlen(str))) ;
    }
}