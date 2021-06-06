def solution(s):

    # 길이가 1 or 2 인 경우 무조건 1,2 인 예외 처리
    if len(s) == 1 or len(s) == 2 : return len(s)
    
    
    res = int(1e9)
    for unit in range(1,len(s)//2+1) :
        cnt = 1
        ans = ""
        for i in range(unit,len(s),unit) :
            if s[i-unit:i] == s[i:i+unit] :
                cnt += 1
            else :
                if cnt == 1 :
                    ans += s[i-unit:i]
                else :
                    ans += (str(cnt) + s[i-unit:i])
                    cnt = 1
        
        if cnt == 1 :
            ans += s[i:]
        else :
            ans += (str(cnt) + s[i-unit:i])
        
        print(unit,ans)
        res = min(res,len(ans))

    return res



print(solution("s"))