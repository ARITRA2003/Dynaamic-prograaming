#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//Memoization way
/*
LL f(LL i,LL j,vector<vector<LL>> &v){
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
vector<vector<LL>> v(m,vector<LL>(n,0)), dp(m,vector<LL>(n,-1));
cout<<f(m-1,n-1,)
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