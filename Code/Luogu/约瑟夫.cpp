#include<bits/stdc++.h>
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

const int N = 105 ;
int n , mod ;
list<int>mylist ;

signed main(){
	n = read<int>() ;
	mod = read<int>() ;
	for(int i = 1 ; i <= n ; ++i ){
		mylist.push_back(i) ;
	}
	while(!mylist.empty()){
		int num = 1 ;
		while (num <= mod){
			for(list<int>::iterator it = mylist.begin();it != mylist.end();it++){
//				cerr << *it << ' ' << num << endl ;
				if(!(num++%mod)) {
					cout << *it << ' ' ;
					num -= mod ;
					it = mylist.erase(it) ;
					it -- ;
				}
				else if(mylist.size() == 1) { it = mylist.begin(); cout << *it << endl ; return 0 ;} 
			}
		}
		
	}
}
