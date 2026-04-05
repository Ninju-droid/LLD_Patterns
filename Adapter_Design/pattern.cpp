#include<iostream> 
using namespace std ; 

class IApp{
    public:
    void featureO(){
        cout<<"   ##  this is app's own fucniton, it don't require third lib support "<<endl; 
    }
    virtual void featureA()=0 ; // this is feature that use a thired library just say library_1 
    virtual void featureB()=0 ; // this is feature that use a thired library just say library_1 
    virtual void featureC()=0 ; // this is feature that use a thired library just say library_2
    virtual ~IApp(){}
}; 

class library1{
    public:
    void func1(){
        cout<<"   ##  fucntion_1 of library1 is executed"<<endl;
    }
    void func2(){
        cout<<"   ##  fucntion_2 of library1 is executed"<<endl;
    }
    ~library1(){}
}; 

class library2{
    public:
    void func1(){
        cout<<"   ##  fucntion_1 of library2 is executed"<<endl;
    }
    ~library2(){}
}; 

class Adapter :public IApp{
    private: 
    library1* lib1 ; 
    library2* lib2 ; 

    public:
    Adapter(){
        this->lib1 = new library1() ; 
        this->lib2 = new library2() ; 
    }
    void featureA(){
        lib1->func1() ; 
    }
    void featureB(){
        lib1->func2() ;
    } 
    void featureC(){
        lib2->func1() ;
    }

    ~Adapter(){
        delete lib1; 
        delete lib2 ;
    }
};

int main(){
    IApp* app = new Adapter() ; 
    app->featureA(); 
    app->featureB(); 
    app->featureO(); 
    app->featureC() ; 

    delete app ; 
    return 0 ; 
}