#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = false,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

const int N = 1e5 + 5 , L = 1e6 + 5 ;

int tmp , cnt = 1 , ans , n , len , alpha ;

class Aho_Corasick_automaton {
    private :
        int Tp , idx , value_type ;
        Aho_Corasick_automaton *son[30] , *nxt ;
    public :
        Aho_Corasick_automaton (int x):Tp(x) {
            value_type = 0 , idx = ++ cnt , nxt = NULL ;
            for (int i = 0 ; i < 30 ; ++i )
                son[i] = NULL ;
        }
        void Insert (Aho_Corasick_automaton* &Rt,char str[]) {
            Aho_Corasick_automaton* o = Rt ;
            len = strlen(str) ;
            for (int i = 0 ; i < len ; ++i ) {
                alpha = str[i] - 'a' ;
                if (o -> son[alpha] == NULL) o -> son[alpha] = new Aho_Corasick_automaton(0) , o -> son[alpha] -> value_type = alpha ;
                o = o -> son[alpha] ;
            }
            ++ o -> Tp ;
        }
        void spawn_fail(Aho_Corasick_automaton* &Rt) {
            queue<Aho_Corasick_automaton*> Q ;
            Aho_Corasick_automaton* u ;
            for(int i = 0; i < 30; i++) {
                if(Rt -> son[i] != NULL)
                    Rt -> son[i] -> nxt = Rt , Q.push(Rt -> son[i]) ;
                else
                    Rt -> son[i] = Rt ;
            }
            while(Q.size()) {
                u = Q.front() ; Q.pop() ;
                for (int i = 0 ; i < 30 ; ++i )
                    if (u -> son[i] == NULL) {
                        u -> son[i] = u -> nxt -> son[i] ;
                    } else {
                        Q.push(u -> son[i]) ;
                        u -> son[i] -> nxt = u -> nxt -> son[i] ;
                    }
            }
        }
        void Find(Aho_Corasick_automaton* &Rt,char str[]) {
            ans = 0 ; Aho_Corasick_automaton* o = Rt ;
            len = strlen(str) ;
            for (int i = 0 ; i < len ; ++i ) {
                alpha = str[i] - 'a' ;
                Aho_Corasick_automaton* p = o -> son[alpha] ;
                while (p -> Tp != -1) {
                    ans += p -> Tp ;
                    p -> Tp = -1 ;
                    p = p -> nxt ;
                } o = o -> son[alpha] ;
            }
        }
} ;

int T ;
char str[L] , substr[L] ;

signed main() {
    n = read() ; Aho_Corasick_automaton* Answer = new Aho_Corasick_automaton(-1) ;
    for (int i = 1 ; i <= n ; ++i ) scanf("%s",str) , Answer -> Insert(Answer,str) ;
    scanf("%s",substr) ; Answer -> spawn_fail(Answer) ;
    Answer -> Find(Answer,substr) ;
    printf("%d\n",ans) ;
}