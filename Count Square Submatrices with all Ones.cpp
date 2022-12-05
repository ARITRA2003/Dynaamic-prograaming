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
   LL n,m,sum=0;
   cin>>n>>m;
   vector<vector<LL>> arr(n,vector<LL>(m));
   for(LL i=0;i<n;++i) {
    for(LL j=0;j<m;++j) cin>>arr[i][j];
   }
   //tabulation way
   /*vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(j==0 || i==0){
            dp[i][j]=(arr[i][j]==1);
            sum+=dp[i][j]; 
            continue;
            }
            if(arr[i][j]==1)
            dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            else dp[i][j]=0;
            sum+=dp[i][j];
        }
    }
   cout<<sum<<"\n";
   */
 vector<int> prev(m,0),curr(m,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(j==0 || i==0){
            curr[j]=(arr[i][j]==1);
            sum+=curr[j]; 
            continue;
            }
            if(arr[i][j]==1)
            curr[j]=1+min(prev[j],min(curr[j-1],prev[j-1]));
            else curr[j]=0;
            sum+=curr[j];
        }
         prev=curr;
    }
    cout<<sum<<"\n";
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