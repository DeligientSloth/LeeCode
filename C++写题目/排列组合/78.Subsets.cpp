class Solution {
public:
    vector<vector<int>> retS;
    void subsetshelper(vector<int>& nums,int start,vector<int> B){
        if(start>=nums.size()){
            retS.push_back(B);
            return;
        }
        subsetshelper(nums,start+1,B);
        B.push_back(nums[start]);
        subsetshelper(nums,start+1,B);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return retS;
        vector<int> B;
        subsetshelper(nums,0,B);
        return retS;
    }
};

class Solution {
public:
    vector<vector<int>> retS;
    vector<int> B;
    void subsetshelper(vector<int>& nums,int start){
        if(start>=nums.size()){
            retS.push_back(B);
            return;
        }
        subsetshelper(nums,start+1);
        B.push_back(nums[start]);
        subsetshelper(nums,start+1);
        B.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return retS;
        subsetshelper(nums,0);
        return retS;
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> retS;
        if(nums.empty()) return retS;
        int len=nums.size();
        int n=1<<len;
        for(int item=0;item<n;item++){
            vector<int> vec;
            for(int idx=0;idx<len;idx++){//检查每一位
                if(item&(1<<idx)) vec.push_back(nums[idx]);
            }
            retS.push_back(vec);
        }
        return retS;
    }
};

