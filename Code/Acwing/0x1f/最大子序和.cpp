#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = 0,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 3e5 + 5 , inf = 1e9 + 7 ;
int n , m , ans = - inf ;
int a[N] , sum[N] ;
deque<int> seq ;

signed main() {
    n = read() , m = read() ;
    for (auto i = 1 ; i <= n ; ++i ) a[i] = read() , sum[i] = sum[i - 1] + a[i] ;
    seq.push_front(0) ;
    for (auto i = 1 ; i <= n ; ++i ) {
        while (seq.size() && seq.front() < i - m) seq.pop_front() ;
        ans = max(ans,sum[i] - sum[seq[0]]) ;
        while (seq.size() && sum[seq.back()] >= sum[i]) seq.pop_back() ;
        seq.push_back(i) ;
    } printf("%d\n",ans) ;
}