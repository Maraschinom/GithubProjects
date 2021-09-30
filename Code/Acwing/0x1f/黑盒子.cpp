#include <bits/stdc++.h>

using namespace std;

typedef long long LL ;
typedef pair<int,int> pii ;

int read() {
    int x = 0 ; bool f = false ; char ch = getchar() ;
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 3e4 + 5 ;
priority_queue<int,vector<int>,greater<int> > Fr , Bk ;
int n , m ;
int A[N] , uml[N] ;

signed main() {
    m = read() , n = read() ;
    for (int i = 1 ; i <= m ; ++i ) a[i] = read() ;
    for (int i = 1 ; i <= n ; ++i ) uml[i] = read() ;
    for (int i = 1 ; i <= m ; ++i ) {
        if (a[i] < Fr.front()) Bk.push(a[i]) ;
        else Fr.push(a[i]) ;
        
    }
}