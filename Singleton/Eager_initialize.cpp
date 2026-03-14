// Eager Initialization 
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
        return instance ; 
    }

}; 

Singlton* Singlton::instance = new Singlton() ; 

int main(){
    Singlton* s1 = Singlton::getInstance();
    Singlton* s2 = Singlton::getInstance();

    if(s1==s2){
        cout<<"s1 and s2 are Same"<<endl;
    }
    return 0 ; 
}