#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=200005;

int n,m,fa[maxn][25],deep[maxn];
int root;

vector<int>g[maxn];

void dfs(int i)//ËãfaÊý×éºÍdeep 
{
	for(int k=1;k<=21;k++)
	if(deep[i]>(1<<k)) 
	fa[i][k]=fa[fa[i][k-1]][k-1];

	int t=g[i].size();
	for(int k=0;k<t;k++)
	{
		int j=g[i][k];
		deep[j]=deep[i]+1;
		dfs(j);
	}
}

int lca(int x,int y)
{
	if(deep[x]<deep[y]) swap(x,y);
	int x1=x,y1=y;
	int k=deep[x]-deep[y];
	for(int i=21;i>=0;i--)
	if(k&(1<<i)) x=fa[x][i];
	
	if(x==y) return deep[x1]-deep[x];
	
	for(int i=21;i>=0;i--)
	if(fa[x][i]!=fa[y][i])
	{
		x=fa[x][i];
	    y=fa[y][i];
	}
	k=fa[x][0];
    return deep[x1]+deep[y1]-2*deep[k];
}

void init()
{
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==0) root=i;
		else 
		{
		g[x].push_back(i);
		fa[i][0]=x;
		}
	}
	
	deep[root]=0;
	dfs(root);
	
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",lca(x,y)); 
	}
}
int main()
{
	init();
	return 0;
}
