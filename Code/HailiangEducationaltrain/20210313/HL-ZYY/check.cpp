// #pragma GCC diagnostic error "-std=c++11"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cctype>
#include<vector>
#include<set>
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
	for(;ch != ' ' && ch != '\n';ch = getchar()) u += ch; return u ;
}

LL T , ans ;
char map[8][8] ;
class Point{
	public:
	LL x,y ;
};

Point Pown , King ;

signed main() {
	fre(check) ;
	T = read() ;
	while(T--) {
		ans = 0 ;
		for (LL i = 0 ; i < 8 ; ++i )
				scanf("%s",map[i]) ;
		for (LL i = 0 ; i < 8 ; ++i ) 
			for (LL j = 0 ; j < 8 ; ++j )
				if (map[i][j] == 'k') King.x = j+1 , King.y = i+1 ;
				else if (map[i][j] == 'P') Pown.x = j+1 , Pown.y = i+1 ;
		Pown.y-- ;
		if(Pown.x == King.x || Pown.y == King.y) ans += 2 ;
		if((Pown.x - King.x == 2 && abs(Pown.y-King.y) == 1)) ++ ans ;
		if(abs(Pown.x - King.x) == abs(Pown.y - King.y) ) ans += 1 + (abs(Pown.x-King.x)==8) + (abs(Pown.x-King.x)==2) ;
		if(abs(Pown.x - King.x) == 1 && Pown.y == King.y) ++ ans ;
		if(abs(Pown.y - King.y) == 1 && Pown.x == King.x) ++ ans ;
		printf("%lld\n",ans) ;
	}
}