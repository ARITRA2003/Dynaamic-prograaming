#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//Memoization way
/*
LL f(LL i,LL j,vector<vector<LL>> &dp){
 if(i==0 && j==0) return dp[i][j]=1;
 if(i<0 || j<0) return 0;
 if(dp[i][j]!=-1) return dp[i][j];
 LL up=f(i-1,j,dp);
 LL left=f(i,j-1,dp);
 return dp[i][j]=(left+up);
}
*/
void answer(){
LL n,m;
cin>>n>>m;
vector<LL> temp(n,0),curr(n);

/*f(m-1,n-1,dp);*/
/*Tabulation way
vector<vector<LL>> dp(m,vector<LL>(n,0));
for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
        if(i==0 && j==0) dp[i][j]=1;
        else{
        LL up=0,left=0;
        if(i>0) up+=dp[i-1][j];
        if(j>0) left+=dp[i][j-1];
        dp[i][j]=up+left;
        }
        }
}
cout<<dp[m-1][n-1]<<"\n";*/
for(int i=0;i<m;++i){
    for(int j=0;j<n;++j){
        if(i==0 && j==0) curr[j]=1;
        else{
        curr[j]=temp[j];
        if(j>0) curr[j]+=curr[j-1];
        }
        }
        temp=curr;
}
cout<<curr[n-1]<<"\n";
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