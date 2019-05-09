///Topic : Coinchange+Optimization

/// Both solutions are accepted.....But first solution is straightforward coin change algo which complexity is O(numberOfCoin * Price * maxPrice);
/// But 2nd solution is done by doing little bit optimization......complexity: O( NumberOfCoin * maxPrice)
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
const int sz= 10100;
int n;
int coin[103];
int dp[103][sz];
int inf=1e9+100;
int cholo(int in,int price)
{
    if(in==n){
        if(price==0)  return 0;
        else return inf;
    }
    else if(price==0)  return 0;
    int &ret=dp[in][price];
    if(~ret)   return ret;
    int p=inf,q=inf;
    if(price-coin[in]>=0) p=1+cholo(in+1,price-coin[in]);
    q=cholo(in+1,price);
    ret=min(p,q);
    return ret;
}
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,x1,y1,mn,mx,ans,h,sum1,len;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    sf("%d",&t);
    while(t--)
    {
        int price;
        sf("%d %d",&price,&n);
        i=0;
        while(i<n){
            sf("%d",&coin[i]);
            ++i;
        }
       int start=price;
       mn=inf;
       while(start<sz){
        memset(dp,-1,sizeof dp);
        p=cholo(0,start);
        if(p<inf){
            pf("%d %d\n",start,p);
            break;
        }
        ++start;
       }


    }


}





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
const int sz= 10100;
int n;
int coin[103];
int dp[sz];
int inf=1e9+100;
int main()
{
    LOL
    int a,b,c,i,j,k,q,p,x,y,sum,ct,ct1,m,l,r,x1,y1,mn,mx,ans,h,sum1,len;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int cs=1,t;
    sf("%d",&t);
    while(t--)
    {
        int price;
        sf("%d %d",&price,&n);
        i=0;
        while(i<n){
            sf("%d",&coin[i]);
            ++i;
        }
       for(i=1;i<sz;i++)  dp[i]=inf;

       dp[0]=0;
       for(j=0;j<n;j++){
        for(i=sz-1;i>=1;i--){
            if(i-coin[j]>=0 && (1+dp[i-coin[j]]<dp[i])) dp[i]=1+dp[i-coin[j]];
        }
       }

       int start=price;
       while(start<sz){
        if(dp[start]<inf){
            pf("%d %d\n",start,dp[start]);
            break;
        }
        ++start;
       }

    }


}


