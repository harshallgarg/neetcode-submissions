class Solution {
    public boolean hasDuplicate(int[] nums) {
        
        Set<Integer> set1 = new HashSet<>();
        
        for(int i=0;i<nums.length;i++){
            if(set1.contains(nums[i])==false)
            set1.add(nums[i]);

            else
            return true;
        }

        return false;
    }
}