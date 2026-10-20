class Solution {

    public int[] leftGreatestElement(int[] height){
        int[] leftMaxElements = new int[height.length];

        int max = 0;

        for(int i=0;i<height.length;i++){
            leftMaxElements[i] = max;

            if(height[i]>max)
            max = height[i];
        }

        return leftMaxElements;
    }

    public int[] rightGreatestElement(int[] height){
        int[] rightMaxElements = new int[height.length];

        int max = 0;

        for(int i=height.length-1;i>=0;i--){
            rightMaxElements[i] = max;

            if(height[i]>max)
            max = height[i];
        }

        return rightMaxElements;
    }


    public int trap(int[] height) {

        int[] leftMaxElements = leftGreatestElement(height);
        int[] rightMaxElements = rightGreatestElement(height);

        int trappedWater = 0;


        for(int i=0;i<height.length;i++){

            int water = Math.min(leftMaxElements[i],rightMaxElements[i]) - height[i];

            if(water>0)
            trappedWater+=water;
        }

        return trappedWater;
    }
}
