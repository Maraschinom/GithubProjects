#include <algorithm> 
#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;

#define re register
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define FOR(i,x,y) for(LL i = x ; i <= y ; ++i )
#define ROF(i,x,y) for(LL i = x ; i >= y ; --i )

typedef long long LL ; typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~ u + 1 : u ;
}

inline string get (re string s = "",re char ch = getchar()) {
	for(;!isalpha(ch);ch = getchar()) 0 ;
	for(;isalpha(ch);ch = getchar()) s.push_back(ch) ; return s ;
}

LL T , a , b , c , sum ;

inline LL gcd(LL x,LL y) {return y ? gcd(y,x%y) : x ;}

// const LL half = 180 ;

signed main() {
	fre(cake) ;
	T = read() ;
    for (;T--;) {
        a = read() , b = read() , c = read() ;
        if (!(a|c)) { puts("0") ; continue ; } ;// two empty
        if (!(a|b)) { puts("0") ; continue ; } ; // twp empty
        if (!(b|c)) { puts("0") ; continue ; } ; // two empty
        cerr << a << ' ' << b << ' ' << c << endl ;
        if (a == 0 || b == 0 || c == 0) { // one empty
            if (a == c) { puts("1") ; continue ; } ;
            if (a == b) { puts("1") ; continue ; } ;
            if (b == c) { puts("1") ; continue ; } ;
            { puts("2") ; continue ; } ;
        } else { // everybody needs cake
            if (a + b == c) { puts("2") ; continue ; } ;
            if (a + c == b) { puts("2") ; continue ; } ;
            if (b + c == a) { puts("2") ; continue ; } ;
            if (a == b) { puts("2") ; continue ; } ;
            if (b == c) { puts("2") ; continue ; } ;
            if (a == c) { puts("2") ; continue ; } ;
            { puts("3") ; continue ; } ;
        }
    }
	fclose(stdin) , fclose(stdout) ;
    return 0 ; 
}
/*
6
0 0 8
0 5 3
9 9 0
6 2 4
1 7 4
5 8 5
*/