#include <bits/stdc++.h>

using namespace std ;

typedef long long LL ;
typedef pair<int,int> PII ;

#define Make_Pair make_pair

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 105 ;
int n , m ;
int a[N] , b[N] ;
map<int,bool> vis; 

signed main() {
    n = read() ;
    for (int i = 1 ; i <= n ; ++i )
        a[i] = read() , vis[a[i]] = true ;
    m = read() ;
    for (int i = 1 ; i <= m ; ++i )
        b[i] = read() , vis[b[i]] = true ;
    for (int i = 1 ; i <= n ; ++i )
        for (int j = 1 ; j <= m ; ++j )
            if (!vis[a[i] + b[j]]) return printf("%d %d\n",a[i],b[j]) , 0 ;
}
