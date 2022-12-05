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
vector<LL> f(LL b,LL size){
    vector<LL> v(size,0);
    LL count=0;
    while(b){
        if(b&1) v[count]=1;
        count++;
        b/=2;
    }
    return v;
}
void answer(){
    LL a,b,c,sum=0,sum1=0,sum2=0;
    cin>>a>>b>>c;
    vector<LL> v1(a,0),v2(a,0);
    v1=f(b,a);
    v2=f(c,a);
    for(LL i=0;i<a;++i){
        if(v1[i]==0 && v2[i]==0){
          sum+=(1<<i);
        }
        if(v1[i]==0){
            sum1+=(1<<i);
        }
        if(v2[i]==0){
            sum2+=(1<<i);
        }
    }
    LL t1=(b^sum1)*(c^sum1);
    LL t2=(b^sum2)*(c^sum2);
    LL t3=(b^sum)*(c^sum);
    LL x= (t1>t2)?  (t1>t3)?  t1 : t3    :   (t2>t3)?   t2  : t3 ;
    if(x==t1) {
        cout<<sum1<<"\n";
        return;
    }
    if(x==t2) {
        cout<<sum2<<"\n";
        return;
    }
    if(x==t3) {
        cout<<sum<<"\n";
        return;
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt","w",stderr);
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