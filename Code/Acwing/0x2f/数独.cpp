#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std ;

#define lowbit(x) ((x)&(-x))
#define get(x,y) (((x / 3) * 3) + (y / 3))

const int N = 10 ;

int tot ;
int row[N] , col[N] , lattice[N] , cnt[N] , num[1 << 9] ;
char map[N][N] ; 
char answer[N * N] ;

inline void modify(int x,int y,int digit) {
    row[x] ^= (1 << digit) ;
    col[y] ^= (1 << digit) ;
    lattice[get(x,y)] ^= (1 << digit) ;
}

inline bool dfs(int tot) {
    if (!tot) return true ;
    int number = 10 , sx , sy ;
    for (int i = 0 ; i < 9 ; ++ i)
        for (int j = 0 ; j < 9 ; ++ j) {
            if (map[i][j] != '.') continue ;
            int v = row[i] & col[j] & lattice[get(i,j)] ;
            if (!v) return false ;
            if (cnt[v] < number)
                number = cnt[v] ,
                sx = i , sy = j ;
        }
    int v = row[sx] & col[sy] & lattice[get(sx,sy)] ;
    for (;v;v -= lowbit(v)) {
        int numm = num[lowbit(v)] ;
        map[sx][sy] = '1' + numm ;
        modify(sx,sy,numm) ;
        if (dfs(tot - 1))
            return true ;
        modify(sx,sy,numm) ;
        map[sx][sy] = '.' ;
    } return false ;
}

signed main(int argc,char *argv[]) {
    for (register int i = 0 ; i < 1 << 9 ; ++ i) 
        for (register int j = i ; j ; j -= lowbit(j))
            ++ cnt[i] ;
    for (register int i = 0 ; i < 9 ; ++ i) num[1 << i] = i ;
    while (~scanf("%s",answer) && answer[0] != 'e') {
        for (register int i = 0 ; i < 9 ; ++ i)
            for (register int j = 0 ; j < 9 ; ++ j)
                map[i][j] = answer[i * 9 + j] ;
        for (register int i = 0 ; i < 9 ; ++ i) row[i] = col[i] = lattice[i] = (1 << 9) - 1 ;
        tot = 0 ;
        for (register int i = 0 ; i < 9 ; ++ i)
            for (register int j = 0 ; j < 9 ; ++ j)
                if (map[i][j] != '.') modify(i,j,map[i][j]-'1') ;
                else ++ tot ;
        dfs(tot) ;
        for (register int i = 0 ; i < 9 ; ++ i)
            for (int j = 0 ; j < 9 ; ++ j)
                answer[i * 9 + j] = map[i][j] ;
        puts(answer) ;
    } return 0 ;
}
/*
4.....8.5.3..........7......2.....6.....8.4......1.......6.3.7.5..2.....1.4......
......52..8.4......3...9...5.1...6..2..7........3.....6...1..........7.4.......3.
end
*/