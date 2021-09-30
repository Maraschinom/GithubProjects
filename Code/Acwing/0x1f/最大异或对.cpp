#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ; return f ? ~ x + 1 : x ;
}

class Trie {
    private :
        int Tp ;
        Trie *son[2] ;
    public :
        Trie(int x):Tp(x){
            for (int i = 0 ; i < 2 ; ++i ) son[i] = NULL ;
        }
        void insert(Trie* &Root,int x) {
            Trie* p = Root ;
            for (int i = 30 ; ~i ; --i ) {
                int arr = x >> i & 1 ;
                if (p -> son[arr] == NULL) p -> son[arr] = new Trie(0) ;
                p = p -> son[arr] ;
            }
        }
        int search(Trie* &Root,int x) {
            int ans = 0 ;
            Trie* p = Root ;
            for (int i = 30 ; ~i ; --i ) {
                int arr = x >> i & 1 ;
                if (p -> son[!arr] == NULL) {
                    p = p -> son[arr] ;
                } else {
                    ans |= 1 << i ;
                    p = p -> son[!arr] ;
                }
            } return ans ;
        }
} ;

const int N = 1e6 + 5 ;
int n , Ans ;
int a[N] ;

signed main() {
    Trie* Answer = new Trie(0) ;
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) a[i] = read() , Answer -> insert(Answer,a[i]) ;
    for (int i = 1 ; i <= n ; ++i ) {
        Ans = max(Ans,Answer -> search(Answer,a[i])) ;
    }
    return printf("%d\n",Ans) , 0 ;
}