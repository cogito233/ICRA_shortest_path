#include<bits/stdc++.h>
#define ll long long
inline ll read(){
    char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
    ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
    while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
int n,m,k,a[1010][1010],x,y,xx,yy;
signed main(){
    freopen("/home/cogito/CLionProjects/ICRA_shortest_path/mapdata.in","r",stdin);
    freopen("/home/cogito/CLionProjects/ICRA_shortest_path/map.in","w",stdout);
    n=read();m=read();k=read();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)a[i][j]=0;
    for (int i=1;i<=k;i++){
        x=read();y=read();xx=read();yy=read();
        if (x>xx)swap(x,xx);if (y>yy)swap(y,yy);
        for (int ii=x;ii<=xx;ii++)
            for (int jj=y;jj<=yy;jj++)a[ii][jj]=1;
    }write(n);putchar(' ');writeln(m);
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++)write(a[i][j]);
        puts("");
    }
}
