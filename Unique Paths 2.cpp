//RECURSION
//time o(2^n*m)
//space o(path length) ~ o(n-1+m-1)
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& obstacleGrid)
    {
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        return helper(i-1,j,obstacleGrid)+helper(i,j-1,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        return helper(n-1,m-1,obstacleGrid);
    }
};

//MEMOIZATION
//time o(n*m)
//space o(path length) ~ o(n-1+m-1)
class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp)
    {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        
        
        return dp[i][j]=helper(i-1,j,obstacleGrid,dp)+helper(i,j-1,obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(n-1,m-1,obstacleGrid,dp);
    }
};
