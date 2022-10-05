class Solution
{
    public:
        int findLength(vector<int> &nums1, vector<int> &nums2)
        {
            vector<int>prev(nums2.size()+1,0);
            vector<int>curr(nums2.size()+1,0);
//             int **dp = new int *[nums1.size() + 1];
//             for (int i = 0; i <= nums1.size(); i++)
//             {
//                 dp[i] = new int[nums2.size() + 1];
//             }

//             for (int i = 0; i <= nums1.size(); i++)
//             {
//                 for (int j = 0; j <= nums2.size(); j++)
//                 {
//                     if (i == 0 || j == 0) dp[i][j] = 0;
//                 }
//             }

            // int maxlength = 0;
            // for (int i = 1; i <= nums1.size(); i++)
            // {
            //     for (int j = 1; j <= nums2.size(); j++)
            //     {
            //         if (nums1[i - 1] == nums2[j - 1])
            //         {
            //             dp[i][j] = 1 + dp[i - 1][j - 1];
            //             maxlength = max(maxlength, dp[i][j]);
            //         }
            //         else dp[i][j] = 0;
            //     }
            // }
           
          int maxlength=0;
          for(int i=1;i<=nums1.size();i++){
            for(int j=1;j<=nums2.size();j++){
               if(nums1[i-1]==nums2[j-1]){                
                  curr[j]=1 + prev[j-1];
                   maxlength = max(maxlength, curr[j]);                  
               }
              else{
                curr[j]=0;
              }
            }
            prev=curr;
          
          }
            return maxlength;
        }
};