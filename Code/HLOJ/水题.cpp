#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m,q,a[500005];
LL sum[500005];
struct node{
	int op,l,r,x;
}c[500005];
struct nade{
	int l,r;
	LL sum,tag;
}tree[2000005];
void build(int x,int l,int r){
	tree[x].l=l;tree[x].r=r;
	if(l==r)return;
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
}
void pudo(int x){
	if(tree[x].tag==-1){
		tree[x].tag=0;
		if(tree[x].l==tree[x].r)return;
		tree[x<<1].tag=tree[x<<1|1].tag=-1;
		tree[x<<1].sum=tree[x<<1|1].sum=0;
		return;
	}
	else{
		if(tree[x<<1].tag==-1&&tree[x<<1].l!=tree[x<<1].r)pudo(x<<1);
		if(tree[x<<1|1].tag==-1&&tree[x<<1|1].l!=tree[x<<1|1].r)pudo(x<<1|1);
		tree[x<<1].sum+=tree[x].tag*(tree[x<<1].r-tree[x<<1].l+1);
		tree[x<<1|1].sum+=tree[x].tag*(tree[x<<1|1].r-tree[x<<1|1].l+1);
		tree[x<<1].tag+=tree[x].tag;
		tree[x<<1|1].tag+=tree[x].tag;
		tree[x].tag=0;
	}
}
void puup(int x){
	tree[x].sum=tree[x<<1].sum+tree[x<<1|1].sum;
}
LL ask(int x,int l,int r){
	if(tree[x].l>=l&&tree[x].r<=r){
		tree[x].tag=-1;
		LL tmp=tree[x].sum;
		tree[x].sum=0;
		return tmp;
	}
	pudo(x);
	LL ans=0;
	if(tree[x<<1].r>=l)ans+=ask(x<<1,l,r);
	if(tree[x<<1|1].l<=r)ans+=ask(x<<1|1,l,r);
	puup(x);
	return ans;
}
void change(int x,int l,int r,LL w){
	if(tree[x].l>=l&&tree[x].r<=r){
		if(tree[x].tag==-1)pudo(x);
		tree[x].sum+=w*(tree[x].r-tree[x].l+1);
		tree[x].tag+=w;
		return;
	}
	pudo(x);
	if(tree[x<<1].r>=l)change(x<<1,l,r,w);
	if(tree[x<<1|1].l<=r)change(x<<1|1,l,r,w);
	puup(x);
}
void last(int x){
	if(tree[x].l==tree[x].r){
		sum[a[tree[x].l]]+=tree[x].sum;
		return;
	}
	pudo(x);
	last(x<<1);
	last(x<<1|1);
	puup(x);
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)scanf("%d%d%d%d",&c[i].op,&c[i].l,&c[i].r,&c[i].x);
	build(1,1,n);
	for(int i=q;i>=1;i--){
		if(c[i].op==1)sum[c[i].x]+=ask(1,c[i].l,c[i].r);
		else change(1,c[i].l,c[i].r,c[i].x);
	}
	last(1);
	for(int i=1;i<=m;i++)printf("%LLd\n",sum[i]);
}
