''' Leetcode '''


# NO.51

class Solution:
    # 将当前可行方案加入到最终结果result中
    def add_result(self, result: List[List[str]], temp_index: List[int]):
        temp = []
        lens = len(temp_index)
        for i in range(lens):
            inputs = ""
            for j in range(lens):
                if j == temp_index[i]:
                    inputs += "Q"
                else:
                    inputs += "."
            temp.append(inputs)
        result.append(temp)
        return

    def judge(self, temp_index: List[int], index: int) -> bool:
        lens = len(temp_index)
        for i in range(lens):
            if temp_index[i] == index:
                return False
            elif (abs(temp_index[i] - index) == abs(i - lens)):
                return False
        return True

    def DFSQueens(self, result: List[List[str]], n: int, row: int, temp_index: List[int]):
        if row == n:
            add_result(result, temp_index)
            return
        else:
            for i in range(n):
                if self.judge(temp_index, i) is True:
                    temp_index.append(i)
                    self.DFSQueens(result, n, row+1, temp_index)
                    temp_index.pop()

    def solveNQueens(self, n: int) -> List[List[str]]:
        result = []
        temp_index = []
        self.DFSQueens(result, n, 0, temp_index)
        return result



## NO.303

class NumArray:

    def __init__(self, nums: List[int]):
        self.sums = [0]
        for num in nums:
            sums.append(sums[-1] + num)

    def sumRange(self, i: int, j: int) -> int:
        result = self.sums[j + 1] - self.sums[i]
        return result;


# NO.17

class Solution:
    def number_to_char(number: str) -> List[str]:
        if number is '2':
            result = ['a','b','c']
            return result
        elif number is '3':
            result = ['d','e','f']
            return result
        elif number is '4':
            result = ['g','h','i']
            return result
        elif number is '5':
            result = ['j','k','l']
            return result
        elif number is '6':
            result = ['m','n','o']
            return result
        elif number is '7':
            result = ['p','q','r','s']
            return result
        elif number is '8':
            result = ['t','u','v']
            return result
        elif number is '9':
            result = ['w','x','y','z']
            return result

    def add_char(letters: queue, chars: List[str]) -> queue:
        result = queue.Queue()
        if letters.empty() is True:
            for ch in chars:
                result.put(str(ch))
        else:
            while letters.empty() is False:
                letter = letters.get()
                for ch in chars:
                    result.put(letter + str(ch))
        return result

    def queue_to_list(letters: queue) -> List[str]:
        result = []
        while letters.empty() is False:
            result.append(letters.get())
        return result

    def letterCombinations(digits: str) -> List[str]:
        result = queue.Queue()
        for number in digits:
            chars = number_to_char(number)
            result = add_char(result, chars)
        return queue_to_list(result)

# NO.52
class Solution:
    def judge(self, checkerboard: List[int], index: int) -> bool:
        lens = len(checkerboard)
        for i in range(lens):
            if checkerboard[i] == index:
                return False
            elif abs(checkerboard[i] - index) == abs(lens - i):
                return False
        return True

    def DFSQueens(self, n: int, row: int, result: List[int], checkerboard: List[int]):
        if row == n:
            result[0] += 1
            return
        else:
            for i in range(n):
                if self.judge(checkerboard, i) is True:
                    checkerboard.append(i)
                    self.DFSQueens(n, row+1, result, checkerboard)
                    checkerboard.pop()

    def totalNQueens(self, n: int) -> int:
        result = [0]
        checkerboard = []
        row = 0
        self.DFSQueens(n, row, result, checkerboard)
        return result[0]


# NO.54

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        m = len(matrix)
        n = len(matrix[0])
        flag_matrix = [[0 for x in range(n)] for y in range(m)]
        lens = m * n
        flag = 1
        i = 0
        j = 0
        while lens > 0:
            result.append(matrix[i][j])
            flag_matrix[i][j] = 1
            if flag is 1:
                if j + 1 < n and flag_matrix[i][j+1] == 0:
                    j += 1
                elif i + 1 < m and flag_matrix[i+1][j] == 0:
                    i += 1
                    flag = 2
            elif flag is 2:
                if i + 1 < m and flag_matrix[i+1][j] == 0:
                    i += 1
                elif j - 1 >= 0 and flag_matrix[i][j-1] == 0:
                    j -= 1
                    flag = 3
            elif flag is 3:
                if j - 1 >= 0 and flag_matrix[i][j-1] == 0:
                    j -= 1
                elif i - 1 >= 0 and flag_matrix[i-1][j] == 0:
                    i -= 1
                    flag = 4
            elif flag is 4:
                if i - 1 >= 0 and flag_matrix[i-1][j] == 0:
                    i -= 1
                elif j + 1 < n and flag_matrix[i][j+1] == 0:
                    j += 1
                    flag = 1
            lens -= 1
        return result


# NO.45
class Solution:
    def jump(self, nums: List[int]) -> int:
        index = 0
        step = 0
        end = len(nums) - 1
        result = 0
        while index != end:
            step = nums[index]
            if index + step >= end:
                index = end
                result += 1
            else:
                next_index = index
                max_index = nums[next_index]
                last = index + step
                for i in range(index + 1, last + 1):
                    if nums[i] + i >= max_index + next_index:
                        next_index = i
                        max_index = nums[i]
                index = next_index
                result += 1
        return result


class Solution:
    def DFSCombinationSum(self, candidates: List[int], target: int, result: List[List[int]], temp_result: List[int], index: int):
        if index == len(candidates):
            return
        if target == 0:
            result.append(temp_result)
            return
        self.DFSCombinationSum(candidates, target, result, temp_result, index+1)
        if target - candidates[index] >= 0:
            temp_result.append(candidates[index])
            self.DFSCombinationSum(candidates, target - candidates[index], result, temp_result, index)
            temp_result.pop()

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []
        temp_result = []
        self.DFSCombinationSum(candidates, target, result, temp_result, 0)
        return result


# NO.125

class Solution:
    def str_to_char(self, s: str) -> List[str]:
        result = [];
        s_lower = s.lower();
        for char in s_lower:
            if char.isdigit():
                result.append(char)
            elif char.isalpha():
                result.append(char)
        return result;

    def isPalindrome(self, s: str) -> bool:
        chars = self.str_to_char(s)
        left = 0
        right = len(chars) - 1
        while left < right:
            if chars[left] != chars[right]:
                return False
            left += 1
            right -= 1
        return True

# NO.1221

class Solution:
    def balancedStringSplit(self, s: str) -> int:
        result = 1
        countR = 0
        countL = 0
        for ch in s:
            if countR > 0 and countL > 0 and countR == countL:
                countR = 0
                countL = 0
                result += 1
            if ch == 'R':
                countR += 1
            if ch == 'L':
                countL += 1
        return result

# NO.728
class Solution:
    def judge(self, number: int) -> bool:
        if number >= 1 and number <= 9:
            return True
        temp = number
        while temp > 0:
            factor = temp % 10
            temp /= 10
            if factor == 0:
                 return False
            elif number % factor != 0:
                return False
        return True

    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        result = []
        for num in range(left, right + 1):
            if self.judge(num) is True:
                result.append(num)
        return result


# NO.789
class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        self_to_target = abs(target[0] - 0) + abs(target[1] - 0)
        ghost_to_target = []
        for point in ghosts:
            ghost_to_target.append(int(abs(target[0] - point[0]) + abs(target[1] - point[1])))
        for dis in ghost_to_target:
            if dis < self_to_target:
                return False
        return True

# NO.1410
class Solution:
    def entityParser(self, text: str) -> str:
        dictionary = {"&quot;": '"', "&apos;": "'", "&amp;": "&", "&gt;": ">", "&lt;": "<", "&frasl;": "/"}
        word = ["&quot;", "&aops;", "&amp;", "&gt;", "&lt;", "&frasl;"]
        result = ""
        temp = ""
        for ch in text:
            if(ch == "&"):
                result = result + temp
                temp = ""
            temp = temp + ch
            if(ch == ";"):
                if temp in word:
                    trans = dictionary[temp]
                    result = result + trans
                else:
                    result = result + temp
                temp = ""
        result = result + temp
        return result

# NO.874
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        dx = [0, 1, 0, -1]
        dy = [1, 0, -1, 0]
        x = 0
        y = 0
        di = 0
        obstaclesSet = set(map(tuple, obstacles))
        result = 0
        for command in commands:
            if command is -1:
                di = (di + 1) % 4
            elif command is -2:
                di = (di - 1) % 4
            else:
                for i in range(1, command + 1):
                    if (x + dx[di], y + dy[di]) not in obstaclesSet:
                        x += dx[di]
                        y += dy[di]
                        result = max(result, x ** 2 + y ** 2)
        return result


