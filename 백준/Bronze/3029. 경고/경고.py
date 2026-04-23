present_time = input()
start_time = input()

converted_present_time = (int(present_time[0]) * 10 + int(present_time[1])) * 60 * 60 + (int(present_time[3]) * 10  + int(present_time[4])) * 60 + int(present_time[6]) * 10 + int(present_time[7])
converted_start_time = (int(start_time[0]) * 10 + int(start_time[1])) * 60 * 60 + (int(start_time[3]) * 10  + int(start_time[4])) * 60 + int(start_time[6]) * 10 + int(start_time[7])

converted_total_time = (converted_start_time - converted_present_time) % (24*60*60)
if converted_total_time == 0:
    converted_total_time = 24*60*60
print(str(converted_total_time // 3600).zfill(2) + ':'+str(converted_total_time // 60 % 60).zfill(2)+':'+str(converted_total_time%60).zfill(2))