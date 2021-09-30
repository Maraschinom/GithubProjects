#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps=1e-5;
inline int read(){
    register int x=0;
    register bool f=false;
    register char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=true;
    for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    return f?~x+1:x;
}
const int maxn=1e5+5;
int n,f,a[maxn];
double sum[maxn],minv;
inline void summ(double x){
    sum[0]=0;
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i]-x;
    return;
}
inline double Min(double a,double b){return a>b?b:a;}
inline double Max(double a,double b){return a>b?a:b;}
inline bool check(double x){
    double minv=0;
    summ(x);
    for(int i=0,j=f;j<=n;j++,i++){
        minv=Min(minv,sum[i]);
        if(sum[j]>=minv) return true;
    }
    return false;
}
signed main(){
    n=read();
    f=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    double l=0.0,r=2000.0;
    while(l+eps<r){
        double mid=(l+r)/2;
        if(check(mid))  
            l=mid;
        else
            r=mid;
    }
    printf("%d\n",(int)(r*1000));
    return 0;
}