def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n - 1)

def summary(data):
    length = len(data)
    minimum = min(data)
    maximum = max(data)
    total = sum(data)
    average = total / length
    return length, minimum, maximum, total, average

print("Welcome to the Data Analyzer and Transformer Program")
my_list = []

while True:
    print("Main Menu:\n1. Input Data\n2. Display Data Summary\n3. Calculate Factorial\n4. Filter Data by Threshold\n5. Sort Data\n6. Show Dataset Statistics\n7. Exit Program")

    try:
        choice = int(input("Enter your choice: "))
    except ValueError:
        print("Please enter a valid number between 1 and 7.")
        continue
    if choice == 1:
        user_input = input("Enter numbers separated by spaces: ")
        parts = user_input.split()
        if all(x.isdigit() for x in parts):
            my_list = [int(x) for x in parts]
            print("Data stored successfully!")
        else:
            print("Invalid input! Please enter only numeric values.")
    elif choice == 2:
        if my_list:
            print("Data Summary:")
            print(f" - Total elements: {len(my_list)}")
            print(f" - Minimum value: {min(my_list)}")
            print(f" - Maximum value: {max(my_list)}")
            print(f" - Sum of values: {sum(my_list)}")
            print(f" - Average value: {sum(my_list) / len(my_list):.2f}")
        else:
            print("No data available. Please input data first.")
    elif choice == 3:
        try:
            number = int(input("Enter a number to calculate its factorial: "))
            if number < 1:
                print("Factorial is not defined for numbers less than 1.")
            else:
                print(f"Factorial of {number} is {factorial(number)}")
        except ValueError:
            print("Please enter a valid integer.")
    elif choice == 4:
        if not my_list:
            print("No data to filter. Please input data first.")
            continue
        try:
            threshold = int(input("Enter a threshold number: "))
            below = list(filter(lambda x: x < threshold, my_list))
            above = list(filter(lambda x: x > threshold, my_list))
            print(f"Numbers below threshold: {below}")
            print(f"Numbers above threshold: {above}")
        except ValueError:
            print("Please enter a valid number.")
    elif choice == 5:
        if not my_list:
            print("No data to sort. Please input data first.")
            continue
        print("1. Ascending\n2. Descending")
        sort_choice = input("Enter your choice: ")
        if sort_choice == '1':
            print("Sorted (Ascending):", sorted(my_list))
        elif sort_choice == '2':
            print("Sorted (Descending):", sorted(my_list, reverse=True))
        else:
            print("Invalid sort choice.")
    elif choice == 6:
        if my_list:
            length, minimum, maximum, total, average = summary(my_list)
            print(f"Dataset Statistics:\n- Total elements: {length}\n- Minimum value: {minimum}\n- Maximum value: {maximum}\n- Sum of values: {total}\n- Average value: {average:.2f}")
        else:
            print("No data available. Please input data first.")
    elif choice == 7:
        print("Thank you for using the program. Goodbye!")
        break
    else:
        print("Invalid choice. Please select from 1 to 7.")