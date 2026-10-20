class Solution {
    public int maxArea(int[] heights) {
        
        int i=0;
        int j = heights.length-1;

        int maxWater = 0;

        while(i<j){
            int waterCollected = (j-i) * Math.min(heights[i],heights[j]);
            maxWater = Math.max(maxWater, waterCollected);
            
            if(heights[i]<heights[j])
            i++;
            else
            j--;
        }

        return maxWater;
    }
}
