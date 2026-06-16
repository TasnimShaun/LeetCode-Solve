class Solution {

    public String processStr(String inputString) {

        // Stores the processed string
        StringBuilder processedString =
                new StringBuilder();

        for (char currentCharacter :
                inputString.toCharArray()) {

            // If it is a lowercase letter,
            // append it to the result
            if (currentCharacter >= 'a' &&
                currentCharacter <= 'z') {

                processedString.append(
                        currentCharacter
                );
            }

            // Remove the last character
            else if (currentCharacter == '*') {

                if (processedString.length() > 0) {

                    processedString.deleteCharAt(
                            processedString.length() - 1
                    );
                }
            }

            // Duplicate the current string
            else if (currentCharacter == '#') {

                processedString.append(
                        processedString.toString()
                );
            }

            // Reverse the current string
            else if (currentCharacter == '%') {

                processedString.reverse();
            }
        }

        return processedString.toString();
    }
}
