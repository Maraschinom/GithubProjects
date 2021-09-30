/*
Author:@Mukrus
Date:2021/2/5 9:33:34
File:Water Tree.cpp length: 4.01KB
Email:8950466@qq.com
QQ:8950466
Phone number:15355730136
*/
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cctype>
#define clr(s,b) memset(s,(b),sizeof(s))
#define Temp template<typename T>
using namespace std;
typedef long long LL;
#define re register
#define fre(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout);

inline LL read (re LL f = 0,re LL x = 0,re char ch = getchar()){
	for(;!isdigit(ch);ch = getchar()) if(ch=='-') f = 1 ;
	for(;isdigit(ch);ch=getchar()) x = (x<<1) + (x<<3) + (ch^48) ; return f ? ~x + 1 : x ;
}

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)
#define read(x) x = read()

const LL N=5e5+10;
LL n,m,r;
LL tot,Head[N],Next[N<<1],to[N<<1],w[N<<2],wt[N<<2];
LL s[N<<2],lazy[N<<2];
LL son[N],dfn[N],fa[N],Index,dep[N],siz[N],top[N]; 
LL res=0;

inline void add(LL x,LL y){
    to[++tot]=y;
    Next[tot]=Head[x]	;
    Head[x]=tot;
}
inline void pushdown(LL rt,LL lenn){
    if(lazy[rt]){
		lazy[rt<<1]=lazy[rt];
		lazy[rt<<1|1]=lazy[rt];
		if(lazy[rt<<1]==1){ // full
			s[rt<<1]=(lenn-lenn>>1);
		}else s[rt<<1]=0; // empty
		if(lazy[rt<<1|1]==1){
			s[rt<<1|1]=(lenn>>1);  // full   
		}else s[rt<<1|1]=0; // empty
		lazy[rt]=0; // clear
	}
}

inline void build(LL rt,LL l,LL r){
    if(l==r){
        s[rt]=0;
        return;
    }
    build(lson);
    build(rson);
}

inline void query(LL rt,LL l,LL r,LL L,LL R){
    if(L<=l&&r<=R){pushdown(rt,len);res+=s[rt];return;}
    else{
        if(lazy[rt])pushdown(rt,len);
        if(L<=mid)query(lson,L,R); 
        if(R>mid)query(rson,L,R);
		s[rt] = s[rt<<1] + s[rt<<1|1];
    }
}

inline void update(LL rt,LL l,LL r,LL L,LL R,LL k){
    if(L<=l&&r<=R){
        if(k==-1)
            lazy[rt]=-1,s[rt]=0; // -1 empty
        else{
			lazy[rt]=1,s[rt]=len;
		}
		pushdown(rt,len);
    }
    else{
        if(lazy[rt])pushdown(rt,len);
        if(L<=mid)update(lson,L,R,k);
        if(R>mid)update(rson,L,R,k);
        s[rt]=(s[rt<<1]+s[rt<<1|1]);
    }
}

inline void updRange(LL x,LL y,LL k){ 
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,dfn[top[x]],dfn[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,dfn[x],dfn[y],k);
}

inline void dfs1(LL x,LL f,LL deep){
    dep[x]=deep;
    fa[x]=f;
    siz[x]=1;
    LL maxson=-1;
    for(register LL i=Head[x];i;i=Next[i]){
        LL y=to[i];
        if(y==f)continue;
        dfs1(y,x,deep+1);
        siz[x]+=siz[y];
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];
    }
}

inline void dfs2(LL x,LL topf){ 
    dfn[x]=++Index;
    wt[Index]=w[x];
    top[x]=topf;
    if(!son[x])return;
    dfs2(son[x],topf);
    for(register LL i=Head[x];i;i=Next[i]){
        LL y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);
    }
}

signed main(){
//	fre(WaterTree);
    read(n);
    for(register LL i=1;i<n;i++){
        LL s,b;
        read(s);read(b);
        add(s,b);add(b,s);
    }
    r = 1 ;
	Index = 0 ;
    dfs1(r,0,1);
    dfs2(r,r);
    build(1,1,n);
    read(m) ;
    while(m--){
        LL opt,x,y,z;
        read(opt);
        if(opt==1){
            read(x);
            update(1,1,n,dfn[x],dfn[x]+siz[x]-1,1);
			for(LL i = 1 ; i <= n; ++i){res = 0 ;query(1,1,n,i,i);cout<<res<<endl;}
		}
        if(opt==2){
            read(x);
            updRange(x,1,-1);
        }
        if(opt==3){
            read(x);
            res = 0;
            query(1,1,n,dfn[x],dfn[x]) ;
            printf("%lld\n",res);
        }
    }
    return 0;
}
/*
INPUT:
5
1 2
5 1
2 3
4 2
12
1 1
2 3
3 1
3 2
3 3
3 4
1 2
2 4
3 1
3 3
3 4
3 5
*/