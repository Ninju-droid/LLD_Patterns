#include<iostream> 
#include <mutex>
using namespace std; 

class Singleton{
    private: 
    static Singleton* instance ; 
    static mutex mtx ;
    Singleton(){
        cout<<"Singleton Constructor Called "<<endl;
    } 
    public: 
    static Singleton* getInstance(){
        if(instance==nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance==nullptr){
                instance = new Singleton(); 
            }
        }
        return instance ; 
    }

}; 

Singleton* Singleton::instance = nullptr ; 
mutex Singleton::mtx ;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    if(s1==s2){
        cout<<"s1 and s2 are Same"<<endl;
    }
    return 0 ; 
}
