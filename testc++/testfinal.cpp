// 1.
// #include <iostream>
// #include <string>
// using namespace std;
// class Book {
// public:
//     string title;
//     string author;
//     int publishedYear;
    
//     Book(string t, string a, int y) {
//         title = t;
//         author = a;
//         publishedYear = y;
//     }

//     void display() {
//         cout << "Title: " << title << ", Author: " << author<< ", Year: " << publishedYear << endl;
//     }
// };

// int main() {
//     Book books[3] = {
//         Book("harry poter", "james cameron", 2000),
//         Book("sherlock homes", "taarak mehta", 1960),
//         Book("rich dad poor dad", "robert", 2005)
//     };

//     for (int i = 0; i < 3; ++i) {
//         cout << "Book " << i + 1 << ": ";
//         books[i].display();
//     }
//     return 0;
// }









// 2.
// #include <iostream>
// #include <string>
// using namespace std;
// class person {
// private:
//     string name, address;
//     int age;

// public:
//     person() {
//         setperson();
//     }

//     void setperson() {
//         cout << "Enter name: "; cin>>name;
//         cout << "Enter address: "; cin>>address;
//         cout << "Enter age: "; cin>>age;
//     }

//     void getperson() const {
//         cout << "Name: " << name << "\nAddress: " << address << "\nAge: " << age << "\n";
//     }
// };

// int main() {
//     int n;
//     cout << "Enter number of persons: ";
//     cin >> n;

//     person* p = new person[n];

//     for (int i = 0; i < n; i++) {
//         cout << "\nPerson " << i + 1 << ":\n";
//         p[i].getperson();
//     }

//     return 0;
// }









// 3.
// #include <iostream>
// #include <string>
// using namespace std;

// class Animal {
// protected:
//     string name1, name2;
//     string sound1, sound2;
// public:
//     void getname() {
//         cin >> name1 >> name2;
//     }

//     void setsound() {
//         cin >> sound1 >> sound2;
//     }

//     string getSound1() {
//         return sound1;
//     }

//     string getSound2() {
//         return sound2;
//     }

//     string getName1() {
//         return name1;
//     }

//     string getName2() {
//         return name2;
//     }
// };

// class Dog : public Animal {
// public:
//     void setsound(string a1) {
//         cout << "Dog " << a1 << endl;
//     }
// };

// class Cat : public Animal {
// public:
//     void setsound(string a2) {
//         cout << "Cat " << a2 << endl;
//     }
// };

// int main() {
//     Animal a;
//     Dog d;
//     Cat c;

//     cout << "Enter two animal names (dog and cat): ";
//     a.getname();

//     cout << "Enter dog sound & cat sound: ";
//     a.setsound();

//     d.setsound(a.getSound1());
//     c.setsound(a.getSound2());

//     return 0;
// }









// 4.
// #include <iostream>
// #include <string>
// using namespace std;
// class Animal {
// public:
//     string name1, name2;
//     string sound1, sound2;
//     virtual void getname() {
//         cin >> name1 >> name2;
//     }

//     virtual void setsound() {
//         cin >> sound1 >> sound2;
//     }

//     string getSound1() {
//         return sound1;
//     }
//     string getSound2() {
//         return sound2; 
//     }
//     string getName1() {
//         return name1; 
//     }
//     string getName2() {
//         return name2;
//     }

//     virtual void displaydetails() const {
//         cout << "Generic Animal details.\n";
//     }

//     virtual ~Animal() {}
// };

// class Dog : public Animal {
// public:
//     void setsound(string a1) {
//         cout << "Dog sounds: " << a1 << endl;
//     }

//     void displaydetails() const override {
//         cout << "Animal Type: Dog\n";
//         cout << "Name: " << name1 << "\n";
//         cout << "Sound: " << sound1 << "\n";
//     }
// };

// class Cat : public Animal {
// public:
//     void setsound(string a2) {
//         cout << "Cat sounds: " << a2 << endl;
//     }
//     void displaydetails() const override {
//         cout << "Animal Type: Cat\n";
//         cout << "Name: " << name2 << "\n";
//         cout << "Sound: " << sound2 << "\n";
//     }
// };

// int main() {
//     Animal a;
//     Dog d;
//     Cat c;
//     cout << "Enter two animal names (dog and cat): ";
//     a.getname();
//     cout << "Enter dog sound & cat sound: ";
//     a.setsound();

//     d.name1 = a.getName1();
//     d.sound1 = a.getSound1();

//     c.name2 = a.getName2();
//     c.sound2 = a.getSound2();

//     d.setsound(d.getSound1());
//     c.setsound(c.getSound2());

//     Animal *animals[2];
//     animals[0] = &d;
//     animals[1] = &c;

//     for (int i = 0; i < 2; ++i) {
//         animals[i]->displaydetails();
//         cout << endl;
//     }
//     return 0;
// }









// 5.
// #include <iostream>
// using namespace std;
// class Complex
// {
// public:
//     int real;
//     int imaginary;

//     Complex(int r = 0, int i = 0) : real(r), imaginary(i) {
         
//     }
//     Complex operator-(const Complex &other) {
//         return Complex(real - other.real, imaginary - other.imaginary);
//     }
    
//     void display() {
//         cout<<real<<" + "<<imaginary<<"j"<<endl;
//     }
// };

// int main() {
//     int real1, imag1, real2, imag2;

//     cout<<"Enter first two complex number: ";
//     cin>>real1>>imag1;

//     cout << "Enter second two complex number: ";
//     cin>>real2>>imag2;

//     Complex c1(real1, imag1);
//     Complex c2(real2, imag2);

//     Complex result = c1 - c2;
//     cout<<"Result: ";
//     result.display();
    
//     return 0;
// }











// 6.
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// class FileManager {
// public:
//     void readFile(const string& fileName) {
//         ifstream file;          
//         file.open(fileName);

//         if (!file) {
//             throw runtime_error("Error: Could not open the file '" + fileName + "'");
//         }

//         string line;
//         cout << "Contents of the file:" << endl;
//         while (getline(file, line)) {
//             cout << line << endl;
//         }

//         file.close();  // Close the file
//     }
// };

// int main() {
//     FileManager fm;
//     string fileName;

//     cout << "Enter the file name: ";
//     cin >> fileName;

//     try {
//         fm.readFile(fileName);  // Try to read the file
//     } catch (const runtime_error& e) {
//         cout << e.what() << endl;
//     }

//     return 0;
// }









// 7.
// #include <iostream>
// #include <cmath>
// using namespace std;
// class Shape {
// public:
//     virtual double Area() const = 0;
//     virtual void Draw() const = 0;
//     virtual ~Shape() {}
// };

// class Circle : public Shape {
// private:
//     double radius;

// public:
//     Circle(double r) : radius(r) {}

//     double Area() const override {
//         return M_PI * radius * radius;
//     }

//     void Draw() const override {
//         cout<<"Circle ";
//     }
// };

// class Rectangle : public Shape {
// private:
//     double width, height;

// public:
//     Rectangle(double w, double h) : width(w), height(h) {}

//     double Area() const override {
//         return width * height;
//     }

//     void Draw() const override {
//         cout << "Rectangle ";
//     }
// };

// int main() {
//     double radius, width, height;
//     cout << "Enter radius: ";
//     cin >> radius;

//     cout << "Enter width: ";
//     cin >> width;

//     cout << "Enter height: ";
//     cin >> height;

//     Shape* shapes[2];
//     shapes[0] = new Circle(radius);
//     shapes[1] = new Rectangle(width, height);

//     for (int i = 0; i < 2; ++i) {
//         shapes[i]->Draw();
//         cout << "Area: " << shapes[i]->Area() << endl;
//     }
//     return 0;
// }