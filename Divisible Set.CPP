#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
void answer(){
LL n;
cin>>n;
vector<LL> v(n),v1,dp(n,1),hash(n,0);
for(LL i=0;i<n;++i) cin>>v[i];
sort(v.begin(),v.end());
LL lastindex=0,maxi=-1;
for(LL i=1;i<n;++i){
    hash[i]=i;
    for(LL j=0;j<i;++j){
        if(v[i]%v[j]==0 && dp[j]+1>dp[i]){
            dp[i]=1+dp[j];
            hash[i]=j;
        }
    }
    if(maxi<dp[i]){
        maxi=dp[i];
        lastindex=i;
    }
    }
    v1.push_back(v[lastindex]);
    while(hash[lastindex]!=lastindex){
        lastindex=hash[lastindex];
        v1.push_back(v[lastindex]);
    }
    reverse(v1.begin(),v1.end());
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<"\n";
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL ARITRASEN=1,x=0;
    cin>>ARITRASEN;
    while(ARITRASEN--)
    {
    //cout<<"Case #"<<++x<<":\t";
    answer();
    /*if(answer()) cout<<"YES\n";
    else cout<<"NO\n";*/
    }
    return 0;
}