#include <bits/stdc++.h>
using  namespace std;
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n==0) return 0;
    int ans=INT_MAX;
    int k=n;
    while(k)
    {
        if
    }
    return ans;
}
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin>>v[i];
	cout<<frogJump(n-1,v)<<"\n";
} 