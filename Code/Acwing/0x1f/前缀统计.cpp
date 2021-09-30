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
    public :
        Trie(int x):Tp(x){
            for (int i = 0 ; i < 26 ; ++i ) son[i] = NULL ;
        }
        void insert(Trie* &Root,char str[]) {
            int len = strlen(str) ;
            Trie* p = Root ;
            for (int i = 0 ; i < len ; ++i ) {
                int alpha = str[i] - 'a' ;
                if (p -> son[alpha] == NULL) {
                    p -> son[alpha] = new Trie(0) ;
                    p -> son[alpha] -> value_type = alpha ;
                }
                p = p -> son[alpha] ;
            }
            ++ p -> Tp ;
        }
        int search(Trie* &Root,char str[]) {
            int len = strlen(str) , ans = 0 ;
            Trie* p = Root ;
            for (int i = 0 ; i < len ; ++i ) {
                int alpha = str[i] - 'a' ;
                if (p -> son[alpha] == NULL) return ans ;
                p = p -> son[alpha] ;
                ans += p -> Tp ;
            } return ans ;
        }
} ;

const int N = 1e6 + 5 ;
int n , m ;
char str[N] ;

signed main() {
    Trie* Answer = new Trie(0) ;
    n = read() ; m = read() ;
    for (int i = 1 ; i <= n ; ++i )
        scanf("%s",str) , Answer -> insert(Answer,str) ;
    for (int i = 1 ; i <= m ; ++i )
        scanf("%s",str) , printf("%d\n",Answer -> search(Answer,str)) ;
    return 0 ;
}