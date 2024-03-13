# PirmaUzduotis
## Description
#### The program compares the performance of different container types: std::vector, std::list, std::deque. The goal is to investigate how the choice of container impacts the performance of the program, including data reading, sorting and organizing.

## Test 1
#### The program was tested with the same files of 1000, 10000, 100000, 1000000, 10000000 records. During each test, the time required for data reading, sorting and organization was measured. Additionally, parameters such as CPU and RAM usage, and SSD activity were recorded during testing.

## Results
#### 1.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/709a9918-9059-4437-8667-c55f23044bb2)
#### CPU, RAM and SSD during 1.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/b60f88a3-8904-4017-b4a1-41d04c617e73)

#### 10.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/5564b0d1-3121-45cc-8b38-92c2c71099ab)
#### CPU, RAM and SSD during 10.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/1fda8473-e3be-4a1e-92e0-6e8c3c84a566)

#### 100.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/d12ee898-9950-4ef6-be8b-927bbf746ace)
#### CPU, RAM and SSD during 100.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/0f538446-72a2-4cea-a1ab-163a91cba8ae)

#### 1.000.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/29e59d74-079d-46d1-8a1a-18e441df7905)
#### CPU, RAM and SSD during 1.000.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/09b190e0-6ae5-4de6-b0a3-ffc5adc8626f)

#### 10.000.000 records
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/03a49947-3ba1-40b1-9774-d5417830707f)
#### CPU, RAM and SSD during 10.000.000 records
##### During std::vector container performance
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/f2b2efd8-e08f-411f-8ba7-13f0dece1faf)
##### During std::list container performance
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/7466ba8d-d2dd-4f9f-a020-45f5946a9fcd)
##### During std::deque container performance
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/3f3194c2-deca-4964-ba2a-611a3f736f4e)

## Summary of Test 1
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/a61123f6-46e1-4c08-b64e-7076ffe80661)
#### As we can notice in the table, the program with the std::list container operates the fastest(about 63s for all 5 files), while the program with the std::deque container takes the longest(about 185s for all 5 files). This happens because the std::list container seems to be the most efficient for sorting. While it takes much more time with the std::vector and std::deque containers.

## Test 2
#### The program has optimized sorting function for students to divide them into two categories: "vargsiukai" and "kietiakai". There were made 3 different strategies to do it.
### Strategy 1
#### Splitting the common students container (std::vector, std::list, std::deque) into two new containers "vargsiukai" and "kietiakai". Although, this strategy is inefficient in terms of memory usage:
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/10f68bd5-6f19-45fa-9146-e5b457443656)
#### Results
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/ad892d14-15e4-4198-bbf1-9cc0372d1730)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/7579851a-0265-48c6-8e9d-4aaf804f525c)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/618abd1c-b9f4-4807-b317-53405149e85e)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/c1f2b752-f4bd-420e-ab08-a858e39dab35)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/58b7eb9c-9b1d-495d-ac9c-5ebf68d5cedb)

### Strategy 2
#### Splitting the common students container (std::vector, std::list, std::deque) into one new container "vargsiukai". If a student is a "vargsiukas", he is moved to the new container and deleted from common students container. After this, in the students container will only "kietiakai" remain.
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/a91c86b6-b5e3-4d29-91d7-ed1d227e4ea8)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/307582eb-c180-49ae-af75-02d6f7539de3)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/ac93e873-0921-4499-b813-5685ab0a94b5)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/31cd7728-dd48-43ec-b441-5a6e80ad10dd)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/6536f0d3-a36f-423e-8768-b994a22e0267)

### Strategy 3
#### Splitting the common students container (std::vector, std::list, std::deque) using the most efficient 2 Strategy and adding "efficient" container manipulation methods such us "find_if", "remove_if".
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/7c76aa50-521d-45a8-a756-c99df1b26020)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/67ff43d1-90f8-42d1-a018-e7b26b4ae0d4)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/e1de90cd-fdce-416d-ab30-875870a0b67a)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/79dda94b-8fb6-4039-9d0e-601128d2993b)
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/a6dc2037-7f5a-4109-b2ed-e7523d43e1ae)

## Summary of Test 2
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/b3caa661-8361-40f7-a981-aeaf561c645a)
#### We can notice in the table, that the results of Test 1 are also confirmed there. The program with the std::list container operates the fastest, while the program with the std::deque container takes the longest. 
#### Test 2 had the aim to see how results would differ if for sorting student in increasing order we would implement 3 different strategies. There container std::list seems to be the most efficient for sorting. While it takes much more time with the std::vector and std::deque containers.
### 1 strategy
#### It is inefficient, as it takes much more time to sort students and also it has problems with memory usage. When we work with large files, a "bad_alloc" error may occur. Although, with std::list container it took only 17s for all 9 files to sort students.
### 2 strategy
#### It is much more efficient, as it takes more than twice less time to sort students. Even with std::list container it took only 7s for 9 files for program to sort students.
### 3 strategy
#### The results are similar to the ones in 2 strategy. That could be because in both the 2 and 3 strategies, I used 'efficient' methods. I tried to use more effective methods in the 3rd strategy, but that probably caused the reason why it took a little bit more time for program to sort students.

## Program Installation Instructions


## Program Usage Guide
#### To start with a program, you have to compile the program using the provided makefile file. In the terminal you have to write:
#### make vektoriai
#### make funkcijos
#### make programa
#### ./Vektoriai.exe
#### Command "./Vektoriai.exe" will run the program. After that you will see the menu with 6 possible choices. You have to make a choice, depending on what you want.
### Choice description:
#### 1. You have to input students information data manually. You have to write students' names, surnames, how much homework grades they have and what grades did they get from homeworks and exams. Then program will ask what do you want to output: average grade, median or both. You will have to make a choice and the results will be outputed in the terminal.
#### 2. You have to input students information data manually. Although, uou have to write only students' names and surnames. Program will generate homework and exam grades. Then program will ask what do you want to output: average grade, median or both. You will have to make a choice and the results will be outputed in the terminal.
#### 3. In this case, program will generate the amount of students, their names, surnames and grades. You only have to choose what do you want to output: average grade, median or both. When you make a choice, the results are outputed in the terminal.
#### 4. This choices can read the data from input files, calculate median and average and output results into a new file. It gives you a choice which file do you want to read from, gives 4 ways to sort students (by names, surnames, by average or by median) and then outputs the results.
#### 5. In this case, program asks you if you want to generate new files. If you do, you generate new files with students data like names, surnames and grades. Then program uses 3 container types and 3 strategies to read the data from files. 3 container types are needed to see which container impacts the speed of program more effectively. In the 1 strategy, data will by stored in 3 containers (studentai, vargsiukai and kietiakai). Then, the results will be sorted in increasing order and outputed in 2 different files "vargsiukai" and "kietiakai". Although, this strategy is not effective in term of memory usage. Then you can try 2 strategy, which identifies who is "vargsiukas" and stores them in a new container. Those students, that were not sorted, they are left in a "studentai" container. This is much more effective way. There will be only one new file with "vargsiukai" in them. You can also try 3 strategy, which has implemented "effective" methods, which should speed up program.
#### 6. This choice ends the program. 

