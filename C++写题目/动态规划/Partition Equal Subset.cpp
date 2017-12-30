class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.empty()||nums.size()==1) return false;
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum&1) return false;
        sum=sum>>1;
        vector<bool> dp(sum+1,false);//在子集合取数使得和等于sum/2,dp:0->sum
        dp[0]=true;
        for(int num:nums){
            for(int j=sum;j>=num;--j){
                dp[j]=dp[j]||dp[j-num];
                if(dp[sum]==true) return true;
            }
        }
        return dp[sum];
    }
};