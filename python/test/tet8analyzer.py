import numpy as np

class DataAnalytics:
    def __init__(self):
        self.arr = None
        self.rows = 0
        self.cols = 0

    def array(self):
        while True:
            print("\nSelect the type of array to create:")
            print("1. 1D Array")
            print("2. 2D Array")
            print("3. 3D Array")
            print("4. Exit to Main Menu")

            choice = int(input("Enter your choice: "))

            if choice == 1:
                n = int(input("Enter the number of elements: "))
                elements = list(map(int, input(f"Enter {n} elements separated by space: ").split()))
                if len(elements) != n:
                    print("Number of elements does not match the specified count.")
                    continue
                self.arr = np.array(elements)
                print("\nArray created successfully:")
                print(self.arr)

            elif choice == 2:
                self.rows = int(input("Enter the number of rows: "))
                self.cols = int(input("Enter the number of columns: "))
                total = self.rows * self.cols
                elements = list(map(int, input(f"Enter {total} elements separated by space: ").split()))
                if len(elements) != total:
                    print("Number of elements does not match rows * columns.")
                    continue
                self.arr = np.array(elements).reshape(self.rows, self.cols)
                print("\nArray created successfully:")
                print(self.arr)

            elif choice == 3:
                d1 = int(input("Enter size for dimension 1: "))
                d2 = int(input("Enter size for dimension 2: "))
                d3 = int(input("Enter size for dimension 3: "))
                total = d1 * d2 * d3
                elements = list(map(int, input(f"Enter {total} elements separated by space: ").split()))
                if len(elements) != total:
                    print("Number of elements does not match specified dimensions.")
                    continue
                self.arr = np.array(elements).reshape(d1, d2, d3)
                print("\nArray created successfully:")
                print(self.arr)

            elif choice == 4:
                break
            else:
                print("Invalid choice.")
                continue

            while True:
                print("\nChoose an operation:")
                print("1. Indexing")
                print("2. Slicing (only for 2D arrays)")
                print("3. Go Back")
                choice2 = int(input("Enter your choice: "))

                if choice2 == 1:
                    indices = list(map(int, input("Enter indices separated by space: ").split()))
                    try:
                        print("Indexed Value:", self.arr[tuple(indices)])
                    except:
                        print("Invalid index for array dimensions.")
                elif choice2 == 2:
                    if self.arr.ndim != 2:
                        print("Slicing is only supported for 2D arrays.")
                        continue
                    row_range = input("Enter the row range (start:end): ")
                    col_range = input("Enter the column range (start:end): ")
                    r_start, r_end = map(int, row_range.split(":"))
                    c_start, c_end = map(int, col_range.split(":"))
                    print("Sliced Array:")
                    print(self.arr[r_start:r_end, c_start:c_end])
                elif choice2 == 3:
                    break
                else:
                    print("Invalid choice.")

    def math_op(self):
        if self.arr.ndim != 2:
            print("Math operations support only for 2D arrays")
            return

        print("\nChoose a mathematical operation:")
        print("1. Addition")
        print("2. Subtraction")
        print("3. Multiplication")
        print("4. Division")
        math_choice = int(input("Enter your choice: "))

        elements2 = list(map(int, input(f"\nEnter {self.rows * self.cols} elements for the second array: ").split()))
        if len(elements2) != self.rows * self.cols:
            print("Incorrect number of elements.")
            return

        arr2 = np.array(elements2).reshape(self.rows, self.cols)

        print("\nOriginal Array:")
        print(self.arr)
        print("\nSecond Array:")
        print(arr2)

        if math_choice == 1:
            result = self.arr + arr2
            print("\nResult of Addition:")
        elif math_choice == 2:
            result = self.arr - arr2
            print("\nResult of Subtraction:")
        elif math_choice == 3:
            result = self.arr * arr2
            print("\nResult of Multiplication:")
        elif math_choice == 4:
            with np.errstate(divide='ignore', invalid='ignore'):
                result = np.true_divide(self.arr, arr2)
                result[arr2 == 0] = 0
            print("\nResult of Division:")
        else:
            print("Invalid math operation choice.")
            return

        print(result)

    def combine_split(self):
        if self.arr is None or self.arr.ndim != 2:
            print("Please create a 2D array first")
            return

        print("\nChoose an option:")
        print("1. Combine Arrays")
        print("2. Split Array")
        ch = int(input("Enter your choice: "))

        if ch == 1:
            total = self.rows * self.cols
            elements = list(map(int, input(f"\nEnter the elements of another array to combine ({total} elements separated by space): ").split()))
            if len(elements) != total:
                print("Number of elements must match the original array size.")
                return
            second = np.array(elements).reshape(self.rows, self.cols)

            print("\nOriginal Array:")
            print(self.arr)
            print("\nSecond Array:")
            print(second)

            combined = np.vstack((self.arr, second))
            print("\nCombined Array (Vertical Stack):")
            print(combined)

        elif ch == 2:
            print("\nOriginal Array:")
            print(self.arr)
            try:
                num_splits = int(input(f"Enter number of splits (must divide number of columns {self.cols}): "))
                if self.cols % num_splits != 0:
                    print("Number of splits must evenly divide the number of columns.")
                    return
                split_arrays = np.hsplit(self.arr, num_splits)
                for idx, part in enumerate(split_arrays):
                    print(f"\nPart {idx + 1}:")
                    print(part)
            except:
                print("Invalid input.")
        else:
            print("Invalid choice.")
    def search_sort_filter(self):
        print('''
            Choose an option:
            1. Search a value
            2. Sort the array
            3. Filter values1
            ''')
        ch = int(input("Enter your choice: "))

        if ch == 1:
            val = int(input("Enter value to search: "))
            result = np.where(self.arr == val)
            if len(result[0]) == 0:
                print("Value not found.")
            else:
                print(f"Value {val} found at indices:")
                for i in range(len(result[0])):
                    print(tuple(r[i] for r in result))
        elif ch == 2:
            print("\nOriginal Array:")
            print(self.arr)
            sorted_arr = np.sort(self.arr, axis=1)
            print("\nSorted Array:")
            print(sorted_arr)
            print("\n(Sorting applied row-wise.)")
        elif ch == 3:
            val = int(input("Enter threshold value to filter greater values: "))
            filtered = self.arr[self.arr > val]
            print(f"\nValues greater than {val}:")
            print(filtered)
        else:
            print("Invalid choice.")

    def aggregate_stats(self):
        print("Only 2D arrays supported for statistical operations.")            

        print("\nChoose an aggregate/statistical operation:")
        print("1. Sum")
        print("2. Mean")
        print("3. Median")
        print("4. Standard Deviation")
        print("5. Variance")
        choice = int(input("Enter your choice: "))

        print("\nOriginal Array:")
        print(self.arr)

        if choice == 1:
            print("Sum:", np.sum(self.arr))
        elif choice == 2:
            print("Mean:", np.mean(self.arr))
        elif choice == 3:
            print("Median:", np.median(self.arr))
        elif choice == 4:
            print("Standard Deviation:", np.std(self.arr))
        elif choice == 5:
            print("Variance:", np.var(self.arr))
        else:
            print("Invalid choice.")

obj1 = DataAnalytics()

while True:
    print('''
Welcome to the NumPy Analyzer!
1. Create a NumPy Array
2. Perform Mathematical Operations
3. Combine or Split Arrays
4. Search, Sort, or Filter Arrays
5. Compute Aggregates and Statistics
6. Exit
''')
    choice = int(input("Enter your choice: "))

    match choice:
        case 1:
            obj1.array()
        case 2:
            obj1.math_op()
        case 3:
            obj1.combine_split()
        case 4:
            obj1.search_sort_filter()
        case 5:
            obj1.aggregate_stats()
        case 6:
            print("Exiting...")
            break
        case _:
            print("Enter no between 1 to 6")