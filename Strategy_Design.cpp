/* 
Strategy Design Pattern
  => Some Imp. 
    -> Encapsulate what varies & keep it separate form what remains same . 
    -> Solution to inheritence is not more inheritence . 
    -> Composition should be favoured over inheritence . 
    -> Code to interface & not to concretion. 
    -> Do not repeat yourself .
*/

# include<iostream> 
using namespace std; 

class feature1{
public:
    virtual void perform() = 0;
    virtual ~feature1() {}
};

class feature2{
public:
    virtual void perform() = 0;
    virtual ~feature2() {}
};

class feature3{
public:
    virtual void perform() = 0;
    virtual ~feature3() {}
};

class feature4{
public:
    virtual void perform() = 0;
    virtual ~feature4() {}
};

class feature1_enable : public feature1{
    void perform() override {
        cout<<"Feature 1 Activated"<<endl;
    }
} ;

class feature1_not_enable : public feature1{
    void perform() override {
        cout<<"This is Client with Feature 1 Disability"<<endl;
    }
};

class feature2_enable : public feature2{
    void perform() override {
        cout<<"Feature 2 Activated"<<endl;
    }
} ;

class feature2_not_enable : public feature2{
    void perform() override {
        cout<<"This is Client with Feature 2 Disability"<<endl;
    }
};

class feature3_enable : public feature3{
    void perform() override {
        cout<<"Feature 3 Activated"<<endl;
    }
} ;

class feature3_not_enable : public feature3{
    void perform() override {
        cout<<"This is Client with Feature 3 Disability"<<endl;
    }
};

class feature4_enable : public feature4{
    void perform() override {
        cout<<"Feature 4 Activated"<<endl;
    }
} ;

class feature4_not_enable : public feature4{
    void perform() override {
        cout<<"This is Client with Feature 4 Disability"<<endl;
    }
};

class client{
public: 
    feature1* f1; 
    feature2* f2; 
    feature3* f3; 
    feature4* f4;

    client(feature1* f1 ,feature2* f2 ,feature3* f3 ,feature4* f4){
        this->f1 = f1 ; 
        this->f2 = f2 ; 
        this->f3 = f3 ; 
        this->f4 = f4 ; 
    }

};

int main(){
    client* c1 = new client(new feature1_not_enable(), 
        new feature2_enable(), 
        new feature3_not_enable(), 
        new feature4_enable());

    client* c2 = new client(new feature1_enable(), 
        new feature2_not_enable(), 
        new feature3_enable(), 
        new feature4_not_enable()); 

    c1->f1->perform();
    c1->f2->perform(); 
    c1->f3->perform();
    c1->f4->perform();

    c2->f1->perform();
    c2->f2->perform(); 
    c2->f3->perform();
    c2->f4->perform();

    delete c1;
    delete c2;
    return 0 ; 
}