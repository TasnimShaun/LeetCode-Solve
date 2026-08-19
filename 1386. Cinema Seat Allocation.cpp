class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                rows[row] |= (1 << col);
            }
        }

        int answer = 2 * (n - static_cast<int>(rows.size()));

        const int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        const int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        const int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (const auto& [row, mask] : rows) {
            bool canLeft = (mask & left) == 0;
            bool canMiddle = (mask & middle) == 0;
            bool canRight = (mask & right) == 0;

            if (canLeft && canRight) {
                answer += 2;
            }
            else if (canLeft || canMiddle || canRight) {
                answer += 1;
            }
        }

        return answer;
    }
};
