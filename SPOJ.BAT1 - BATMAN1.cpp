/*
   Problem link : https://www.spoj.com/problems/BAT1/
   Type: Knapsack
   Hints: https://www.quora.com/What-is-the-solution-to-this-problem-on-SPOJ
*/
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
//const int sz=;
int dp[2][22][1100];
int tk[22][22];
int val[22][22];
int KG,n,m;
int open[22];
int cholo(int in,int tot,int st)
{
    if(in==n || tot==0)   return 0;
    int &ret=dp[st][in][tot];
    if(~ret)   return ret;
    int p=cholo(in+1,tot,0);
    int x=0,i;
    if(st==0 && open[in]<tot){
        tot-=open[in];
        for(i=0;i<m;i++){
            if(tk[in][i]<=tot) x=max(x,cholo(in,tot-tk[in][i],1)+val[in][i]);
        }
    }
    else if(st==1){

        for(i=0;i<m;i++){
            if(tk[in][i]<=tot) x=max(x,cholo(in,tot-tk[in][i],1)+val[in][i]);
        }
    }

    ret=max(x,p);
    return ret;

}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,l,r,len,x1,y1,mn,mx,ans,h,sum1;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    sf("%d",&t);
    while(t--)
    {
        sf("%d %d %d",&n,&m,&KG);
        for(i=0;i<n;i++)   sf("%d",&open[i]);
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++)  sf("%d",&tk[i][j]);
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++)   sf("%d",&val[i][j]);
        }
        memset(dp,-1,sizeof dp);
        p=cholo(0,KG,0);
        pf("%d\n",p);
    }

}

