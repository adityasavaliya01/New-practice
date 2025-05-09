students = []
def display_menu():
    print("\nSelect an option:\n1. Add student\n2. Display all students\n3. Update student information\n4. Delete student\n5. Display subjects offered\n6. Exit")

while True:
    display_menu()
    try:
        choice = int(input("Enter your choice: "))
    except ValueError:
        print("Invalid input! Please enter a number.")
        continue

    if choice == 1:
        student = {
            "id": int(input("Student ID: ")),
            "name": input("Name: "),
            "age": int(input("Age: ")),
            "grade": input("Grade: "),
            "dob": input("Date of Birth: "),
            "subjects": input("Subjects: ")
        }
        students.append(student)
        print("Student added successfully")

    elif choice == 2:
        if not students:
            print("No students to display.")
        else:
            for s in students:
                print(f"\nID: {s['id']}, Name: {s['name']}, Age: {s['age']}, Grade: {s['grade']}, DOB: {s['dob']}, Subjects: {s['subjects']}")

    elif choice == 3:
        sid = int(input("Enter the student ID to update: "))
        for s in students:
            if s['id'] == sid:
                print("1. Update Age\n2. Update Subjects\n3. Update id\n4. Update name\n5. Update grade\n6. Update DOB")
                update_choice = input("Choose an option: ")
                if update_choice == "1":
                    s['age'] = input("Enter new age: ")
                elif update_choice == "2":
                    s['subjects'] = input("Enter new subjects: ")
                elif update_choice == "3":
                    s['id'] = int(input("Enter new id: "))
                elif update_choice == "4":
                    s['name'] = int(input("Enter new name: "))
                elif update_choice == "5":
                    s['grade'] = int(input("Enter new grade: "))
                elif update_choice == "6":
                    s['dob'] = int(input("Enter new DOB: "))
                print("Student information updated.")
                break
        else:
            print("Student ID not found.")

    elif choice == 4:
        sid = int(input("Enter Student ID to delete: "))
        for s in students:
            if s['id'] == sid:
                students.remove(s)
                print("Student deleted successfully.")
                break
            else:
                print("Student ID not found.")
    elif choice == 5:
        subject_set = set()
        for s in students:
            subject_set.update(map(str.strip, s['subjects'].split(',')))
        print("Subjects Offered:", ", ".join(sorted(subject_set)))

    elif choice == 6:
        print("Exiting program.")
        break
    else:
        print("Invalid input")