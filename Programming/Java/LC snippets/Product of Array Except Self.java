// 4. Product of Array Except Self

// Given an integer array nums, return an array answer such that
// answer[i] is equal to the product of all the elements of nums
// except nums[I].
// The product of any prefix or suffix of nums is guaranteed to fit in a
// 32-bit integer.
// You must write an algorithm that runs in O(n) time and without
// using the division operation.
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]




class ProductofArrayExceptSelf
{

    // we can't use division so can't multiple ALL elements and then just go through dividing the i'th element
    // HAS to be O(n) which means no nested loop
    // soln: go through from left to right and multiply everything on the left of the i'th element
    // then go through from right to left and multiple eveyrthing on its right and that's the answer


    public static void main(String[] args)
    {

        //given test case
        int nums[] = {1,2,3,4};

        // code
        int n = nums.length;
        int ans[] = new int [n];
        
        // left pass
        ans[0] = 1;
        for(int a = 1; a<n; a++)
        {
            ans[a] = nums[a-1]*ans[a-1];
        }
        
        // right pass
        int right=1;
        for(int a = n-1; a>=0; a--)
        {
            ans[a]=ans[a]*right;
            right*=nums[a];
        }


        // printing to check
        for(int a = 0; a<n; a++)
        {
        System.out.print(ans[a] + " ");
        }
    }
}