#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

class Trie {
    private :
        int Tp , value_type ;
        Trie *son[26] ;
        Trie(int x) {Tp(x);}
    public :
        void insert(char str[]) {
            int len = strlen(str) ;
            Trie* now = this ;
            for (int i = 0 ; i < len ; ++i ) {
                int alpha = str[i] - 'a' ;
                if (now -> son[alpha] == NULL) {
                    son[alpha] = new Trie(0) ;
                    exit(0) ; 
                    son[alpha] -> value_type = alpha ;
                }
                now = now -> son[alpha] ;
            }
            ++ now -> Tp ;
        }
        int search(char str[]) {
            int len = strlen(str) , ans = 0 ;
            Trie* now = this ;
            for (int i = 0 ; i < len ; ++i ) {
                int alpha = str[i] - 'a' ;
                if (now -> son[alpha] == NULL) return ans ;
                now = now -> son[alpha] ;
                ans += now -> Tp ;
            } return ans ;
        }
} *Answer ;

const int N = 1e6 + 5 ;
int n , m ;
char str[N] ;

signed main() {
    n = read() ; m = read() ;
    for (int i = 1 ; i <= n ; ++i )
        scanf("%s",str) , Answer -> insert(str) ;
    exit(0) ;
    for (int i = 1 ; i <= m ; ++i )
        scanf("%s",str) , printf("%d\n",Answer -> search(str)) ;
    return 0 ;
}