#include<vector>
#include<iostream>

using namespace std;

class Student
{
public:
    string rollNo;
    string name;
    vector<string> coursesRegistered;
    float CGPA;
    int numberOfCredits;
    string address;

    Student()
    {
    }
    Student(string name, string rollNo, string address, vector<string> coursesRegistered)
    {
        this->name = name;
        this->rollNo = rollNo;
        CGPA = 0;
        numberOfCredits = 0;
        this->coursesRegistered = coursesRegistered;
        this->address = address;
    }

    void showDetails()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "CGPA: " << CGPA << endl;
        cout << "Number of Credits: " << numberOfCredits << endl;
        cout << "Address: " << address << endl;

        cout << "Courses Registered: " << endl;
        for (auto course : coursesRegistered)
        {
            cout << course << endl;
        }
    }

    void updateCGPA(int currSGPA, int currCredits)
    {
        float prevCGPA = CGPA;
        int prevCredits = numberOfCredits;

        CGPA = (prevCGPA * prevCredits + currSGPA * currCredits) / (prevCredits + currCredits);
        numberOfCredits=numberOfCredits+currCredits;
    }
};