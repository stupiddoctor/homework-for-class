#include <iostream>
#include <vector>
#include <string>
#include <cctype>


template <typename T>
class storage {
public:
    storage(int i) : data(i), Size(0) {} // 构造函数

    void insert(T element) {
        data[Size] = element;
        ++Size;
    }

    T  readlast() const {    
        return data[Size - 1];    
    }

    void popout() {
        if (Size > 0) {
            --Size;
        }
    }
    
    void clean(){
        Size=0;
    }

    int getSize() const {
        return Size;
    }

private:
    std::vector<T> data;//具体元素组成的向量
    int Size;//元素的数量
};


int signal(char c){
    int sign;
    switch (c) {
        case '+':
        case '-':
            {
                sign = 1;
                break;
            }
        case '*':
        case '/':
            {
                sign = 2;
                break;
            }
        case '(':
                sign=100;
                break;
        case')':
            sign=0;
            break;
        default:
            sign=3;
            break;           

    }; 
    return sign;       
}
//计算后缀表达式


void addoperator(storage<int> &sign,storage<char> &operators ,std::vector<std::string> &changeresult, char c)
{
    std::string op1;
    for(int j=sign.getSize()+1;j>0;j--)
            {
                //第一个符号 或者 优先级比下面的高 或者 在左括号上面（除非是右括号）
               if(sign.getSize()==0||sign.readlast()< signal(c)||sign.readlast()+signal(c)>100)
               {
                    sign.insert(signal(c));
                
                    operators.insert(c);
                    break;
               }
               else
               {
                    if(sign.readlast()+signal(c)==100){
                        sign.popout();
                        operators.popout();
                        break;
                    }//如果刚好一左一右两个括号,将左括号去掉
                    else
                    {
                        sign.popout();
                        op1=operators.readlast();
                        changeresult.push_back(op1);
                        operators.popout();
                    }//如果不是一左一右两个，正常弹出
                }
            }
}

//change函数把原始的string转成vector形式的后缀表达式
std::vector<std::string> change(std::string origin)
{
    bool operatorindex = 1;
    bool numberindex = 0;
    storage<int> sign(origin.size());
    storage<char> operators(origin.size());
    std::string numberpart,op;
    std::vector<std::string> changeresult;
    for(int i=0;i<origin.size();i++){
        if(std::isdigit(origin[i])||origin[i]=='.'){
            numberpart+=origin[i];
            operatorindex = 0;
        }
        else
        {
            //如果是符号的话，先将之前的数字弹出
            if(numberpart.size())
            {
                changeresult.push_back(numberpart);
            }
            
            numberpart.clear();//重置numberpart

            if(numberindex)
            {
                addoperator(sign,operators,changeresult,')');
                numberindex=0;
            }

            //先判断是否是负数
            if(operatorindex)//operatorindex为1，相当于出现了两个相邻的符号
            {
                if(origin[i]=='-'&&(i==0||origin[i-1]!=')'))
                {
                    addoperator(sign,operators,changeresult,'(');
                    changeresult.push_back("0");
                    numberindex=1;
                }
                
            }
            
            addoperator(sign,operators,changeresult,origin[i]);
            operatorindex = 1;
        }    
    }
    if(numberpart.size())
    {
    changeresult.push_back(numberpart);
    numberpart.clear();
    }
    while(operators.getSize())
    {
        op=operators.readlast();
        changeresult.push_back(op);
        operators.popout();
    }
    
    return changeresult;

}


std::string Calculate(const std::vector<std::string>& a) 
{
    double  firstnum, secondnum,result;
    std::string lastresult;
    storage<double> numbles(a.size());
    

    for (const auto& element : a) {
        //遍历a
        //注意：要求每个字符串如果开头是数字，则为数字
        if (std::isdigit(element[0]) ) {
            // 如果是数字，进入 numbles
            numbles.insert(std::stod(element)); 
        } 
        else {
            if (numbles.getSize() < 2) {
                lastresult = "ILLEGAL";
                return lastresult;
            }
            // 弹出两个数字
            secondnum = numbles.readlast();
            numbles.popout();
            firstnum = numbles.readlast();
            numbles.popout();
            // 计算并将结果插入
            switch (element[0]) {
            case '+':
                result = firstnum + secondnum;
                break;
            case '-':
                result = firstnum - secondnum;
                break;
            case '*':
                result = firstnum * secondnum;
                break;
            case '/':
                if (secondnum != 0) {
                    result = firstnum / secondnum;;
                } else {
                    lastresult = "ILLEGAL";
                    return lastresult;        
                }
                break;
            default:
                lastresult = "ILLEGAL";
                return lastresult;
            }
            numbles.insert(result);
    
        }
        }
    
    
    lastresult = std::to_string(numbles.readlast());
    return lastresult;
}
std::string calculate_formula(std::string formula)
{
    std::string result;
    result = Calculate(change(formula));
    return result;
}
void printcalucate_result(std::string formula)
{
    if(calculate_formula(formula)=="ILLEGAL")
        std::cout<<"ILLEGAL"<<std::endl;
    else
        std::cout<<"Result: "<<std::stod(calculate_formula(formula))<<std::endl;    
}