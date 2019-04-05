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
#define pii pair<ll ,ll>
//const int sz=;
struct  node
{
    ll a,b,c;
};
node pr[300];
ll ss;
ll dp[300];
ll cholo(int in)
{
    ll &ret=dp[in];
    if(~ret)    return ret;
    ll mx=0;
    for(int i=0;i<ss;i++)
    {
        if(pr[in].a> pr[i].a && pr[in].b>pr[i].b) mx=max(mx,pr[i].c+cholo(i));
    }
    return (ret = mx);
}
int main()
{
    LOL
    ll a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,len,x1,y1,mn,n,mx,ans,h,sum1,z;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    while(sf("%lld",&n) && n)
    {
          j=0;
          for(i=0;i<n;i++){
              sf("%lld %lld %lld",&x,&y,&z);
              pr[j].a=x,pr[j].b=y,pr[j].c=z;              /// Rotating all possible way & then storing it .....
              ++j;
              pr[j].a=x,pr[j].b=z,pr[j].c=y;
              ++j;
              pr[j].a=y,pr[j].b=z,pr[j].c=x;
              ++j;
              pr[j].a=y,pr[j].b=x,pr[j].c=z;
              ++j;
              pr[j].a=z,pr[j].b=x,pr[j].c=y;
              ++j;
              pr[j].a=z,pr[j].b=y,pr[j].c=x;
              ++j;
          }
          ss=j;
          memset(dp,-1,sizeof dp);
          mx=0;
          for(i=0;i<ss;i++){
            mx=max(mx,pr[i].c+cholo(i));
          }
          pf("Case %d: maximum height = %lld\n",cs,mx);
          ++cs;
    }

}
