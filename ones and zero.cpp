//RECURSION
class Solution {
public:
    int x;  //for size
    int helper(vector<vector<int>>& v, int m, int n,int indx)
    {
        if(indx>=x) return 0;
        if(m+n==0) return 0;
        int take=0;
        if(v[indx][0]<=m && v[indx][1]<=n)
        {
            take=1+helper(v,m-v[indx][0],n-v[indx][1],indx+1);
        }
        int nottake=helper(v,m,n,indx+1);
        
        return max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v(strs.size(),vector<int>(2));
        x=strs.size();
     
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            int count0=0,count1=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='0') count0++;
                else count1++;
            }
            v[i][0]=count0;
            v[i][1]=count1;
        }
        
        return helper(v,m,n,0);
    }
};

//MEMOIZATION
class Solution {
public:
    int x;
    int helper(vector<vector<int>>& v, int m, int n,int indx,vector<vector<vector<int>>>& dp)
    {
        if(indx>=x) return 0;
        if(m+n==0) return 0;
        if(dp[m][n][indx]!=-1) return dp[m][n][indx];
        int take=0;
        if(v[indx][0]<=m && v[indx][1]<=n)
        {
            take=1+helper(v,m-v[indx][0],n-v[indx][1],indx+1,dp);
        }
        int nottake=helper(v,m,n,indx+1,dp);
        
        return dp[m][n][indx]=max(take,nottake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v(strs.size(),vector<int>(2));
        x=strs.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(x,-1)));
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            int count0=0,count1=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='0') count0++;
                else count1++;
            }
            v[i][0]=count0;
            v[i][1]=count1;
        }
        
        return helper(v,m,n,0,dp);
    }
};

//TABULATION
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> v(strs.size(),vector<int>(2));
        int x=strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            int count0=0,count1=0;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='0') count0++;
                else count1++;
            }
            v[i][0]=count0;
            v[i][1]=count1;
        }
        
        for(int i=0;i<x;i++)
        {
            int countzero=v[i][0];
            int countone=v[i][1];
            
            for(int zero=m;zero>=countzero;zero--)
            {
                for(int one=n;one>=countone;one--)
                {
                    dp[zero][one]=max(dp[zero-countzero][one-countone]+1,dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
};
