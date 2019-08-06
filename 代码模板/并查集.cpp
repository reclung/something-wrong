#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;

int pa[maxn];

int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}

void un(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py) return;
    pa[py]=px;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    return 0; 
}
