#include<bits/stdc++.h>
using namespace std;
/*
int fibbonacchi(int n,vector<int> &dp)//Memoization way
{
	if(n<=1) return n;
	if(dp[n]!=-1) return dp[n];
	return dp[n]=fibbonacchi(n-1,dp)+fibbonacchi(n-2,dp);
}
*/
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n
	cin>>n;
    vector<int> dp(n+1,-1);
    //cout<<fibbonacchi(n,dp);
    dp[0]=0;dp[1]=1;//Tarbulation way
    for (int i = 2; i<=n ; ++i)
    {
    	dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];
	return 0;
}