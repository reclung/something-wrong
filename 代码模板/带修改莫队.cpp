#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int n,m,l,r,sz,a[350005];
int flag[1000005]={0},Ans[50005]={0},vis[50005]={0},last[50005],ans,now,tot=0,top=0;

struct shu
{
	int l,r,id,pre;
	friend bool operator <(shu a,shu b)
	{
		if(a.l/sz!=b.l/sz) return a.l/sz<b.l/sz;
		if(a.r/sz!=b.r/sz) return a.r/sz<b.r/sz;
		return a.pre<b.pre;
	}
}q[50005];
struct
{
	int o,x,y;
}g[50005];

void up(int x)
{
    if(vis[x])
    {
        if(--flag[a[x]] == 0) ans--;
    }
    else
    {
        if(++flag[a[x]] == 1)ans++;
    }
    vis[x]^=1;
}

void re(int x, int v)
{
    if(vis[x])
    {
        up(x);a[x]=v;up(x);
    }
    else a[x]=v;
}

int main()
{ 
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
   	scanf("%d%d",&n,&m);
   	sz=pow(n,2.0/3.0);
   	for(int i=1;i<=n;i++) 
	{
	   scanf("%d",&a[i]);
	   last[i]=a[i];
	}
   	int x,y;
   	char ch[5];
   	for(int i=1;i<=m;i++)
   	{
   		scanf("%s%d%d",ch,&x,&y);
   		x++; 
   		if(ch[0]=='Q') q[++tot].l=x,q[tot].r=y,q[tot].id=tot,q[tot].pre=top;
        else g[++top].x=x,g[top].y=y,g[top].o=last[x],last[x]=y;
	}
	sort(q+1,q+1+tot);
	l=1,r=0,ans=0,now=0;
	for(int i=1;i<=tot;i++)
	{
		while(now<q[i].pre) ++now,re(g[now].x,g[now].y);
        while(now>q[i].pre) re(g[now].x,g[now].o),--now;
		while(l<q[i].l) up(l++);
		while(l>q[i].l) up(--l);
		while(r>q[i].r) up(r--);
		while(r<q[i].r) up(++r);
		Ans[q[i].id]=ans;
	}
	for(int i=1;i<=tot;i++)
	printf("%d\n",Ans[i]);
   	return 0;
}
