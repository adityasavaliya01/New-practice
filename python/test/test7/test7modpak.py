import date_time
import randomm
import maths
import uuid_1
import file
import mod

def main_menu():
    while True:
        print("""
        Welcome to Multi-Utility Toolkit
        Choose an option:
        1. Datetime and Time Operations
        2. Mathematical Operations
        3. Random Data Generation
        4. Generate Unique Identifiers (UUID)
        5. File Operations (Custom Module)
        6. Explore Module Attributes (dir())
        7. Exit
        """)
        choice = input("Enter your choice: ")
        if choice == '1':
            date_time.datetime_time_operations()
        elif choice == '2':
            maths.mathematical_operations()
        elif choice == '3':
            randomm.random_data()
        elif choice == '4':
            uuid_1.uuid_operations()
        elif choice == '5':
            file.file_operations()
        elif choice == '6':
            mod.explore_module()
        elif choice == '7':
            print("Exit")
            break
        else:
            print("Invalid choice")

if __name__ == '__main__':
    main_menu()