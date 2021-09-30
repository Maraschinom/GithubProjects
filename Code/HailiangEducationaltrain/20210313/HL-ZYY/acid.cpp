// #pragma GCC diagnostic error "-std=c++11"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<cstring>

using namespace std;

#define re register

#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;

#define inl inline 

typedef long long LL ;
typedef pair<LL,LL> PLL ;

inline LL read (re LL f = 0,re LL u = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch = getchar()) u = (u<<1) + (u<<3) + (ch^48) ; return f ? ~u + 1 : u ;
}

inline string get (re string u = "",re char ch = getchar()) {
	for(;ch == ' ' || ch == '\n';ch = getchar()) 0 ;
	for(;(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z');ch = getchar()) u += ch; return u ;
}

static const LL N = 1e4+5 ;
LL Q ;
string s ; 

signed main() {
	fre(acid) ;
	Q = read() ;
	for (LL i = 1 ; i <= Q ; ++i) {
		s = get() ;
		LL len = s.length() ;
		if (len < 7) {
			if (s[len-1] == 'c' && s[len-2] == 'i') puts("polyatomic acid") ;
			else puts("not an acid") ;
		} else {
			if (s[len-1] != 'c' || s[len-2] != 'i') puts("not an acid") ;
			else if (s[0] == 'h'&& s[1] == 'y'&& s[2] == 'd'&& s[3] == 'r'&& s[4] == 'o') puts("non-metal acid") ;
			else puts("polyatomic acid") ;
		}	
	}
}
/*
Input :
3
hydrochloric
rainbowic
idontevenknow
Output :
non-metal acid
polyatomic acid
not an acid
*/