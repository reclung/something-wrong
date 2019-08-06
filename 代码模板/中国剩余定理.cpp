#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath> 
using namespace std;
typedef long long ll;

ll n;
ll a,b,x,y,d,A,B;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if(b==0) {d=a,x=1,y=0;}
    else
    {
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
ll china(ll *a,ll *b,int N)
{
	int ok=0;
	A=a[1],b=b[1];
	for(int i=2;i<=N;i++)
	{
		exgcd(A,a,d,x,y);
		if((b-B)%d)
		{
			ok=1;
		}
		x*=(b-B)/d;
		x=(x%(a/d)+a/d)%(a/d);
		B=x*A+B;
		A=a/d*A;
	}
	if(ok) return -1;
	else return B;
}

int main() 
{
	return 0;
}
