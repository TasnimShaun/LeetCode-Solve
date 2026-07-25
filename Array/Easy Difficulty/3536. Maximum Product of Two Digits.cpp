/* 
Question: you are given a positive integer n.
Return the maximum product of any two digits in n.
Note: You may use the same digit twice if it appears more than once in n.

Example 1:

Input: n = 31
Output: 3
Explanation:
The digits of n are [3, 1].
The possible products of any two digits are: 3 * 1 = 3.
The maximum product is 3.
Example 2:
Input: n = 22
Output: 4
Explanation:
The digits of n are [2, 2].
The possible products of any two digits are: 2 * 2 = 4.
The maximum product is 4.
Example 3:
Input: n = 124
Output: 8
Explanation:

The digits of n are [1, 2, 4].
The possible products of any two digits are: 1 * 2 = 2, 1 * 4 = 4, 2 * 4 = 8.
The maximum product is 8.
*/

// optimal solution 
// time complexity - > O(n)
class Solution {
public:
    int maxProduct(int n) {
        
        int largest = 0, second_largest = 0;

        while (n > 0) {
            int digit = n % 10;
            if(digit >= largest)
            {
                second_largest = largest;
                largest = digit;
            }
            else if( digit > second_largest )
            {
                second_largest = digit;
            }
            n /= 10;
        }
        return largest * second_largest;

    }
};

// brute force solution 
// time complexity - O(n^2)

class Solution {
public:
    int maxProduct(int n) {
        int arr[10];
        int count = 0;

        while (n > 0) {
            arr[count] = n % 10;
            count++;
            n /= 10;
        }

        int maximum = 0;

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                int product = arr[i] * arr[j];
                maximum = max(maximum, product);
            }
        }

        return maximum;
    }
};



