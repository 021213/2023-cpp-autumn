#include<iostream>

int main(int argc, char* argv[])
{
    int n = 0;
    std::cin >> n;
    
    for(int i = 0; i < 32; ++i)
    {
        std::cout << (n >> (31 - i) & 1);
    }
    
    return 0;
}
