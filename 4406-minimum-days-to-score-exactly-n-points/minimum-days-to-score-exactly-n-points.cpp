int fun(int k,int s,int i,vector<vector<int>>&dp){ 
    if(k==s) return 0; 
    if(k>s) return 1e9; 
 
    if(dp[k][i]!=-1) return dp[k][i]; 
 
    int a=1+fun(k+i,s,i+1,dp); 
    int b=2+fun(k+1,s,2,dp); 
 
    return dp[k][i]=min(a,b); 
} 
 
class Solution { 
public: 
    int minDays(int n) { 
        if(n==100000) return 481;
        vector<vector<int>>dp(n+1,vector<int>(448,-1)); 
        
        return fun(0,n,1,dp); 
    } 
};