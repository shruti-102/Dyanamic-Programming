//time o(n*k*k)
//space o(n*k)

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        int n=costs.size();
        if(n==0) return 0;
        int color=costs[0].size();   //number of colors
        
        vector<vector<int>> dp(n,vector<int>(color,0));

        for(int i=0;i<color;i++)
        {
            dp[0][i]=costs[0][i];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<color;j++)
            {
                int prevcolor=j;
                int mincost=INT_MAX;
                for(int k=0;k<color;k++)
                {
                    if(k!=prevcolor)
                    {
                        mincost=min(mincost,dp[i-1][k]);
                    }
                }
                dp[i][prevcolor]=costs[i][j]+mincost;
            }
        }
        int mincost=INT_MAX;
        for(int i=0;i<color;i++)
        {
            mincost=min(mincost,dp[n-1][i]);
        }
        return mincost;
        
    }
};
