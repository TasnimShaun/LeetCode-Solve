class Solution {

    public int maximumElementAfterDecrementingAndRearranging(
            int[] numbers) {

        // Sort the array in ascending order
        Arrays.sort(numbers);

        // The first element must be 1
        numbers[0] = 1;

        // Make sure the difference between
        // adjacent elements is at most 1
        for (int index = 1;
             index < numbers.length;
             index++) {

            numbers[index] = Math.min(
                    numbers[index],
                    numbers[index - 1] + 1
            );
        }

        // The last element is the maximum
        return numbers[numbers.length - 1];
    }
}
