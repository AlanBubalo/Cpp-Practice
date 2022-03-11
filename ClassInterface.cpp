using namespace std;
#include <iostream>

class Person {
    public:
        int age;

        Person(int initialAge){
            // Add some more code to run some checks on initialAge
            if (initialAge < 0){
                initialAge = 0;
                cout << "Age is not valid, setting age to 0." << endl;
            }
            this->age = initialAge;
        }

        string amIOld(){
            // Do some computations in here and print out the correct statement to the console
            if (age < 13)
                return "You are young.\n";
            if (age >= 13 && age < 18)
                return "You are a teenager.\n";
            return "You are old.\n";
        }

        void yearPasses(){
            // Increment the age of the person in here
            age++;
        }
};

int main () {
    int t, age;
    cin >> t;
    for (int _ = 0; _ < t; _++) {
    	cin >> age;
        Person p(age);
        cout << p.amIOld();
        for (int __ = 0; __ < 3; __++)
        	p.yearPasses();
        cout << p.amIOld() << '\n';
    }
    return 0;
}