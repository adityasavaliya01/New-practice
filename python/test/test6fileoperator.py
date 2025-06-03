import os
from datetime import datetime

file_name = "journal.txt"

def ensure_file_exists():
    if not os.path.exists(file_name):
        with open(file_name, 'w'):
            pass
        print(f"Created {file_name}")
    else:
        print(f"{file_name} already exists")

def current_time():
    return datetime.now().strftime("[%Y-%m-%d %H:%M:%S]")

def read_file():
    with open(file_name, 'r') as file:
        return file.read()

def write_entry(text):
    with open(file_name, 'a') as file:
        file.write(f"{current_time()} {text}\n")

def search_entries(keyword):
    with open(file_name, 'r') as file:
        return [line for line in file if keyword.lower() in line.lower()]

def delete_entries():
    with open(file_name, 'w'):
        pass

def menu():
    print("""
    === Personal Journal Manager ===
    1. Add a New Entry
    2. View All Entries
    3. Search for an Entry
    4. Delete All Entries
    5. Exit
    """)

def main():
    ensure_file_exists()

    while True:
        menu()
        try:
            choice = int(input("Enter your choice: "))
        except ValueError:
            print("Please enter a number between 1 to 5")
            continue

        if choice == 1:
            entry = input("Enter your journal entry:\n")
            write_entry(entry)
            print("Entry added successfully")
        elif choice == 2:
            content = read_file()
            print("\nJournal Entries\n" + (content if content.strip() else "No entries found"))
        elif choice == 3:
            keyword = input("Enter keyword to search: ")
            results = search_entries(keyword)
            print("\n--- Search Results ---\n" + ("".join(results) if results else "No matching entries found"))
        elif choice == 4:
            if input("Are you sure you want to delete all entries? (y/n): ").lower() == 'y':
                delete_entries()
                print("All entries have been deleted")
        elif choice == 5:
            print("Goodbye")
            break
        else:
            print("Invalid choice. Please enter a number between 1 to 5")
if __name__ == "__main__":
    main()