import math

def mathematical_operations():
    while True:
        print("""
        Mathematical Operations:
        1. Calculate Factorial
        2. Solve Compound Interest
        3. Trigonometric Calculations
        4. Area of Geometric Shapes
        5. Back to Main Menu
        """)
        choice = input("Enter your choice: ")
        if choice == '1':
            n = int(input("Enter a number: "))
            print("Factorial:", math.factorial(n))
        elif choice == '2':
            p = float(input("Enter principal amount: "))
            r = float(input("Enter rate of interest: ")) / 100
            t = float(input("Enter time: "))
            ci = p * (1 + r)**t
            print("Compound Interest: {:.2f}".format(ci))
        elif choice == '3':
            angle = float(input("Enter angle in degrees: "))
            rad = math.radians(angle)
            print(f"sin({angle}) = {math.sin(rad):.4f}")
            print(f"cos({angle}) = {math.cos(rad):.4f}")
            print(f"tan({angle}) = {math.tan(rad):.4f}")
        elif choice == '4':
            print("Choose shape: 1.Circle 2.Rectangle 3.Triangle")
            s = input("Enter choice: ")
            if s == '1':
                r = float(input("Enter radius: "))
                print("Area: ", math.pi * r * r)
            elif s == '2':
                l = float(input("Enter length: "))
                b = float(input("Enter breadth: "))
                print("Area: ", l * b)
            elif s == '3':
                b = float(input("Enter base: "))
                h = float(input("Enter height: "))
                print("Area: ", 0.5 * b * h)
            else:
                print("Invalid shape")
        elif choice == '5':
            break
        else:
            print("Invalid choice")