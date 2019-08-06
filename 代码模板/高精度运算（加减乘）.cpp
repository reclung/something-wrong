#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1005;
const int inf=200000000;
int a[maxn]={0},an,b[maxn]={0},bn;
char a1[maxn],a2[maxn];

void input()
{
	an=strlen(a1);
	bn=strlen(a2);
	for(int i=0;i<an;i++)
	a[i]=a1[an-i-1]-'0';
	for(int i=0;i<bn;i++)
	b[i]=a2[bn-i-1]-'0';
}

void add()
{
	int k=max(an,bn);
	int c[maxn]={0};
	for(int i=0;i<k;i++)
	{
		c[i]=a[i]+b[i]+c[i];
		c[i+1]=(int)c[i]/10;
		c[i]=(int)c[i]%10;
	}
	while(!c[k]) k--;
	if(c[k]) k++;
	for(int i=k-1;i>=0;i--)
	printf("%d",c[i]);
	printf("\n");
} 

void sub(int a[],int b[])
{
	int k=max(an,bn),t=0;
	int c[maxn]={0};
	
	if(an<=bn)
	for(int i=bn;a[i]<=b[i]&&i>=0;i--)
	if(a[i]<b[i]) t=1;
	
	if(!t)
	  for(int i=0;i<=k;i++)
	  {
	  	if(a[i]<b[i]) a[i+1]--,a[i]+=10;
	  	c[i]=a[i]-b[i];
	  }	
    else
      for(int i=0;i<=k;i++)
	  {
	  	if(b[i]<a[i]) b[i+1]--,b[i]+=10;
	  	c[i]=b[i]-a[i];
	  }
	while(c[k]==0&&k>0) k--;
	for(int i=k;i>=0;i--)
	printf("%d",c[i]);
	printf("\n");
}

void mul()
{
	int i,j,c[maxn]={0},k;
    k=an+bn-1;
    for(i=0;i<an;i++)
        for(j=0;j<bn;j++)
        {
            c[i+j]=a[i]*b[j]+c[i+j];
            c[i+j+1]=c[i+j]/10+c[i+j+1];
            c[i+j]=c[i+j]%10;
        }
        while(!c[k]) k--;
        for(int i=k;i>=0;i--)
        printf("%d",c[i]);
        printf("\n");
}

int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%s%s",a1,a2);
	input();
	add();
	sub(a,b);
	mul(); 
	return 0;
}

