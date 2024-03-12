# PirmaUzduotis
## Description
#### I created a program, which compares the performance of different container types: std::vector, std::list, std::deque. The goal is to investigate how the choice of container impacts the performance of the program, including data reading, sorting and organizing.

## Testing 
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

## Summary
![изображение](https://github.com/aran1ja/PirmaUzduotis/assets/147089828/a61123f6-46e1-4c08-b64e-7076ffe80661)
#### As we can notice in the table, the program with the std::list container operates the fastest(about 63s for all 5 files), while the program with the std::deque container takes the longest(about 185s for all 5 files). This happens because the std::list container seems to be the most efficient for sorting. While it takes much more time with the std::vector and std::deque containers.
