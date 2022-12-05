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
bool ispalindrome(string &s,LL i,LL j){
  LL n=s.size();
  while(i<j){
    if(s[i]!=s[j]) return 0;
    i++,j--;
  }
  return 1;
}
/*
LL f(LL i,LL n,string &s,vector<LL> &dp){
  if(i==n) return 0;
  if(dp[i]!=-1) return dp[i];
  LL mini=n-1;
  for(LL j=i;j<n;++j){
   if(ispalindrome(s,i,j)){
    LL cut=1+f(j+1,n,s,dp);
    mini=min(mini,cut);
   }
  }
  return dp[i]=mini;
}*/
void answer(){
   string s;
   cin>>s;
   LL n=s.size();
   vector<LL> dp(n+1,0);
   //cout<<f(0,n,s,dp)-1<<"\n";
   for(LL i=n-1;i>=0;--i){
       LL mini=INT_MAX;
       for(LL j=i;j<n;++j){
           if(ispalindrome(s,i,j)){
            LL cut=1+dp[j+1];
            mini=min(mini,cut);
           }
          }
       dp[i]=mini;
   }
   cout<<dp[0]-1<<"\n";
  
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
