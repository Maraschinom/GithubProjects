#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<queue>

using namespace std;

#define re register 
#define fre(x) freopen(#x".in","r",stdin) ; freopen(#x".out","w",stdout) ;
#define inl inline 
#define f(i,j) for(LL i = 1 ; i <= j ; ++i)

typedef long long LL ; 
typedef pair<LL,LL> PLL ;

inl LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

static const LL N = 5e6 + 5 ;
LL n , opt , ans ;
LL f[N] , a[N] , prufer[N] , cnt[N] ;
PLL point[N] ;
priority_queue<PLL,vector<PLL>,greater<PLL> > Q ; 

inl void TP(){
    f(i,n-1){
        f[i] = read() ;
        ++point[f[i]].first ;
        point[i].second = i ;
    }
    point[n].second = n ;
    f(i,n)if(!point[i].first) Q.push(point[i]) ;
    f(i,n-2){
        PLL tmp  = Q.top() ;
        Q.pop() ;
        prufer[i] = f[tmp.second] ;
        --point[f[tmp.second]].first ;
        if(!point[f[tmp.second]].first) Q.push(point[f[tmp.second]]) ;
        ans ^= i*prufer[i] ;
    }
    printf("%lld\n",ans) ;
}
inl void PT(){
    f(i,n-2){
        prufer[i] = read() ;
        ++cnt[prufer[i]] ;
    }
    prufer[n-1] = n ;
    for(LL i = 1 , j = 1 ; i < n ; ++i , ++j ){
        while(cnt[j]) ++j ;
        f[j] = prufer[i] ;
        --cnt[prufer[i]] ;
        while(i<n&&!cnt[prufer[i]]&&prufer[i]<j){
            f[prufer[i]] = prufer[i+1] , ++i ;
            --cnt[prufer[i]] ;
        }
    }
    for(LL i = 1 ; i <= n ; ++i ) ans ^= i * f[i] ;
    printf("%lld\n",ans) ;
}

signed main(){
	n = read() ;
	opt = read() ;
    !(--opt)?TP():PT();
	fclose(stdin) ;	fclose(stdout) ;
	return 0 ;
}	