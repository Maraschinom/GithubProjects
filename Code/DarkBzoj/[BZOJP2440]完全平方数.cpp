#include <string.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

// --------------------------------------------------------------------

typedef long long LL ;
typedef unsigned long long ULL ;
typedef unsigned int Uint ;
typedef pair<LL,LL> PLL ;

// --------------------------------------------------------------------

#define re register 
#define TEMP template<typename T>
#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);
#define lowbit(x) (x)&(~x+1)
#define inl inline
#define Clear(x,y) memset(x,y,sizeof x)
#define mk make_pair

// --------------------------------------------------------------------

TEMP
inl T read ( re T x = 0 , re T f = 0 ){
	re char ch = getchar() ;
	for (;!isdigit(ch);ch = getchar() ) if(ch == '-') f = 1 ;
	for (;isdigit(ch);ch = getchar() ) x = (x << 1) + (x << 3) + (ch ^ 48) ;
	return f ? ~x+1 : x ;
}

TEMP
inl T MAX ( re T a , re T b ){
	return a > b ? a : b ;
}

TEMP
inl T MIN ( re T a , re T b ){
	return a < b ? a : b ;
}

TEMP
inl T ABS ( re T a ){
	return a > 0 ? a : -a ;
}

inl void SWAP_INT ( re int a , re int b ){
	re int tmp = a ;
	a = b ;
	b = a ;
	return ;
}

inl void SWAP_LL ( re LL a , re LL b ){
	re LL tmp = a ;
	a = b ;
	b = a ;
	return ;
}

const LL N = 5e4 + 5 ;
LL Answer , n , l , r , mid ;
LL T , tot ;
LL mobius[N] , prime[N] ;
bool mark[N] ;

inl void Mobius()
{
    mobius[1] = 1 ;
    for(LL i = 2 ; i <= N ; ++i )
    {
		if (!mark[i]) prime[++tot] = i , mobius[i] = -1 ;
		for (LL j = 1 ; j <= tot && prime[j] * i <= N ; ++j )
		{
			mark[i*prime[j]] = 1 ;
			if (i%prime[j] == 0) {mobius[i*prime[j]] = 0 ; break ; }
			else mobius[i*prime[j]] = -mobius[i] ;
		}
    }
    return ;
}

inl LL chk (LL x)
{
    LL sum = 0 ;
    LL t = sqrt(x) ;
    for (LL i = 1 ; i <= t ; ++i )
		sum += x / (i*i) * mobius[i] ;
    return sum;
}

inl LL Dichotomous (LL x){
    l = x , r = 1644934081 ;
    while (l <= r){
        mid = l + r >> 1 ;
        chk(mid) >= x ? Answer = mid , r = mid - 1 : l = mid + 1 ;
    }
    return Answer ;
}

signed main () {
    // fre() ;
    Mobius() ;
    T = read<LL>() ;
    for (LL Case = 1 ; Case <= T ; ++Case ){
        n = read<LL>() ;
        printf( "%LLd\n",Dichotomous(n) ) ;
    }
    fclose(stdout) ;
    fclose(stdin) ;
    return 0 ;
}