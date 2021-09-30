#include <bits/stdc++.h>

using namespace std ;

typedef pair<int,int> pii ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 1e4 + 5 ;
int n , ans ;
pii a[N] ;
priority_queue<int,vector<int>,greater<int> > shop ; 

signed main() {
    while (~scanf("%d",&n)) {
        ans = 0 ;
        for (int i = 1 ; i <= n ; ++i)
            a[i].second = read() , a[i].first = read() ;
        sort(a + 1,a + 1 + n) ;
        for (int i = 1 ; i <= n ; ++i) {
            shop.push(a[i].second) ;
            if (shop.size() > a[i].first) shop.pop() ;
        }
        while (shop.size()) {
            ans += shop.top() ;
            shop.pop() ;
        } printf("%d\n",ans);
    } return 0 ;
}