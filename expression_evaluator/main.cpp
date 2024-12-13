#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "expression_evaluator.h"



int main() {

    std::string test1,index;
    index="0";
    std::cout<<"计算器使用:输入1,回车后开始,输入0,回车后结束程序"<<std::endl;
    std::cin>>index;
    while(index!="0")
    {
        if(index!="1")
        {
            std::cout<<"乖,别乱按"<<std::endl;
            std::cout<<"计算器使用:输入1,回车后开始,输入0,回车后结束程序"<<std::endl;
            std::cin>>index;
        }else{
        std::cout<<"请输入式子,支持四则运算、括号和负数计算,不要输入等号,例如 (-5*3)+2,按回车执行计算"<<std::endl;
        std::cin>>test1;
        printcalucate_result(test1);
        std::cout<<"输入1回车继续使用,输入0回车结束使用"<<std::endl;
        std::cin>>index;
        }
    }
    
    /*test1="5.1+3*23";
    printcalucate_result(test1);
    test1="(5.1-5)*23";
    printcalucate_result(test1);
    test1="((5+3)*20/5)";
    printcalucate_result(test1);
    test1="(5+-3)/3";
    printcalucate_result(test1);
    test1="5.1+3*23)";
    printcalucate_result(test1);
    test1="(5+3)#*23";
    printcalucate_result(test1);
    test1="((5+3)*23/0)";
    printcalucate_result(test1);
    test1="(.5-3)*23";
    printcalucate_result(test1);*/
    
    return 0;
}