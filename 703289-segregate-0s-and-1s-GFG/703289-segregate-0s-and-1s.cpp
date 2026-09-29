class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
       int i=0, j=arr.size()-1;
       while(i<j){
       while(arr[i]==0 && i< j){
           i++;
       }
       while(arr[j]==1 && i<j){
           j--;
           
       }
       if(i<j){
           swap(arr[i],arr[j]);
           i++;
           j--;
       }
       }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna