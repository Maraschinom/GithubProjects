#include <bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin) ;freopen(#x".out","w",stdout) ;

typedef long long LL ;

inline int read (register int x=0,register bool f=0,register char ch=getchar()) {
    for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
    for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return f?~x+1:x;
}

int T , x , y , a , b ;
double score ;

signed main(int argc,char *argv[]) {
    fre(pass) ;
    for (T = read() ; T ; --T) {
        x = read() , y = read() , a = read() , b = read() ;
        score = (int)floor(x * 1.0 * a / 100 + y * 1.0 * b / 100) ;
        if (a+b == 100) {
            if (score >= 60.0) puts("0") ;
            else puts("poor little A!") ;
        } else {
            if ((60.0-score)*100*1.0/(100-a-b) > 100.0) puts("poor little A!") ;
            else printf ("%d\n",std::max((int)ceil((60-score)*100*1.0/(100-a-b)),0)) ;
        }
    }
    fclose(stdin) ; fclose(stdout) ; return 0 ;
}