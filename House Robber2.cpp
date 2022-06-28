//time o(n)
//space o(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<vector<int>> dp (2,vector<int>(n));
        dp[0][0]=nums[0];
        dp[1][0]=0;
        for(int i=1;i<n;i++)
            {
            int take=dp[1][i-1]+nums[i];
            int nottake=max(dp[0][i-1],dp[1][i-1]);
            dp[0][i]=take;
            dp[1][i]=nottake;
        }
        int including_house0=dp[1][n-1];
        
        dp[0][n-1]=nums[n-1];
        dp[1][n-1]=0;
        
        for(int i=n-2;i>=0;i--)
        {
            dp[1][i]=max(dp[0][i+1],dp[1][i+1]);
            dp[0][i]=dp[1][i+1]+nums[i];
        }
        int including_house1=dp[1][0];
        
         return max(including_house0,including_house1);           
    }
};
