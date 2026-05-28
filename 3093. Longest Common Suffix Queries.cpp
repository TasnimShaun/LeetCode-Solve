class Solution {

    struct TrieNode {

        // Stores indices of child nodes
        int nextNode[26];

        // Smallest word length passing through this node
        int smallestLength;

        // Index of the best matching word
        int smallestWordIndex;

        TrieNode() {

            // Initially no child exists
            fill(begin(nextNode), end(nextNode), -1);

            smallestLength = 1e9;
            smallestWordIndex = 1e9;
        }
    };

public:

    vector<int> stringIndices(vector<string>& containerWords,
                              vector<string>& queryWords) {

        // Trie structure
        vector<TrieNode> trieTree;

        // Root node
        trieTree.emplace_back();

        // ================= BUILD TRIE =================

        for (int wordIndex = 0; wordIndex < containerWords.size(); wordIndex++) {

            int wordLength = containerWords[wordIndex].length();

            int currentNode = 0;

            // Update root node information
            if (wordLength < trieTree[currentNode].smallestLength ||
               (wordLength == trieTree[currentNode].smallestLength &&
                wordIndex < trieTree[currentNode].smallestWordIndex)) {

                trieTree[currentNode].smallestLength = wordLength;
                trieTree[currentNode].smallestWordIndex = wordIndex;
            }

            // Insert characters in reverse order
            for (int position = wordLength - 1; position >= 0; position--) {

                int letterIndex = containerWords[wordIndex][position] - 'a';

                // Create new node if needed
                if (trieTree[currentNode].nextNode[letterIndex] == -1) {

                    trieTree[currentNode].nextNode[letterIndex] = trieTree.size();

                    trieTree.emplace_back();
                }

                // Move to child node
                currentNode = trieTree[currentNode].nextNode[letterIndex];

                // Update best word info for current node
                if (wordLength < trieTree[currentNode].smallestLength ||
                   (wordLength == trieTree[currentNode].smallestLength &&
                    wordIndex < trieTree[currentNode].smallestWordIndex)) {

                    trieTree[currentNode].smallestLength = wordLength;
                    trieTree[currentNode].smallestWordIndex = wordIndex;
                }
            }
        }

        // ================= PROCESS QUERIES =================

        vector<int> result;

        result.reserve(queryWords.size());

        for (const string& currentQuery : queryWords) {

            int currentNode = 0;

            int queryLength = currentQuery.length();

            // Traverse query in reverse order
            for (int position = queryLength - 1; position >= 0; position--) {

                int letterIndex = currentQuery[position] - 'a';

                // Stop if path does not exist
                if (trieTree[currentNode].nextNode[letterIndex] == -1) {
                    break;
                }

                currentNode = trieTree[currentNode].nextNode[letterIndex];
            }

            // Store best matching word index
            result.push_back(trieTree[currentNode].smallestWordIndex);
        }

        return result;
    }
};
