#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<queue>
using namespace std;
const int maxn=105;
const int maxm=3005;
const int inf=200000000;
struct shu
{
	int u,id;
};
vector<int>g[maxn],w[maxn];
int n,m,d[maxn],vis[maxn]={0},q[maxn*maxn];

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(y);
		w[x].push_back(z);
		g[y].push_back(x);
		w[y].push_back(z);
	}
}

void in()
{
	for(int i=1;i<=n;i++)
	d[i]=inf;
}

void spfa(int x)
{
	int front=0,root=0;
	q[root++]=x;
	vis[x]=1;
	d[x]=0;
	while(front!=root)
	{
		int i=q[front++];
		vis[i]=0;
		for(int k=0;k<g[i].size();k++)
		{
			int j=g[i][k],c=w[i][k];
			if(d[i]+c>=d[j]) continue;
			d[j]=d[i]+c;
			if(vis[j]) continue;
			q[root++]=j;
			vis[j]=1;
		}
	}
}

int main()
{
	init();
	in();
	spfa(1);
	return 0;
}
