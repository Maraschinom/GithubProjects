#include<bits/stdc++.h>
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
LL T , tot ;
LL mobius[N] , prime[N] , sum[N] ;
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
    for (LL i = 1 ; i <= N ; ++i ) sum[i] = sum[i-1] + mobius[i] ;
    return ;
}

inl LL Calc (LL n ,LL m ){
    LL Answer = 0 , Last ;
    if (n > m)  swap(n,m) ;
    for (LL i = 1 ; i <= n ; i = Last+1 ){
		Last = min(n/(n/i),m/(m/i)) ;
        Answer += (sum[Last] - sum[i-1]) * (n/i) * (m/i) ;
    }
    return Answer ;
}

inl LL Solve (LL a,LL b,LL c,LL d){
    LL Answer = 0 ;
    Answer = Calc(a,c)+Calc(b,d)-Calc(a,d)-Calc(b,c) ;
    return Answer ;
}

signed main() {
    // fre() ;
    T = read<LL>() ;
    Mobius() ;
    for (LL Case = 1 , a , b , c , d , k ; Case <= T ; ++Case ){
        a = read<LL>() ;
        b = read<LL>() ;
        c = read<LL>() ;
        d = read<LL>() ;
        k = read<LL>() ;
        --a , --c ;
        a /= k ;
        b /= k ;
        c /= k ;
        d /= k ;
        printf("%LLd\n",Solve(a,b,c,d) ) ;
    }
    fclose(stdin) ;
    fclose(stdout) ;
    return 0 ;
}
