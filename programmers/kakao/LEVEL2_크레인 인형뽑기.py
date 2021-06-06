def solution(board, moves):
    stack = []
    ans = 0 
    for move in moves : 
        for row in board :
            if row[move-1] != 0 :
                if len(stack) != 0 and stack[-1] == row[move-1] :
                    ans += 2
                    stack.pop()
                    row[move-1] = 0
                    break
                else :
                    stack.append(row[move-1])
                    row[move-1] = 0
                    break
    return ans

board = [[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
moves = [1,5,3,5,1,2,1,4]	
print(solution(board, moves))