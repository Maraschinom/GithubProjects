// #pragma GCC diagnostic error "-std=c++11"
#include <bits/stdc++.h>
using namespace std;

typedef long long LL ;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

inline LL read (register LL f = 0,register LL u = 0,register char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

static const LL N = 3e4 + 5 , M = 26 ;

string s , t ;
LL its , itt , lens , lent ;
char num ;
bool flag ;

inline bool check(char c) {
    LL cnt1 = 0 , cnt2 = 0 ;
    bool flag = false ;
    while (its < lens && s[its] == c || s[its] == '*') {
        if (s[its] == c) ++cnt1 ;
        flag |= (s[its]=='*') ; ++its ;
    }
    while (itt < lent && t[itt] == c) ++cnt2 , ++itt ;
    if (cnt2 < cnt1 || cnt1 < cnt2 && !flag ) return false ;
    return true ;
}

signed main(int argc,char *argv[]) {
    fre(string) ;
    for (register LL T = read() ; T ; --T ) {
        cin >> s >> t ;
        its = itt = 0 ; lens = s.length() , lent = t.length() ;
        if (s[0] == t[0]) flag = true , num = s[0] ;
        if (!flag) {puts("No");continue;}
        while(flag&&its < lens &&itt < lent) {
            flag = check(num) ;
            if (s[its] == t[itt]) num = s[its] ;
            else {puts("No");goto End;}
        }
        puts(flag?"Yes":"No") ;
        End: continue ;
    }
    fclose(stdin),fclose(stdout) ; return 0 ;
}
