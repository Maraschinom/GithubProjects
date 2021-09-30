#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
inline void fre()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}
inline int read(){
    register int x=0;
    register bool f=false;
    register char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=true;
    for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    return f?~x+1:x;
}
inline void write(int x)
{
    register char F[200];
    register int tmp=x>0?x:-x ;
    if(x<0)putchar('-') ;
    register int cnt=0;
    if(tmp==0)F[cnt++]='0';
    while(tmp>0){F[cnt++]=tmp%10+'0';tmp/=10;}
    while(cnt>0)putchar(F[--cnt]) ;
}
const int maxn=1e4+5;
int n,a[maxn],sum;
priority_queue < int, vector<int>, greater<int> > q;
signed main()
{
//  fre();
    n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        q.push(a[i]);
    }
    while(q.size()>=2)
    {
        int first=q.top();
        q.pop();
        int second=q.top();
        q.pop();
        q.push(first+second);
        sum+=first+second;
    }
    write(sum);
    putchar('\n');  
    return 0;   
}