//time o(n)
//space o(n*n)

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> mp;
        int n=stones.size();
        
        mp[stones[0]]={0};
        
        for(int i=0;i<n;i++)
        {
            int stone=stones[i];
            
            for(auto it: mp[stone])
            {
                
                 mp[stone+it].insert(it);
                 mp[stone+it-1].insert(it-1);
                 mp[stone+it+1].insert(it+1);
            }
            
        }
        
        if(mp[stones[n-1]].size()>0) return true;
        return false;
    }
};
