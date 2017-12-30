class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int low=0,high=array.size()-1;
        while(low<=high){
            int mid=low+((high-low)>>1);
            if(array[mid]>target) high=mid-1;
            else if(array[mid]<target) low=mid+1;
            else{
                if(mid==0||array[mid-1]!=array[mid]) return mid;
                else high=mid-1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int low=0,high=array.size()-1;
        while(low<high){
            int mid=low+((high-low)>>1);
            if(array[mid]>target) high=mid-1;
            else if(array[mid]<target) low=mid+1;
            else high=mid;
        }
        if(array[low]==target) return low;
        return -1;
    }
};
