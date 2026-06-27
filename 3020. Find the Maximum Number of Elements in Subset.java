class Solution {

    public int maximumLength(int[] numbers) {

        // Stores the frequency of each number
        HashMap<Long, Integer> frequencyMap =
                new HashMap<>();

        for (int currentNumber : numbers) {

            frequencyMap.put(
                    (long) currentNumber,
                    frequencyMap.getOrDefault(
                            (long) currentNumber,
                            0
                    ) + 1
            );
        }

        int maximumSequenceLength = 1;

        // Handle the special case for number 1
        if (frequencyMap.containsKey(1L)) {

            int oneCount =
                    frequencyMap.get(1L);

            // The final length must be odd
            maximumSequenceLength = Math.max(
                    maximumSequenceLength,
                    (oneCount % 2 == 1)
                            ? oneCount
                            : oneCount - 1
            );
        }

        // Try every unique number
        // as the starting value
        for (long startingValue :
                frequencyMap.keySet()) {

            if (startingValue == 1L) {
                continue;
            }

            long currentValue =
                    startingValue;

            int currentLength = 0;

            while (
                    frequencyMap.containsKey(
                            currentValue
                    )
            ) {

                // Need at least two occurrences
                // to continue the chain
                if (
                        frequencyMap.get(
                                currentValue
                        ) >= 2
                ) {

                    currentLength += 2;

                    currentValue =
                            currentValue
                                    * currentValue;
                }
                else {

                    // Last occurrence
                    currentLength++;

                    break;
                }
            }

            // Final answer must be odd
            if ((currentLength & 1) == 0) {

                currentLength--;
            }

            maximumSequenceLength = Math.max(
                    maximumSequenceLength,
                    currentLength
            );
        }

        return maximumSequenceLength;
    }
}
