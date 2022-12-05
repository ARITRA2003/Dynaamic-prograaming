#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
typedef unsigned long long int ULL;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(LL t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(long double t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(unsigned long long t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*
LL f(LL i,LL t,LL n,LL k,vector<LL> &v,vector<vector<LL>> &dp){
  if(i==n || t==k) return 0;
  if(dp[i][t]!=-1) return dp[i][t];
  if(t&1) return dp[i][t]=max(v[i]+f(i+1,t+1,n,k,v,dp),f(i+1,t,n,k,v,dp));
  return dp[i][t]=max(-v[i]+f(i+1,t+1,n,k,v,dp),f(i+1,t,n,k,v,dp));
}
*/
void answer(){
  LL n,k;
  cin>>n>>k;
  vector<LL> v(n);
  for(LL i=0;i<n;++i) cin>>v[i];
  if(k==0){
    cout<<"0\n";
    return;
  }
  /*vector<vector<LL>> dp(n+1,vector<LL>(2*k+1,0));
  //cout<<f(0,0,n,2*k,v,dp)<<"\n";
  for(LL i=n-1;i>=0;--i){
    for(LL t=0;t<(2*k);++t){
       if(t&1) dp[i][t]=max(v[i]+dp[i+1][t+1],dp[i+1][t]);
       else dp[i][t]=max(-v[i]+dp[i+1][t+1],dp[i+1][t]);
    }
  }
  cout<<dp[0][0]<<"\n";
  */
  vector<LL> prev(2*k+1,0);
  for(LL i=n-1;i>=0;--i){
    for(LL t=0;t<(2*k);++t){
       if(t&1) prev[t]=max(v[i]+prev[t+1],prev[t]);
       else prev[t]=max(-v[i]+prev[t+1],prev[t]);
    }
  }
  cout<<prev[0]<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
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