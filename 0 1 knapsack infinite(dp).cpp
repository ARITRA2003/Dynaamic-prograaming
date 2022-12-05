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
//Memorization way
/*
LL f(vector<LL> &v,vector<LL> &w,LL k,LL i,vector<vector<LL>> &dp){
  if(i==0){
  return dp[i][k]=(v[i]*(int)(k/w[i]));
  }
  if(dp[i][k]!=-1) return dp[i][k];
  LL ntk=f(v,w,k,i-1,dp);
  LL tk=INT_MIN;
  if(k>=w[i]) tk=v[i]+f(v,w,k-w[i],i,dp);
  return dp[i][k]=max(tk,ntk);
}
*/
void answer(){
   LL n,k;
   cin>>n>>k;
   vector<LL> v(n),w(n);
   for(LL i=0;i<n;++i) cin>>v[i];
   for(LL i=0;i<n;++i) cin>>w[i];
   /*vector<vector<LL>> dp(n,vector<LL>(k+1,-1));
   //cout<<f(v,w,k,n-1,dp)<<"\n";
   for(LL i=0;i<=k;++i){
    dp[0][i]=(v[0]*(int)(i/w[0]));
   }
   for(LL i=1;i<n;++i){
    for(LL j=0;j<=k;++j){
      LL tk=INT_MIN;
       if(j>=w[i]) tk=v[i]+dp[i][j-w[i]];
       dp[i][j]=max(tk,dp[i-1][j]);
    }
   }
   cout<<dp[n-1][k]<<"\n";
   */
    vector<LL> prev(k+1,0);
    for(LL i=0;i<=k;++i){
    prev[i]=(v[0]*(int)(i/w[0]));
   }
   for(LL i=1;i<n;++i){
    for(LL j=0;j<=k;++j){
      LL tk=INT_MIN;
       if(j>=w[i]) tk=v[i]+prev[j-w[i]];
       prev[j]=max(tk,prev[j]);
    }
   }
   cout<<prev[k]<<"\n";
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