class Solution {

    public List<Integer> sequentialDigits(
            int low,
            int high
    ) {

        String digits = "123456789";

        List<Integer> result =
                new ArrayList<>();

        int minLength =
                String.valueOf(low).length();

        int maxLength =
                String.valueOf(high).length();

        for (int length = minLength;
             length <= maxLength;
             length++) {

            for (int start = 0;
                 start + length <= 9;
                 start++) {

                int number = Integer.parseInt(
                        digits.substring(
                                start,
                                start + length
                        )
                );

                if (number >= low &&
                    number <= high) {

                    result.add(number);
                }
            }
        }

        return result;
    }
}
