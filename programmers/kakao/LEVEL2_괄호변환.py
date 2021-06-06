def fineBracket(p) :
    s = []
    for b in p :
        if b == "(":
            s.append(b)
        else :
            if len(s) == 0 : return False
            else : s.pop()
    return not s

def splitBracket(p) :
    o,c = 0,0
    for i,b in enumerate(p) :
        if i != 0 and o == c :
            return p[:i],p[i:]
        if b == "(" :
            o += 1
        elif b == ")" :
            c += 1

    return p,""

def filpBracket(p) :
    ret = ""
    for b in p :
        if b == "(" :
            ret += ")"
        else :
            ret += "("

    return ret

def solution(p):

    if fineBracket(p) : return p
    
    u,v = splitBracket(p)
    
    if fineBracket(u) :
        rec = solution(v)
        return u + rec
    else :
        rec = "(" + solution(v) + ")"
        filp = filpBracket(u[1:-1])
        return rec + filp


print(solution("()))((()"))