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
bool comp(string &s1,string &s2){
  if((s1.size()-s2.size())!=1) return 0;
  LL i=0,j=0,a=0;
  while(s1[i]!='\0'){
    if(s1[i]==s2[j]){
      i++,++j;
      continue;
    }
    i++;
    a++;
    if(a>1) return 0;
  }
  return 1;
}
bool cmp(string &s1,string &s2){
    return (s1.size()<s2.size());
}
void answer(){
  LL n;
  cin>>n;
  vector<string> v(n);
  for(LL i=0;i<n;++i) cin>>v[i];
  sort(v.begin(),v.end());
  vector<LL> dp(n,1);
  LL maxi=1;
  for(LL i=1;i<n;++i){
    for(LL j=0;j<i;++j){
      if(comp(v[i],v[j]) && 1+dp[j]>dp[i]){
        dp[i]=dp[j]+1;
      }
    }
    if(maxi<dp[i]){
      maxi=dp[i];
    }
  }
  cout<<maxi<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt","w", stdout);
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