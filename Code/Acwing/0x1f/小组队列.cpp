#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std ;

int read(int x = 0 ,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= (ch == '-') ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

const int N = 1e4 + 5 , M = 1e6 + 5 ;
int n , u , v , x , idx , s , cnt ;
char str[10] ;
int bel[M] , id[N] ;
bool inque[N] ;

deque< deque<int> > Group ;
deque<int> res ;

void solve(int x) {
    if (inque[bel[x]]) {
        Group[id[bel[x]] - s - 1].push_back(x) ;
    } else {
        res.push_front(x) ;
        Group.push_back(res) ;
        inque[bel[x]] = true ;
        id[bel[x]] = ++ cnt  ;
        res.pop_front() ;
    }
}

void query() {
    int x = Group.front().front() ;
    printf("%d\n",x) ;
    if (Group.front().size() == 1) {
        inque[bel[x]] = false ;
        ++ s ; 
        Group.pop_front() ; return ;
    }
    Group.front().pop_front() ;
}

signed main() {
    while (n = read()) {
        Group.clear() ; cnt = s = 0 ;
        memset(inque,0,sizeof inque) ;
        memset(id,0,sizeof id) ;
        printf("Scenario #%d\n",++ idx) ;
        for (int i = 1 ; i <= n ; ++i ) {
            x = read() ;
            for (int j = 1 ; j <= x ; ++j ) {
                u = read() ; bel[u] = i ;
            }
        }
        while (scanf("%s",str) && str[0] != 'S') {
            if (str[0] == 'E') solve(read()) ;
            else query() ;
        } puts("") ;
    } return 0 ;
}