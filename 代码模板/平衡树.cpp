#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;

int a[maxn],ch[maxn][2],fa[maxn],root,n,s[maxn];

void up(int x){
    s[x]=s[ch[x][0]]+s[ch[x][1]]+1;
}

void link(int x,int d,int y){
    fa[y]=x;ch[x][d]=y;
}

void rot(int x){ //��x��Ϊ�� 
    int y=fa[x],z=fa[y];
    int d=(ch[y][0]==x);
    link(y,d^1,ch[x][d]);
    link(z,ch[z][1]==y,x);
    link(x,d,y);
    up(y);
    up(x);
}

void sp(int x){ //��x��תΪ�� 
    int y,z;
    while(fa[x])
    {
        y=fa[x],z=fa[y];
        if(z)
        if((ch[z][1]==y)==(ch[y][1]==x)) rot(y);else rot(x);
        rot(x);
    }
    root=x;
}

int pre() { //�������Ǹ��������������ұߵģ�
    int now=ch[root][0];
    while (ch[now][1]) now=ch[now][1];
    return now;
}

int next(){ //�������Ǹ���������������ߵģ�
    int now=ch[root][1];
    while (ch[now][0]) now=ch[now][0];
    return now;
}

void in(int x,int y){ //�ڸ�Ϊy�����������x 
    int t=y,d;
    while(1)
    {
        if(a[x]<=a[t]) d=0;
        else d=1;
        if(!ch[t][d]) break;
        t=ch[t][d];
    }
    link(t,d,x);
    sp(x);
}

void clear(int x){ //�ѵ�x���������
    fa[x]=ch[x][0]=ch[x][1]=s[x]=0;
}

void del(int x){ //ɾ����x
    sp(x);
    if(!ch[root][0]&&!ch[root][1]) {root=0;return;}
    if(!ch[root][0]) {
        int oldroot=root; root=ch[root][1];fa[root]=0; clear(oldroot); return;
    }
    else if (!ch[root][1]) {
        int oldroot=root; root=ch[root][0];fa[root]=0; clear(oldroot); return;
    }
    int oldroot=root; int leftbig=pre();
    sp(leftbig);
    ch[root][1]=ch[oldroot][1];
    fa[ch[oldroot][1]]=root;
    clear(oldroot);
    up(root);
}

int K(int x,int k){
    int t,p=x;
    while(1)
    {
        t=1;
        if(ch[p][0]) t+=s[ch[p][0]];
        if(t>k) p=ch[p][0];
        else if(t<k) p=ch[p][1],k-=t;
        else break;
    }
    return p;
}

int main()
{
    return 0;
}
