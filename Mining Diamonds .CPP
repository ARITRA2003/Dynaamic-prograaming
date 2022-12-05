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
/*LL f(LL i,LL j,vector<LL> &v,vector<vector<LL>> &dp){
  if(i>j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  LL maxi=INT_MIN;
  for(LL k=i;k<=j;++k){
    LL cost = v[i-1]*v[k]*v[j+1]+f(i,k-1,v,dp)+f(k+1,j,v,dp);
    maxi=max(maxi,cost);
  }
  return dp[i][j]=maxi;
}*/
void answer(){
  LL n;
  cin>>n;
  vector<LL> v(n);
  for(LL i=0;i<n;++i) cin>>v[i];
  v.push_back(1);
  v.insert(v.begin(),1);
  vector<vector<LL>> dp(n+2,vector<LL>(n+2,0));
  //cout<<f(1,n,v,dp)<<"\n";
  for(LL i=n;i>0;--i){
    for(LL j=i;j<=n;++j){
       LL maxi=INT_MIN;// 
        for(LL k=i;k<=j;++k){
          LL cost =v[i-1]*v[k]*v[j+1]+dp[i][k-1]+dp[k+1][j];
          maxi=max(maxi,cost);
        }
        dp[i][j]=maxi;
    }
  }
  cout<<dp[1][n]<<"\n";
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