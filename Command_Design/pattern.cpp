#include<iostream> 
using namespace std ; 

class ICommand{
    public: 
    virtual void execute() = 0 ; 
    virtual void undo() = 0 ; 
    virtual ~ICommand(){}
};

class obj1{
    public: 
    void on(){
        cout<<"obj1 is starting"<<endl;
    }
    void off(){
        cout<<"obj1 is stoping"<<endl;
    }
}; 

class obj2{
    public: 
    void on(){
        cout<<"obj2 is starting"<<endl;
    }
    void off(){
        cout<<"obj2 is stoping"<<endl;
    }
};

class command_obj1 : public ICommand{
    private : 
    obj1* obj ;

    public: 
    command_obj1(obj1* obj){
        this->obj = obj ; 
    }

    void execute(){
        obj->on(); 
    }
    void undo(){
        obj->off();
    }

}; 

class command_obj2 : public ICommand{
    private : 
    obj2* obj ;

    public: 
    command_obj2(obj2* obj){
        this->obj = obj ; 
    }

    void execute(){
        obj->on(); 
    }
    void undo(){
        obj->off();
    }
    
};

int main(){

}