#include<bits/stdc++.h>
using namespace std;
#define add(a,b) ((a)+(b))
#define mult(a,b) ((a)*(b)%10000)
#define re register 
typedef long long LL ;
stack<LL> nums ;
stack<char> op ;
map<char,LL> pri ;
string poly ;
bool f ;
inline void calc(LL p) {
	while(!op.empty()&&pri[op.top()]>=p) {
		LL b = nums.top() ;
		nums.pop();
		LL a = nums.top() ;
		nums.pop();
		char c = op.top();
		op.pop() ;
		if(c == '*') nums.push(mult(a,b)) ;
		else if(c == '+') nums.push(add(a,b)) ;
	}
}
signed main() {
	pri['+'] = 0 ;
	pri['*'] = 1 ;
	cin >> poly ;
	for(LL i = 0; i < poly.length(); ++i) {
		if(poly[i] == '+' || poly[i] == '*' ){
			if(op.empty()||pri[poly[i]]>pri[op.top()]) {
				op.push(poly[i]) ;
			} else {
				calc(pri[poly[i]]) ;
				op.push(poly[i]) ;
			}
		}
		else if(isdigit(poly[i])){
			re LL x = 0 ;
			f = 0 ;
			for(;isdigit(poly[i]);++i) x = (x<<1) + (x<<3) + (poly[i]-'0') ;
			i-=1 ;
			nums.push(f? ~x+1 : x ) ;
		}
	}
	calc(-3) ;
	LL ans=nums.top()%10000;
	printf("%LLd\n",ans);
	return 0 ; 
}
map < pair < pair <int , pair <int , pair <int , pair < int , pair<int,int> > > > > > > ; 
