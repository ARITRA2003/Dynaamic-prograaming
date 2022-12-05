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
/*LL f(vector<vector<LL>> &v,LL m,LL i,LL j,vector<vector<LL>> &dp){
//if(j>=m || j<0 || i<0) return 0;
if(i==0) return v[i][j];
if(dp[i][j]!=INT_MIN) return dp[i][j];
LL dl=INT_MIN,dr=INT_MIN;
if(j>0)   dl=v[i][j]+f(v,m,i-1,j-1,dp);
if(j+1<m) dr=v[i][j]+f(v,m,i-1,j+1,dp);
LL up=v[i][j]+f(v,m,i-1,j,dp);
return dp[i][j]=max(max(dl,dr),up);
}*/
void answer(){
LL n,m,maxi=INT_MIN;
cin>>n>>m;
vector<vector<LL>> v(n,vector<LL>(m,0)),dp(n,vector<LL>(m,INT_MIN));
for(LL i=0;i<n;++i) 
for(LL j=0;j<m;++j) cin>>v[i][j];
/*for(LL j=0;j<m;++j){
  maxi=max(maxi,f(v,m,n-1,j,dp));
}
cout<<maxi<<"\n";*/
// tabulation form 
/*for(LL i=0;i<n;++i){ 
for(LL j=0;j<m;++j) 
{
if(i==0)
dp[i][j]=v[i][j];
else{
LL dl=INT_MIN,dr=INT_MIN;
if(j>0)   dl=v[i][j]+dp[i-1][j-1];
if(j+1<m) dr=v[i][j]+dp[i-1][j+1];
LL up=v[i][j]+dp[i-1][j];
dp[i][j]=max(max(dl,dr),up);
}
if(i==n-1)maxi=max(maxi,dp[i][j]);
}
} 
cout<<maxi<<"\n";
*/
vector<LL> temp(m,0),curr(m,0);
for(LL i=0;i<m;++i)
{
  temp[i]=v[0][i];
}
for(LL i=1;i<n;++i){ 
for(LL j=0;j<m;++j) 
{
LL dl=INT_MIN,dr=INT_MIN;
if(j>0)   dl=v[i][j]+temp[j-1];
if(j+1<m) dr=v[i][j]+temp[j+1];
LL up=v[i][j]+temp[j];
curr[j]=max(max(dl,dr),up);
}
temp=curr;
}

LL ans=*max_element(temp.begin(),temp.end());
cout<<ans<<"\n";
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