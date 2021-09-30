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

const int N = 1e1 + 5 ;

int T , n ;
bool fl ;
char str[N] ;

class Trie {
    private :
        int Tp , value_type ;
        Trie *son[10] ;
    public :
        Trie(int x):Tp(x){
            for (int i = 0 ; i < 10 ; ++i ) son[i] = NULL ;
        }
        void insert(Trie* &Root,char str[]) {
            int len = strlen(str) ;
            Trie* p = Root ;
            for (int i = 0 ; i < len ; ++i ) {
                int num = str[i] - '0' ;
                if (p -> son[num] == NULL) {
                    p -> son[num] = new Trie(0) ;
                    p -> son[num] -> value_type = num ;
                }
                p = p -> son[num] ;
            }
            ++ p -> Tp ;
        }
        int search(Trie* &Root,char str[]) {
            int len = strlen(str) , ans = 0 ;
            Trie* p = Root ;
            for (int i = 0 ; i < len ; ++i ) {
                int num = str[i] - '0' ;
                if (p -> son[num] == NULL) return ans ;
                p = p -> son[num] ;
                ans += p -> Tp ;
            } return ans ;
        }
} ;


signed main() {
    T = read() ;
    while (T --) {
        n = read() , fl = true ;
        Trie* Root = new Trie(0) ;
        for (int i = 1 ; i <= n ; ++i ) {
            scanf("%s",str) ;
            if (Root -> search(Root,str)) fl = false ;
            Root -> insert(Root,str) ;
        } puts(fl ? "YES" : "NO") ;
        delete(Root) ;
    }
}