import random

def random_data():
    while True:
        print("""
Random Data Generation:
1. Generate Random Number
2. Generate Random List
3. Create Random Password
4. Generate Random OTP
5. Back to Main menu
""")
        choice = input("Enter your choice: ")
        if choice == '1':
            print("Random Number: ", random.randint(1, 100))
        elif choice == '2':
            print("Random List: ", random.sample(range(1, 100), 5))
        elif choice == '3':
            length = int(input("Enter password length: "))
            chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()-_+/?\|<>,.[]}{;:="
            password = ''.join(random.choices(chars, k=length))
            print(password)
        elif choice == '4':
            otp = ''.join(random.choices("0123456789", k=6))
            print(otp)
        elif choice == '5':
            break
        else:
            print("Invalid choice")
