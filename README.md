# AntraUzduotis
For this part of project I made a clone of my first repository named "PirmaUzduotis" and created a new repository "AntraUzduotis". I did it using terminal in my computer. Commands that I used:
* git clone --mirror https://github.com/aran1ja/PirmaUzduotis.git
* git clone --bare C:\Users\acer\PirmaUzduotis.git AntraUzduotis
* git branch -a
* git remote set-url origin https://github.com/aran1ja/AntraUzduotis.git
* git push --mirror
## Program performance comparison
To compare 'struct' and 'class' implementations I did measure the time it takes to run the program. Specifically, I measured the time it takes to run 2 files (with 100.000 and 1.000.000 records) for one container at a time, using the fastest strategy among 1-3 (from previous version of the program).
## Results
### Type 'struct' 
#### Vector
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/d59f312d-1311-418f-aae2-13ef54126dac)
#### List
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/96313a39-2f74-4c29-8c11-64ba81f276b3)
#### Deque
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/c6412be4-05d5-4790-897f-a69fc263d856)

### Type 'class' 
#### Vector
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/c80e1a9d-5a18-4866-8448-650b0f721a94)
#### List
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/2b2c9620-8bc1-409d-ae7d-45dc94cccbe2)
#### Deque
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/8169a652-b837-468b-b6ab-bbf9deddbe0a)

### Summary
