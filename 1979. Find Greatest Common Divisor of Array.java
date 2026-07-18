class Solution {
    public int findGCD(int[] nums) {
      int mn = nums[0];
        int mx = nums[0];

        for (int num : nums) {
            if (num < mn)
                mn = num;
            if (num > mx)
                mx = num;
        }

        while (mx != 0) {
            int temp = mx;
            mx = mn % mx;
            mn = temp;
        }

        return mn;  
    }
}
