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
// Memoisation  code
/*
LL f(LL i,LL pri,vector<LL> &v,vector<vector<LL>> &dp){
 if(i==0){
  if(v[i]<v[pri]) return dp[i][pri]=1;
  else  return dp[i][pri]=0;
 }
 if(dp[i][pri]!=-1) return dp[i][pri];
 LL ntk=f(i-1,pri,v,dp),tk=INT_MIN;
 if(v[i]<v[pri]) tk=1+f(i-1,i,v,dp);
 return dp[i][pri]=max(tk,ntk);
}
*/
void answer(){
 LL n;
 cin>>n;
 vector<LL> v(n+1);
 for(LL i=0;i<n;++i) cin>>v[i];
  v[n]=1e6;
//Tabulation Way
/*
 vector<vector<LL>> dp(n,vector<LL>(n+1,0));
 //cout<<f(n-1,n,v,dp)<<"\n";
 for(LL i=0;i<=n;++i){
  if(v[i]>v[0]) dp[0][i]=1;
  else dp[0][i]=0;
 }
 for(LL i=1;i<n;++i){
  for(LL j=0;j<=n;++j){
     LL ntk=dp[i-1][j],tk=INT_MIN;
     if(v[i]<v[j]) tk=1+dp[i-1][i];
     dp[i][j]=max(tk,ntk);
  }
 }
 cout<<dp[n-1][n]<<"\n";
 */
/*
 vector<LL> prev(n+1,0),curr(n+1,0);
 for(LL i=0;i<=n;++i){
  if(v[i]>v[0]) prev[i]=1;
  else prev[i]=0;
 }
  for(LL i=1;i<n;++i){
  for(LL j=0;j<=n;++j){
     LL ntk=prev[j],tk=INT_MIN;
     if(v[i]<v[j]) tk=1+prev[i];
     curr[j]=max(tk,ntk);
  }
  prev=curr;
 }
 cout<<prev[n]<<"\n";
 */
// Required this tabulated form to print the LIS
vector<LL> dp(n,1),hash(n,0);
LL lastindex=-1,maxi=INT_MIN;
for(LL i=1;i<n;++i){
  hash[i]=i;
  for(LL j=0;j<i;++j){
    if(v[i]>v[j] && dp[j]+1>dp[i]) {
      dp[i]=dp[j]+1;
      hash[i]=j;
    }
  }
  if(maxi<dp[i]){
    lastindex=i;
    maxi=dp[i];
  }
}
vector<LL>temp;
temp.push_back(v[lastindex]);
while(hash[lastindex]!=lastindex){
  lastindex=hash[lastindex];
  temp.push_back(v[lastindex]);
}
reverse(temp.begin(),temp.end());
for(auto i:temp){
  cout<<i<<" ";
}
cout<<"\n";
cout<<temp.size()<<"\n";
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