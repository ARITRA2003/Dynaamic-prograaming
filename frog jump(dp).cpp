/*There is a frog on the 1st step of an N stairs long staircase. The frog
 wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.
 If Frog jumps from ith to jth stair, the energy lost in the jump is given 
 by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can 
 jump either to (i+1)th stair or to (i+2)th stair. Your task is to find 
 the minimum total energy used by the frog to reach from 1st stair to Nth 
 stair.*/
#include <bits/stdc++.h>
using  namespace std;
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    if(n==0) return 0;
    int left= frogJump(n-1,heights) + abs(heights[n]- heights[n-1]);
    int right=INT_MAX;
    if(n>1) right= frogJump(n-2,heights) + abs(heights[n]- heights[n-2]);
    return min(left,right);
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