x, y = map(int, input().split())
days = ['SUN', 'MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT']
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day_num = 0
for i in range(x-1):
    day_num += months[i]
day_num += y
day_num %= 7
print(days[day_num])