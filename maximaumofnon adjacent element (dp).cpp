#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//Memorization way
/*
LL f(vector<LL> &v,LL i,vector<LL> &dp){
  if(dp[i]!=-1) return dp[i];
	if(i==0) return v[0];
  if(i<0)  return 0;
	LL ans=v[i];
	if(i>1) ans+=f(v,i-2,dp);
    LL ans1=INT_MIN;
    ans1=f(v,i-1,dp);
    return dp[i]=max(ans,ans1);
}*/
int main(){
	  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	LL n;
	cin>>n;
	vector<LL> v(n),dp(n,-1);
	for(int i=0;i<n;i++) cin>>v[i];
	//cout<<f(v,n-1,dp)<<"\n";
	//Tabulation way
  dp[0]=v[0],dp[1]=v[1];
    for(LL i=1;i<n;i++){
      if(i>1)
      dp[i]=max(dp[i-2]+v[i],dp[i-1]);
      else
      dp[i]=max(v[i],dp[i-1]);
    }
    cout<<dp[n-1]<<"\n";
   // space optimization
  /*LL prev2=0,prev1=v[0],curr=0;
  for(LL i=1;i<n;i++){
      curr=max(prev2+v[i],prev1);
      prev2=prev1;
      prev1=curr;
    }
    cout<<prev1<<"\n";*/
    return 0;
}