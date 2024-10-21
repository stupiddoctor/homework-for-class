#include <utility>
#include <initializer_list>
#include <iostream>
#include <List.h>



int main()
{
    List<int> intlist1;
    List<int> intlist2={1,2,3,4,5};//验证构造函数
    List<int> intlist3=intlist2;//验证拷贝构造函数
    std::cout << "intlist3:" << std::endl;
    intlist3.printall();
    intlist3.push_back(1);
    intlist1=intlist2=intlist3;//验证赋值运算

    // 打印intlist1中的所有元素,检验结果
    std::cout << "intlist1:" << std::endl;
    intlist1.printall();

  

    
    // 验证==、！=、++i、i++、--i、i--和*的运算
    
    auto it1 = intlist1.begin();
    auto it2 = it1;
    std::cout << "迭代器相等: " << (it1 == it2) << std::endl;
    it2 = intlist1.end();
    std::cout << "迭代器不等: " << (it1 != it2) << std::endl;
    std::cout << "intlist1的第一和第三个数据分别是:"; 
    std::cout << *(it1++) << "和";
    std::cout << *(++it1) << std::endl;
    std::cout << "intlist1的倒数第一和第三个数据分别是:"; 
    it1=--(intlist1.end());
    std::cout << *(it1--) << "和";
    std::cout << *(--it1) << std::endl;

    // 测试插入功能
    std::cout << std::endl<<"插入功能测试" << std::endl;
    std::cout << "intlist1:" << std::endl;
    auto it = intlist1.begin();
    ++it; 
    intlist1.insert(it,20);
    intlist1.insert(it,*it+20);
    intlist1.push_front(*it-10);
    intlist1.push_back(*it+10);
    intlist1.printall();
    std::cout << "size:"<<intlist1.size() << std::endl;//检验size是否正确

    //测试修改功能
    std::cout << std::endl<<"修改头尾测试" << std::endl;
    intlist1.front() = 100;
    intlist1.back() = 200;
    intlist1.printall();
    
    //删除功能
    std::cout << std::endl<<"删除功能测试" << std::endl;
    // 测试单个删除功能
    std::cout <<"删除第二个元素";
    it = intlist1.begin();
    ++it;
    intlist1.erase(it);
    intlist1.printall();
    std::cout <<"删除第一个元素";
    intlist1.pop_front();
    intlist1.printall();
    std::cout <<"删除最末端元素";
    intlist1.pop_back();
    intlist1.printall();
    
     //测试删除指定范围的节点
    std::cout << "intlist只保留头尾:";
    auto et = intlist1.end(); 
    --et;
    it = intlist1.begin();
    ++it;
    intlist1.erase(it,et);
    intlist1.printall();
    std::cout <<"size:"<<intlist1.size()<<std::endl;
    et = intlist1.end();
    it = intlist1.begin();

    
    // 测试清空功能
    std::cout << std::endl<<"清空功能测试" << std::endl;
    intlist1.clear();
    std::cout << "清空intlist1:" ;
    intlist1.printall();

    //检验是否为空
    if(intlist1.empty())
        std::cout<<"已清空";

    return 0;
}
    