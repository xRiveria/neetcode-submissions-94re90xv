class Solution:
    def countBits(self, n: int) -> List[int]:
        results = []
        for item in range(0, n + 1):
            count = 0
            while item:
                if item & 1:
                    count += 1
                item = item >> 1
            results.append(count)

        return results