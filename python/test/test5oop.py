class person:
    def settr(self,n,a):
        self.name=n
        self.age=a
        print(f'Person with name: {self.name} & age: {self.age}')      
        
    def gettr(self):
        print(f'Person Name: {self.name}, Age: {self.age}')

class employee(person):
    def settr(self,name,id,age,salary):
        super().settr(name, age)
        self.id=id
        self.name=name
        self.age=age
        self.salary=salary
        print(f'Employee created with id: {self.id}, name: {self.name}, age: {self.age}, salary: {self.salary}')

    def gettr(self):
        print(f'Employee Name: {self.name}, Age: {self.age}, Id: {self.id}, Salary: {self.salary}')

class manager(person):
    def settr(self,id,name,age,salary,department):
        super().settr(name, age)
        self.id=id
        self.name=name
        self.age=age
        self.salary=salary
        self.department=department
        print(f'Manager created with id: {self.id}, name: {self.name}, age: {self.age}, salary: {self.salary}, department: {self.department}')

    def gettr(self):
        print(f'Manager Name: {self.name}, Age: {self.age}, Id: {self.id}, Salary: {self.salary}, Department: {self.department}')

people = []
employ=[]
mngr=[]
while True:
    print('''
    1. Create a Person
    2. Create an Employee
    3. Create a Manager
    4. Show Details
    5. Compare Salaries
    6. Exit''')
    try:
        num = int(input('Select: '))
    except ValueError:
        print("Please enter a valid number.")
        continue

    if num==1:
        nop=int(input('Enter number of persons: '))
        for i in range(nop):
            name=input('Enter name: ')
            age=int(input('Enter age: '))
            p = person()
            p.settr(name, age)
            people.append(p)
    elif num==2:
        nop=int(input('Enter number of employ: '))
        for i in range(nop):
            name=input('Enter name: ')
            id =(input('Enter id: '))
            age=int(input('Enter age: '))
            salary=int(input('Enter salary: '))
            e=employee()
            e.settr(name,id,age,salary)
            employ.append(e)
    elif num==3:
        nop=int(input('Enter number of manager: '))
        for i in range(nop):
            name=input('Enter name: ')
            id =input('Enter id: ')
            age=int(input('Enter age: '))
            salary=int(input('Enter salary: '))
            depart=input('Enter department: ')
            m=manager()
            m.settr(id,name,age,salary,depart)
            mngr.append(m)
    elif num==4:
        for s in people:
            s.gettr()
        for q in employ:
            q.gettr()
        for t in mngr:
            t.gettr()
    elif num == 5:
        all_emps = employ + mngr
        if len(all_emps) < 2:
            print("At least two employees or managers are needed to compare salaries.")
        else:
            print("\nSelect two people to compare their salaries:")
            for index, person in enumerate(all_emps, start=1):
                print(f"{index}. {person.name} - Salary: {person.salary}")

            try:
                first = int(input("Enter the number of the first person: ")) - 1
                second = int(input("Enter the number of the second person: ")) - 1

                if first == second:
                    print("Please select two different people.")
                elif 0 <= first < len(all_emps) and 0 <= second < len(all_emps):
                    person1 = all_emps[first]
                    person2 = all_emps[second]

                    if person1.salary > person2.salary:
                        print(f"{person1.name} has a higher salary than {person2.name}.")
                    elif person1.salary < person2.salary:
                        print(f"{person2.name} has a higher salary than {person1.name}.")
                    else:
                        print(f"{person1.name} and {person2.name} have equal salaries.")
                else:
                    print("Invalid selection. Please enter valid numbers from the list.")
            except ValueError:
                print("Invalid input. Please enter numbers only.")
    elif num==6:
        print("Exiting the program. Goodbye!")
        break
    else:
        print('Pls enter no between 1 to 6.')