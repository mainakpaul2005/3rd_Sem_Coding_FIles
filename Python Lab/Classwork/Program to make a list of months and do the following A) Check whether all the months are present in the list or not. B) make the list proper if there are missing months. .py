# Initial month list (example: missing some months)
months_list = ["January", "February", "March", "April", "June", "July", "August", "October", "December"]

# Full month list
full_months = ["January", "February", "March", "April", "May", "June",
               "July", "August", "September", "October", "November", "December"]

# PART A: Check if all months are present
if months_list == full_months:
    print("All months are present.")
else:
    print("Some months are missing.")

# PART B: Fix list if missing months
for i in range(len(full_months)):
    if full_months[i] not in months_list:
        months_list.insert(i, full_months[i])

print("\nUpdated Month List:")
for m in months_list:
    print(m)

# PART C: Calendar creation
days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

year = int(input("\nEnter the year: "))
start_day = input("Enter the starting day of the year (Sunday/Monday/...): ").capitalize()

# Leap year adjustment
if (year % 400 == 0) or (year % 4 == 0 and year % 100 != 0):
    days_in_month[1] = 29

weekdays = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]

# Find starting day index
day_index = 0
for i in range(len(weekdays)):
    if weekdays[i] == start_day:
        day_index = i
        break

print("\nCalendar for", year, "\n")

for i in range(12):
    print("-----", full_months[i], year, "-----")
    print("Su Mo Tu We Th Fr Sa")
    print("   " * day_index, end="")

    for day in range(1, days_in_month[i] + 1):
        print(f"{day:2}", end=" ")
        day_index += 1
        if day_index == 7:
            day_index = 0
            print()
    print("\n")
