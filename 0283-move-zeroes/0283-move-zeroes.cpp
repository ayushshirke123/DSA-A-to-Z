class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int result=-1;
        for(int i=0; i<n; i++){
            if(nums[i]!=0){
                result++;
                swap(nums[i],nums[result]);
                
            }
        }
    }
};