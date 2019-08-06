#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=405;
const int inf=4000005;
int d1[maxn][maxn],n,m,g[maxn][maxn],d2[maxn][maxn],d3[maxn][maxn];//d1最短路径,d2最大边最小,d3最小边最大。 

void init()
{
	scanf("%d%d%d",&n,&m);
	for(int i=1;i<=n;i++)//初值 
	for(int j=1;j<=n;j++)
	{
		if(i==j) g[i][j]=0;
		else g[i][j]=inf;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		g[x][y]=z;
		g[y][x]=z;
	}
}

void floyd()
{
	memcpy(d1,g,sizeof(d1));
	memcpy(d2,g,sizeof(d2));
	memcpy(d3,g,sizeof(d3));
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(d2[i][j]==inf)
	d2[i][j]=-inf;
	
    for(int k=1;k<=n;k++) 
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
       if(d1[i][k]+d1[k][j]<d1[i][j])
         d1[i][j]=d1[i][k]+d1[k][j];
         
       int x=min(d2[i][k],d2[k][j]);
       d2[i][j]=max(d2[i][j],x);
         
         
       int  t=max(d3[i][k],d3[k][j]); 
        d3[i][j]=min(d3[i][j],t); 
    }
}
int main()
{
	init();
	floyd();
	return 0;
}
