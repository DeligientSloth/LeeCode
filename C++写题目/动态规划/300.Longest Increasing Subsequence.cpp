class Solution {
public:
    /*
    用动态规划法: dp[i]表示以i结尾的最长上升子序列，则
    dp[i]=max{dp[k]+1 a[k]<a[i] k=0->i-1}
    */
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(),1);//初始化为1
        int maxLength=1;
        for(int i=1;i<nums.size();i++){
            for(int k=0;k<i;k++)
                if(nums[k]<nums[i]){
                    dp[i]=max(dp[i],dp[k]+1);
                    if(dp[i]>maxLength) maxLength=dp[i];
                }
        }
        return maxLength;
    }
};