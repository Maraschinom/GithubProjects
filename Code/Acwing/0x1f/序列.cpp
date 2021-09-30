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

const int N = 2e3 + 5 ;
int T , n , m , idx ;
int arr[N] , seq[N] , ans[N] ;

void solve() {
    priority_queue<pii,vector<pii>,greater<pii> > Q ;
    for (int i = 1 ; i <= n ; ++i ) Q.push(make_pair(arr[1] + seq[i],1)) ;
    for (int i = 1 ; i <= n ; ++i ) {
        pii x = Q.top() ; Q.pop() ;
        ans[i] = x.first , idx = x.second ;
        Q.push(make_pair(x.first - arr[idx] + arr[idx + 1],idx + 1)) ;
    }
    memcpy(arr,ans,sizeof ans) ;
}

signed main() {
    T = read() ;
    while (T --) {
        m = read() , n = read() ;
        for (int i = 1 ; i <= n ; ++i ) arr[i] = read() ;
        sort(arr + 1,arr + 1 + n) ;
        for (int i = 1 ; i < m ; ++i ) {
            for (int j = 1 ; j <= n ; ++j )
                seq[j] = read() ;
            solve() ;
        }
        for (int i = 1 ; i <= n ; ++i )
            printf("%d%c",arr[i],i == n ? '\n' : ' ') ;
    } return 0 ;
}