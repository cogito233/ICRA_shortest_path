//
// Created by cogito on 2021/1/5.
//

#include<bits/stdc++.h>
#include <sys/timeb.h>
#define ll long long
inline ll read(){
    char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
    ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
    while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int N=110,M=210;
int n,m,d,x,y,xx,yy;
char s[N][M];
bool flag[N][M],ff[N][M];
int f[N][M];
pair<int,int>seq[N*M*5],last[M][M],c[4],dd,z[N*M];
void get_map(){
    memset(c,0,sizeof(0));
    memset(s,0,sizeof(s));
    c[0].first=c[2].second=1;
    c[1].first=c[3].second=-1;
    n=read();m=read();
    for (int i=1;i<=n;i++)scanf("%s",&s[i][1]);
    x=read();y=read();xx=read();yy=read();
}/*
void navagation(double x,double y){//to output the next point we need to go
    print("next_point_is: %.10lf %.10lf\b");
}
void check(int x,int y,int xx,int yy){//to check if there is a direct route from x,y to xx,yy
    double dx=,dy=;
    for (double i=x,j=y;i<=xx&&j<=yy;i+=dx,j+=dy){

    }
}*/
pair<int,int> operator+(const pair<int,int> &x, pair<int,int> &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
void SPFA(){//the core part of the shortest path
    int l=0,r=1;seq[r]=make_pair(x,y);
    memset(f,1,sizeof(f));memset(flag,0,sizeof(flag));
    memset(ff,0,sizeof(ff));memset(last,0,sizeof(last));
    f[x][y]=0;
    while (l<r&&r<5*N*M-4){
        l++;for (int i=0;i<4;i++){
            dd=seq[l]+c[i];
            if (s[dd.first][dd.second]=='0'&&f[dd.first][dd.second]>f[seq[l].first][seq[l].second]+1){
                f[dd.first][dd.second]=f[seq[l].first][seq[l].second]+1;
                last[dd.first][dd.second]=seq[l];
                ff[dd.first][dd.second]=1;
                if (!flag[dd.first][dd.second]){
                    seq[++r]=dd;flag[dd.first][dd.second]=1;
                }
            }
        }flag[seq[l].first][seq[l].second]=0;
    }
}
void dfs(int x,int y){//to get the path
    z[++d]=make_pair(x,y);
    if (last[x][y].first!=0)
        dfs(last[x][y].first,last[x][y].second);
}
void output(){
    if (ff[xx][yy]){
        d=0;dfs(xx,yy);writeln(d);
        for (int i=d;i>=1;i--){
            write(z[i].first);putchar(' ');
            writeln(z[i].second);
            s[z[i].first][z[i].second]='2';
        }for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)putchar(s[i][j]);
            puts("");
        }
    }else puts("No such a path");
    //  for (int i=1;i<=n;i++){
    //     for (int j=1;j<=m;j++)write(f[i][j]),putchar(' ');
    //     puts("");
    // }
}
ll getSystemTime(){
    timeb t;
    ftime(&t);`
    return t.time * 1000 + t.millitm;
}

signed main(){
    freopen("/home/cogito/CLionProjects/ICRA_shortest_path/map.in","r",stdin);`
    ll tim=getSystemTime();
    get_map();
    SPFA();
    output();
    writeln(getSystemTime()-tim);
}
//
// Created by cogito on 2021/1/4.
//

