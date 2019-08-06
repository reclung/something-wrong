#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int maxn=1000005;

struct shu
{
    int x,id,y;
    ll ans;
    friend bool operator <(shu a,shu b)
    {
        return a.y<b.y;
    }
}a[maxn],c[maxn];
int n,m,bit[maxn],b[maxn];

ll lowbit(ll x){
    return x&(-x);
}

void in(ll x){
    for(;x<=n;x+=lowbit(x))
    bit[x]++;
}

void out(ll x){
    for(;x<=n;x+=lowbit(x))
    bit[x]=0;
}

ll find(ll x){
    ll t=0;
    for(;x>=1;x-=lowbit(x))
    t+=bit[x];
    return t;
}

bool cmp(shu a,shu b){
    return a.id<b.id;
}

void CDQ(int l,int r){
    if(l==r) return;
    int m=(l+r)>>1;
    CDQ(l,m);
    CDQ(m+1,r);
    sort(a+l,a+r+1);
    int j=l;
    for(int i=l;i<=r;i++)
    {
        if(a[i].id<=m) in(n+1-a[i].x);
        else a[i].ans+=find(n-a[i].x);
    }
    for(int i=l;i<=r;i++)
    if(a[i].id<=m) out(n+1-a[i].x);
    j=m;
    for(int i=r;i>=l;i--)
    {
        if(a[i].id<=m) in(a[i].x);
        else a[i].ans+=find(a[i].x-1);
    }
    for(int i=l;i<=r;i++)
    if(a[i].id<=m) out(a[i].x);
}
char ch[50];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].x);
        a[i].ans=0;
        a[i].y=i;
        a[i].id=0;
        b[a[i].x]=i;
    }
    int x,t=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&x);
        a[b[x]].id=n+1-i;
    }
    for(int i=1;i<=n;i++) if(a[i].id==0) a[i].id=++t;
    sort(a+1,a+1+n,cmp);
    CDQ(1,n);
    sort(a+1,a+1+n,cmp);
    ll ans=0;
    for(int i=1;i<=n;i++)
    ans+=a[i].ans;
    for(int i=n;i>=n+1-m;i--)
    {
        printf("%d\n",ans);
        ans-=a[i].ans;
    }
    return 0;   
}


