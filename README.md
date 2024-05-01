# AntraUzduotis

## v1.1 release
#### Clonining the repository
I made a clone of my first repository named "PirmaUzduotis" and created a new repository "AntraUzduotis".

#### Test 1 - program performance comparison
To compare 'struct' and 'class' implementations I did measure the time it takes to run the program. Specifically, I measured the time it takes to run files with 100.000 and 1.000.000 records using the fastest strategy among 1-3.
##### Result
When using vector container, the class type operates around 2s faster (for 100.000 and 1.000.000 records it takes 14.32s for 'struct' type and 12.46s for 'class'). However, while using list and deque containers it is almost the same. Although, if larger file is used, the difference in time becomes more apparent - 'class' type is more efficient.

#### Test 2 - comparison of -O1, -O2, -O3 flags
This test was made to analyze how the performance of a program and its executable file size changes depending on the optimization level using flags: -O1, -O2 and -O3. Also, there was made a comparison between programs using 'struct' and 'class'.
##### Result
My compiler works the fastest with -O3 flag for both 'struct' and 'class' types. However, with 'struct' type .exe file is smaller using -O2 flag, while with 'class' type it is smaller using a -O1 flag.

## v1.2 release
#### Rule of Five
To use "Rule of Five", I implement all necessary methods, which are: copy constructor, copy assignment operator, move constructor, move assignment operator, destructor as well as input/output operators that would work with my class "Studentai". To check if they work properly, I did some test.
##### Results
All tests were successful, which means that Rule of Five works properly.

#### Input / output methods explanation
I did overridden input and output methods and did explanations. Example:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/639c853e-dbd6-4f24-9109-12f9f860f14c)
##### Results
Whether input was manual, automated or read from file, the information was read successfully as the output gave correct results.

## v1.5 release
#### Base and abstract class
In this part I had to implement two classes: a base abstract class to describe a person (Zmogus) and a derived class (Studentas) inheriting from it. This program also works with Rules of Five and to check that I did some tests.
##### Results
If base abstract class and derived class where written correctly, I couldn't create Zmogus object. That's why in int main() I wrote Zmogus zmogus; and this was the result: 
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/c41668b4-f5e7-4d3a-9f95-ffd940a24e84)
This red wave shows that there is a mistake, which means that Zmogus object creation is not possible. And this shows that base and abstract class work properly.

## v2.0 release

## Program Installation Instructions
1. Firstly, you have to setup your GitHub account. It is easier to do that following this guide: https://docs.github.com/en/get-started/onboarding/getting-started-with-your-github-account 
2. To find needed code, input a link into a search bar. For example, https://github.com/aran1ja/PirmaUzduotis/tree/v1.0
3. Open "Command Prompt" on your device.
4. In your terminal, write following command: git clone <https://github.com/aran1ja/PirmaUzduotis.git>
5. Open an app, you would like to run the code.
6. Depending on your app, you should install extensions. If you use Visual Studio Code, it is recommended to install following extensions:
"C/C++ Extension Pack", "C/C++ Runner", "Code Runner", "CMake", "CMake Tools".
7. On menu bar select "Terminal" -> "New Terminal". New terminal window should appear at the bottom of your app's interface.
Use the cd command followed by the path to your cloned repository: cd <your\directory\path>
For example, cd<C:\Users\acer\Desktop\Adri\VSCode\Programavimas>
8. To run the program, you have to compile it using "Makefile" file, which is provided in the repository. In the app's (like VSCode) terminal write:
* make programa
* make vektoriai

If you want to understand how to run and use the program, see "Program Usage Guide" below.

## Program Usage Guide
To start with a program, you have to write "./Vektoriai.exe" in a terminal.
Command "./Vektoriai.exe" will run the program. If there are no mistakes, you will see the menu with 7 possible choices. You have to make a choice, depending on what you want.

## Choice description:
1. You have to input students information data manually. You have to write students' names, surnames, how much homework grades they have and what grades did they get from homeworks and exams. Then program will ask what do you want to output: average grade, median or both. You will have to make a choice and the results will be outputed in the terminal.
2. You have to input students information data manually. Although, uou have to write only students' names and surnames. Program will generate homework and exam grades. Then program will ask what do you want to output: average grade, median or both. You will have to make a choice and the results will be outputed in the terminal.
3. In this case, program will generate the amount of students, their names, surnames and grades. You only have to choose what do you want to output: average grade, median or both. When you make a choice, the results are outputed in the terminal.
4. This choices can read the data from input files, calculate median and average and output results into a new file. It gives you a choice which file do you want to read from, gives 4 ways to sort students (by names, surnames, by average or by median) and then outputs the results.
5. In this case, program asks you if you want to generate new files. If you do, you generate new files with students data like names, surnames and grades. Then program uses 3 container types and 3 strategies to read the data from files. 3 container types are needed to see which container impacts the speed of program more effectively. In the 1 strategy, data will by stored in 3 containers (studentai, vargsiukai and kietiakai). Then, the results will be sorted in increasing order and outputed in 2 different files "vargsiukai" and "kietiakai". Although, this strategy is not effective in term of memory usage. Then you can try 2 strategy, which identifies who is "vargsiukas" and stores them in a new container. Those students, that were not sorted, they are left in a "studentai" container. This is much more effective way. There will be only one new file with "vargsiukai" in them. You can also try 3 strategy, which has implemented "effective" methods, which should speed up program.
6. This choice runs tests to check the Rule of Five method.
7. This choice ends the program. 
