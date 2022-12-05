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
LL f(LL i,LL l,vector<LL> &v,vector<vector<LL>> &dp){
  if(i==0){
    return dp[i][l]=(v[i]*l);
  }
  if(dp[i][l]!=-1) return dp[i][l];
  LL ntk=f(i-1,l,v,dp);
  LL tk=INT_MIN;
  if(l>=(i+1)) tk=v[i]+f(i,l-i-1,v,dp);
  return dp[i][l]=max(tk,ntk);
}
*/
void answer(){
   LL n;
   cin>>n;
   vector<LL> v(n);
   for(LL i=0;i<n;++i) cin>>v[i];
    /* //tabulation way
   vector<vector<LL>> dp(n,vector<LL>(n+1,0));
   //cout<<f(n-1,n,v,dp)<<"\n";
   for(LL i=0;i<=n;++i){
    dp[0][i]=v[0]*i;
   }
   for(LL i=1;i<n;++i){
    for(LL j=0;j<=n;++j){
      LL tk=INT_MIN;
      if(j>=(i+1)) tk=v[i]+dp[i][j-i-1];
      dp[i][j]=max(tk,dp[i-1][j]);
    }
   }
   cout<<dp[n-1][n]<<"\n";
   */
    vector<LL> prev(n+1,0);
  for(LL i=0;i<=n;++i){
    prev[i]=v[0]*i;
   }
   for(LL i=1;i<n;++i){
    for(LL j=0;j<=n;++j){
      LL tk=INT_MIN;
      if(j>=(i+1)) tk=v[i]+prev[j-i-1];
      prev[j]=max(tk,prev[j]);
    }
   }
   cout<<prev[n]<<"\n";
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