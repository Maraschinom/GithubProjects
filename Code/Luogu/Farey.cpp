#include<cstdio>
#include<cmath>
 
using namespace std;
 
const int N=100200;
 
int f[N],p[N],mu[N],n,k,s[N],t[N],tot;
 
void getprime(){
    mu[1]=1;
    for(int i=2;i<N;i++){
        if(!f[i]) p[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot;j++){
            if(i*p[j]>=N) break;
            f[i*p[j]]=true;
            if(i%p[j])
                mu[i*p[j]]=-mu[i];
            else{
                mu[i*p[j]]=0;
                break;
            }
        }
    }
}
 
int calc(double x){
    int ans=0;
    for(int i=1;i<=n;i++)
        t[i]=x*i;
    for(int i=1;i<=n;i++)
        if(mu[i])
            for(int j=1;j*i<=n;j++)
                ans+=mu[i]*t[j];
    return ans;
}
 
void find(double x,int &p,int &q){
    p=0,q=1;
    for(int i=1;i<=n;i++){
        int tmp=x*i;
        if(abs(double(p)/double(q)-x)>
            abs(double(tmp)/double(i)-x))
            p=tmp,q=i;
    }
}
 
int main(){
    scanf("%d%d",&n,&k);
    getprime();
    double l=0,r=1;
    while(r-l>1e-9){
        double mid=(l+r)/2;
        if(calc(mid)<k)l=mid;else r=mid;
    }
    int p,q;
    find(r,p,q);
    printf("%d %d\n",p,q);
    return 0;
}