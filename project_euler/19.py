import datetime

week_days = [False for _ in range(7)]
week_days[6] = True

ans = 0
for year in range(1901,2001):
    for month in range(1,13):
        if week_days[datetime.date(year,month,1).weekday()]:
            ans += 1
                
print(ans)