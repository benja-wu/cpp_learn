# cpp_learn
Learn mode C++ project 

## Background
* Since 2018, I didn't use C++ as my main computer program language. Time flies! So does the C++ evolution.  

## Run with vscode github codespace 
0. Open website vscode.dev, login with your github account, install the plugin `GitHub Codespaces`. It will create one remote VM for u.  

1. Update the Ubuntu dependence version
```bash
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:ubuntu-toolchain-r/test

```

2. Install c++-11 to use c++20 std feature 
```bash
sudo apt install g++-11

```
3. Compile and run with C++20 features

```bash
g++-11 -std=c++2a -o a a.cpp
```