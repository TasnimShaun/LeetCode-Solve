class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        
        def waviness(n: int) -> int:
            d = list(map(int, str(n)))
            if len(d) < 3:
                return 0
            count = 0
            for i in range(1, len(d) - 1):
                if d[i] > d[i-1] and d[i] > d[i+1]:  # peak
                    count += 1
                if d[i] < d[i-1] and d[i] < d[i+1]:  # valley
                    count += 1
            return count

        return sum(waviness(n) for n in range(num1, num2 + 1))
