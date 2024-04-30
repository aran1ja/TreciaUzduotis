# AntraUzduotis
For this part of project I made a clone of my first repository named "PirmaUzduotis" and created a new repository "AntraUzduotis". I did it using terminal in my computer. Commands that I used:
* git clone --mirror https://github.com/aran1ja/PirmaUzduotis.git
* git clone --bare C:\Users\acer\PirmaUzduotis.git AntraUzduotis
* git branch -a
* git remote set-url origin https://github.com/aran1ja/AntraUzduotis.git
* git push --mirror
## Program performance comparison
To compare 'struct' and 'class' implementations I did measure the time it takes to run the program. Specifically, I measured the time it takes to run 2 files (with 100.000 and 1.000.000 records) for one container at a time, using the fastest strategy among 1-3 (from previous version of the program). Also, I measured the time it takes to run a program using flags -O1, -O2, -O3.
## Results - 'struct' and 'class' comparison
### Type 'struct' 
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/d59f312d-1311-418f-aae2-13ef54126dac)

### Type 'class' 
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/c80e1a9d-5a18-4866-8448-650b0f721a94)

### Summary

struct: 14.32s

class: 12.46s

It is easy to notice a slight difference in the time it takes to run the program with 'struct' and 'class' types. 
When using vector container, the _class_ type operates around 2s faster. However, while using list and deque containers it is almost the same. Although, if we would use larger files, the difference would become more apparent. For this reason I decided to check the file with 10.000.000 records and results were following.

struct:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/97d03e27-df48-4791-9a68-e0fc4b015c24)

 class:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/62fa3cc8-e0cd-4f2d-bcbc-984efe7268a8)

Overall, the class type is more efficient.

## Results - flags -O1, -O2, -O3 comparison
### Type 'struct'
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/5ad3252d-51b8-4154-8e2d-2a990e6c70b8)

.exe file size: 424 KB
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/c221a8ec-13b3-48e1-a7fa-4c9874c1a98e)

.exe file size: 287 KB
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/57660745-a62e-4aad-997e-e5980abbc498)

.exe file size: 268 KB
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/1cff3523-f980-4b8e-9655-42c3e4bb986e)

.exe file size: 272 KB
#### .exe file size

![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/70a5f56c-9bbf-4f6c-b45d-422252eb16f7)
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/476a6738-9628-4ac0-b505-1dfe618fec35)

### Type 'class'
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/4d8704eb-e0e3-42ee-b500-59ff6ee0e621)

.exe file size: 445 KB
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/8b332495-fe6b-4122-9e44-dbd73239c4cc)

.exe file size: 254 KB
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/7bcaa0fd-50d2-4db2-8989-efa30e8319aa)

.exe file size: 259 KB
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/263be4cc-b15e-4897-9f16-b5779ec9fb6c)

.exe file size: 274 KB
#### .exe file size
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/2f43f0b3-ccfc-42ca-b679-84deec3b2f0c)
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/218d96d8-4363-4b7f-89d8-a2d8b3ea021f)

### Summary
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/e1dde9b9-adfa-46ec-879c-03c9b6b8d059)

From this table we get a lot of information about compiler flags and containers. It is easy to notice, that my compiler works the fastest with -O3 flag for both struct and class types. Although, with _struct_ type .exe file size is smaller while using _-O2 flag_. However, with _class_ type file size is smaller with _-O1 flag_, but _-O2_ is also effective, as .exe file is almost the same size.

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

For this part of project I had to implement two classes: a base abstract class to describe a person (Zmogus) and a derived class (Studentas) inheriting from it. 

To do that I made a new class Zmogus:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/60dc0c5d-f61c-4a87-b6d5-e9fef6697c3e)

Also, I modified my Studentas class:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/f8d725ed-893e-48ff-9ac2-954698307ee9)

This program works with Rules of Five. To check that I made some tests:

![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/f249bf1f-d0d5-43a0-8929-d15e492109a2)

#### To check Input / Output methods I used function friend:
For input I used friend istream& operator>>(istream& is, Studentas& studentas) {...}

For output I used friend ostream& operator<<(ostream& os, const Studentas& studentas) {...}

To check if I can create object Zmogus, I wrote:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/c41668b4-f5e7-4d3a-9f95-ffd940a24e84)

Red wave shows that there is a mistake, which means that Zmogus object creation is not possible.
