#include <cstdlib>
#include<string>
#include <iostream>
using namespace std;

class Person {
private:
	string firstName;
	static string familyName;

public:
	Person(string firstName = "unknown"){
		this->firstName = firstName;
	}
	
	const string getFirstName() {
        return firstName;
    }

    void setFirstName(string firstName) { 
        this->firstName = firstName;
    }

    static const string getFamilyName() { 
        return familyName;
    }

    static void setFamilyName(string newFamilyName) { 
        familyName = newFamilyName;
    }
};

string Person::familyName = "Logan"; 

int main(int argc, char** argv) {
    Person person1; 
    cout << "Person 1's first name: " << person1.getFirstName() << endl;
    cout << "Person 1's last name: " << Person::getFamilyName() << endl; 

    Person person2("Jimmy"); 
    cout << "Person 2's first name: " << person2.getFirstName() << endl;
    cout << "Person 2's last name: " << Person::getFamilyName() << endl; 
    
    person2.setFirstName("Bobby"); 
    cout << "Person 1's first name: " << person1.getFirstName() << endl;
    cout << "Person 1's last name: " << Person::getFamilyName() << endl;
    cout << "Person 2's first name: " << person2.getFirstName() << endl;
    cout << "Person 2's last name: " << Person::getFamilyName() << endl; 

    return 0;
}


