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
/*LL f(vector<LL> &v,LL n,LL i,bool by,vector<vector<LL>> &dp){
  if(i==n) return 0;
  if(dp[i][by]!=-1) return dp[i][by];
  if(by) return dp[i][by]=max(-v[i]+f(v,n,i+1,0,dp),f(v,n,i+1,1,dp));
  else return dp[i][by]=max(v[i]+f(v,n,i+1,1,dp),f(v,n,i+1,0,dp));
}*/
void answer(){
  LL n;
  cin>>n;
  vector<LL> v(n);
  for(LL i=0;i<n;++i) cin>>v[i];
  vector<vector<LL>> dp(n+1,vector<LL>(2,0));
  /*cout<<f(v,n,0,1,dp)<<"\n";
  cout<<dp[0][1]<<"\n";*/
  for(LL i=n-1;i>=0;--i){
      for(LL j=0;j<2;++j){
        if(j)  dp[i][j]=max(-v[i]+dp[i+1][0],dp[i+1][1]);
        else dp[i][j]=max(v[i]+dp[i+1][1],dp[i+1][0]);
       }
      }
  cout<<dp[0][1]<<"\n";
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