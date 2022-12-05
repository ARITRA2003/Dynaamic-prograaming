#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//Memoization way
/*LL f(LL n,LL i,LL j,vector<vector<LL>> &v,vector<vector<LL>> &dp){
    if(i==n-1) return dp[i][j]=v[n-1][j];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=v[i][j]+min(f(n,i+1,j+1,v,dp),f(n,i+1,j,v,dp));
}*/
void answer(){
    LL n;cin>>n;
    vector<vector<LL>> v(n,vector<LL>(n)),dp(n,vector<LL>(n,-1));
    for(LL i=0;i<n;++i){
        for(LL j=0;j<=i;j++) cin>>v[i][j];
    }
    //cout<<f(n,0,0,v,dp)<<"\n";
    vector<LL> curr(n,0),temp(n,0);
    for(int j=0;j<=(n-1);j++){
        temp[j]=v[n-1][j];
    }
    for(LL i=n-2;i>=0;--i){
        for(LL j=0;j<=i;j++){
            curr[j]=v[i][j]+min(temp[j+1],temp[j]);
        }
        temp=curr;
    }
    cout<<temp[0]<<"\n";
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
