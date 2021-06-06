# 교집합 생각을 이상하게 했네
def intersection(list1,list2) :
    cnt = 0
    if len(list1) < len(list2) : 
        tmp = list2.copy()
        for l in list1 :
            if l in tmp :
                tmp.remove(l)
                cnt += 1
    else :
        tmp = list1.copy()
        for l in list2 :
            if l in tmp :
                tmp.remove(l)
                cnt += 1

    return cnt


def solution(str1, str2):
    ans = 0
    str1 = str1.lower()
    str2 = str2.lower()

    list1 = []
    for i in range(len(str1)-1) :
        str_ = str1[i] + str1[i+1]
        if str_.isalpha() :
            list1.append(str_)
    
    list2 = []
    for i in range(len(str2)-1) :
        str_ = str2[i] + str2[i+1]
        if str_.isalpha() :
            list2.append(str_)
    
    i = intersection(list1,list2)
    u = len(list1)+len(list2) - i

    if u == 0 : 
        return 65536
    else :
        return int(i/u*65536) 



print(solution("aa1+aa2","AAAA12"))

