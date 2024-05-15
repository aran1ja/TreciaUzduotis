# TreciaUzduotis

## Checking 6 Vector functions
This is made to check whether Vector works same as std::vector.
To do this, I took a look on https://cplusplus.com/reference/vector/vector/ website. In this website there are functions made with std::vector. I made similar functions using my Vector container and then compared my output and the output from given site.
### Rational operators
#### The code
    {
      Vector<int> foo (3,100);   // three ints with a value of 100
      Vector<int> bar (2,200);   // two ints with a value of 200
    
      if (foo == bar) std::cout << "foo and bar are equal\n";
      if (foo != bar) std::cout << "foo and bar are not equal\n";
      if (foo <  bar) std::cout << "foo is less than bar\n";
      if (foo >  bar) std::cout << "foo is greater than bar\n";
      if (foo <= bar) std::cout << "foo is less than or equal to bar\n";
      if (foo >= bar) std::cout << "foo is greater than or equal to bar\n";
    }
#### Expected result
      foo and bar are not equal
      foo is less than bar
      foo is less than or equal to bar
#### Result
      foo and bar are not equal
      foo is less than bar
      foo is less than or equal to bar
### resize()
#### The code
    {
      Vector<int> myvector;

      for (int i=1; i < 10; i++) myvector.push_back(i);

     myvector.resize(5);
     myvector.resize(8, 100) 
     myvector.resize(12);

      cout << "myvector contains: ";
      for (int i = 0; i < myvector.size();i++)
         cout << ' ' << myvector[i];
      cout << '\n';
    }
#### Expected result
      myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
#### Result
      myvector contains: 1 2 3 4 5 100 100 100 0 0 0 0
### erase()
#### The code
    {
      Vector<int> myvector;
      for (int i = 1; i <= 10; i++) myvector.push_back(i);
      
      myvector.erase (myvector.begin() + 5);
      myvector.erase (myvector.begin(), myvector.begin() + 3);
      cout << "myvector contains:";
      for (unsigned i = 0; i < myvector.size(); ++i)
        cout << ' ' << myvector[i];
      cout << '\n';
    }
#### Expected result
      myvector contains: 4 5 7 8 9 10
#### Result
      myvector contains: 4 5 7 8 9 10
### begin()
#### The code
    {
      Vector<int> myvector;
      for (int i = 1; i <= 5; i++) myvector.push_back(i);
    
      cout << "myvector contains:";
      for (Vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        cout << ' ' << *it;
      cout << '\n';
    }
#### Expected result
      myvector contains: 1 2 3 4 5
#### Result
      myvector contains: 1 2 3 4 5
### shrink_to_fit()
#### The code
    {
      Vector<int> myvector (100);
      cout << "1. capacity of myvector: " << myvector.capacity() << '\n';
    
      myvector.resize(10);
      cout << "2. capacity of myvector: " << myvector.capacity() << '\n';
    
      myvector.shrink_to_fit();
      cout << "3. capacity of myvector: " << myvector.capacity() << '\n';
    }
#### Expected result
      1. capacity of myvector: 100
      2. capacity of myvector: 100
      3. capacity of myvector: 10
#### Result
      1. capacity of myvector: 100
      2. capacity of myvector: 100
      3. capacity of myvector: 10
### pop_back()
#### The code
    {
      Vector<int> myvector;
      int sum (0);
      myvector.push_back (100);
      myvector.push_back (200);
      myvector.push_back (300);
    
      while (!myvector.empty())
      {
        sum += myvector.back();
        myvector.pop_back();
      }
    
      cout << "The elements of myvector add up to " << sum << '\n';
    }
#### Expected result
      The elements of myvector add up to 600
#### Result
      The elements of myvector add up to 600
      
#### Expected results and my results are same. This means that my Vector container works as same as std::vector.

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

## GoogleTests
To check whether my vector.h works properly, I did 14 tests to check functions, operators.
Example code:

        TEST(VectorTest, MoveKonstruktorius) {
            Vector<int> v1(5, 10);
            Vector<int> v2(std::move(v1));
            EXPECT_EQ(v1.size(), 0);
            EXPECT_EQ(v1.capacity(), 0);
            EXPECT_TRUE(v1.empty());
            EXPECT_EQ(v2.size(), 5);
            EXPECT_EQ(v2.capacity(), 5);
            for (int i = 0; i < 5; ++i) {
                EXPECT_EQ(v2[i], 10);
            }
        }
        
        TEST(VectorTest, FrontFunkcija) {
            Vector<int> v = { 1, 2, 3, 4, 5 };
            EXPECT_EQ(v.front(), 1);
        }
        
        TEST(VectorTest, BackFunkcija) {
            Vector<int> v = { 1, 2, 3, 4, 5 };
            EXPECT_EQ(v.back(), 5);
        }

## Setup.exe file
I created Setup.exe file using Inno Setup Compiler from https://inno-setup-compiler.en.lo4d.com/windows. It helped me to create a .iss script. 
Setup.exe file is installed into C:/Program files/VU/Vardenis-Pavardenis folder and Administrator rights are given.

