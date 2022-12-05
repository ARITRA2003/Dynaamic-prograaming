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
/*bool f(LL i,LL k,vector<LL> &v,vector<vector<int>> &dp){
  if(i<0 || k<0) return 0;
  if(k==0) return dp[i][k]=1;
  if(i==0) return (v[0]==k);
  if(dp[i][k]!=-1) return dp[i][k];
  return dp[i][k]=(f(i-1,k-v[i],v,dp) | f(i-1,k,v,dp));
}*/
bool answer(){
 LL n,k;
 cin>>n>>k;
 vector<LL> v(n);
 //vector<vector<bool>> dp(n,vector<bool>(k+1,false));
 for(LL i=0;i<n;++i) cin>>v[i];
 /*dp[0][v[0]]=1;
 for(LL i=0;i<n;++i)
  dp[i][0]=true;

 for(LL i=1;i<n;i++){
  for(LL j=1;j<=k;j++){
    bool nontake=dp[i-1][j],take=false;
    if(v[i]<=j) take=dp[i-1][j-v[i]];
    dp[i][j]= (take | nontake);
  }
 }
  return dp[n-1][k];*/
  vector<bool> prev(k+1,false),curr(k+1,false);
  prev[v[0]]=1;
  prev[0]=1;
  curr[0]=1;
  for(LL i=1;i<n;i++){
  for(LL j=1;j<=k;j++){
    bool nontake=prev[j],take=false;
    if(v[i]<=j) take=prev[j-v[i]];
    curr[j]= (take | nontake);
  }
  prev=curr;
 }
 return prev[k];
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