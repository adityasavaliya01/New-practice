import datetime
import time

def datetime_time_operations():
    while True:
        print("""
        Datetime and Time Operations:
        1. Display current date and time
        2. Calculate difference between two dates/ times
        3. Format date into custom format
        4. Stopwatch
        5. Countdown Timer
        6. Back to Main Menu
        """)
        choice = input("Enter your choice: ")
        if choice == '1':
            print("Current Date and Time:", datetime.datetime.now())
        elif choice == '2':
            d1 = input("Enter the first date (YYYY-MM-DD): ")
            d2 = input("Enter the second date (YYYY-MM-DD): ")
            date1 = datetime.datetime.strptime(d1, '%Y-%m-%d')
            date2 = datetime.datetime.strptime(d2, '%Y-%m-%d')
            print("Difference: ", abs((date2 - date1).days), "days")
        elif choice == '3':
            now = datetime.datetime.now()
            print(now.strftime("%A, %d %B %Y"))
        elif choice == '4':
            input("Press Enter to start stopwatch...")
            start = time.time()
            input("Press Enter to stop stopwatch...")
            end = time.time()
            print("Elapsed Time:", round(end - start, 2), "seconds")
        elif choice == '5':
            sec = int(input("Enter countdown time in seconds: "))
            for i in range(sec, 0, -1):
                print(i, end="\r")
                time.sleep(1)
        elif choice == '6':
            break
        else:
            print("Invalid choice!")