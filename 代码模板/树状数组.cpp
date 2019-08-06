#include<bits/stdc++.h>
using namespace std;
const int maxn=60005;

int bit[maxn]={0};

int lowbit(int x){
    return x&(-x);
}

void add(int x,int y,int N){//点x加y 
    for(;x<=N;x+=lowbit(x))
    bit[x]+=y;
}

int getsum(int x){
    int ans = 0;
    for(int i=x;i;i-=lowbit(i))
        ans += bit[i];
    return ans;
}

//求逆序对数 
int b[maxn];
int get_inverse(int N){ 
	int inv=0;
	for(int i=1;i<=N;i++){
    add(b[i]+1,1,N);
    inv+=i-getsum(b[i]+1);
	}
	return inv;
}

int main()
{
    return 0;
}
