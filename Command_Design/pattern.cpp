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
    ~command_obj1(){
        delete obj ; 
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
    
    ~command_obj2(){
        delete obj ; 
    }
};

class Invoker{
    private: 
    static const int max_cmd = 4 ;
    ICommand* Button[max_cmd];
    bool Button_status[max_cmd] ;

    public:
    Invoker(){
        for(int i=0;i<max_cmd;i++){
            Button[i] = nullptr ;
            Button_status[i] = false ;
        }
    }

    void set_button(int i , ICommand* cmd){
        if(i>=0 && i<max_cmd){
            if(Button[i]!=nullptr){
                delete Button[i] ;
                Button[i] = cmd; 
                Button_status[i] = false ; 
            }else{
                Button[i] = cmd; 
                Button_status[i] = false ;
            }
        }else{
            cout<<"this Button cann't be assigned "<<endl ;
        }
    }

    void press(int i){
        if(i>=0 && i<max_cmd){
            if(Button[i]==nullptr){
            cout<<"this button is not assingned "<<endl; 
            return ;  
            }else if(Button_status[i]){
                Button[i]->undo() ; 
            }else{
                Button[i]->execute() ;
            }
            Button_status[i] = !Button_status[i] ; 
        }
        else{
            cout<<"this Button is not recognizing"<<endl ;
        }
    }

    ~Invoker(){
        for(int i=0; i<max_cmd; i++){
            if(Button[i]!=nullptr){
                delete Button[i] ;
            }
        }
    }

}; 

int main(){
    Invoker* remote = new Invoker(); 

    remote->set_button(0,new command_obj1(new obj1())) ; 
    remote->set_button(1,new command_obj2(new obj2())) ; 
    remote->set_button(2,new command_obj2(new obj2())) ;
    remote->set_button(0,new command_obj1(new obj1())) ; 

    remote->press(0) ; 
    remote->press(2) ; 
    remote->press(3) ;
    remote->press(2) ; 
    remote->press(1) ;

    delete remote ; 
    return 0 ; 
}