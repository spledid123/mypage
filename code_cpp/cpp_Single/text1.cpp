#include<iostream>

class Loves{//基类
        protected: //实施保护 
                void kiss(std::string boyfriend);
                friend class Others;    //友元           
};
class MyLoves : public Loves{//子类：youself
        public:
                void kiss(std::string boyfriend);
};
class Others{//第三者，交友不慎
        public:
                void kiss(std::string boyfriend);
};

void Loves::kiss(std::string boyfriend){
        std::cout << "You kiss " << boyfriend << std::endl;
}
void MyLoves::kiss(std::string boyfriend){
        Loves::kiss(boyfriend);
}
void Others::kiss(std::string boyfriend){
        std::cout << "Your friend kiss " << boyfriend;
}



int main(){
    std::string boyfriend = "your boyfriend";
    class Loves Loves;
    class Others Others;
    class MyLoves MyLoves;
    MyLoves.kiss(boyfriend);//yousdelf
    Others.kiss(boyfriend);//your friend
}

