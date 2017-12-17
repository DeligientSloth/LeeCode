class Solution {
public:
    //快排方法
    void swap(vector<int>& nums,int x,int y){
        if(x==y) return;
        int temp=nums[x];
        nums[x]=nums[y];
        nums[y]=temp;
    }
    int partition(vector<int>& nums,int low,int high){
        if(low==high) return low;
        int i=low-1,j=low;//i指向当前找到的最后一个小于主元的元素
        int pivot=nums[low];
        swap(nums,low,high);
        for(;j<=high-1;j++){
            if(nums[j]<=pivot){
                i++;
                if(i!=j) swap(nums,i,j);
            }
        }
        swap(nums,i+1,high);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()||k<1||k>nums.size()) return -1;
        int low=0,high=nums.size()-1,index=0;
        while(low<=high){
            index=partition(nums,low,high);
            if(nums.size()-index==k) break;
            else if(nums.size()-index<k) high=index-1;
            else low=index+1;
        }
        return nums[index];
    }
};
构建小顶堆
class Solution {
public:
    //堆排序办法
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()||k<1) return -1;
        make_heap(nums.begin(),nums.begin()+k,greater<int>());//小顶堆
        for(int i=k;i<nums.size();i++){
            if(nums[i]>nums[0]){
                //int temp=nums[i];
                //nums[i]=nums[0];
                //nums[0]=temp;
                //make_heap(nums.begin(),nums.begin()+k,greater<int>());//o(k)
                pop_heap(nums.begin(),nums.begin()+k,greater<int>());//交换nums[0]和nums[k-1];使[0,k-1)之间构成最小堆
                nums[k-1]=nums[i];
                push_heap(nums.begin(),nums.begin()+k,greater<int>());
            }
        }
        return nums[0];
    }
};
class Solution {
public:
    //堆排序办法
    void Heap_Adjust(vector<int>& nums,int begin,int end){//把begin->end之间构造一个最小堆，除了begin之外均满足最小堆定义
        int nchild;
        for(int k=begin,temp=nums[k];2*k+1<=end;k=nchild){
            nchild=2*k+1;
            if(nchild+1<=end&&nums[nchild]>nums[nchild+1]) nchild=nchild+1;
            if(temp>nums[nchild]){
                nums[k]=nums[nchild];
                nums[nchild]=temp;
            }else break;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
       for(int i=k/2-1;i>=0;i--)//循环k/2次
           Heap_Adjust(nums,i,k-1);
       for(int i=k;i<nums.size();i++){
           if(nums[i]>nums[0]){
               int temp=nums[i];
               nums[i]=nums[0];
               nums[0]=temp;
               Heap_Adjust(nums,0,k-1);
           }
       }
      return nums[0];
    }
};
