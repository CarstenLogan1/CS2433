#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

class Family{
public:
    string name;
    int age;
    Family* spouse;
    vector <Family>* kids;
    
    Family(string n = "unknown", int a = 18, Family* s = NULL, vector<Family>* v = NULL){
        name = n;
        age = a;
        kids = new vector<Family>;
        spouse = s;
    }
    
    bool operator!(){
        return spouse == NULL;
    }
    
    int operator+(int i){
        age+= i;
        return age;
    }
    
    void operator+(){
        for(int i = 0; i< kids->size(); i++){
            cout<<(*kids)[i].name<<" ";
        }
        cout<<endl;
        
    }
    
    void operator<(Family a){
        kids->push_back(a);
    }
    
    friend void operator&(Family& a, Family& b){
        a.spouse = &b;
        b.spouse = &a;
    }
    
    friend bool operator&&(Family& a, Family& b){
        return a.spouse == &b && b.spouse== &a;
    }
    
    friend bool operator==(Family a, Family b){
        return a.age>=18 && b.age>= 18 && !a.spouse && !b.spouse;
    }
    
    friend void operator^(Family &a, Family &b){
        a.spouse = NULL;
        b.spouse = NULL;
    }
    
};

int main(int argc, char** argv){
    Family F("Nicky",15);
    Family M("Nick",39,&F);
    
    cout<<"Is the female single? "<<(!F)<<endl;
    cout<<"Are they legal to marry? "<<(F==M)<<endl;
    (F+3);
    cout<<"Are they legal to marry now? "<<(F==M)<<endl; 
    //Not legal to marry bc Nick was initialized with Nicky as a spouse so he currently has spouse.
    // We disregard that and marry them anyways below as per request of project
    cout<<"Are they married to each other? "<<(F&&M)<<endl;
    M&F;
    cout<<"Are they married to each other now? "<<(F&&M)<<endl;
    
    
    cout<<"The spouse of the female: "<<(*F.spouse).name<<endl;
    cout<<"The spouse of the male: "<<(*M.spouse).name<<endl;
    
    
    Family B("Billy", 12);
    Family J("Johnny", 10);
    Family A("Arny", 6);
    Family P("Phil", 4);
    
    M<B;
    M<J;
    M<A;
    M<P;
    
    (+F);
    (+M);
    
    Family C("Charlie",2);
    Family D("Dan", 1);
    
    M<C;
    M<D;
    
    (+M);
    M^F;
    cout<<"Are they still married? "<<(F&&M)<<endl;
    
    
    
    return 0;
}
        


