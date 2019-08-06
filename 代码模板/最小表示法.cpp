#include<bits/stdc++.h>
 using namespace std;
 
 char a[105],b[105];
 int n;
 set<string>q;
 
int getmin()
 {
 	int i=0,j=1,len=strlen(a),k=0;
	while(i<len&&j<len&&k<len)
	{
		int t=a[(i+k)%len]-a[(j+k)%len];
		if(t==0) 
			k++;
		else
		{
			if(t>0)
				i=i+k+1;
			else 
				j=j+k+1;
			if(i==j)j++;
			k=0;
		}
	}
	return min(i,j);
 }
 
 int main()
 {
 	while(~scanf("%d",&n))
 	{
 		int k,m;
 		for(int i=1;i<=n;i++)
 		{
 			scanf("%s",a);
 			k=getmin();
 			m=strlen(a);
 			for(int j=0;j<m;j++) b[j]=a[(j+k)%m];
 			b[m]='\0';
 			q.insert(b);
		 }
		 printf("%d\n",q.size());
		 q.clear();
	 }
 	return 0;
 }
