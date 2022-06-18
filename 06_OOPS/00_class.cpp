#include <bits/stdc++.h>
using namespace std;

class student
{
    string name; // private
public:
    int age;
    bool gender;
    student(){
        cout<<"default constructor"<<endl; 
    }//default constructor
    student(string s, int a, int g){ 
        cout<<"parameterised constructor"<<endl; 

        name= s;
        age =a;
        gender = g;
    }//parameterised condtructor

    student(student &a){
        cout<<"copy constructor"<<endl; 
        name=a.name;
        age=a.age;
        gender=a.gender;
    }//copy constructor
    void setname(string s) //seter fuction
    {
        name = s;
    }
    void getname(){
        cout<<name<<endl;
    }
    void printinfo()
    {
        cout << "Name = ";
        cout << name << endl;
        cout << "Age = ";
        cout << age << endl;
        cout << "Gender = ";
        cout << gender << endl;
    }

    ~student(){
        cout<<"Destructor called"<<endl;
    }
    
    bool operator==(student &a){
        if(name == a.name && age == a.age && gender == a.gender){
            return true;
        }
        return false;
    }
};

int main()
{
    // student a;         //for single student
    // a.name = "sahil";
    // a.age = 3;
    // a.gender = 0

    // student arr[3]; // for multiple student                          using array
    // for (int i = 0; i < 3; i++)
    // {
    //     string s;

    //     cout << "Name = ";

    //     cin >> s;                 
    //     arr[i].setname(s);//for private attribute
    //     cout << "Age = ";
    //     cin >> arr[i].age;
    //     cout << "Gender = ";
    //     cin >> arr[i].gender;
    // }
    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printinfo();
    // }

    student a("urvi",20,1);
    // a.printinfo();
    student b;
    student c=a; // or c(a);
    if(a==c){
        cout<<"same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }



    return 0;
}