# combinations 아이디어까지는 잘 떠올렸으나
# 중복제거 부분을 생각못해버렸네
# 다시 풀어보자
from itertools import combinations
def solution(relation):

    nR = len(relation)
    nC = len(relation[0])

    candi = []
    for i in range(1,nC+1) :
        candi.extend(combinations(range(nC),i))
    
    ans = []
    for keys in candi :
        tmp = [tuple([val[key] for key in keys]) for val in relation]
        if len(set(tmp)) == nR :
            ans.append(keys)
        
    ret = set(ans)
    for i in range(len(ans)) :
        for j in range(i+1,len(ans)) :
            if len(ans[i]) == len(set(ans[i]).intersection(ans[j])) :
                ret.discard(ans[j])

    return len(ret)



relation = [["100","ryan","music","2"],
            ["200","apeach","math","2"],
            ["300","tube","computer","3"],
            ["400","con","computer","4"],
            ["500","muzi","music","3"],
            ["600","apeach","music","2"]]


print(solution(relation))
