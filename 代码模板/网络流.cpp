#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=1000005;
const ll inf=20000000000005ll;

struct edge
{
	int u,v,next;
	ll f,c;
}e[maxn*10];

int f[maxn],s,t,cur[maxn],d[maxn],cnt=-1,q[maxn*10],n,m;

void add(int u,int v,ll F){
	e[++cnt]=(edge){u,v,f[u],F,0};f[u]=cnt;
	e[++cnt]=(edge){v,u,f[v],0,0};f[v]=cnt;
}

bool bfs(){
	int frond=0,root=0;
	memset(d,0,sizeof(d));
	q[root++]=s;
	d[s]=1;
	while(root!=frond)
	{
		int i=q[frond++];
		for(int k=f[i];k!=-1;k=e[k].next)
		{
			int j=e[k].v;
			if(d[j]||e[k].f==e[k].c) continue;
			d[j]=d[i]+1;
			q[root++]=j;
		}
	}
	return d[t];
}

ll dfs(int i,ll a){
	if(i==t||a==0) return a;
	ll F,flow=0;
	for(int &k=cur[i];k!=-1;k=e[k].next)
	{
		int j=e[k].v;
		if(d[j]==d[i]+1&&(F=dfs(j,min(a,(ll)e[k].f-e[k].c))))
		{
			a-=F;
			flow+=F;
			e[k].c+=F;
			e[k^1].c-=F;
			if(!a) break;
		}
	}
	return flow;
}

ll dinic(){
	ll flow=0;
	while(bfs())
	{
		memcpy(cur,f,sizeof(cur));
		flow+=dfs(s,inf);
	}
	return flow;
}
int main()
{
	scanf("%d%d",&n,&m);
	s=1,t=n*m;
	for(int i=s;i<=t;i++) f[i]=-1;
	int x,y,w;
	for(int i=1;i<=n;i++)
	for(int j=1;j<m;j++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(y,x,w);
		add(x,y,w);
	}
	cout<<dinic();
	return 0;
}
