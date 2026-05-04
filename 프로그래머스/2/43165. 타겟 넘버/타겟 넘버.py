answer = 0
number_lst = []
def get_result(is_add_lst, target):
    global answer
    if len(is_add_lst) == len(number_lst):
        result = 0
        length = len(is_add_lst)
        for i in range(length):
            if is_add_lst[i]:
                result += number_lst[i]
            else:
                result -= number_lst[i]
        if target == result:
            answer += 1
            # print(is_add_lst)
        return
    
    get_result(is_add_lst + [False], target)
    get_result(is_add_lst + [True], target)
    return

def solution(numbers, target):
    global number_lst, answer
    number_lst = numbers
    
    get_result([], target)
    
    return answer