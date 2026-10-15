class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        Map<Integer, Integer> map = new HashMap<>();

        for(int i=0;i<nums.length;i++){            

            int findNum = target - nums[i];

            if(map.containsKey(findNum)==true)
            return new int[]{map.get(findNum),i};
            
            map.put(nums[i],i);
        }

        return new int[]{0,0};
    }
}