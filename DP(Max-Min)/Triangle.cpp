//time o(n*n)
//space o(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                int choice1=1e9,choice2=1e9;
                if(j-1>=0)
                    choice1=triangle[i-1][j-1];
            
                if(j!=i)
                    choice2=triangle[i-1][j];
                
                triangle[i][j]=min(choice1,choice2)+triangle[i][j];
            }
        }
        int minpathsum=INT_MAX;
        for(int j=0;j<n;j++)
        {
            minpathsum=min(minpathsum,triangle[n-1][j]);
        }
        return minpathsum;
    }
};
