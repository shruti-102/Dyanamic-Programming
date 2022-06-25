//RECURSION
//time o(2^n*m)
//space o(m*n)- stack space
class Solution {
public:
    
    int helper(vector<vector<int>>& grid,int r,int c)
    {
        if( r==0 && c==0)
        {
            return grid[0][0];
        }
        if(r<0 || c<0) return 1e9;
        int sum1=grid[r][c]+helper(grid,r-1,c);
        int sum2=grid[r][c]+helper(grid,r,c-1);
        
        return min(sum1,sum2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        return helper(grid,m-1,n-1);
    }
};


//memoization
//time o(m*n)
//space o(m*n)+[o(path length)]->o(m-1+n-1)

class Solution {
public:
    
    int helper(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& dp)
    {
        if( r==0 && c==0)
        {
            return grid[0][0];
        }
        if(r<0 || c<0) return 1e9;
        
        if(dp[r][c]!=-1) return dp[r][c];
        int sum1=grid[r][c]+helper(grid,r-1,c,dp);
        int sum2=grid[r][c]+helper(grid,r,c-1,dp);
        
       return dp[r][c]=min(sum1,sum2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(grid,m-1,n-1,dp);
    }
};

//TABULATION
//time o(m*n)
//space o(m*n)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=grid[i][j];
                }
                else
                {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0)
                        up=grid[i][j]+dp[i-1][j];
                    if(j>0)
                        left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
