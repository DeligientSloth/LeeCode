class Solution {
public:
    /*
    可以转化为背包问题求解，这里的背包容量不能用S表示
    经典背包问题:dp[i][j]=max(dp[i-1][j-w[i]]+c[i],dp[i-1][j])，表示为了凑足容量为j的背包所能获取的价值
    凑钱问题中:dp[i][j]=dp[i-1][j-coins[i]]+dp[i-1][j]，表示可以转化为用前面i-1个钱币凑j-coins[i]块或者凑j块
    则这个问题: dp[i][j]=dp[i-1][j-nums[i]](+nums[i])+dp[i-1][j+nums[i]](-nums[i])
    这里背包容量j的上限和下限不能是0-S，实际应该去全集:-sum->+sum，前面的问题中凑够S块钱就结束了，凑负数的钱没用意义，但这里
    凑负数的钱还可以加回来
    因此：用dp[i][j]表示用用前面i个数凑足j数值的方法,-sum<=j<=sum，映射一下，加sum使之变为正数：0<=j<=2*sum;一共2*sum+1个数
    最后返回:dp[nums.size()][S+sum]
    */
    int findTargetSumWays(vector<int>& nums, int S) {
        //用滚动数组的方式实现
        if(nums.empty()) return 0;
        int sum=0;
        for(int num:nums) sum+=num;
        //if(sum==S) return 1;这道题可能有问题！当最后一个num==0时，temp[2*sum]=dp[2*sum-0]+dp[2*sum+0];居然有两种表示
        if(S>sum||S<-sum) return 0;
        vector<int> dp(2*sum+1,0);
        dp[sum]=1;//对应dp[-sum->sum][0]=1
        for(int num:nums){
            //num逐个遍历，表示用前面的i个数
            vector<int> temp(2*sum+1,0);//记录这次运算的结果
            for(int j=0;j<=2*sum;j++){
                if(j-num>=0) temp[j]+=dp[j-num];
                if(j+num<=2*sum) temp[j]+=dp[j+num];
            }
            dp=temp;//更新dp
        }
        return dp[S+sum];
    }
};
class Solution {
public:
    /*
    数学转化一下：
    positive-negatitive=S positive+negatitive=sum
    positive=(S+sum)/2，如果为奇数则不存在这样的组合，这样问题又可以转化为在数组中取数使得和为某一个数
    */
    int findTargetSumWays(vector<int>& nums, int S) {
        if(nums.empty()) return 0;
        int sum=0;
        for(int num:nums) sum+=num;
        if(S>sum||S<-sum||((S+sum)&1)) return 0;
        sum=(S+sum)>>1;
        vector<int> dp(sum+1,0);//申请sum+1个空间
        dp[0]=1;
        for(int num:nums){
            for(int j=sum;j>=num;j--)
                dp[j]=dp[j-num]+dp[j];
        }
        return dp[sum];
    }
};
