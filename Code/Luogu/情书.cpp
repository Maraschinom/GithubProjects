#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>

using namespace std;

#define rep(i,j) for(LL i = 1 ; i <= j ; ++i )

typedef long long LL ;

LL n , g ;
std::string s , ss ;
std::map<string,bool> glossary ;
std::map<string,bool> vis ;

signed main(){
    std::ios::sync_with_stdio(false);
    glossary.clear() ;
    std::cin >> n ;
    rep(i,n){cin >> s ;std::transform(s.begin(),s.end(),s.begin(),::tolower);glossary[s] = true;}
    std::getchar() ;
    std::getline(cin,s) ;
    std::transform(s.begin(),s.end(),s.begin(),::tolower) ;
    for(std::string::iterator it = s.begin() ; it != s.end(); it++ ){
        if(*it == ' ' ) {
            // cout << ss << endl ;
            if(glossary.find(ss) != glossary.end() && vis.find(ss) == vis.end() )
                ++g , vis[ss] = true ;
            ss = "" ;
        }
        else if(*it == ',' ) {
            if(glossary.find(ss) != glossary.end() && vis.find(ss) == vis.end() )
                ++g , vis[ss] = true ;
            ss = "" ;
        }else if(*it == '.' ) {
            if(glossary.find(ss) != glossary.end() && vis.find(ss) == vis.end() )
                ++g , vis[ss] = true ;
            ss = "" ;
            vis.clear() ;
        }
        else ss+= *it ;
    }
    std::cout << g << endl ;
    fclose(stdin),fclose(stdout);
    return 0 ;
}