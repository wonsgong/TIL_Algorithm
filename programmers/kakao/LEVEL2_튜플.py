# 내 풀이.
# 정규식 -> 다른 사람 아이디어 => 코드가 한줄로 줄어버린다.ㅋㅋㅋㅋ
from collections import Counter
import re 
def solution(s):
    
    # nums = []
    # num = ""
    # for i in s[1:-1] :
    #     if i == "{" or i == "}" : continue
    #     elif i == "," : 
    #         nums.append(int(num))
    #         num = ""
    #     else :
    #         num += i
    # nums.append(int(num))
    cnt = Counter(re.findall("\d+",s)).most_common()
    ans = [int(k) for k,v in cnt]

    return ans


s = "{{2},{2,1},{2,1,3},{2,1,3,4}}"

print(solution(s))

