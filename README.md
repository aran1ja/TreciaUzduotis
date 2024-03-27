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


