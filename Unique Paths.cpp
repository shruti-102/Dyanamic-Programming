//RECURSION
//time o(2^m*n)
//space o(path length) ~ o(m-1+n-1)
class Solution {
public:
    int helper(int m,int n)
    {
        if(m==0 && n==0)
            return 1;
        if(m<0 ||n<0) return 0;
        return helper(m-1,n)+helper(m,n-1);
    }
    int uniquePaths(int m, int n) {
        return helper(m-1,n-1);
    }
};

//MEMOIZATION
//time o(m*n)
//space o(m*n) + o(m-1+n-1)
class Solution {
public:
    int helper(int m,int n,vector<vector<int>> &dp)
    {
        if(m==0 && n==0)
            return 1;
        if(m<0 || n<0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n]= helper(m-1,n,dp)+helper(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};

//TABULATION
//time o(m*n)
//space o(m*n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                 int up=0,left=0;
                if(i==0 && j==0) dp[0][0]=1;
                else
                {
                    if(i-1>=0) up=dp[i-1][j];
                    if(j-1>=0) left=dp[i][j-1];
                    
                    dp[i][j]=up+left;
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};
