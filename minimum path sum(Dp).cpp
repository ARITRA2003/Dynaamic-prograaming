#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//Memoization way
/*
LL f(LL i,LL j,vector<vector<LL>> &v,vector<vector<LL>> &dp){
 if(i==0 && j==0) return dp[i][j]=v[i][j];
 if(i<0 || j<0) return INT_MAX;
 if(dp[i][j]!=-1) return dp[i][j];
 return dp[i][j]=(v[i][j]+min(f(i-1,j,v,dp),f(i,j-1,v,dp)));
}
*/
void answer(){
LL n,m;
cin>>m>>n;
vector<vector<LL>> v(m,vector<LL>(n,0)), dp(m,vector<LL>(n,-1));
for(LL i=0;i<m;++i){
 for(LL j=0;j<n;++j) cin>>v[i][j];
}
//cout<<f(m-1,n-1,v,dp)<<"\n";
//Tabulation way
/*
for(LL i=0;i<m;++i){
 for(LL j=0;j<n;++j) 
 {
    if(i==0 && j==0) dp[i][j]=v[i][j];
    else {
        if(i==0) dp[i][j]=v[i][j]+dp[i][j-1];
        else if(j==0) dp[i][j]=v[i][j]+dp[i-1][j];
        else dp[i][j]=(v[i][j]+min(dp[i-1][j],dp[i][j-1]));
    }
    }
 }
 cout<<dp[m-1][n-1]<<"\n";
 */
vector<LL> temp(n,INT_MAX),curr(n,0);
for(LL i=0;i<m;++i){
 for(LL j=0;j<n;++j) 
 {
    if(i==0 && j==0) curr[j]=v[i][j];
    else {
        if(i==0) curr[j]=v[i][j]+curr[j-1];
        else if(j==0) curr[j]=v[i][j]+temp[j];
        else curr[j]=(v[i][j]+min(temp[j],curr[j-1]));
    }
    }
    temp=curr;
 }
 cout<<temp[n-1]<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL ARITRASEN=1,x=0;
    cin>>ARITRASEN;
    while(ARITRASEN--)
    {
    //cout<<"Case #"<<++x<<":\t";
    answer();
    /*if(answer()) cout<<"YES\n";
    else cout<<"NO\n";*/
    }
    return 0;
}