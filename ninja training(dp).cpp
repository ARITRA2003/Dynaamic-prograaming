/*Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. Can you help Ninja find out the maximum merit points Ninja can earn?
You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. Your task is to calculate the maximum number of merit points that Ninja can earn.
For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
/*
//Recursion way
LL f(vector<vector<LL>> &v,LL i,LL last){
    if(i==0){
        LL m=INT_MIN;
        for(int j=0;j<=2;j++){
         if(j!=last){
            m=max(m,v[0][j]);
         }
        }
        return m;
    }
    LL maxi=INT_MIN;
    for(int j=0;j<=2;++j){
      if(j!=last){
        LL activity=v[i][j]+f(v,i-1,j);
        maxi=max(maxi,activity);
      }
    }
    return maxi;
}
*/
//1st memorization way
/*
LL f(vector<vector<LL>> &v,LL i,LL last,vector<vector<LL>> &dp){
    if(dp[i][last]!=-1) return dp[i][last];
    if(i==0){
        LL m=INT_MIN;
        for(int j=0;j<=2;j++){
         if(j!=last){
            m=max(m,v[0][j]);
         }
        }
        return m;
    }
     LL maxi=INT_MIN;
    for(int j=0;j<=2;++j){
      if(j!=last){
        LL activity=v[i][j]+f(v,i-1,j,dp);
        maxi=max(maxi,activity);
      }
    }
    return dp[i][last]=maxi;
}
// 2nd way of memorization
LL f(vector<vector<LL>> &v,LL i,LL last,LL a,vector<vector<LL>> &dp){
    if(dp[i][last]!=-1) return dp[i][last];
    if(i==a){
        LL m=INT_MIN;
        for(int j=0;j<=2;++j){
            if(j!=last){
                m=max(m,v[a][j]);
            }
        }
        return dp[i][last]=m;
    }
    LL m=INT_MIN;
    for(int j=0;j<=2;++j){
      if(j!=last){
        m=max(m,v[i][j]+f(v,i+1,j,a,dp));
      }
    }
    return dp[i][last]=m;
}
*/
void answer(){
LL n;
cin>>n;
vector<vector<LL>> v1(n,vector<LL>(3)),dp(n,vector<LL>(4,-1)); 
for(LL i=0;i<n;++i) {
    for(LL j=0;j<3;j++) cin>>v1[i][j];
}
//cout<<f(v1,n-1,3,dp)<<"\n";
/*
f(v1,0,3,n-1,dp);
cout<<dp[0][3]<<"\n";
*/
//Tabulation 1st way
dp[0][0]=max(v1[0][1],v1[0][2]);
dp[0][1]=max(v1[0][0],v1[0][2]);
dp[0][2]=max(v1[0][1],v1[0][0]);
dp[0][3]=max(v1[0][1],max(v1[0][2],v1[0][0]));
for(int i=1;i<n;++i){
    for(int last=0;last<=3;last++){
        dp[i][last]=0;
       for(int j=0;j<=2;++j){
        if(j!=last){
          LL points=dp[i-1][j]+v1[i][j];
          dp[i][last]=max(points,dp[i][last]);
        }
       }
 }
}
cout<<dp[n-1][3]<<"\n";
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
/*
#include<bits/stdc++.h>
typedef  int LL;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> dp(n,-1);
       dp[0]=max(points[0][1],points[0][2]);
   dp[1]=max(points[0][0],points[0][2]);
   dp[2]=max(points[0][1],points[0][0]);
   dp[3]=max(points[0][1],max(points[0][2],points[0][0]));
   for(int i=1;i<n;++i){
       vector<int> temp(4,-1);
    for(int last=0;last<=3;last++){
       for(int j=0;j<=2;++j){
        if(j!=last){
          LL activity=dp[j]+points[i][j];
          temp[last]=max(activity,temp[last]);
        }
       }
 }
  dp=temp;
}
    return dp[3];
}
*/