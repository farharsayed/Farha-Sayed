// 3. Contains Duplicate
// Given an integer array nums, return true if any value appears at
// least twice in the array, and return false if every element is
// distinct.
// Input: nums = [1,2,3,1]
// Output: true



class containsDuplicate {
    public static void main(String[] args)
    {

        // given test case
        int nums[] = {1,2,3,1};

        // code
        boolean check = false;
        int unique[] = new int [nums.length];
        int pointer = 1;
        for(int a = 0; a<nums.length; a++)
        {
            for(int b = 0; b<pointer; b++)
            {
                if(nums[a] == unique[b])
                {
                    check = true;
                    break;
                }
                else
                {
                    
            unique[pointer] = nums[a];
                }
            }
        }
        System.out.println(check);
        
    }
}