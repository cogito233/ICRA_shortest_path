#include<bits/stdc++.h>
#include <sys/timeb.h>
#define ll long long
#define eps 1e-5
inline ll read(){
    char c=getchar();while (c!='-'&&(c<'0'||c>'9'))c=getchar();
    ll k=0,kk=1;if (c=='-')c=getchar(),kk=-1;
    while (c>='0'&&c<='9')k=k*10+c-'0',c=getchar();return kk*k;
}using namespace std;
void write(ll x){if (x<0)x=-x,putchar('-');if (x/10)write(x/10);putchar(x%10+'0');}
void writeln(ll x){write(x);puts("");}
const int N=110,M=210,C=20;
int n,m,d,x,y,xx,yy;
char s[N][M];
bool flag[N][M],ff[N][M];
double f[N][M],value[N][M];
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
void check(int x,int y,int xx,int yy){
 //to check if there is a direct route from x,y to xx,yy
    double dx=,dy=;
    for (double i=x,j=y;i<=xx&&j<=yy;i+=dx,j+=dy){

    }
}*/
pair<int,int> operator+(const pair<int,int> &x, pair<int,int> &y){
    return make_pair(x.first+y.first,x.second+y.second);
}
void init(){
    int l=0,r=0;
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=m+1;j++){
            value[i][j]=flag[i][j]=0;
            if (s[i][j]!='0'){
                flag[i][j]=1;
                seq[++r]=make_pair(i,j);
            }
        }
    while (l<r){
        l++;for (int i=0;i<4;i++){
            dd=seq[l]+c[i];
            if (dd.first<0||dd.second<0)continue;
            if (s[dd.first][dd.second]=='0'&&!flag[dd.first][dd.second]){
                value[dd.first][dd.second]=value[seq[l].first][seq[l].second]+1;
                seq[++r]=dd;flag[dd.first][dd.second]=1;
            }
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)value[i][j]=1+C/value[i][j];
}
void change_value(int x,int y,int xx,int yy,double d){
    for (int i=x;i<=y;i++)
        for (int j=xx;j<=yy;j++)value[i][j]+=d;
}
void SPFA(){//the core part of the shortest path
    int l=0,r=1;seq[r]=make_pair(x,y);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)f[i][j]=1e15;
    memset(flag,0,sizeof(flag));
    memset(ff,0,sizeof(ff));memset(last,0,sizeof(last));
    f[x][y]=0;
    while (l<r&&r<5*N*M-4){
        l++;for (int i=0;i<4;i++){
            dd=seq[l]+c[i];
            if (s[dd.first][dd.second]=='0'&&f[dd.first][dd.second]+eps>
                f[seq[l].first][seq[l].second]+value[seq[l].first][seq[l].second]){
                f[dd.first][dd.second]=f[seq[l].first][seq[l].second]+value[seq[l].first][seq[l].second];
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
    if (last[x][y].first!=0)
        dfs(last[x][y].first,last[x][y].second);
    z[++d]=make_pair(x,y);
}
void output(){
    if (ff[xx][yy]){
        d=0;dfs(xx,yy);writeln(d);
        for (int i=1;i<=d;i++){
          //  write(z[i].first);putchar(' ');
          //  writeln(z[i].second);
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
    ftime(&t);
    return t.time * 1000 + t.millitm;
}
pair<int,int> zz[N*M];
int top_zz;
pair<int,int> return_next_point(){
    int x=0,y=0,xx[N*M],yy[N*M],now_x=z[1].first,now_y=z[1].second,dd=0;
    cout<<now_x<<' '<<now_y<<endl;
    for (int i=2;i<=d;i++){
        if (z[i].first-z[i-1].first){
            x+=z[i].first-z[i-1].first;
            if (y){
                xx[++dd]=x;yy[dd]=y;x=y=0;
                //cout<<xx[dd]<<' '<<yy[dd]<<endl;
            }
        }if (z[i].second-z[i-1].second){
            y+=z[i].second-z[i-1].second;
            if (x){
                xx[++dd]=x;yy[dd]=y;x=y=0;
                //cout<<xx[dd]<<' '<<yy[dd]<<endl;
            }
        }
    }if (x!=0 or y!=0){
        xx[++dd]=x;yy[dd]=y;x=y=0;
    }
    xx[dd+1]=yy[dd+1]=1e9;
    for (int i=1;i<=dd;){
       // cout<<now_x<<' '<<now_y<<endl;
        int j=i,dx=0,dy=0;
        for (;xx[j]==xx[i]&&yy[j]==yy[i];j++)dx+=xx[j],dy+=yy[j];
        now_x+=dx;now_y+=dy;
        write(now_x);putchar(' ');write(now_y);putchar(' ');puts("This is new route.");
        i=j;zz[++top_zz]=make_pair(now_x,now_y);
    }for (int i=1;i<=dd;i++)xx[i]+=xx[i-1],yy[i]+=yy[i-1];
    return zz[1];
  //  cout<<xx[dd]<<' '<<yy[dd]<<endl;
}
signed main(){
    freopen("/home/cogito/CLionProjects/ICRA_shortest_path/map.in","r",stdin);
    freopen("/home/cogito/CLionProjects/ICRA_shortest_path/map.out","w",stdout);
    ll tim=getSystemTime();
    get_map();
    init();
    SPFA();
    output();
    pair<int,int> qwq=return_next_point();
    write(qwq.first);putchar(' ');writeln(qwq.second);
    writeln(getSystemTime()-tim);
}
//
// Created by cogito on 2021/1/4.
//

