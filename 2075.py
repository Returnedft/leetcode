class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        cols = int(len(encodedText) / rows)
        matrix = []
        result = ""
        curr = 0

        if (rows == 1):
            return encodedText

        # Matrix Gen

        for i in range(rows):
            inside = []
            for j in range(cols):
                inside.append(encodedText[curr])
                curr += 1
            matrix.append(inside)

        currRow = 0
        currCol = 0

        lastChar = 0
        print(matrix)

        for iter in range(cols):

            currRow = 0
            currCol = iter

            while (currRow < rows and currCol < cols):

                if matrix[currRow][currCol] != " ":
                    lastChar = len(result)

                result += matrix[currRow][currCol]
                currRow += 1
                currCol += 1
                print(result)
            

        return result[:lastChar+1]







# Tests

encodedText = " b  ac"
rows = 2

result = Solution().decodeCiphertext(encodedText, rows)

print(result)