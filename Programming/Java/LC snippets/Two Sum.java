// 1. Two Sum
// Given an array of integer nums and an integer target, return
// indices of the two numbers such that they add up to the target.
// You may assume that each input would have exactly one solution,
// and you may not use the same element twice.
// You can return the answer in any order.
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1]

class TwoSum {

    public static void main(String[] args) {
        //given nums = {1,2,7,9,5}
        //given target = 6

        // Scanner sc = new Scanner(System.in);
        // System.out.println("Please initialize the array, first enter no of elements");
        // int n = sc.nextInt();
        // System.out.println("Now enter each element one at a time");
        // int nums[] = new int[n];
        // for(int a = 0; a<n; a++)
        // {
        //     System.out.println("Enter element "+a);
        //     nums[a]=sc.nextInt();
        // }
        // System.out.println("Enter target");
        // int target = sc.nextInt();


        // initializing for test case
         int nums[]={1,2,7,9,5};
         int target=6;


        //  start of code
         int ans[] = new int[2];
        int n = nums.length;
         for(int a = 0; a<n-1; a++)
         {
            for(int b = a+1; b<nums.length; b++)
            {
                if(nums[a]+nums[b]==target)
                {
                    ans[0] = a;
                    ans[1]=b;
                    System.out.println(a+b);
                    System.out.println("a = " + a + "and element = " + nums[a]);
                }
            }
         }
         System.out.println(ans[0] + " " + ans[1]);








    }
}
