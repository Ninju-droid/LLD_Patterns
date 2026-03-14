/* If there are Multiple Manufaturing factory with there own way 
   then we use fatory methode . In this we create abstract factory
   and concreate factories that produce product in thier own way*/ 

#include<iostream>
using namespace std; 

class product{
    public:
    virtual void prepare()=0;  
    virtual ~product(){}; 
};

class product1_facA : public product{
    public:
    void prepare(){
        cout<<"product1 is prepared in FacA"<<endl;
    }
}; 

class product2_facA : public product{ 
    public:
    void prepare(){
        cout<<"product2 is prepared in FacA"<<endl;
    }
}; 

class product1_facB : public product{
    public:
    void prepare(){
        cout<<"product1 is prepared in FacB"<<endl;
    }
}; 

class product2_facB : public product{ 
    public:
    void prepare(){
        cout<<"product2 is prepared in FacB"<<endl;
    }
}; 

class factory{
    public: 
    virtual product* create_product(string s) = 0 ; 
    virtual ~factory(){}; 
};

class facA: public factory{
    public:
    product* create_product(string s){
        if(s=="product1"){
            return new product1_facA();
        }else{
            return new product2_facA();
        }
    }
};

class facB: public factory{
    public:
    product* create_product(string s){
        if(s=="product1"){
            return new product1_facB();
        }else{
            return new product2_facB();
        }
    }
};

int main(){
    string product_name = "product1"; 

    factory* fac = new facB(); 

    product* my_product = fac->create_product(product_name); 
    
    my_product->prepare(); 

    delete my_product;
    delete fac;
}
