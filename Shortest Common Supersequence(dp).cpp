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
void answer(){
   string s1,s2,s="",ans="";
   cin>>s1>>s2;
   LL n=s1.size(),m=s2.size();
   vector<vector<LL>> dp(n+1,vector<LL>(m+1,0));
   for(LL i=1;i<=n;++i){
      for(LL j=1;j<=m;++j){
         if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
         else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
   }
   LL i=n,j=m;
   while(i>0 && j>0){
      if(s1[i-1]==s2[j-1]){
         s=s1[i-1]+s;
         i--,j--;
      }
      else{
         if(dp[i-1][j]>dp[i][j-1]) 
            {
               s=s1[i-1]+s;
               i--;
            }
         else {
            s=s2[j-1]+s;
            j--;
         }
      }
   }
   while(i>0){
      s=s1[i-1]+s;
      i--;
   }
   while(j>0){
      s=s2[j-1]+s;
      j--;
   }
   cout<<s<<"\n";
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