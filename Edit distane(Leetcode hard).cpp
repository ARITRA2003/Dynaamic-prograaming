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
/*//Memorization Way
LL f(LL i,LL j,string &s1,string &s2,vector<vector<LL>> &dp){
  if(i==0) return j;
  if(j==0) return i;
  if(dp[i][j]!=-1) return dp[i][j];
  if(s1[i-1]==s2[j-1]) return dp[i][j]=f(i-1,j-1,s1,s2,dp);
   LL insert=f(i,j-1,s1,s2,dp);
   LL deletion=f(i-1,j,s1,s2,dp);
   LL replace=f(i-1,j-1,s1,s2,dp);
   return dp[i][j]=1+min(min(insert,replace),deletion);
}
*/
void answer(){
 string s1,s2;
 cin>>s1>>s2;
 LL n=s1.size(),m=s2.size();
 vector<vector<LL>> dp(n+1,vector<LL>(m+1,-1));
 //cout<<f(n,m,s1,s2,dp)<<"\n";
 /*
 for(LL i=0;i<=m;++i) dp[0][i]=i;
 for(LL i=0;i<=n;++i) dp[i][0]=i;
 for(LL i=1;i<=n;++i) 
 {
 for(LL j=1;j<=m;++j) {
  if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
  else{
   LL insert=dp[i][j-1];
   LL deletion=dp[i-1][j];
   LL replace=dp[i-1][j-1];
   dp[i][j]=1+min(min(insert,replace),deletion);
 }
 }
}
cout<<dp[n][m]<<"\n";
*/
 vector<LL> prev(m+1,0),curr(m+1,0);
 for(LL i=0;i<=m;++i) prev[i]=i;
  for(LL i=1;i<=n;++i) 
 {
 for(LL j=0;j<=m;++j) {
  if(j==0) curr[0]=i;
  else {
  if(s1[i-1]==s2[j-1]) curr[j]=prev[j-1];
   else curr[j]=1+min(min(curr[j-1],prev[j]),prev[j-1]);
 }
 }
 prev=curr;
 }
 cout<<prev[m]<<"\n";
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
    //cin>>ARITRASEN;
    while(ARITRASEN--)
    {
    answer();
    /*if(answer()) cout<<"YES\n";
    else cout<<"NO\n";*/
    }
    return 0;
}