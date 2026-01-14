#permutation
import itertools

def unique_permutations(s):
    perms = itertools.permutations(s)
    unique_perms = set(''.join(p) for p in perms)
    return list(unique_perms)

s = input()
print(unique_permutations(s))

def permute(s, b, per):
    for i in range(len(s)):
        if b[i]:
            per.append(s[i])
            b[i] = False
            permute(s, b, per)
            if len(per) == len(s):
                print("".join(per))
            per.remove(s[i])
            b[i] = True

def permutate(s):
    b = []
    for i in s:
        b.append(True)
    permute(s, b, [])

permutate("123")

#string palendrom convertable or not
def can_form_palindrome(s):
    freq = {}
    for char in s:
        freq[char] = freq.get(char, 0) + 1
    
    odd_count = 0
    for count in freq.values():
        if count % 2 != 0:
            odd_count += 1
    
    return odd_count <= 1

print(can_form_palindrome("civic"))    

# Write a Python program using functions that prompt the user to enter today’s date (in the format
# YYYY-MM-DD) and the current day of the week. Then, ask the user to input a number of days. The
# program should calculate and display the new date and the day of the week after the specified number
# of days have passed.
# Input:
# Today’s date: 2024-08-27
# Today’s day: Tuesday
# Number of days: 5
# Output:
# New date: 2024-09-01
# New day: Sunday
def leap(year):
    return year%400==0 or (year%100!=0 and year%4==0)

weeks = ['Monday','Tuesday','Wednesday','Thursday','Friday','Saturday','Sunday']
date = input("Enter today's date in YYYY-MM-DD format: ")
week =input("Enter current day of the week: ")
days = int(input('Enter no of days: '))
date = date.replace("-","")
year,month,day = int(date[:4]),int(date[4:6]),int(date[6:8])
days_in_month = [31,29 if leap(year) else 28,31,30,31,30,31,31,30,31,30,31]

day+=days
while day>days_in_month[month-1]:
    day-=days_in_month[month-1]
    month+=1
    if month>12:
        month=1
        year+=1
        days_in_month[1] = 29 if leap(year) else 28

new_date = (weeks.index(week)+days)%7
new_day = weeks[new_date]

print(f"New date after {days} days: {year:04d}-{month:02d}-{day:02d}")
print(f"Day of the week: {new_day}")

#