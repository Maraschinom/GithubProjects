#include<string.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;
typedef long long LL ;
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
const LL N = 1e6+5 ;
string s1 , s2 ; 
LL len1 , len2 ;
LL Next[N] ;
vector<LL> ans ;
inline void KMP(){
	LL k = 0 ;
	for(LL i = 2 ; i <= len1 ; ++i ){
		while(k && s1[i] != s2[k+1] ) k = Next[k] ;
		if(s2[k+1] == s1[i] ) ++k ;
		if(k == len2 ){
			ans.push_back(i - k);
			k = Next[k] ;
		}
	}
	return ;
}
inline void Getnext(){
	Next[0] = 0 ;
	LL k = 0 ;
	for(LL i = 2 ; i <= len2 ; ++i ){
		while(k && s2[k+1] != s2[i] ) k = Next[k] ;
		if(s2[k+1] == s2[i]) ++k ;
		Next[i] = k ; 
	}
	return ;
}
signed main(){
	cin >> s1 >> s2 ;
	s1 = ' ' + s1 ;
	s2 = ' ' + s2 ; 
	len1 = s1.length() - 1 ;
	len2 = s2.length() - 1 ;
	Getnext() ;
	KMP() ;
	if(ans.size())
		for(LL i:ans){
			printf("%LLd\n",i+1) ;
		}
//	printf("`````````````````") ;
	for(LL i = 1 ; i <= len2 ; ++i){
		printf("%LLd ",Next[i]<0?0:Next[i]) ;		
	}
	return 0; 
}
