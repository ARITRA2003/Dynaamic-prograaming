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
/*LL f(LL i,LL j1,LL j2,LL n,LL m,vector<vector<LL>> &v,vector<vector<vector<LL>>> &dp){
  if(j1<0 || j2<0 || j2>=m || j1>=m) return INT_MIN;
  if(i==n-1){
    if(j1==j2) return dp[i][j1][j2]=v[i][j1];
    else return dp[i][j1][j2]=v[i][j1]+v[i][j2];
  }
  if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
  LL maxi=0;
  for(int a=-1;a<=1;++a){
    for(int b=-1;b<=1;b++){
      if(j1==j2) maxi=max(maxi,v[i][j1]+f(i+1,j1+a,j2+b,n,m,v,dp));
      else maxi=max(maxi,v[i][j1]+v[i][j2]+f(i+1,j1+a,j2+b,n,m,v,dp));
    }
  }
  return dp[i][j1][j2]=maxi;
}*/
void answer(){
  LL n,m;
  cin>>n>>m;
  vector<vector<LL>> v(n,vector<LL>(m,0));
  for(LL i=0;i<n;i++)
  for(LL j=0;j<m;++j)
  cin>>v[i][j];
  
  //cout<<f(0,0,m-1,n,m,v,dp)<<"\n";
  //Tabulation 
  /*vector<vector<vector<LL>>> dp(n,vector<vector<LL>>(m,vector<LL>(m,-1)));
  for(LL j1=0;j1<m;j1++){
    for(LL j2=0;j2<m;j2++){
      if(j1==j2) dp[n-1][j1][j2]=v[n-1][j2];
      else dp[n-1][j1][j2]=v[n-1][j1]+v[n-1][j2];
    }
  }
  for(LL i=n-2;i>=0;--i){
    for(LL j1=0;j1<m;j1++){
      for(LL j2=0;j2<m;j2++){
        LL maxi=0;
        for(int a=-1;a<=1;++a){
         for(int b=-1;b<=1;b++){
        if(j1==j2) {
          if(j1+a<m && j2+b<m && j1+a>=0 && j2+b>=0) 
          maxi=max(maxi,v[i][j1]+dp[i+1][j1+a][j2+b]);
        }
        else {
          if(j1+a<m && j2+b<m && j1+a>=0 && j2+b>=0)
          maxi=max(maxi,v[i][j1]+v[i][j2]+dp[i+1][j1+a][j2+b]);
          }
       }
      }
      dp[i][j1][j2]=maxi;
      }
    }
  }
  cout<<dp[0][0][m-1]<<"\n";
  */
  vector<vector<LL>> temp(m,vector<LL>(m,0)),curr(m,vector<LL>(m,0));
  for(LL j1=0;j1<m;j1++){
    for(LL j2=0;j2<m;j2++){
      if(j1==j2) temp[j1][j2]=v[n-1][j2];
      else temp[j1][j2]=v[n-1][j1]+v[n-1][j2];
    }
  }
  for(LL i=n-2;i>=0;--i){
    for(LL j1=0;j1<m;j1++){
      for(LL j2=0;j2<m;j2++){
        LL maxi=0;
        for(int a=-1;a<=1;++a){
         for(int b=-1;b<=1;b++){
        if(j1==j2) {
          if(j1+a<m && j2+b<m && j1+a>=0 && j2+b>=0) 
           {maxi=max(maxi,v[i][j1]+temp[j1+a][j2+b]);}
        }
        else {
          if(j1+a<m && j2+b<m && j1+a>=0 && j2+b>=0)
          {maxi=max(maxi,v[i][j1]+v[i][j2]+temp[j1+a][j2+b]);}
          }
       }
      }
       curr[j1][j2]=maxi;
      }
    }
    temp=curr;
  }
  cout<<temp[0][m-1]<<"\n";
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