#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Observalble; //  forward declaration

class IObserver{
public:
    virtual void update() = 0; 
    virtual void getcontent(string &msg, Observalble* ob) = 0;
    virtual ~IObserver(){}
}; 

class IObservable{
public:
    string name; 
    vector<IObserver*> observers; 

    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notify() = 0;

    virtual ~IObservable(){}
}; 

class Observalble : public IObservable{ 
public:
    string event = "";

    Observalble(const string& s){
        this->name = s;
    }

    void addObserver(IObserver* observer) override {
        observers.push_back(observer);
    }

    void removeObserver(IObserver* observer) override {
        observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override {
        for(auto it: observers){
            it->getcontent(event, this); 
        }
    }
}; 

class Observer : public IObserver{
private:
    string from = "";  
    string s = "";

public:
    void getcontent(string &msg, Observalble* ob) override {
        from = ob->name; 
        s = msg;
        update();   //  push model
    }

    void update() override { 
        if(s == "") return; 

        cout<<"Hello this notification is from "<<from<<endl; 
        cout<<"You are notified that: "<<s<<endl; 

        s = "";
        from = "";
    }
};

int main(){
    Observalble ob("XYZ");   //  stack allocation

    Observer ram, radha, shyam;

    ob.addObserver(&ram); 
    ob.addObserver(&radha);
    ob.addObserver(&shyam);

    ob.event = "Happy Holi";
    ob.notify();  
}