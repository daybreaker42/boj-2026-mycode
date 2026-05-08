def solution(cards):
    answer = 0
    n = len(cards)
    groups = []
    available = [True] * n
    
    max_length = 0
    sub_length = 0
    curr_idx = 0
    for idx, card in enumerate(cards):
        next_idx = card - 1
        curr_idx = idx
        while available[curr_idx]:
            available[curr_idx] = False
            if groups and groups[-1][-1] == curr_idx + 1:
                groups[-1].append(next_idx + 1)
            else:
                if len(groups) > 0:
                    if len(groups[-1]) >= max_length:
                        sub_length = max_length
                        max_length = len(groups[-1])
                    elif len(groups[-1]) > sub_length:
                        sub_length = len(groups[-1])
                        
                groups.append([next_idx+ 1])
            curr_idx = next_idx
            next_idx = cards[next_idx] - 1
            
    if len(groups[-1]) >= max_length:
        sub_length = max_length
        max_length = len(groups[-1])
    elif len(groups[-1]) > sub_length:
        sub_length = len(groups[-1])
    
    answer = max_length * sub_length            
    
    return answer