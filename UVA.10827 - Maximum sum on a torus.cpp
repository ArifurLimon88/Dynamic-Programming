///   Topic :   Maximum Sum Rectangle In A 2D Matrix - Kadane's Algorithm Applications   (DP)


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
int ara[77][77],n;
int Kadanes(int ara1[])
{
     int mx=-1e9+100;
     for(int i=0;i<n;i++){
        int sum=0;
        bool bl=false;
        for(int j=i;;j++){
            if(j==n) j=0;
            if(j==i && !bl) bl=true;
            else if(j==i && bl) break;
            sum+=ara1[j];
            if(sum<0) sum=0;
            else if(sum>mx) mx=sum;
        }
        mx=max(ara1[i],mx);
     }
     return mx;
}
int fun()
{
        int mx=-1e9+100;
        int temp[n],i,j,k;
        for(i=0;i<n;i++){
            bool bl=false;
            for(j=i;;j++){
                if(j%n==0) j=0;
                if(j==i && !bl) bl=true;
                else if(j==i && bl)  break;
                for(k=0;k<n;k++){
                    if(i==j) {
                            temp[k]=ara[k][j];
                    }
                    else {
                            temp[k]+=ara[k][j];
                    }
                }
            mx=max(mx,Kadanes(temp));
            }
        }
        return mx;
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
        sf("%d",&n);
        int ara1[n+1][n+1];
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)   {
                    sf("%d",&ara[i][j]);
            }
        }
        mx=fun();
        pf("%d\n",mx);
    }


}

