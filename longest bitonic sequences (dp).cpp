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
  LL n,maxi=1;
  cin>>n;
  vector<LL> v(n);
  for(LL i=0;i<n;++i) cin>>v[i];
  vector<LL> dp1(n,1),dp2(n,1),hash1(n,0),hash2(n,n-1),temp1,temp2;
  for(LL i=1;i<n;i++){
    hash1[i]=i;
    hash2[i]=i;
   for(LL j=0;j<i;++j){
    if(dp1[i]<1+dp1[j] && v[i]>v[j]){
      dp1[i]=dp1[j]+1;
      hash1[i]=j;
    }
    if(dp2[n-1-i]<1+dp2[n-1-j] && v[n-1-i]>v[n-1-j]){
      dp2[n-1-i]=dp2[n-1-j]+1;
      hash2[i]=n-1-j;
    }
   }
  }
  LL in=0,index=0;
  for(LL i=0;i<n;++i){
    if(maxi<dp1[i]+dp2[i]-1){
      in=i;
      maxi=dp1[i]+dp2[i]-1;
    }
  }
  index=in;
  cout<<maxi<<"\n";
  // printing Longest biTonic subsequence
  while(hash1[in]!=in){
    in=hash1[in];
    temp1.push_back(v[in]);
  }
  reverse(temp1.begin(),temp1.end());
  debug(temp1);
  temp2.push_back(v[index]);
  while(hash2[index]!=index){
    index=hash2[index];
    temp2.push_back(v[index]);
  }
  debug(temp2);
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