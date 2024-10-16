# cpp_learn
Learn mode C++ project 

## Background
* Since 2018, I didn't use C++ as my main computer program language. Time flies! So does the C++ evolution. 
* C++20 introduces so many interesting features, coroutine, lambda, new std and so on. Need to catch up with it.  

## Run with vscode github codespace 

With network turns on, one browser, one github account, we can write and run codes easily, even with iPad Pro!(Actually, that's my only gear for this project!).  

0. Open website https://vscode.dev, login with your github account, install the plugin `GitHub Codespaces`. It will create one remote VM for compiling and running the code. 

1. Update the Ubuntu dependence version
```bash
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:ubuntu-toolchain-r/test

```

2. Install g++-11/g++-13 to use c++20 std feature 
```bash
sudo apt install g++-11
or
sudo apt install g++-13
```
3. Compile and run with C++20 features

```bash
g++-11 -std=c++2a -o a a.cpp
or
g++-13 -std=c++20 -o a a.cpp
```