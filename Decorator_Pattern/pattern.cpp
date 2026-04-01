#include<iostream>
using namespace std ; 

class IObject{
    public : 
    virtual string getinfo() = 0 ; 
    virtual ~IObject(){}
}; 

class Object : public IObject{
    public:
    string getinfo() override{
        return "Object" ; 
    }
}; 

class Decorator : public IObject{
    protected: 
    IObject* obj ; 
    public: 
    Decorator(IObject* obj){
        this->obj = obj ; 
    }
    virtual ~Decorator(){}
}; 

class Decorate_type1 : public Decorator{
    public:
    Decorate_type1(IObject* obj) : Decorator(obj){}
    string getinfo(){
        return obj->getinfo() + " with Decorate_type1";
    }
};

class Decorate_type2 : public Decorator{
    public:
    Decorate_type2(IObject* obj) : Decorator(obj){}
    string getinfo(){
        return obj->getinfo() + " with Decorate_type2";
    }
};

class Decorate_type3 : public Decorator{
    public:
    Decorate_type3(IObject* obj) : Decorator(obj){}
    string getinfo(){
        return obj->getinfo() + " with Decorate_type3";
    }
};

int main(){

    IObject* my_obj = new Object() ; 
    cout<<my_obj->getinfo()<<endl; 

    my_obj = new Decorate_type1(my_obj); 
    cout<<my_obj->getinfo()<<endl; 

    my_obj = new Decorate_type3(my_obj); 
    cout<<my_obj->getinfo()<<endl; 

    my_obj = new Decorate_type1(my_obj); 
    cout<<my_obj->getinfo()<<endl; 

    my_obj = new Decorate_type2(my_obj); 
    cout<<my_obj->getinfo()<<endl; 

    delete(my_obj); 
    return 0 ; 
}