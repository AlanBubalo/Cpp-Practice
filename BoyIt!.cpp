#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

class Box{
    private:
        unsigned long long l, b, h;
    public:
        Box(){
            l=0;
            b=0;
            h=0;
        }
        Box(unsigned long long initialL, unsigned long long initialB, unsigned long long initialH){
            l = initialL;
            b = initialB;
            h = initialH;
        }
        Box(Box &initialBox){
            l = initialBox.l;
            b = initialBox.b;
            h = initialBox.h;
        }
        unsigned long long getLength(){
            return l;
        }
        unsigned long long getBreadth(){
            return b;
        }
        unsigned long long getHeigth(){
            return h;
        }
        unsigned long long CalculateVolume(){
            return l * b * h;
        }
        bool operator<(Box initialBox){
            if (l < initialBox.l || (b < initialBox.b && l == initialBox.l))
                return true;
            if (h < initialBox.h && b == initialBox.b && l == initialBox.l)
                return true;
            return false;
        }
        friend ostream &operator<<(ostream &output, Box &initialBox){
            output << initialBox.l << " " << initialBox.b << " " << initialBox.h;
            return output;
        }
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++) {
		int type;
		cin >> type;
        switch (type) {
            case 1:
                cout << temp;
                break;
            case 2:
                int l, b, h;
			    cin >> l >> b >> h;
			    Box NewBox(l,b,h);
			    temp = NewBox;
			    cout << temp;
                break;
            case 3:
                int l, b, h;
			    cin >> l >> b >> h;
			    Box NewBox(l, b, h);
			    if(NewBox < temp)
			    	cout << "Lesser";
			    else
			    	cout << "Greater";
                break;
            case 4:
                cout << temp.CalculateVolume();
                break;
            case 5:
                Box NewBox(temp);
			    cout << NewBox;
            default:
                break;
        }
        cout << endl;
	}
}

int main()
{
	check2();
    return 0;
}