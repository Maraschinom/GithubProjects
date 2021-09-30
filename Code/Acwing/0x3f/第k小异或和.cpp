#include <bits/stdc++.h>

using namespace std;

typedef long long LL ;

inline LL read(register LL x=0,register char ch=getchar(),register bool f=false) {
    for (;!isdigit(ch);ch=getchar()) if(ch=='-') f=1 ;
    for (;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48) ; return f ? ~x+1 : x ;
}

const LL N = 105 ;
LL T , n , ans , k , q , idx ;
LL a[N] , p[N] ;

class Linear_basis {
	public :
		LL a[N] , p[N] , tot ;
		
		void insert (LL x) {
			for (LL i = 62 ; ~i ; --i ) {
				if ((1LL<<i)&x) {
					if (!p[i]) { p[i] = x ; break ; } else x ^= p[i] ;
				}
			}
		}
		
        void build () {
            for (LL i = 62 ; ~i ; --i ) {
                if (p[i]) {
                    for (LL j = i + 1 ; j <= 62 ; ++j ) {
                        if ((p[j] >> i) & 1) p[j] ^= p[i] ;
                    }
                }
            }
            for (LL i = 0 ; i <= 62 ; ++i ) {
                if (!p[i]) continue ; 
                p[tot ++] = p[i] ;
            } -- tot ;
        }

		void init () {
			for (LL i = 1 ; i <= n ; ++i ) a[i] = read() ;
			for (LL i = 1 ; i <= n ; ++i ) insert(a[i]) ;
		}
		
		LL kth (LL k) {
			if (k >= (1LL << tot + 1)) return -1 ;
			LL ans = 0 ;
			for (LL i = 62 ; ~i ; --i ) if ((1LL << i) & k) ans ^= p[i] ;
			return ans ;
		}
};

Linear_basis lb ;

signed main() {
    T = read() ;
    while(T --) {
        memset(lb.p,0,sizeof lb.p) ;
        lb.tot = 0 ;
        printf("Case #%lld:\n",++ idx) ;
	    n = read() ;
	    lb.init() ;
	    lb.build() ;
        q = read() ;
        for (LL i = 1 ; i <= q ; ++i ) {
            LL x = read() ;
            if(n != lb.tot + 1) -- x ;
	        ans = lb.kth(x) ,
	        printf("%lld\n",ans) ;
        }
    }
}