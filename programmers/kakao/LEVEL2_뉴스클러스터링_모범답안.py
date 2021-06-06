from collections import Counter

def solution(str1, str2):
    str1 = str1.lower()
    str2 = str2.lower()

    str1 = [str1[i:i+2] for i in range(len(str1)-1) if str1[i:i+2].isalpha()]
    str2 = [str2[i:i+2] for i in range(len(str2)-1) if str2[i:i+2].isalpha()]

    str1C = Counter(str1)
    str2C = Counter(str2)

    inters = set(str1) | set(str2)

    # 중복 제거된 교집합의 개수를 세주면 되는거였어...
    intersection = 0
    for inter in inters :
        intersection += min(str1C[inter],str2C[inter])

    union = len(str1) + len(str2) - intersection

    if union == 0 :
        return 65536
    else :
        return int(intersection/union*65536)



print(solution("aa1+aa2","AAAA12"))

