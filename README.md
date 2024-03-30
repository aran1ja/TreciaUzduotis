# AntraUzduotis
For this part of project I had to implement all necessary "_Rule of Five_" methods, which are: copy constructor, copy assignment operator, move constructor, move assignment operator, destructor as well as input/output operators that would work with my class "Studentai". 

Using a given example from this site https://en.cppreference.com/w/cpp/language/rule_of_three , I modified my code:

![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/897d73c4-d1dc-4de7-b220-5db63f8b792b)
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/44b002f5-bf95-4829-bac6-18993472a174)

Then I added a void function that checks whether the constructor, copy and move methods, destructor work properly. If they do, the terminal will display the following result: 'Visi testai sekmingi!'."
// Constructors
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/1598b9e7-8202-4c57-bbaa-17bbb68c3298)

// Copy method
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/bae356ed-8fe3-4bf0-b3ea-14a62c7df7a0)

// Move method
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/f791387d-8078-4e80-8a63-04c6052ae69a)

// Dectructor

![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/d526a4c0-aefb-4f16-9a6a-80e08cd80ef4)

## Input / output methods explanation
### Input
For input setter's are used. As example, I will use setVardas.
1. The setVardas method sets student's name.
2. After receiving the name, it stores it in the vardas_ private member variable.
   
Example:

cin >> vardas;

naujas_studentas.setVardas(vardas);
#### Manual input
Users provide the student's name via the input. The setVardas method sets the name of a student and stores it in the vardas_ private member variable.
#### Automated input
The program generates student data. The method can accept the name and store it in the vardas_ private member variable.
#### Input from file
The method can read the student's name from a file and then store it in the private member variables.
### Output
For output getter's are used. As example, I will use getVardas.
Basically, the getVardas method retrieves the student's name from private using getVardas method. Then it can be displayed on the screen or be written to a file.
It is determined by the way the code is written. 
#### Display on a screen
To display information on a screen, cout is used. For example, 

for (const auto& studentas : studentai) {

cout << left << setw(15) << studentas.getVardas() << endl; }
#### Display in a file
To display information in a file, ofstream is used. For exapmle, 

ofstream file(failoPavadinimas);

for (const auto& studentas : studentai) {

file << setw(15) << left << studentas.getVardas() << endl; }
