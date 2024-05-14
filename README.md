# TreciaUzduotis
##  5 functions
## std::vector and Vector efficiency/speed analysis
Using push_back() function I have to check how much time it will take both std::vector and Vector containers to be filled with 10.000, 100.000, 1.000.000, 10.000.000 and 100.000.000 elements. 
To check that I used chrono function and the code, given below.
#### Result
|               |    10 000     |    100 000    |   1 000 000   |  10 000 000   |  100 000 000  |
| ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
|  std::vector  |   0.000559s   |   0.000984s   |   0.014556s   |   0.133064s   |   1.167885s   |
|    Vector     |   0.000999s   |   0.001039s   |   0.015117s   |   0.165021s   |   1.522337s   |

It is easy to notice that std::vector is filled with elements faster than Vector. 
In overall, it took 1.317048s for std::vector and 1.704513s for Vector to be filled with every element number.

## std::vector and Vector memory reallocations when filling them with 100000000 elements
I have to check how many times containers std::vector and Vector undergo memory reallocations when filling both of them with 100000000 elements.
To make that, I made a simple function:

                unsigned int sz = 100000000;  // 10000, 100000, 1000000, 10000000, 100000000
                std::vector<int> v1;
                int std_vector_perskirstymas = 0;
                for (int i = 1; i <= sz; ++i) {
                    v1.push_back(i);
                    if (v1.capacity() == v1.size()) {
                        ++std_vector_perskirstymas;
                    }
                }
                cout << "Atmintis buvo perskirstyta " << std_vector_perskirstymas << " kartu su std::vector" << endl;

                Vector<int> v2;
                int vector_perskirstymas = 0;
                for (int i = 1; i <= sz; ++i) {
                    v2.push_back(i);
                    if (v2.capacity() == v2.size()) {
                        ++vector_perskirstymas;
                    }
                } 
                cout << "Atmintis buvo perskirstyta " << vector_perskirstymas << " kartu su Vector" << endl;
                
#### Result
While filling std::vector and Vector with 100.000.000 element, both of them reallocated memory 27 times.

![изображение](https://github.com/aran1ja/TreciaUzduotis/assets/147089828/ff20c8de-bac5-4a47-9d16-68e4ce758ec3)

## std::vector and Vector speed analysis using 100.000, 1.000.000 and 10.000.000 elements
### 100 000 elements
| std::vector                         |   Time   |
| ----------------------------------- | -------- |
| Reading data                        |  0.9764s |
| Sorting by ascending order          |  0.7319s |
| Dividing students into two groups   |  0.1459s |
| Writing data into "kietiakai" file  |  0.8200s |
| Writing data into "vargsiukai" file |  0.5811s |
| Total time                          |  3.5403s |

| Vector                              |   Time   |
| ----------------------------------- | -------- |
| Reading data                        |  0.8815s |
| Sorting by ascending order          |  0.7376s |
| Dividing students into two groups   |  0.1747s |
| Writing data into "kietiakai" file  |  0.8500s |
| Writing data into "vargsiukai" file |  0.5313s |
| Total time                          |  3.4001s |
### 1 000 000 elements
| std::vector                         |   Time   |
| ----------------------------------- | -------- |
| Reading data                        |  6.8916s |
| Sorting by last name                |  9.3750s |
| Dividing studnets into thwo groups  |  1.6716s |
| Writing data into "kietiakai" file  |  8.7873s |
| Writing data into "vargsiukai" file |  5.9741s |
| Total time                          | 34.9499s |

| Vector                              |   Time   |
| ----------------------------------- | -------- |
| Reading data                        |  6.5422s |
| Sorting by last name                |  9.9797s |
| Dividing studnets into thwo groups  |  2.1934s |
| Writing data into "kietiakai" file  |  8.8425s |
| Writing data into "vargsiukai" file |  5.3752s |
| Total time                          | 35.0439s |
### 10 000 000 elements
There is a mistake 'std:bad_alloc' with both std::vector and Vector containers.

#### Results
The results are very similar. The difference is only in milliseconds.

