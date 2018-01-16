class Solution {
public:
    vector<vector<int>> retS;
    void dfspermute(vector<int>& nums,int start){
        if(start>=nums.size()-1) retS.push_back(nums);
        else{
            for(int k=start;k<nums.size();k++){
                swap(nums[start],nums[k]);
                dfspermute(nums,start+1);
                swap(nums[start],nums[k]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return retS;
        dfspermute(nums,0);
        return retS;
    }
};