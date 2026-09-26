int dp[1001];

int fun(int i,vector<vector<int>>&nums){
    if(i>=nums.size()){
        return 0;
    }

    if(dp[i]!=-1) return dp[i];

    int id=nums.size();

  

    int l=i+1;
    int h=nums.size()-1;

    while(l<=h){
        int mid=(l+h)/2;
        if(nums[mid][0]>nums[i][1]){
            id=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }

    int a=1+fun(id,nums);
    int b=fun(i+1,nums);

    return dp[i]=max(a,b);
}


class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        return fun(0,pairs);
    }
};