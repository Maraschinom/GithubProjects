#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define re register
#define fre(x) freopen( #x".in","r",stdin ) ; freopen( #x".out","w",stdout ) ;
#define lowbit (x)&(~x+1)
#define int long long
template< class T >
T read(T sum = 0 ){
	re bool f = false ;
	re char c = getchar () ;
	for(; !isdigit ( c ) ; c = getchar () ) if ( c == '-' ) f = true ;
	for(; isdigit ( c ) ; c = getchar () ) sum = ( sum << 1 ) + ( sum << 3 ) + ( c xor 48 ) ;
	return f ? ~sum+1 : sum ;
}
typedef pair<int,int> pii ;
const long long N= 2e1+5;
const int dx [] = { 0 , 0 , -1 , 1 } ;
const int dy [] = { -1 , 1 , 0 , 0 } ;
const int dirt_p[] = { 'n' , 's' , 'w' , 'e' } ;
const int dirt_b[] = { 'N' , 'S' , 'W' , 'E' } ;
int n = 0 , m = 0 , T = 0 ;
int px = 0 , py = 0 , bx = 0 , by = 0 , hx = 0, hy = 0 ; 
bool can = false ;
char mp [ N ] [ N ] ;
bool vis [ N ] [ N ] ;
queue < vector< int > > ct ;
inline void b_bfs () {
	memset ( vis ,0 ,sizeof vis ) ;
	while (ct.size () )
		ct.pop();
	queue < pii > Q ;
	while (Q . size () )
		Q.pop () ;
	vector <int> vec={};
	Q . push ( make_pair ( bx , by ) ) ;
	ct . push ( vec );
	while ( Q . size () ){
		pii u =  Q .front () ;
    	Q . pop () ;
		vector <int> v = ct . front () ;
		ct . pop () ;
		if ( u.first == hx && u.second == hy ){
			can = true ;
			ct . push ( v ) ; 
			return ;
		}
		for (int dir = 0 ; dir < 4 ; ++ dir ){
			int xx = u . first + dx [ dir ] ;
			int yy = u . second + dy [ dir ] ;
			int lx = u . first - dx [ dir ] ;
			int ly = u . second - dy [ dir ] ;
			if ( ly > 0 && lx > 0 && ly <= n && lx <= m &&  mp [ ly ] [ lx ] != '#' )
				if ( yy > 0 && xx > 0 && yy <= n && xx <= m &&  mp [ yy ] [ xx ] != '#' && ! vis [ xx ] [ yy ] )
					Q. push ( make_pair ( xx , yy ) ) , vis [ xx ] [ yy ] = true ,v.push_back ( dir ) ,ct . push ( v ),v.erase ( v.end() - 1 , v.end() ) ;
			
		} 
	} 
}
inline void bfs ( int sx ,int sy ,int ex ,int ey) {
	memset ( vis ,0 ,sizeof vis ) ;
	while (ct.size () )
		ct.pop(); 
	queue < pii > Q ;
	while ( Q .size () )
		Q.pop () ;
	vector <int> vec={};
	Q . push ( make_pair ( sx , sy ) ) ;
	ct . push ( vec );
	while ( Q . size () ){
		pii u =  Q .front () ;
		Q . pop () ;
		vector <int> v = ct . front () ;
		ct . pop () ;
		if ( u.first == ex && u.second == ey ){
			ct . push ( v ) ;
			return ;
		}
		for (int dir = 0 ; dir < 4 ; ++ dir ){
			int xx = u . first + dx [ dir ] ;
			int yy = u . second + dy [ dir ] ;
				if ( yy > 0 && xx > 0 && yy <= n && xx <= m &&  mp [ yy ] [ xx ] != '#' && ! vis [ xx ] [ yy ] )
					Q. push ( make_pair ( xx , yy ) ) , vis [ xx ] [ yy ] = true ,v.push_back ( dir ) ,ct . push ( v ),v.erase ( v.end()-1 , v.end() );
		}
	}
	return ;
}
signed main ()
{
	while ( ++T ){
		memset(mp,' ',sizeof mp);
		n = read<int>() ;
		m = read<int>() ;
		can = false ;
		if (! (n | m) ) 
			return 0 ;
		printf ( "Maze #%lld\n" , T ) ;
		for ( int i = 1 ; i <= n ; ++ i ){
			for ( int j = 1 ; j <=m ; ++ j ){
				mp [ i ] [ j ] = getchar () ;
				if ( mp [ i ] [ j ] == 'S' ) px = j , py = i ;
				if ( mp [ i ] [ j ] == 'T' ) hx = j , hy = i ;
				if ( mp [ i ] [ j ] == 'B' ) bx = j , by = i ;
			}
			getchar () ; 
		}
		can = false ;
		b_bfs () ;
		if ( ! can ){
			puts ( "Impossible." ) ;
			continue ; 
		}else {
			while ( ct .size () > 1) ct .pop () ;
			vector <int> ans=ct.front();
			int _x = bx , _y = by ;
			mp [ _y ] [ _x ] = '#';
			bfs ( px , py , bx - dx [ ans [ 0 ] ] , by - dy [ ans [ 0 ] ]) ;
			mp [ _y ] [ _x ] = 'B';
			while ( ct .size () > 1) ct . pop () ;
			vector <int> anss = ct.front();
			for (int i = 0 ;i < anss.size () ;++i){
				putchar(dirt_p [ anss [i] ] ) ;
			}
			putchar(dirt_b [ ans [ 0 ] ] ) ;
			for(int i = 1 ; i < ans .size () ; ++ i)	{
				if ( ans [i] != ans [ i-1 ] ){
					mp [ _y ] [ _x ] = '#';
					bfs ( _x - dx [ ans [ i-1 ] ], _y - dy [ ans [ i-1 ] ], _x + dx [ ans [ i-1 ] ] - dx [ ans [ i ] ] , _y + dy [ ans [ i-1 ] ] - dy [ ans [ i ] ] ) ;
					mp [ _y ] [ _x ] = '.';
					while ( ct .size () > 1) ct . pop () ;
					vector <int> anss = ct.front();
					for (int i = 0 ;i < anss.size () ;++i){
						putchar(dirt_p [ anss [i] ] ) ;
					}
				}
				putchar( dirt_b [ ans [ i ] ] ) ;
				_x += dx [ ans [ i ] ] , _y += dy [ ans [ i ] ] ;
			}
			puts("\n");
		}
	}
	return 0;
}