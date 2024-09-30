#include <iostream>
#include <functional>

auto main() -> int {
    std::cout<<"Hello World! Modern CPP"<<'\n';
    std::cout<<std::plus<int>{}(1, 1.23)<<'\n';
}