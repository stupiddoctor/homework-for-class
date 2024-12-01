#include <vector>
#include <stdexcept>
#include <algorithm>
#include <iostream>


template <typename Comparable>
class BinaryHeap {
public:
    BinaryHeap(int Size) : array(Size), currentSize(0) {}//建立空堆
    

    //判断是否为空堆
     bool isEmpty() const 
    {
        return currentSize == 0;
    }

    //将堆中元素打印出来
    void Printout(){
        for(int i=0;i<currentSize;i++){
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }


    void insert(const Comparable &x) {
        if (currentSize == array.size()) {
            throw std::overflow_error("Heap overflow");
        }
        array[currentSize] = x;//先插在最后
        percolateUp(currentSize);//升堆操作
        ++currentSize;
    }

    void DeleteMin() {
        if (isEmpty()) {
            throw std::out_of_range("Heap is empty");
        }
        array[0]=std::move(array[currentSize-1]);//把最后一个节点换到根节点上
        --currentSize;
        percolateDown(1);
        
    }

    void DeleteMin(Comparable &minItem) {
        minItem = std::move(array[0]);
        DeleteMin();
    }


private:
    int currentSize; // 堆中的元素个数
    std::vector<Comparable> array; 

    void percolateUp(int index){
        if(array[index]<array[((index+1)/2-1)]){
            std::swap(array[index],array[((index+1)/2-1)]);
            percolateUp((index+1)/2-1);
        }

    }

    void percolateDown(int index){
        if(2*index>currentSize){
            return;//没有子节点
        }
        if(2*index+1>currentSize){
            if(array[index-1]>array[2*index-1]){
                std::swap(array[index-1],array[2*index-1]);
            }
            return;//只有一个子节点
        }
        if(array[index-1]<=array[2*index-1]&&array[index-1]<=array[2*index]){
            return;//比两个子节点小，不需要换
        }
        //以下只有“有两个子节点且需要交换”的情况
        if(array[2*index-1]<array[2*index]){
            std::swap(array[index-1],array[2*index-1]);
            percolateDown(2*index);
        }else{
            std::swap(array[index-1],array[2*index]);
            percolateDown(2*index+1);
        }    
    }
       
};

template <typename Comparable>
void myheapsort(std::vector<Comparable> &array)
{
    int capacity=array.size();
    BinaryHeap<Comparable> heap(capacity);
    for(int i=0;i<capacity;i++){
        heap.insert(array[i]);
    }
    
    for(int i=0;i<capacity;i++){
        heap.DeleteMin(array[i]);
    }
    
}