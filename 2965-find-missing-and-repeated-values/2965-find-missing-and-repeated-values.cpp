class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int total=n*n;
        int rep=0;
        int miss=0;
        for(int nums=1;nums<=total;nums++){
            int cnt=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==nums){
                        cnt++;
                    }
                }
            }
            if(cnt==2) rep= nums;
            if(cnt==0) miss= nums;
        }
        return{rep,miss};
        
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna