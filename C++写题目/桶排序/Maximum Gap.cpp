class Solution {
public:
    class Bucket
    {
    public:
        bool emptyBucket=true;
        int Max=INT_MIN;
        int Min=INT_MAX;
    };

    int maximumGap(vector<int>& nums) {
        if(nums.empty()||nums.size()==1) return 0;
        vector<Bucket> buckets(nums.size());
        int Max=*max_element(nums.begin(),nums.end());
        int Min=*min_element(nums.begin(),nums.end());
        double delta=double((Max-Min))/(nums.size()-1);
        if(delta==0) return 0;//，每个数都相同
        for(size_t i=0;i<nums.size();i++){
           int bucketIndex=(nums[i]-Min)/delta;
           if(buckets[bucketIndex].Min>=nums[i]) buckets[bucketIndex].Min=nums[i];
           if(buckets[bucketIndex].Max<=nums[i]) buckets[bucketIndex].Max=nums[i];
           buckets[bucketIndex].emptyBucket=false;
        }
        int maxGap=0,prevMax=buckets[0].Max,gap=0;
        for(size_t i=1;i<nums.size();i++){
            if(buckets[i].emptyBucket==false) {
                gap=buckets[i].Min-prevMax;
                if(buckets[i].Max!=INT_MIN) prevMax=buckets[i].Max;
            }
            if(gap>maxGap) maxGap=gap;
        }
        return maxGap;
    }
};
