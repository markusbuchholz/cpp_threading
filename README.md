### This is a repo for threadnig development (just for fun)
```
 mkdir build
 cd build
 /build/cmake ..
 /build/make
./run_your_program
```
**or**
 ```
 g++ -std=c++17 mutex2.cpp -o test -pthread
 ```
 
 **for TBB**
˝˝˝
g++ your_file.cpp -p output.out -ltbb
˝˝˝
### Links:

https://github.com/anthonywilliams/ccia_code_samples

### concurrency vs. parallelism

#### concurrency
```
| ~~ ~~ ~~ ~~  
|   ~~       ~~
|~~    ~~
|~~ ~~   ~~ ~~ ~~
|___________________
  execution time
```
#### parallelism
```
|~~ ~~ ~~ ~~ ~~ ~~
|~~ ~~ ~~ ~~ ~~ ~~
|~~ ~~ ~~ ~~ ~~ ~~
|~~ ~~ ~~ ~~ ~~ ~~
|___________________
    execution time
```
