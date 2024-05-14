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


