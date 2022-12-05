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
/*bool f(vector<LL> &v,LL k,LL i,vector<vector<LL>> &dp){
  if(i<0 || k<0) return 0;
  if(k==0) return dp[i][k]=1;
  if(i==0) return (dp[i][v[0]]=(v[0]==k));
  if(dp[i][k]!=-1) return dp[i][k];
  return dp[i][k]=(f(v,k-v[i],i-1,dp)|f(v,k,i-1,dp));
}*/
bool answer(){
  LL n,sum=0;
  cin>>n;
  vector<LL> v(n);
  for(LL i=0;i<n;++i){
    cin>>v[i];
    sum+=v[i];
  }
  if(sum&1) return 0;
  sum/=2;
  /*
  vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
  for(LL j=0;j<n;++j) dp[j][0]=1;
  for(LL j=1;j<=sum;++j){
    if(v[0]==j) dp[0][j]=1;
    else dp[0][j]=0;
  }
  for(LL i=1;i<n;++i){
    for(LL j=1;j<=sum;++j){
       bool take=0;
       if(v[i]<=j) take=dp[i-1][j-v[i]];
       dp[i][j]=take|(dp[i-1][j]);
    }
  }
  return dp[n-1][sum];
  */
  vector<bool> prev(sum+1,0),curr(sum+1,0);
  prev[0]=1;
  curr[0]=1;
  for(LL j=1;j<=sum;++j){
    if(v[0]==j) prev[j]=1;
    else prev[j]=0;
  }
  for(LL i=1;i<n;++i){
    for(LL j=1;j<=sum;++j){
       bool take=0;
       if(v[i]<=j) take=prev[j-v[i]];
       curr[j]=take|(prev[j]);
    }
    prev=curr;
  }
  return prev[sum];
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
    //answer();
    if(answer()) cout<<"YES\n";
    else cout<<"NO\n";
    }
    return 0;
}