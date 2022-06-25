//asked in microsoft
//time: o(m*n)
//space: o(m*n)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 && j==n-1)
                {
                    dp[i][j]=min(0,dungeon[i][j]);  //zero tb lege jb +ve value h ku k zarurat n h extra power
                                                    //k islie min k agr +ve ho to 0 le or negative ho to negative value le
                }
                else if(i==m-1)
                {
                    dp[i][j]=min(0,dungeon[i][j]+dp[i][j+1]);   //right only possible
                }
                else if(j==n-1)
                {
                    dp[i][j]=min(0,dungeon[i][j]+dp[i+1][j]);   //down only possible
                }
                else
                    dp[i][j]=min(0,dungeon[i][j]+max(dp[i+1][j],dp[i][j+1]));   //both possible ways
                //take the max eg: -7 and -3 then -3 will cost less
                //eg: 10 and -8 then 10 will not cost any extra power
                //so take max
                //then compute it with present index value and take the min
            }
        }
        
        int energy=abs(dp[0][0])+1;
        return energy;
    }
};
