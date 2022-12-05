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
const int N=1000000007;
/*
LL f(LL i,LL j,bool istrue,string &s,vector<vector<vector<LL>>> &dp){
  if(i>j) return 0;
  if(i==j){
    if(istrue) return s[i]=='T';
    else return s[i]=='F';
  }//base cases
  if(dp[i][j][istrue]!=-1) return dp[i][j][istrue];
  LL ways=0;
  for(LL k=i+1;k<j;k+=2){
    LL ltt=f(i,k-1,1,s,dp),ltf=f(i,k-1,0,s,dp);
    LL rtt=f(k+1,j,1,s,dp),rtf=f(k+1,j,0,s,dp);
    if(istrue){
      if(s[k]=='&') ways+=((ltt*rtt))%N;
      else if(s[k]=='^') ways+=((ltf*rtt)%N+(ltt*rtf)%N)%N;
      else ways+=((ltf*rtt)%N+(ltt*rtf)%N+(ltt*rtt)%N)%N;
    }
    else {
      if(s[k]=='|') ways+=(ltf*rtf)%N;
      else if(s[k]=='^') ways+=((ltf*rtf)%N+(ltt*rtt)%N)%N;
      else ways+=((ltf*rtt)%N+(ltt*rtf)%N+(ltf*rtf)%N)%N;      
    }
  }
  return dp[i][j][istrue]=ways%N;
}
*/
void answer(){
  string s;
  cin>>s;
  LL n=s.size();
  vector<vector<vector<LL>>> dp(n,vector<vector<LL>>(n,vector<LL>(2,0)));
  //cout<<f(0,n-1,1,s,dp)<<"\n";
  for(LL i=n-1;i>=0;--i){
  for(LL j=i;j<n;++j){
      if(i==j){
      dp[i][j][1]=(s[i]=='T');
      dp[i][j][0]= (s[i]=='F');
      continue;
      }
     for(LL k=i+1;k<j;k+=2){
       LL ltt=dp[i][k-1][1],ltf=dp[i][k-1][0];
       LL rtt=dp[k+1][j][1],rtf=dp[k+1][j][0];
      if(s[k]=='&') {
          dp[i][j][1]= (dp[i][j][1]+((ltt*rtt))%N)%N;
          dp[i][j][0]=(dp[i][j][0]+(ltf*rtt)%N+(ltt*rtf)%N+(ltf*rtf)%N)%N;
      }
      else if(s[k]=='^'){
          dp[i][j][1]= (dp[i][j][1]+(ltf*rtt)%N+(ltt*rtf)%N)%N;
          dp[i][j][0]= (dp[i][j][0]+((ltf*rtf)%N+(ltt*rtt)%N)%N)%N;
        }
      else {
       dp[i][j][1]= (dp[i][j][1]+((ltf*rtt)%N+(ltt*rtf)%N+(ltt*rtt)%N)%N)%N;
       dp[i][j][0]= (dp[i][j][0]+(ltf*rtf)%N)%N;
      }    
   }
  }
  }
  cout<<dp[0][n-1][1]<<"\n";
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