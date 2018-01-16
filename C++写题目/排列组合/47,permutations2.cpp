class Solution {
public:
    vector<vector<int>> retS;
    void dfspermute(vector<int> nums,int start){
        if(start>=nums.size()-1) retS.push_back(nums);
        else{
            for(int k=start;k<nums.size();k++){
                if(start!=k&&nums[start]==nums[k]) continue;
                swap(nums[start],nums[k]);
                dfspermute(nums,start+1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty()) return retS;
        sort(nums.begin(),nums.end());
        dfspermute(nums,0);
        return retS;
    }
};
