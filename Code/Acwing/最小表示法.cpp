#include<iostream>
#include<string.h>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long LL ;
typedef pair<int,int> pii ;
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define re register
#define temp template<typename T>

temp
inline T read (T x = 0 , T f = 0){
	re char ch = getchar() ;
	for (;!isdigit(ch);ch = getchar() ) if (ch == '-') f = 1 ;
	for (;isdigit(ch);ch = getchar()) x = (x<<1) + (x<<3) + (ch^48) ;
	return f? ~x+1 : x ;
}
temp
inline void write (T x ){
	putchar(x%10 - 48) ;
	if(x>=10) write (x/10) ;
	return ;
}
inline void Swap (LL &a , LL &b){
	LL tmp = a ;
	a = b ;
	b = tmp ;
}
inline LL Max (LL a , LL b){
	return a>b?a:b ;
}
inline LL Min (LL a , LL b){
	return a<b?a:b ;
}
LL n ;
inline string Get (string S){
	string res = "" ;
//	cerr << res << endl ;
	LL i = 0 , j = 1 , k = 0 , p ;
	while (i < n && j < n && k < n ){
		p = S[(i+k)%n] - S[(j+k)%n] ;
		if(p == 0) ++k ;
		else{
			if(p > 0) i += k + 1 ;
			else j += k + 1 ;
			if(i == j) ++j ;
			k = 0 ;
		}
	}
	LL start = i < j ? i : j ;
//	cerr << start << endl ;
	for (LL j = 0 ; j < n ; ++ j){
		res.push_back(S[(start+j)%n]) ;
	}
	return res ;
}
string s1 , s2 ;
signed main(){
	fre(test) ;
	cin >> s1 >> s2 ;
	n = s1.length() ;
	s1 = Get(s1) ;
	s2 = Get(s2) ;
	puts(s1 == s2?"Yes":"No") ;
	if (s1 == s2) cout << s1 << endl ;
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
