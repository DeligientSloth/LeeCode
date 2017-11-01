/*
基本思路是确定一个数nums[i]后，查找target-nums[i]是否在数组中，可以通过建立哈希表实现
在C++中，可以通过map或者unordered_map实现，但是map是通过红黑树实现查找的，时间效率没有那么高
*/
/*解法一，分开两个循环来写，第一个循环遍历数据建立map，第二个循环是遍历数组查找target-nums[i]，时间9ms*/
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> res;
    for (vector<int>::size_type i = 0; i < nums.size(); i++)
      m[nums[i]] = i;
    for (vector<int>::size_type i = 0; i < nums.size(); i++) {
      int t = target - nums[i];
      if (m.count(t) != 0 && m[t] != i) {
        return { i,m[t] };
      }
    }
    return {};
  }
};
/*解法二，两个循环合并，先确定每个元素nums[i]是否在map中，在则返回结果，不在就插入*/
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> res;
    for (vector<int>::size_type i = 0; i<nums.size(); i++) {
      int t = target - nums[i];
      if (m.count(t) != 0) {
        return { m[t],i };
      }
      m[nums[i]] = i;
    }
    return {};
  }
};
