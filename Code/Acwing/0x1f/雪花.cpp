#include <bits/stdc++.h>

using namespace std ;

int read(int x = 0,bool f = 0,char ch = getchar()) {
    for (;!isdigit(ch);ch = getchar()) f |= ch == '-' ;
    for (;isdigit(ch);ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48) ;
    return f ? ~ x + 1 : x ;
}

#define same "Twin snowflakes found."
#define dif "No two snowflakes are alike."

const int N = 1e5 + 5 , inf = 1e9 + 7 , base = 1e6 + 7 ;
int n , sum ;
vector<int> v[N] , vec ;
int in[(base << 1) + (base << 2)] ;
int hs[(base << 1) + (base << 2)][10] ;

bool check(vector<int> a,vector<int> b) {
    for (int i = 0 ; i < 5 ; ++i ) {
        if (a[i] != b[i]) return false ;
    } return true ;
}

bool find(vector<int> a) {
    sum = 0 ; for (int i = 0 ; i <= 5 ; ++i ) sum = (sum + a[i]) % base ;
    if (!in[sum]) return false ;
    for (int i = 1 ; i <= in[sum] ; ++i )
        if (check(a,v[hs[sum][i]])) return true ;
    return false ;
}

void change(vector<int> &v) {
    int i = 0 , j = 1 , k = 0 ; vec.clear() ;
    int len = v.size() ;
    while (i < len && j < len && k < len) {
        int t = v[(i + k) % len] - v[(k + j) % len] ;
        if (!t) ++ k ;
        else if (t < 0) {
            j += k + 1 ;
            k = 0 ;
        } else {
            i += k + 1 ;
            k = 0 ;
        }
        if (i == j) ++ j ;
    }
    i = min(i,j) ;
    for (int now = 1 ; now <= len ; ++ now ) vec.push_back(v[(i + now - 1) % len]) ;
    swap(v,vec) ; return void() ;
}

void insert(vector<int> v,int idx) {
    sum = 0 ; for (int i = 0 ; i <= 5 ; ++i ) sum = (sum + v[i]) % base ;
    ++ in[sum] ; hs[sum][in[sum]] = idx ;
    return void() ;
}

signed main() {
    n = read() ;
    for (int i = 1 ; i <= n ; ++i ) {
        for (int j = 1 ; j <= 6 ; ++j )
            v[i].push_back(read()) ;
        change(v[i]) ;
        if (find(v[i])) return puts(same),0 ;
        reverse(v[i].begin(),v[i].end()) ;
        change(v[i]) ;
        if (find(v[i])) return puts(same),0 ;
        insert(v[i],i) ;
    } puts(dif) ;
}