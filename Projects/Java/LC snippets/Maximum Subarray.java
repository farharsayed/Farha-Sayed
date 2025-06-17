// 5. Maximum Subarray
// Given an integer array nums, find the subarray with the largest
// sum, and return its sum.
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum of 1.

class MaxSubarray {

    public static void main(String[] args) {

        // given test case
        int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

        // code
        int n = nums.length;
        int max = 1, start = 0, end = 0;
        int potential = 0;
        for (int a = 0; a < n-1; a++) {
            potential=nums[a];
            for (int b = a+1; b < n; b++) {
                potential+=nums[b];
                if(potential>max)
                {
                    
                    max=potential;
                   start = a;
                   end = b;
            }
        }
            potential= 0;
        }

        System.out.println(max);
        for (int i = start; i <= end; i++) {
            System.out.print(nums[i] + " ");
        }
        
        
    }
}





// optimized approach to this is called Kadane's Algorithm

