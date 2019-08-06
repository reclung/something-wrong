#include<bits/stdc++.h>
using namespace std;

int w[550005],n,m;

void build(int k,int l,int r)
{
	if(l==r) 
	{
		scanf("%d",&w[k]);
		return ; 
	} 
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	w[k]=max(w[k<<1],w[k<<1|1]); 
}

void up(int k,int l,int r,int x,int y)
{
	if(l==r) 
	{
		w[k]=y;
		return ;
	} 
	int mid=(l+r)>>1;
	if(x<=mid) up(k<<1,l,mid,x,y);
	else up(k<<1|1,mid+1,r,x,y);
	w[k]=max(w[k<<1],w[k<<1|1]); 
}

int query(int k,int l,int r,int x,int y)
{
	if(x<=l&&y>=r)  return w[k];
	int mid=(l+r)>>1,t1=0,t2=0;
	if(x<=mid) t1=query(k<<1,l,mid,x,y);
	if(y>mid) t2=query(k<<1|1,mid+1,r,x,y);
	return max(t1,t2);
}

int main()
{	
	int x,y;
	char ch[5];
	while(~scanf("%d%d",&n,&m))
	{
		build(1,1,n);
		
		while(m--)
		{
			scanf("%s%d%d",ch,&x,&y);
			if(ch[0]=='U') up(1,1,n,x,y);
			else printf("%d\n",query(1,1,n,x,y));
		}
	}
	return 0;
 } 
