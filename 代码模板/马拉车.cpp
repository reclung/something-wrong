#include<bits/stdc++.h>
 using namespace std;
 
 char a[200005],ch[5],b[500005];
 int d[500005];
 
 int main()
 {
 	while(~scanf("%s",a))
 	{
 		int n=0,m;
 		m=strlen(a);
 		b[0]='&';
 		for(int i=0;i<m;i++)
 		{
 			b[++n]='#';
 			b[++n]=a[i];
		}
		b[++n]='#';
		int r=0,pos=0,mx=0;
		for(int i=1;i<=n;i++)
		{
		 	if(i<r) d[i]=min(d[2*pos-i],r-i);
		 	else d[r=i]=1;
		 	while(b[i-d[i]]==b[i+d[i]]) d[i]++;
		 	if(i+d[i]>r) r=i+d[i],pos=i;
		 	if(d[i]>mx) mx=d[i];
		}
			printf("%d\n",mx-1);
	}
 	return 0;
 }
