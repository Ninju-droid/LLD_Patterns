/* The Singleton design pattern ensures a class has only one 
 instance and provides a global access point to it, commonly
 used for managing shared resources like database connections, 
 configurations, or loggers.It restricts instantiation, provides
 lazy initialization, and is generally implemented using a private
 constructor, a static variable, and a static getInstance() method */


// static members class se associated hote hai, kisi objects se nahi. 

#include<iostream> 
using namespace std; 

class Singlton{
    private: 
    static Singlton* instance ; 
    Singlton(){
        cout<<"Singlton Constructor Called "<<endl;
    } 
    public: 
    static Singlton* getInstance(){
        if(instance==nullptr){
            instance = new Singlton(); 
        }
        return instance ; 
    }

}; 

Singlton* Singlton::instance = nullptr ; 

int main(){
    Singlton* s1 = Singlton::getInstance();
    Singlton* s2 = Singlton::getInstance();

    if(s1==s2){
        cout<<"s1 and s2 are Same"<<endl;
    }
    return 0 ; 
}
