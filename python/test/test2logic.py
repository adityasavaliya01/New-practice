print('Welcome to Pattern Generator and Number Analyzer!\nSelect an option.\n\n1.Generate a Pattern\n2.Analyze a range of numbers\n3.Exit')
choice=int(input('Enter your choice: '))
if choice==1:
    print('Choose a pattern type\n1. Right-angle triangle\n2. pyramid\n3. left-angled triangle')    
    choice1=int(input('Enter choice: '))
    if choice1==1:
        rows=int(input('Enter no of rows: '))
        for i in range(1,rows+1):
            for j in range(1,i+1):
                print('*',end=' ')
            print()
    elif choice1==2:
        rows = int(input('Enter no of rows: '))
        for i in range(1, rows + 1):
            for j in range(1, rows - i + 1):
                print(' ', end='')
            for l in range(1, 2 * i):
                print('*', end='')
            print()
    elif choice1==3:
        rows = int(input('Enter no of rows: '))
        for i in range(1, rows + 1):
            for j in range(i):
                print("*", end="")
            print()
    else:
        print('Pls enter a valid no')   
elif choice==2:
    start = int(input("Enter start of the range: "))
    end = int(input("Enter end of the range: "))
    count = 0
    for number in range(start, end + 1):
        count += number
        if number % 2 == 0:
            print(f"Number {number} is Even.")
        else:
            print(f"Number {number} is Odd.")
    print(f"\nThe sum of numbers from {start} to {end} is: {count}")
elif choice==3:
    print('Exiting...')
else:
    print('Pls enter a valid no')   
