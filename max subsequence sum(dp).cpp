 #include<bits/stdc++.h>
 using namespace std;
 typedef long long int LL;
 //MEMORIATION WAY
 /*LL maxsum(vector<LL> &v,LL i,vector<LL> &dp){
    if(i==0){
        return dp[0]=v[0];
    }
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];
    LL m=v[i],ans=INT_MIN;
     m+=maxsum(v,i-2,dp);
     ans=maxsum(v,i-1,dp);  
    return dp[i]=max(ans,m);
 }*/
 void answer(){
    int n,pick,nonpick;
    cin>>n;
    vector<LL> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    //cout<<maxsum(v,n-1,dp)<<"\n";
    //Tabulation way
    /*vector<LL> dp(n,-1);
    dp[0]=v[0];
    for(LL i=1;i<n;i++){
        pick=v[i];if(i>1) pick+=dp[i-2];
        nonpick=dp[i-1];
        dp[i]=max(pick,nonpick);
    }
    cout<<dp[n-1]<<"\n";
    */
    LL a,b=0,c=0;
    for(LL i=1;i<=n;i++){
        pick=v[i];if(i>1) pick+=c;
        nonpick=b;
        a=max(pick,nonpick);
        c=b;
        b=a;
    }
    cout<<b<<"\n";
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
    LL ARITRASEN=1;
    cin>>ARITRASEN;
    while(ARITRASEN--)
    {
    answer();
    /*if(answer()) cout<<"YES\n";
    else cout<<"NO\n";*/
    }
    return 0;
}