//time o(n*m)
//space o(n*m)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int left=INT_MAX,right=INT_MAX,up=INT_MAX;
                if(j>0) left=dp[i-1][j-1];
                if(j+1<m)right=dp[i-1][j+1];
                up=dp[i-1][j];
                
                dp[i][j]=min(up,min(left,right));
                dp[i][j]+=matrix[i][j];
            }
        }
        int minpath=INT_MAX;
        for(int i=0;i<m;i++)
        {
           minpath= min(minpath,dp[n-1][i]);
        }
        return minpath;
    }
};

//SPACE OPTIMIZATION TABULATION
//time o(n*m)
//space o(n)+ o(n)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        vector<int> prev(m,0),cur(m,0);
        
        for(int i=0;i<m;i++)
        {
            prev[i]=matrix[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int left=INT_MAX,right=INT_MAX,up=INT_MAX;
                if(j>0) left=prev[j-1];
                if(j+1<m)right=prev[j+1];
                up=prev[j];
                
                cur[j]=(min(up,min(left,right))+matrix[i][j]);
                
            }
            prev=cur;
        }
        int minpath=INT_MAX;
        for(int i=0;i<m;i++)
        {
           minpath= min(minpath,prev[i]);
        }
        return minpath;
    }
};
