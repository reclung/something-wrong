#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
const int inf=20000005;

struct edge
{
	int u,v,f,c,w;
};

struct shu
{
	int id,sum;
	friend bool operator <(shu a,shu b)
	{
		return a.sum<b.sum;
	}
};
vector<edge>e;
vector<int>g[maxn];
int n,m,s,t,cnt=-1,d[maxn],fa[maxn];

void add(int u,int v,int f,int w)
{
	e.push_back((edge){u,v,f,0,w});
	g[u].push_back(++cnt);
	e.push_back((edge){v,u,0,0,-w});
	g[v].push_back(++cnt);
}

int dij()
{
	priority_queue<shu>q;
	for(int i=s;i<=t;i++) d[i]=-1;
	fa[s]=-1;
	d[s]=0;
	q.push((shu){s,0});
	while(!q.empty())
	{
		shu p=q.top();q.pop();
		int i=p.id;
		if(d[i]>p.sum) continue;
		d[i]=p.sum;
		int tt=g[i].size();
		for(int k=0;k<tt;k++)
		{
			int id=g[i][k],j=e[id].v;
			if(d[j]>=d[i]+e[id].w||e[id].f==e[id].c) continue;
			fa[j]=id;
			d[j]=d[i]+e[id].w;
			q.push((shu){j,d[j]});
		}
	}
	return d[t];
}

int dinic()
{
	int cost=0,f,flow=0;
	while(1)
	{
		f=dij();
		if(f<=0) break;
		cost+=f;
		flow++;
		int id=fa[t];
		while(id!=-1)
		{
			e[id].c++;
			e[id^1].c--;
			id=fa[e[id].u];
		}
	}
	return cost;
}
void init()
{
	scanf("%d%d",&n,&m);
	int x,k;
	s=0,t=n*n*2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x);
			k=(i-1)*n+j;
			add(k,k+n*n,1,x);
			add(k,k+n*n,m-1,0);
			if(i<n) add(k+n*n,k+n,m,0);
			if(j<n) add(k+n*n,k+1,m,0);
		}
	}
	add(s,1,m,0);
}
int main()
{
	init();
	printf("%d\n",dinic());
	return 0;
}
