#include<bits/stdc++.h>
 using namespace std;
 
 int fail[10005],n,m,T;
 char a[1000005],b[10005];
 
 void getnext()
 {
 	fail[0]=-1;
 	for(int i=0;i<m;i++)
 	{
 		int k=fail[i];
 		if(k!=-1&&b[i]!=b[k]) k=fail[k];
 		fail[i+1]=k+1;
	 }
 }
 
 int KMP()
 {
 	int ans=0;
 	for(int i=0,j=0;i<n;)
 	{
 		if(j==-1||a[i]==b[j])
 		i++,j++;
 		else 
 		j=fail[j];
 		if(j==m)
 		{
 			ans++;
 			j=0;
		}
	}
	return ans;
  } 
 
 int main()
 {	
 	scanf("%s",a);
 	scanf("%s",b);
 	n=strlen(a),m=strlen(b);
 	getnext();
	printf("%d\n",KMP());
 	return 0;
 }
