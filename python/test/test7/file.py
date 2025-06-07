
def create_file(filename):
    with open(filename, 'w') as f:
        pass
    print("File created successfully")

def write_file(filename, data):
    with open(filename, 'w') as f:
        f.write(data)
    print("Data written successfully")

def read_file(filename):
    try:
        with open(filename, 'r') as f:
            content = f.read()
        print("File Content: ")
        print(content)
    except FileNotFoundError:
        print("File not found")

def append_file(filename, data):
    with open(filename, 'a') as f:
        f.write(data)
    print("Data appended successfully")

def file_operations():
    while True:
        print("""
            File Operations :
            1. Create a new file
            2. Write to a file
            3. Read from a file
            4. Append to a file
            5. Back to Main Menu
            """)
        choice = input("Enter your choice: ")
        if choice == '1':
            name = input("Enter file name: ").strip()
            create_file(name)
        elif choice == '2':
            name = input("Enter file name: ").strip()
            data = input("Enter data: ")
            write_file(name, data)
        elif choice == '3':
            name = input("Enter file name: ").strip()
            read_file(name)
        elif choice == '4':
            name = input("Enter file name: ").strip()
            data = input("Enter data to append: ")
            append_file(name, data)
        elif choice == '5':
            break
        else:
            print("Invalid choice")