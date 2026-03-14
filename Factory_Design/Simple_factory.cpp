 //  # FACTORY DESIGN MATHODE . 

 /* a creational pattern that provides an interface for 
 creating objects in a superclass but allows subclasses
 to alter the type of objects that will be created */


 // i.> Simple factory 


#include<iostream>
using namespace std; 

class product{
    public:
    virtual void prepare()=0;  
    virtual ~product(){}; 
};

class product1 : public product{
    public:
    void prepare(){
        cout<<"product1 is prepared"<<endl;
    }
}; 

class product2 : public product{ 
    public:
    void prepare(){
        cout<<"product2 is prepared"<<endl;
    }
}; 

class factory{
    public: 
    product* give_product(string s){
        if(s=="product1"){
            return new product1(); 
        }else{
            return new product2();
        }
    }
}; 

int main(){
    string product_name = "product2"; 

    factory* fac = new factory(); 

    product* my_product = fac->give_product(product_name); 

    my_product->prepare(); 
    delete(fac); 
    delete(my_product);
    return 0 ; 
}