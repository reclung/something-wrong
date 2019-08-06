#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;

int n,m,l,r,sz,a[100005];
int flag[100005]={0},Ans[100005]={0},ans;

struct shu
{
	int l,r,id;
	friend bool operator <(shu a,shu b)
	{
		if(a.l/sz==b.l/sz) return a.r<b.r;
		else return a.l/sz<b.l/sz;
	}
}q[500005];

void add(int x)
{
	if(a[x]>100000) return; 
	if(flag[a[x]]==a[x]) ans--;
	flag[a[x]]++;
	if(flag[a[x]]==a[x]) ans++;
}

void del(int x)
{
	if(a[x]>100000) return; 
	if(flag[a[x]]==a[x]) ans--;
	flag[a[x]]--;
	if(flag[a[x]]==a[x]) ans++;
}

int main()
{ 
   	scanf("%d%d",&n,&m);
   	sz=sqrt(n);
   	l=1,r=0,ans=0;
   	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
   	for(int i=1;i<=m;i++)
   	{
   		scanf("%d%d",&q[i].l,&q[i].r);
   		q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1;i<=m;i++)
	{
		while(l<q[i].l) del(l++);
		while(l>q[i].l) add(--l);
		while(r>q[i].r) del(r--);
		while(r<q[i].r) add(++r);
		Ans[q[i].id]=ans;
	}
	for(int i=1;i<=m;i++)
	printf("%d\n",Ans[i]);
   	return 0;
}
