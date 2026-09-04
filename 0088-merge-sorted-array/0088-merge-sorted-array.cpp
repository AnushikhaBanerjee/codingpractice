class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int indx=m+n-1, i=m-1, j=n-1;
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[indx]=nums1[i];
                indx--,i--;
            }
            else{
                nums1[indx]=nums2[j];
                indx--,j--;
            }
        }
        while(j>=0){
            nums1[indx]=nums2[j];
            indx--,j--;

        }

        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna