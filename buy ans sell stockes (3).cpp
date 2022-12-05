// 1st  Way
/*
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
LL f(vector<LL> &v,LL n,LL i,bool by,LL u,vector<vector<vector<LL>>> &dp){
  if(i==n || u==2) return 0;
  if(dp[i][by][u]!=-1) return dp[i][by][u];
  if(by) return dp[i][by][u]=max(-v[i]+f(v,n,i+1,0,u,dp),f(v,n,i+1,1,u,dp));
  else return dp[i][by][u]=max(v[i]+f(v,n,i+1,1,u+1,dp),f(v,n,i+1,0,u,dp));
}

void answer(){
  LL n;
  cin>>n;
  vector<LL> v(n);
  for(LL i=0;i<n;++i) cin>>v[i];
  /*
  vector<vector<vector<LL>>> dp(n+1,vector<vector<LL>>(2,vector<LL>(3,0)));
  //f(v,n,0,1,0,dp);
  for(LL i=n-1;i>=0;--i){
    for(LL j=0;j<=1;++j){
      for(LL u=0;u<=1;++u){
        if(j) dp[i][j][u]=max(-v[i]+dp[i+1][0][u],dp[i+1][1][u]);
        else dp[i][j][u]=max(v[i]+dp[i+1][1][u+1],dp[i+1][0][u]);
      }
    }
  }
  cout<<dp[0][1][0]<<"\n";
  */
  /*vector<vector<LL>> prev(2,vector<LL>(3,0)),curr(2,vector<LL>(3,0));
  for(LL i=n-1;i>=0;--i){
    for(LL j=0;j<=1;++j){
      for(LL u=0;u<=1;++u){
        if(j) curr[j][u]=max(-v[i]+prev[0][u],prev[1][u]);
        else curr[j][u]=max(v[i]+prev[1][u+1],prev[0][u]);
      }
    }
    prev=curr;
  }
  cout<<prev[1][0]<<"\n";
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
    else cout<<"NO\n";
    }
    return 0;
}*/
// 2nd Way
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
LL f(LL i,LL n,LL t,vector<LL> &v,vector<vector<LL>> &dp)
{
  if(t==4 || i==n) return 0;
  if(dp[i][t]!=-1) dp[i][t];
  if(!(t&1)) return dp[i][t]=max(-v[i]+f(i+1,n,t+1,v,dp),f(i+1,n,t,v,dp));
  return dp[i][t]=max(v[i]+f(i+1,n,t+1,v,dp),f(i+1,n,t,v,dp));
}
void answer(){
 LL n;
 cin>>n;
 vector<LL> v(n);
 for(LL i=0;i<n;++i) cin>>v[i];
  /*
 vector<vector<LL>> dp(n+1,vector<LL>(5,0));
 //f(0,n,0,v,dp);
 for(LL i=n-1;i>=0;--i){
  for(LL t=0;t<=3;++t){
     if(!(t&1)) dp[i][t]=max(-v[i]+dp[i+1][t+1],dp[i+1][t]);
     else dp[i][t]=max(v[i]+dp[i+1][t+1],dp[i+1][t]);
   }
  }
 cout<<dp[0][0]<<"\n";
 */
  //shorest code 
  vector<LL> prev(5,0);
  for(LL i=n-1;i>=0;--i){
  for(LL t=0;t<=3;++t){
     if(!(t&1)) prev[t]=max(-v[i]+prev[t+1],prev[t]);
     else prev[t]=max(v[i]+prev[t+1],prev[t]);
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

