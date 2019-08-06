#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
const int maxn=250005;

struct edge
{
    int u,v,w,next;
}e[maxn];
int d[maxn],f[maxn]={0},ch[maxn*33][2]={0},cnt=0,tot=0,n;
int a[33];
bool vis[maxn*33]={0},usd[maxn]={0};

void in(int x)//�ӵ� 
{
    int k=30,p=0,d;
    while(k>=0)
    {
        if(x&a[k]) d=1;
        else d=0;
        if(!ch[p][d]) ch[p][d]=++cnt;
        p=ch[p][d];
        k--;
    }
    vis[p]=1;
}

int findmax(int x)//�Һ�x�������ֵ 
{
    int k=30,p=0,d,y=0;
    while(k>=0)
    {
        if(x&a[k]) d=0;
        else d=1;
        if(!ch[p][d]) d=d^1;
        if(d) x^=a[k];
        p=ch[p][d];
        k--;
    }
    return x;
}

int findmin(int x)//�Һ�x�����С��ֵ 
{
    int k=30,p=0,d,y=0;
    while(k>=0)
    {
        d=(x&a[k])>>k;
        if(!ch[p][d]) d=d^1;
        if(d) x^=a[k];
        p=ch[p][d];
        k--;
    }
    return x;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&n);
    a[0]=1;
    for(int i=1;i<=30;i++) a[i]=a[i-1]*2;
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        in(x);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    ans=max(ans,findmax(d[i]));
    cout<<ans;
    return 0;
}
