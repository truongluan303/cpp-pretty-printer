# C++ Pretty Printer

As someone working mostly with high-level languages, something I notice missing from C++ is how tough it is to print a data structure. For example, in python or pretty much any other interpreted language, you can just simply print the data structure as easily as typing `print(arr)`. However, printing a vector in C++ requires me to loop through each element and print that element out. It is even worse if the vector is nested. Most of the time, I find myself wasting time during interviews or debugging sessions because we are lacking helper functions that help us quickly print a data structure.

![typing](https://media.giphy.com/media/9CffOPMLx0Hf2/giphy.gif)

All of that typing just to print out a nested map? It does not make sense! So I just decided to make a quick library that we can use to quickly print a data structure.


### How to use it?

You can just simply call `PrettyPrinter::puts` to print your data structure directly to the console output. If you want to get a string representation of your data structure instead, you can use `PrettyPrinter::str_repr`.

```cpp
vector<int> v0 {1, 2, 3};
vector<int> v1 {4, 5, 6};
vector<vector<int>> v {v0, v1};
map<int, vector<int>> m {{1, v0}, {2, v1}};

PrettyPrinter::puts(v);                     // output: [[1, 2, 3], [4, 5, 6]]

string repr = PrettyPrinter::str_repr(m);
cout << repr << endl;                       // output: {1=>[1, 2, 3], 2=>[4, 5, 6]}
```
