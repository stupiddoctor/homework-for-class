#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <chrono>
#include "HeapSort.h"

//该函数生成随机序列
std::vector<int> generateRandom(int length) {
    std::vector<int> vec(length);
    int k;
    for (int i = 0; i < length; i++) {
        k=rand();
        vec[i] = k;
    }
    return vec;
}

//该函数生成有序序列
std::vector<int> generateOrdinal(int length) {
    std::vector<int> vec(length);
    int k;
    int mod=7;
    for (int i = 0; i < length; i++) {
        k=rand()%7;
        vec[i] = (mod+1)*i + k;
    }
    return vec;
}

//该函数生成逆序序列
std::vector<int> generateInverted(int length) {
    std::vector<int> vec(length);
    int k;
    int mod=7;
    for (int i = 0; i < length; i++) {
        k=rand()%mod;
        vec[i] = (mod+1)*(length-i) + k;
    }
    return vec;
}

//该函数生成部分元素重复序列
std::vector<int> generatePartRepetition(int length) {
    std::vector<int> vec=generateRandom(length);
    int k;
    int mod=(length+8)/7;
    k=rand()%mod;
    for (int i = 0; i < length; i=i+k) {
        
        vec[i] = vec[k];
    }
    return vec;
}

//该函数测试对vec使用std::sort_heap的时间
template <typename Comparable>
auto Duration(std::vector<Comparable> &vec){
    auto start = std::chrono::high_resolution_clock::now();
    std::make_heap(vec.begin(), vec.end());
    std::sort_heap(vec.begin(), vec.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration;
}

//该函数测试对vec使用myheapsort的时间
template <typename Comparable>
auto DurationMy(std::vector<Comparable> &vec){
    auto start = std::chrono::high_resolution_clock::now();
    myheapsort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    return duration;
}

int main() {
    
    std::vector<int> v11 = generateRandom(1000000);
    std::vector<int> v12 = v11;

    std::vector<int> v21 = generateOrdinal(1000000);
    std::vector<int> v22 = v21;

    std::vector<int> v31 = generateInverted(1000000);
    std::vector<int> v32 = v31;

    std::vector<int> v41 = generatePartRepetition(1000000);
    std::vector<int> v42 = v41;

    std::cout <<"随机序列"<< std::endl;
    std::cout << "the heapsort took " << Duration(v11).count() << " milliseconds to execute." << std::endl;
    std::cout << "my heapsort took " << DurationMy(v12).count() << " milliseconds to execute." << std::endl;

    std::cout <<"有序序列"<< std::endl;
    std::cout << "the heapsort took " << Duration(v21).count() << " milliseconds to execute." << std::endl;
    std::cout << "my heapsort took " << DurationMy(v22).count() << " milliseconds to execute." << std::endl;

    std::cout <<"逆序序列"<< std::endl;
    std::cout << "the heapsort took " << Duration(v31).count() << " milliseconds to execute." << std::endl;
    std::cout << "my heapsort took " << DurationMy(v32).count() << " milliseconds to execute." << std::endl;

    std::cout <<"部分元素重复序列"<< std::endl;
    std::cout << "the heapsort took " << Duration(v41).count() << " milliseconds to execute." << std::endl;
    std::cout << "my heapsort took " << DurationMy(v42).count() << " milliseconds to execute." << std::endl;

    

    return 0;
}