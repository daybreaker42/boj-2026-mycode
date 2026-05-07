'''
solved: 2026-
idea:
시간복잡도:
'''
def get_coord(num):
    if num == '*':
        return (0, 3)
    elif num == '#':
        return (2, 3)
    elif num == 0:
        return (1, 3)
    
    x = (num - 1) % 3
    y = (num - 1) // 3
    return (x, y)

def get_dist(p1, p2):
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

def solution(numbers, hand):
    answer = []
    left_loc = '*'
    right_loc = '#'
    hand_ch = ''
    if hand == 'left':
        hand_ch = 'L'
    else:
        hand_ch = 'R'
    
    for ele in numbers:
        if ele in [1, 4, 7]:
            left_loc = ele
            answer.append('L')
        elif ele in [3, 6, 9]:
            right_loc = ele
            answer.append('R')
        else:
            left_dist = get_dist(get_coord(left_loc), get_coord(ele))
            right_dist = get_dist(get_coord(right_loc), get_coord(ele))
            if left_dist == right_dist:
                answer.append(hand_ch)
                if hand_ch == 'L':
                    left_loc = ele
                else:
                    right_loc = ele
            elif left_dist > right_dist:
                answer.append('R')
                right_loc = ele
            else:
                answer.append('L')
                left_loc = ele
    answer = ''.join(answer)
    return answer