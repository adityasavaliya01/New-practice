import uuid

def uuid_operations():
    while True:
        print("""
Generate Unique Identifiers :
1. Generate UUID1(based on timestamp and MAC address)
2. Generate UUID4(random UUID)
3. Back to Main menu
""")
        choice = input("Enter your choice: ")
        if choice == '1':
            print("Generated UUID1:", uuid.uuid1())
        elif choice == '2':
            print("Generated UUID4:", uuid.uuid4())
        elif choice == '3':
            break
        else:
            print("Invalid choice!")