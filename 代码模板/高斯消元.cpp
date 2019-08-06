#inlcude<bits/stdc++.h>
using namespace std;
const int maxn=105;

double a[maxn][maxn];
double x[maxn];

void gauss(int n,int m)
{
    int i=0,j=0,k,r,c;
    while(i<n&&j<m)
    {
        r=i;
        for(k=i+1;k<n;k++) if(fabs(a[k][j])>fabs(a[r][j])) r=k;

        if(r!=i)
        for(k=j;k<=n;k++) swap(a[r][k],a[i][k]);

        if(fabs(a[i][j])>0)
        {
            for(k=i+1;k<n;k++)
            {
                double f=a[k][j]/a[i][j];
                for(c=j;c<=n;c++)
                a[k][c]-=f*a[i][c];
            }
            i++;
        }
        j++;
    }
    for(i=n-1;i>=0;i--)
    {
        for(j=i+1;j<=n;j++)
        a[i][m]-=a[i][j]*x[j];
        x[i]=a[i][m]/a[i][i]; 
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    for(int j=0;j<=n;j++) scanf("%lf",&a[i][j]);

    gauss(n,n);

    for(int i=0;i<n;i++)
    printf("%d ",(int)(x[i]+0.5));
    return 0;
}
