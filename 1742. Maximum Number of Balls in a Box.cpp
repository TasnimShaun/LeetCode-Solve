class Solution {
public:
    int countBalls(int lowLimit, int highLimit) 
    {
        int ans = 0, sum;                      // ans stores max frequency, sum stores digit sum of current number
        unordered_map<int, int> count;         // maps digit sum -> frequency of balls with that sum
        
        // Iterate through each ball number from lowLimit to highLimit
        for(int number = lowLimit; number <= highLimit; number++)
        {
            sum = 0;                           // reset sum for the current number
            string s = to_string(number);      // convert number to string to easily access each digit
            
            // Calculate sum of digits of the current number
            for(auto ch : s)
                sum += ch - '0';               // convert char digit to int and add to sum
                
            count[sum] += 1;                   // increment frequency count for this digit sum
            ans = max(ans, count[sum]);        // update answer if current sum has higher frequency
        }
        
        return ans;                            // return the maximum frequency (smallest box number that appears most often)
    }
};
