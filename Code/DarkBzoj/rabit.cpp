#include<string.h>
#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
#include<map>

using namespace std;
typedef unsigned long long LL ;
typedef pair<LL,LL> pii ;
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

const LL N = 1e6 + 5 ; 
string s ;
LL Q ;
struct query{
	LL l[2] , r[2] ;
}que;
const LL K = 29 ;
LL H[N] ;
LL pow[N] ;
signed main (){
	fre(test) ;
	cin >> s ;
	Q = read<LL>() ;
	s = " " + s ;
	pow[0] = 1 ;
	for (LL i = 1 ; i <= s.length() ; ++i ){
		H[i] = H[i-1] * K + s[i] - 'a' + 1 ;
		pow[i] = pow[i-1] * K ;
	}
	for (LL i = 1 ; i <= Q ; ++i ){
		que.l[0] = read<LL>() ;
		que.r[0] = read<LL>() ;
		que.l[1] = read<LL>() ;
		que.r[1] = read<LL>() ;
		if(H[que.r[0]]-H[que.l[0]-1] * pow[que.r[0]-que.l[0] + 1] == H[que.r[1]]-H[que.l[1]-1] * pow[que.r[1]-que.l[1] + 1] )
			puts("Yes") ;
		else
			puts("No") ;
	}
	fclose(stdin) ;
	fclose(stdout) ;
	return 0 ;
}
