dob = int(input("Enter your date of birth (ddmmyyyy): "))
cd = int(input("Enter the current date (ddmmyyyy): "))

d1, m1, y1 = dob // 1000000, (dob // 10000) % 100, dob % 10000
d2, m2, y2 = cd // 1000000, (cd // 10000) % 100, cd % 10000

mdays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

if d2 < d1:
    m2 -= 1
    d2 += mdays[(m2 - 1) % 12]
if m2 < m1:
    y2 -= 1
    m2 += 12

years, months, days = y2 - y1, m2 - m1, d2 - d1

print("Age:", years, "years", months, "months", days, "days")
