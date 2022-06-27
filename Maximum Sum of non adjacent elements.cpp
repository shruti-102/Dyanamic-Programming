//time o(n)
//space o(n)
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    vector<vector<int>> dp(2,vector<int>(n));
    dp[0][0]=nums[0];
    dp[1][0]=0;
    for(int i=1;i<n;i++)
    {
        int take=dp[1][i-1]+nums[i];
        int nottake=max(dp[0][i-1],dp[1][i-1]);
        
        dp[0][i]=take;
        dp[1][i]=nottake;
    }
    
    return max(dp[0][n-1],dp[1][n-1]);
}

//time o(n)
//space o(1)
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n=nums.size();
    int take=nums[0];
    int nottake=0;
    for(int i=1;i<n;i++)
    {
        int newtake=nottake+nums[i];
        int newnottake=max(take,nottake);
        
        take=newtake;
        nottake=newnottake;
    }
    
    return max(take,nottake);
}
