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
LL f(LL i,LL j,string s1,string s2,vector<vector<LL>> &dp){
  if(i==0){
    if(s1[i]==s2[j] && j==0) return 1;
    else return 0;
  }
  if(dp[i][j]!=-1) return dp[i][j];
  if(s1[i]==s2[j]){
    if(j==0) return dp[i][j]=(1+f(i-1,j,s1,s2,dp));
    else return dp[i][j]=(f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp));
  }
  return dp[i][j]=f(i-1,j,s1,s2,dp);
}
*/
void answer(){
  LL n,m;
  string s1,s2;
  cin>>n>>m>>s1>>s2;
  //vector<vector<LL>> dp(n,vector<LL>(m,0));
  //cout<<f(n-1,m-1,s1,s2,dp)<<"\n";
  /*
  dp[0][0]=(s1[0]==s2[0]);
  for(LL i=1;i<n;++i){
    for(LL j=0;j<m;++j){
      if(s1[i]==s2[j]){
        if(j==0) dp[i][0]=1+dp[i-1][0];
        else dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
      }
      else dp[i][j]=dp[i-1][j];
    }
  }
  cout<<dp[n-1][m-1]<<"\n";
  */
  vector<LL> prev(m,0);
  prev[0]=(s1[0]==s2[0]);
  for(LL i=1;i<n;++i){
    for(LL j=m-1;j>=0;--j){
      if(s1[i]==s2[j]){
        if(j==0) prev[0]=1+prev[0];
        else prev[j]=prev[j]+prev[j-1];
      }
    }
  }
  cout<<prev[m-1]<<"\n";
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