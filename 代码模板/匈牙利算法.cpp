#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int maxn=1010005;

struct edge
{
    int v,next;
}e[maxn*10];
int f[10005],mx[maxn],state[maxn],fa[maxn]={0},n,cnt=0,T=0;

void add(int u,int v){
    e[++cnt]=(edge){v,f[u]};f[u]=cnt;
}

bool hungary(int x){
    for(int k=f[x];k;k=e[k].next)
    {
        int y=e[k].v;
        if(state[y]!=T)
        {
            state[y]=T;
            if(fa[y]==0||hungary(fa[y]))
            {
                fa[y]=x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,i);add(y,i);
    }
    for(int i=1;i<=10001;i++)
    {
        T++;
        if(!hungary(i))
        break;
    }
    printf("%d\n",T-1);
    return 0;
}
