//TABULATION
//time o(n*target)
//space o(n*target)
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    if(num[0]<=tar) dp[0][num[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=tar;j++)
        {
            int notpick=dp[i-1][j];
            int pick=0;
            if(j>=num[i]) pick=dp[i-1][j-num[i]];
            
            dp[i][j]=pick+notpick;
        }
    }
    return dp[n-1][tar];
}

//TABULATION WITH SPACE OPTIMIZATION
//time o(n*target)
//space o(target)
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n=num.size();
    vector<int> curdp(tar+1,0);
    vector<int> prevdp(tar+1,0);
    prevdp[0]=1;
    if(num[0]<=tar) prevdp[num[0]]=1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=tar;j++)
        {
            if(j==0) curdp[j]=1;
            int notpick=prevdp[j];
            int pick=0;
            if(j>=num[i]) pick=prevdp[j-num[i]];
            
            curdp[j]=pick+notpick;
        }
        prevdp=curdp;
    }
    return prevdp[tar];
}
