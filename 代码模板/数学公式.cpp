#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;

const ll mod=100000007; 
//gcd 
ll gcd(ll x,ll y){return x==0?y:gcd(y%x,x);}

//扩展欧几里得 ax+by=gcd(a,b)的解 
void exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0) {x=1,y=0;}
    else
    {
        exgcd(b,a%b,y,x);
        y-=x*(a/b);
    }
}

//逆元
ll mod_inverse(ll a,ll mod){
	ll x,y;
	exgcd(a,mod,x,y);
	return (mod+x%mod)%mod;
} 
 
//逆元表
ll inv[maxn];
void get_inverse(int N){
    inv[1]=1;
    for(int i=2;i<N;i++)
    {
        if(i>=mod) break;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
}

//素数筛 
ll p[maxn];
bool is_p[maxn];

void sieve(int N){ 
	int t=0;
	memset(is_p,1,sizeof(is_p));
	for(int i=2;i<=N;i++)
	{
		if(is_p[i]) p[++t]=i;
		for(int j=1;j<=t&&p[j]*i<=N;j++) 
		{
			is_p[p[j]*i]=0;
			if(i%p[j]==0) break;
		}
	}
}

//快速幂
ll qpow(ll a,ll b,ll mod){
    ll ans=1;
    ll k=a;
    while(b){
        if(b&1)ans=ans*k%mod;
        k=k*k%mod;
        b>>=1;
    }
    return ans;
} 

//快速乘
ll qmul(ll a,ll b,ll mod){
    ll ans=0;
    ll k=a;
    ll f=1;//f是用来存负号的
    if(k<0){f*=-1;k=-k;}
    if(b<0){f*=-1;b=-b;}
    while(b){
        if(b&1)
            ans=(ans+k)%mod;
        k=(k+k)%mod;
        b>>=1;
    }
    return ans*f;
} 

//莫比乌斯反演
int mu[maxn],t,p[maxn];
bool is_mu[maxn];

void get_mu(int N){
	memset(is_p,1,sizeof(is_p));
	memset(p,0,sizeof(p));
	t=0,p[1]=1;
	for(int i=2;i<=N;i++)
	{
		if(is_p[i]) {p[++t]=i;mu[i]=-1;}
		for(int j=1;j<=t&&p[j]*i<=N;j++) 
		{
			is_p[p[j]*i]=0;
			if(i%p[j]==0) break;
			mu[i*p[j]]=-mu[i];
		}
	}
}

//求满足 pa/pb<x/y<qa/qb x的最小值  
void work(ll pa,ll pb,ll qa,ll qb,ll &x,ll &y){
	ll z=(pa+pb-1)/pb;
	if(z<=qa/qb){
		x = z;	y = 1;
		return ;
	}
	pa-=(z-1)*pb;	qa-=(z-1)*qb;
	work(qb,qa,pb,pa,y,x);
	x+=(z-1)*y;
}

int main()
{
	
	return 0;
 } 
