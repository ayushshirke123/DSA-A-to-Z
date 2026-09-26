class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;
        int xorsum=0;
        for(int i: nums){
            xorsum=xorsum^i;
        }
        for(int i=0; i<=n; i++){
            xorsum^=i;
        }
        return xorsum;
    }
}