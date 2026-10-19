class Solution {
    public int longestConsecutive(int[] nums) {

        int ans = 0;
        Set<Integer> occurenceSet = new HashSet<>(); 
        Set<Integer> sequenceStartSet = new HashSet<>();

        for(int i=0;i<nums.length;i++){
            occurenceSet.add(nums[i]);
        }

        for(int i=0;i<nums.length;i++){
            if(occurenceSet.contains(nums[i]-1)==false)
            sequenceStartSet.add(nums[i]);
        }

        for(var i:sequenceStartSet){
            int start = i;

            int count = 1;
            
            while(occurenceSet.contains(start+1)==true)
            {
                count++;
                start++;
            }

            if(ans<count){
                ans = count;
            }
        }

        return ans;
    }
}
