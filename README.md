# AntraUzduotis
For this part of project I had to implement two classes: a base abstract class to describe a person (Zmogus) and a derived class (Studentas) inheriting from it. 

To do that I made a new class Zmogus:
![изображение](https://github.com/aran1ja/AntraUzduotis/assets/147089828/3924bbcd-28cb-4b8f-84c7-0d6bcdbb25ff)

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
