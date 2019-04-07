#include<bits/stdc++.h>
using namespace std;
#define LOL ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define pii pair<int ,int>
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
const double MAX=100000000000000.00;
double dist[10][10];
int n;
int high;
double dp[256][10];
int parent[10];
int pp[10];
pii pr[12];
struct node
{
    int a,b;
    node(int A,int B){a=A,b=B;}
    node(){};
};
node direction[256][10];
double distan(pii a,pii b)
{
    double x=abs(a.f-b.f);
    double y=abs(a.s-b.s);
    x=x*x,y=y*y;
    return (sqrt(x+y)+16.00);
}
double cholo(int mask,int in)
{
    if(mask==high)  {
        direction[mask][in].a=mask;
        direction[mask][in].b=in;
        return 0.00;
    }
    if(dp[mask][in] != -1.00)  return dp[mask][in];
    double p,q;
    double mxx=MAX;
    for(int i=0;i<n;i++){
        if(check(mask,i)==false){
            p=cholo(Set(mask,i),i)+dist[in][i];
            if(p<mxx){
               direction[mask][in].a=Set(mask,i);
               direction[mask][in].b=i;
                mxx=p;
            }
        }
    }
    dp[mask][in]=mxx;
    return mxx;

}
void print(int p,int q)
{
    int _a=direction[p][q].a;
    int _b=direction[p][q].b;
    if(_a==p && _b==q) return ;
    else{

        cout<<setprecision(2)<<fixed<<"Cable requirement to connect ("<<pr[q].f<<","<<pr[q].s<<") to ("<<pr[_b].f<<","<<pr[_b].s<<") is "<<(dist[q][_b])<<" feet."<<endl;
        print(_a,_b);
    }
}
int main()
{
    LOL
    int a,b,c,x,y,i,j,k,q,p,sum,ct,ct1,l,r,len,x1,y1,mn,mx,ans,h,sum1,start,s_a,s_b,m,mm;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    while(cin>>n && n)
    {
        for(i=0;i<n;i++){
            cin>>x>>y;
            pr[i]=mk(x,y);
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)  dist[i][j]=dist[j][i]=distan(pr[i],pr[j]);
        }
        high=(1<<n)-1;

        for(i=0;i<=high;i++) {
            for(j=0;j<n;j++) direction[i][j].a=i,direction[i][j].b=j,dp[i][j]=-1.00;
        }
        double mxx=MAX;
        int mask=0;
        for(j=0;j<n;j++){
        m=mask;
        m=Set(m,j);
        for(i=0;i<n;i++){
            if(check(m,i)==false){
            d=cholo(Set(m,i),i)+dist[j][i];
            if(d<mxx){
                    s_a=j;
                    mm=m;
                direction[m][j].a=Set(m,i);
                direction[m][j].b=i;
                mxx=d;
            }
            }
        }
        }
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<cs<<endl;
        print(mm,s_a);
        cout<<setprecision(2)<<fixed<<"Number of feet of cable required is "<<mxx<<"."<<endl;
        ++cs;
    }

}



