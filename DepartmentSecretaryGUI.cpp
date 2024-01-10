#include<iostream>
#include<vector>
using namespace std;

class DepartmentSecretaryGUI
{
private:

public:
    static void DisplayGUI();
    static void Menu();
    void display(string text)
    {
        cout<<text<<endl;
    }
    string getStudentName()
    {
        string name;
        cout << "Enter Student Name: ";
        cin >> name;
        return name;
    }
    string getStudentRollNo()
    {
        string rollNo;
        cout << "Enter Student Roll Number: ";
        cin >> rollNo;
        return rollNo;
    }

    string getStudentAddress()
    {
        string address;
        cout << "Enter Student Addressr: ";
        cin >> address;
        return address;
    }

    vector<string> getCourses()
    {
        vector<string>coursesRegistered;
        cout << "Enter courses: " << endl;
        bool isComplete = false;
        while (isComplete == false)
        {
            cout << "Enter course name: ";
            string course;
            cin >> course;
            coursesRegistered.push_back(course);

            string choice;
            cout << "Add Anouther Course? 1/0: ";
            cin >> choice;
            if (choice == "1")
            {
                ;
            }
            else
            {
                isComplete = true;
            }
        }
        return coursesRegistered;
    }

}GUI;


void DepartmentSecretaryGUI::Menu()
{
        system("cls");
        cout<<endl<<"====================================================="<<endl;
        cout << "Choose a Functionality: " << endl
             << endl;

        cout <<endl<< "Manage Student Records" << endl;
        cout << "1.Add New Student" << endl;
        cout << "2.Query Student Details" << endl;
        cout << "3.Register for Courses" << endl;
        cout << "4.Enter Grading Details" << endl;

        cout <<endl<< "Manage Department Infrastructure" << endl;
        cout << "5.Add Equipment" << endl;
        cout << "6.Remove Equipment" << endl;
        cout << "7.Get Equipment Details" << endl;
        cout<<"8.Update Equipment Details"<<endl;
        cout <<endl<< "Manage Department Research Project Details" << endl;
        cout << "9.Add Research Project" << endl;
        cout << "10.Update Research Project Details" << endl;
        cout << "11.View Research Projects" << endl;

        cout <<endl<< "Manage Department Publications" << endl;
        cout << "12.Add Publication" << endl;
        cout << "13.Update Publication" << endl;
        cout << "14.View Publications" << endl;

        cout <<endl<< "Manage Department Accounts" << endl;
        cout << "15.Add Funding" << endl;
        cout << "16.View Accounts History" << endl;
        cout << "17.Query Cashbook Details" << endl;

        cout <<endl<< "0.Exit" << endl;

        cout << "=======================================================" << endl;
    
};
