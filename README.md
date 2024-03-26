# AntraUzduotis
For this part of project I made a clone of my first repository named "PirmaUzduotis" and created a new repository "AntraUzduotis". I did it using terminal in my computer. Commands that I used:
* git clone --mirror https://github.com/aran1ja/PirmaUzduotis.git
* git clone --bare C:\Users\acer\PirmaUzduotis.git AntraUzduotis
* git branch -a
* git remote set-url origin https://github.com/aran1ja/AntraUzduotis.git
* git push --mirror
## Program performance comparison
To compare 'struct' and 'class' implementations I did measure the time it takes to run the program. Specifically, I measured the time it takes to run 2 files (with 100.000 and 1.000.000 records) for one container at a time, using the fastest strategy among 1-3 (from previous version of the program). Also, I measured the time it takes to run a program using flags -O1, -O2, -O3, three different containers.
## Results - 'struct' and 'class' comparison
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
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/91fd8e6a-b037-413f-96a1-c071f92ede8c)

From this table, it is easy to notice a slight difference in the time it takes to run the program with 'struct' and 'class' types. 
When using vector container, the _class_ type operates around 2s faster. However, while using list and deque containers it is almost the same. Although, if we would use larger files, the difference would become more apparent. For this reason I decided to check the file with 10.000.000 records and results were following.

struct:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/97d03e27-df48-4791-9a68-e0fc4b015c24)

 class:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/62fa3cc8-e0cd-4f2d-bcbc-984efe7268a8)

Overall, the class type is more efficient.

## Results - flags -O1, -O2, -O3 comparison
### Type 'struct'
#### Vector
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/f119bda1-962d-4fa8-9c6f-5cbb47735ce5)
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/387de290-4b25-40e0-b940-be4fc1352037)
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/3a2abf8c-4ee5-4d44-bbd9-35cbfe8dceac)
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/4dce79cf-2188-4849-82d4-161df23c73a3)

#### List
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/d079e7af-b7c5-4b89-baca-64c1bc7bf4ed)
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/7bf67366-268e-48ef-bcef-d40d2831381f)
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/846c4dab-4653-4127-bbf5-63b4c3f8928d)
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/3f93fd44-844a-4252-ad4e-a5d62744d39d)

#### Deque
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/04bd299f-3705-4d94-b3c3-d435c21c07d7)
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/65e8451e-40d1-4759-aabd-509cb8f44f12)
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/59697315-4991-4227-a969-4f9b66eb90a0)
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/f5436335-b1ca-4e25-b5c7-36ae3b9db093)

#### .exe file size: 424 KB
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/733b7285-42ef-43ff-b24e-74c451fffe20)

### Type 'class'
#### Vector
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/1e616e6b-f697-40e7-a122-b0454b8df213)
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/a75a2111-70a7-4293-85e5-520af9dc8e87)
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/10221d01-c1ee-4390-9b66-237c4ab1958c)
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/73c0c0de-3232-432b-8b6d-b65907a520fb)

#### List
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/d6f13755-3ce9-41c6-96d1-e5f301884bef)
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/3d8c1b44-5682-4b1d-bbc0-627efaba5aa2)
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/d8c738fb-fd1d-4abb-b6a2-50285fad51ed)
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/91ab079a-2ebe-4473-b2fe-58df5aafca47)

#### Deque
##### -O0
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/486ee562-3d60-41fe-a233-dc81de8dad88)
##### -O1
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/67aae809-fbd9-4f0d-b9d7-29a7f1b8984a)
##### -O2
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/7d9f7803-ba39-428b-8c87-ef0242789bff)
##### -O3
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/5536d7de-fd4e-43dd-9347-d9d4cd3da9a8)


#### .exe file size: 444 KB
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/2132a71a-4c89-4df5-b9c0-2fa2f5c5238c)

### Summary
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/91c1a1a2-f8c2-4f76-b152-ec316cf2b540)

From this table we get a lot of information about compiler flags and containers. It is easy to notice, that when I use container <vector>, my compiler works best with the -O3 flag. While using container <deque> it is best to use -O0 flag. For container <list> it is different with each flag: with struct type it is best to use -O2 flag, with class type -O1 or -O2 as they give similar results. 
There is also a second table which shows that for _struct_ type it is best to use -O3 flag, but -O0 also gives similar results. For _class_ type it is the best to use -O0 flag. 
In overall, my compiler works the best with *-O0* or *-O3 flag*.


