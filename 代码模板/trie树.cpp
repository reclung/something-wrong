#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int maxn=50000*50+5;

int m[maxn][52]={0},cnt=0,root=0,v[maxn]={0},n,mm;
char s[55];
int r(char ch)
{
    if(ch>='A'&&ch<='Z') return ch-'A';
    if(ch>='a'&ch<='z') return ch-'a'+26;
}
void in(int &now,int i,char *ch)//加入单词
{
    if(!now) now=++cnt;
    if(!ch[i])
    {
        v[now]++;
        return;
    }
    int d=r(ch[i]); 
    in(m[now][d],i+1,ch);
}
void init()
{
    scanf("%d%d",&n,&mm);
    char ch[55];
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ch);
        in(root,0,ch);
    }
}
void work(int now,int i)//输出这棵树
{
    if(v[now]) 
    {
        s[i]=0;
        printf("%s\n",s);
    }
    for(int k=0;k<52;k++) if(m[now][k])
    {
        s[i]= k<26? k+'A':k-26+'a';
        work(m[now][k],i+1);
    }
}
int find(char *ch)//找单词
{
    int now=root;
    for(int i=0;ch[i];i++)
    {
        int d=r(ch[i]);
        if(!m[now][d]) return 0;
        now=m[now][d];
    }
    return v[now];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    work(root,0);
    printf("\n");
    char ch[55];
    int id;
    for(int i=1;i<=mm;i++)
    {
        scanf("%s",ch);
        printf("%d\n",find(ch));
    }
    return 0;
}
