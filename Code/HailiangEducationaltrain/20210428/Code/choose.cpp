#include <bits/stdc++.h>
using namespace std;

inline int read(register int x=0,register char ch=getchar(),register bool f=0) {
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=true ;
    for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48) ;
    return f ? ~x+1 : x ;
}

inline string reads(register string x="",register char ch=getchar(),register bool f=0) {
    for (;!isalpha(ch);ch=getchar()) continue ;
    for (;isalpha(ch);ch=getchar()) x=x+ch ;
    return x ;
}

#define FILE
#ifdef FILE
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#endif


const int N = 1e5+5 , M = 1e3+5 ;
int n , ans , now ;
string Name[N] , id[N] ;
struct Node {
    int opt ;
    string s ;
    friend bool operator < (Node a,Node b) {return a.s < b.s ;}
} A[N<<1] ;

inline int calc(string a,string b) {
    int ans = 0 ;
    for ( ; ans < std::min(a.length(),b.length()) && a[ans] == b[ans] ; ++ans ) continue ;
    return ans ;
}

inline int findN (int x) {
    int res = x++ ;
    for ( ; x <= n ; ++x ) 
        if (A[x].opt == A[res].opt) return x ;
    return 0 ;
}

signed main() {
    fre(choose) ;
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) A[i].s = Name[i] = reads() ;
    for (int i = 1 ; i <= n ; ++i ) A[i+n].s = id[i] = reads() ;
    for (int i = 1 ; i <= n ; ++i ) A[i].opt = 1 ;
    for (int i = 1 ; i <= n ; ++i ) A[i+n].opt = 2 ;
    sort(Name+1,Name+1+n) ;
    sort(id+1,id+1+n) ;
    sort(A+1,A+1+2*n) ;
    for (int i = 2 ; i <= (n << 1) ; ++i )
        if (A[i].opt != A[i-1].opt) if (calc(A[i].s,A[i-1].s) > calc(A[findN(i)].s,A[i-1].s) && calc(A[i].s,A[i-1].s) > calc(A[i].s,A[findN(i-1)].s)) ans += calc(A[i].s,A[i-1].s) , ++i ;
    printf("%d\n",ans) ;
    return 0 ;
}