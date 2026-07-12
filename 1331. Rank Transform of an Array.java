class Solution {

    public int[] arrayRankTransform(
            int[] numbers
    ) {

        int[] sortedNumbers =
                numbers.clone();

        Arrays.sort(sortedNumbers);

        HashMap<Integer, Integer> rank =
                new HashMap<>();

        int currentRank = 1;

        for (int value : sortedNumbers) {

            if (!rank.containsKey(value)) {

                rank.put(
                        value,
                        currentRank++
                );
            }
        }

        for (int i = 0;
             i < numbers.length;
             i++) {

            numbers[i] =
                    rank.get(numbers[i]);
        }

        return numbers;
    }
}
