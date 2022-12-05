/*Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money 
hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one.
Meanwhile, adjacent houses have a security system connected,and it will automatically contact the police if two adjacent
 houses were broken into on the same night.
You are given an array/list of non-negative integers 'ARR'
 representing the amount of money of each house. Your task
 is to return the maximum amount of money Mr. X can rob tonight without alerting the police.*/
#include <bits/stdc++.h>
using namespace std;
long long int f(vector<int> v){
	long long int n=v.size();
	long long int prev2=0,prev1=v[0],curr=0;
  for(long long int i=1;i<n;i++){
  	long long int pick=v[i],nonpick=prev1;
  	if(i>1) pick+=prev2;
      curr=max(pick,nonpick);
      prev2=prev1;
      prev1=curr;
    }
    return prev1;
}
int main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif // ONLINE_JUDGE
  int T;
  cin>>T;
  while(T--){
  long long int n;
  cin>>n;
  vector<int> v(n),v1,v2;
  for(int i=0;i<n;i++) cin>>v[i];
  	if(n==1){
  		cout<<v[0]<<"\n";
  	}
  	else{
  for(int i=0;i<n;i++){
  	if(i!=0) v1.push_back(v[i]);
  	if(i!=n-1) v2.push_back(v[i]);
  }
  /*for(auto j:v1){
  	cout<<j<<"\t";
  }
    cout<<"\n";
  for(auto j:v2){
  	cout<<j<<"\t";
  }
  cout<<"\n";*/
  cout<<max(f(v1),f(v2))<<"\n";
}
}
}