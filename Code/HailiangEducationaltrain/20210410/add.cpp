#include <bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x".in","r",stdin) ;freopen(#x".out","w",stdout) ;

int type[2] ;
string s , ss ;

inline void solve() {
    s = s+ss ;
    printf("%s\n",s.c_str()) ;
}

inline void solve2() {
    int a = 0 , b = 0 ;
    for (int i = 0 ; i < s.length() ; ++i ) 
        a = (a<<1) + (a<<3) + (s[i]^48) ;
    for (int i = 0 ; i < ss.length() ; ++i ) 
        b = (b<<1) + (b<<3) + (ss[i]^48) ;
    printf("%d\n",a+b) ;
}

inline void calc() {
    if (type[0] == 1) swap(s,ss) ;
    s = s+ss ;
    printf("%s\n",s.c_str()) ;
}

signed main(int argc,char *argv[]) {
    fre(add) ;
    cin >> s >> ss ;
    for (int i = 0 ; i < s.length() ; ++i ) if(isalpha(s[i])) type[0] = 1 ;
    for (int i = 0 ; i < ss.length() ; ++i ) if(isalpha(ss[i])) type[1] = 1 ;
    if (type[0] == 1 && type[1] == 1)
        solve() ;
    else if (type[0] == 0 && type[1] == 0)
        solve2() ;
    else calc() ;
    fclose(stdin) ; fclose(stdout) ; return 0 ;
}