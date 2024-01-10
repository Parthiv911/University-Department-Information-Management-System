#include<iostream>
#include "DataStructures.h"
#include "utility_functions.h"
#include "DepartmentSecretaryGUI.cpp"
#include<conio.h>

using namespace std;

class DepartmentSecretary
{
public:
    static int start();

    static int addStudent();
    static int getStudentDetails();
    static int registerCourses();
    static int enterGradingDetails();

    static int addEquipment();
    static int removeEquipment();
    static int viewEquipment();
    static int updateEquipment();

    static int addPublication();
    static int updatePublication();
    static int viewPublication();

    static int viewAccounts();
    static int addFunding();

    static int viewCashBook();

    static int addResearchProject();
    static int updateResearchProject();
    static int viewResearchProject();
};

int DepartmentSecretary::addStudent()
{
    string name;
    string rollNo;
    string address;

    name=GUI.getStudentName();
    rollNo=GUI.getStudentRollNo();
    

    if (StudentDetails.find(rollNo) != StudentDetails.end())
    {
        GUI.display("Student already exists");
        sleep(1);
        return -1;
    }

    GUI.getStudentAddress();

    vector<string> coursesRegistered = GUI.getCourses();

    Student student1(name,rollNo,address,coursesRegistered);

    StudentDetails[rollNo]=student1;

    GUI.display("\nStudent Added Successfuly");
    sleep(1);

    return 0;
}

int DepartmentSecretary::getStudentDetails()
{
    if(StudentDetails.size()==0)
    {
        GUI.display("Student Records Empty");
        sleep(1);
        return 0;
    }

    for(auto student:StudentDetails)
    {
        student.second.showDetails();
        GUI.display("\n");
    }

    GUI.display("==============================================================\n");
    string choice;
    cout <<endl<< "Show Student by Roll Number?(1/0): ";
    cin >> choice;

    cout << endl;
    if (choice == "1")
    {
        string rollNo;
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        if (StudentDetails.find(rollNo) != StudentDetails.end())
        {
            StudentDetails[rollNo].showDetails();
            getch();
            return 0;
        }
        else
        {
            cout<<"Student Does Not Exist"<<endl;
            sleep(1);
            return 0;
        }
    }

    return 0;
}

int DepartmentSecretary::registerCourses()
{
    cout<<"Enter Student Roll Number: ";
    string rollNo;
    cin>>rollNo;

    if (StudentDetails.find(rollNo) == StudentDetails.end())
    {
        cout << "Student is not registered" << endl;
        sleep(1);
        return -1;
    }

    bool isComplete = false;

    while(isComplete==false)
    {
        cout<<"Enter course name: ";
        string course;
        cin>>course;
        StudentDetails[rollNo].coursesRegistered.push_back(course);

        string choice;
        cout<<"Add Anouther Course? 1/0: ";
        cin>>choice;
        if(choice=="1")
        {
            ;
        }
        else
        {
            isComplete=true;
        }
        //Make a list of available courses
    }
    cout<<endl<<"Course added to Student's Registered Courses"<<endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::enterGradingDetails()
{
    cout<<"Enter Student Roll Number: ";

    string rollNo;
    cin>>rollNo;

    if (StudentDetails.find(rollNo) == StudentDetails.end())
    {
        cout << "Student is not registered" << endl;
        sleep(1);
        return -1;
    }

    int currCredits=0;
    cout<<"Enter Number of Credits in Semester: ";
    cin>>currCredits;

    float currSGPA;

    cout<<"Enter SGPA in Semester: ";
    cin>>currSGPA;

    StudentDetails[rollNo].updateCGPA(currSGPA,currCredits);

    cout<<endl<<"CGPA Updated"<<endl;
    sleep(1);

    return 0;
}

int DepartmentSecretary::addEquipment()
{
    cout<<"Enter Equipment Name: ";
    string name;
    cin>>name;

    cout<<"Enter Equipment ID: ";
    string id;
    cin>>id;

    cout<<"Enter Equipment Location: ";
    string location;
    cin>>location;

    Equipment equipment1(id,name,location);

    EquipmentList[id]=equipment1;

    cout<<"Equipment added"<<endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::updateEquipment()
{
    viewEquipment();
    cout<<"Enter Equipment id: ";
    string id;
    cin>>id;

    if(EquipmentList.find(id)==EquipmentList.end())
    {
        cout<<"Equipment with id is not present in the Database"<<endl;
        sleep(1);
        return -1;
    }
    cout<<"Enter New location: ";
    string location;
    cin>>location;

    EquipmentList[id].location=location;

    cout<<endl<<"Equipment location updated"<<endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::removeEquipment()
{
    viewEquipment();
    cout << "Enter Equipment id: ";
    string id;
    cin >> id;

    if (EquipmentList.find(id) == EquipmentList.end())
    {
        cout << "Equipment with id is not present in the Database" << endl;
        sleep(1);
        return -1;
    }
    EquipmentList.erase(id);

    cout << "Equipment Removed" << endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::viewEquipment()
{
    if (EquipmentList.empty())
    {
        cout << "Equipment Details Empty" << endl;
        sleep(1);
        return -1;
    }
    for(auto equipment:EquipmentList)
    {
        cout<<"Equipment Name: "<<equipment.second.name<<endl;
        cout<<"Equipment id: "<<equipment.second.id<<endl;
        cout<<"Equipment Location: "<<equipment.second.location<<endl;
        cout<<endl;
    }
    getch();
    return 0;
}

int DepartmentSecretary::addPublication()
{
    cout << "Enter Publication Name: ";
    string name;
    cin >> name;

    cout << "Enter Publication ID: ";
    string id;
    cin >> id;

    
    if(PublicationList.list.find(id)!=PublicationList.list.end())
    {
        cout<<"Publication with that ID already exists";
        sleep(1);
        cout<<endl;
    }

    cout << "Enter Publication Date: ";
    string date;
    cin >> date;

    cout << "Enter Publication website: ";
    string website;
    cin >> website;

    cout << "Enter Professor Names: "<<endl;
    bool isComplete = false;
    vector<string> professorNames;

    while (isComplete == false)
    {
        cout << "Enter Professor name: ";
        string profname;
        cin >> profname;
        professorNames.push_back(profname);

        string choice;
        cout << "Add Anouther name? 1/0: ";
        cin >> choice;
        if (choice == "1")
        {
            ;
        }
        else
        {
            isComplete = true;
        }
        // Make a list of available courses
    }

    Publication publication1(id, name, date,website,professorNames);

    PublicationList.list[id] = publication1;

    cout <<endl<< "Publication added" << endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::updatePublication()
{
    if (PublicationList.list.empty())
    {
        cout << "No Publications in Database" << endl;
        sleep(1);
        return -1;
    }
    for (auto publication : PublicationList.list)
    {
        publication.second.showDetails();
    }

    sleep(1);
    cout<<endl<< "Enter Publication id: ";
    string id;
    cin >> id;

    if (PublicationList.list.find(id) == PublicationList.list.end())
    {
        cout << "Publication with id is not present in the Database" << endl;
        sleep(1);
        return -1;
    }
    
    string website;
    string date;
    cout<<"Enter New Date: ";
    cin >> date;
    cout << "Enter New Website Link: ";
    cin>>website;

    PublicationList.list[id].date = date;
    PublicationList.list[id].webPageLink=website;

    cout << "Enter Professor Names: "<<endl;
    bool isComplete = false;
    vector<string> professorNames;

    while (isComplete == false)
    {
        cout <<endl<<"Enter Professor name: ";
        string profname;
        cin >> profname;
        professorNames.push_back(profname);

        string choice;
        cout << "Add Anouther Professor Name? 1/0: ";
        cin >> choice;
        if (choice == "1")
        {
            ;
        }
        else
        {
            isComplete = true;
        }
        // Make a list of available courses
    }

    PublicationList.list[id].professorNames=professorNames;

    cout << endl<< "Publication Details Updated" << endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::viewPublication()
{
    if (PublicationList.list.empty())
    {
        cout << "No Publications in Database" << endl;
        sleep(1);
        return -1;
    }
    for (auto publication : PublicationList.list)
    {
        publication.second.showDetails();
    }
    sleep(1);
    string choice;

    cout<<"1.Show Publications by Faculty Name?(1/0): ";
    cin>>choice;

    if(choice=="0")
    {
        return 0;
    }
    cout<<endl;
    if(choice=="1")
    {
        string profName;
        cout<<"Enter Professor Name: ";
        cin>>profName;

        vector<Publication>facultyPublications=PublicationList.searchByFaculty(profName);

        for(auto entry:facultyPublications)
        {
            entry.showDetails();
        }

    }
    
    getch();
    return 0;
}

int DepartmentSecretary::addResearchProject()
{
    cout << "Enter Research Project ID: ";
    string id;
    cin >> id;

    if (PublicationList.list.find(id) != PublicationList.list.end())
    {
        cout << "Publication with that ID already exists";
        sleep(1);
        cout << endl;
    }

    cout << "Enter Professor Names: ";
    string professorNames;
    cin >> professorNames;

    cout << "Enter Student Names: ";
    string studentNames;
    cin >> studentNames;

    cout << "Enter Publication website: ";
    string website;
    cin >> website;

    cout<<"Enter funding amount: ";
    string amount;
    cin>>amount;

    cout<<"Enter duration of Project: ";
    string duration;
    cin>>duration;

    ResearchProject project1(id, professorNames, studentNames, amount,duration);

    ResearchProjectList[id] = project1;

    cout << endl<<"Research Project added" << endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::updateResearchProject()
{
    for (auto project : ResearchProjectList)
    {
        project.second.showDetails();
    }

    sleep(1);
    cout << endl
         << "Enter Research Project id: ";
    string id;
    cin >> id;

    if (ResearchProjectList.find(id) == ResearchProjectList.end())
    {
        cout << endl<<"Research Project with that id is not present in the Database" << endl;
        sleep(1);
        return -1;
    }

    string professorNames;
    string studentNames;
    cout << "Enter New Professor Name List: ";
    cin >> professorNames;

    cout << "Enter New Student Name List: ";
    cin >> studentNames;
    cout << "Enter New Funding Amount: ";

    string funding;
    cin >> funding;

    cout<<"Enter New Duration: ";
    string duration;
    cin>>duration;

    ResearchProjectList[id].professorNames = professorNames;
    ResearchProjectList[id].studentNames = studentNames;
    ResearchProjectList[id].funding = funding;
    ResearchProjectList[id].duration = duration;

    cout << endl
         << "Research Project Details Updated" << endl;
    sleep(1);
    return 0;
}

int DepartmentSecretary::viewResearchProject()
{
    if (ResearchProjectList.empty())
    {
        cout << endl
             << "No Research Projects Recorded in Database" << endl;
        sleep(1);
        return -1;
    }
    for (auto project : ResearchProjectList)
    {
        project.second.showDetails();
    }
    getch();
    return 0;
}

int DepartmentSecretary::viewAccounts()
{
    cout<<"Funding Records: "<<endl<<endl;

    if(Accounts.fundingList.empty())
    {
        cout<<"No Funding Records"<<endl<<endl;
    }
    else
    {
        for (auto transaction : Accounts.fundingList)
        {
            cout << "Funding ID: " << transaction.second.id << endl;
            cout << "Funding Name: " << transaction.second.name << endl;
            cout << "Professors Involved: " << transaction.second.professorsInvolved << endl;
            cout << "Funding Amount: " << transaction.second.amount << endl;
            cout << endl;
        }
    }
    

    cout<<"Total Funding Amount: "<<Accounts.totalFunding<<endl;
    cout<<"Annual University Funding: "<<Accounts.universityFunding<<endl;
    cout<<endl;
    getch();
    return 0;
}

int DepartmentSecretary::addFunding()
{
    cout<<"1. Add Funding Record"<<endl;
    cout<<"2. Change University Annual Funding Amount"<<endl<<endl;
    sleep(1);
    cout<<"Enter Choice: ";
    string choice;
    cin>>choice;

    int choice1=0;
    if(choice=="1")
    {
        choice1=1;
    }
    else if(choice=="2")
    {
        choice1=2;
    }
    switch(choice1)
    {
        case 1:
        {
            string id;
            string name;
            string professorsInvolved;
            int amount;

            cout << "Enter Funding ID: ";
            cin >> id;
            if(Accounts.fundingList.find(id)!=Accounts.fundingList.end())
            {
                cout<<"Funding with this particular ID already exists"<<endl;
                sleep(1);
                return 0;
            }
            cout << "Enter Funding Name:";
            cin >> name;
            cout << "Enter the list of proffesors involved: ";
            cin >> professorsInvolved;
            cout << "Enter amount: ";
            string amountString;
            cin >> amountString;

            bool isNum = true;
            for (char c : amountString)
            {
                if (!(c >= '0' && c <= '9'))
                {
                    isNum = false;
                    break;
                }
            }
            if (isNum == false)
            {
                cout << endl<<"Invalid Amount" << endl;
                break;
            }
            amount = stoi(amountString);
    
            Funding funding1(id, name, professorsInvolved, amount);

            Accounts.fundingList[id] = funding1;

            Accounts.totalFunding = Accounts.totalFunding + amount;
            cout << "Funding Added to Database" << endl;
            break;
        }
        case 2:
        {
            cout<<"Enter New Annual Funding: ";

            /*

            */
            cin>>Accounts.universityFunding;

            cout<<"Changes Made"<<endl;
            break;
        }
    }
    sleep(1);
    
    return 0;
}

int DepartmentSecretary::viewCashBook()
{
    cout<<"CashBook Amount: "<<Accounts.totalFunding;
    getch();
    return 0;
}

int DepartmentSecretary::start()
{
    while(1)
    {
            DepartmentSecretaryGUI::Menu();
            string choice;

            sleep(1);
            cout << "Please Enter Functionality: ";
            cin >> choice;

            // enter names of choices like: "2.Query Student Detail Selected"

            cout << choice << " selected" << endl;

            system("cls");

            cout << "==============================================================" << endl;
            if (choice == "1")
            DepartmentSecretary::addStudent();
            else if (choice == "2")
            DepartmentSecretary::getStudentDetails();
            else if (choice == "3")
            DepartmentSecretary::registerCourses();
            else if (choice == "4")
            DepartmentSecretary::enterGradingDetails();
            else if (choice == "5")
            DepartmentSecretary::addEquipment();
            else if (choice == "6")
            DepartmentSecretary::removeEquipment();
            else if (choice == "7")
            DepartmentSecretary::viewEquipment();
            else if (choice == "8")
            DepartmentSecretary::updateEquipment();
            else if(choice=="9")
            DepartmentSecretary::addResearchProject();
            else if (choice == "10")
            DepartmentSecretary::updateResearchProject();
            else if (choice == "11")
            DepartmentSecretary::viewResearchProject();
            else if (choice == "12")
            DepartmentSecretary::addPublication();
            else if (choice == "13")
            DepartmentSecretary::updatePublication();
            else if (choice == "14")
            DepartmentSecretary::viewPublication();
            else if (choice == "15")
            DepartmentSecretary::addFunding();
            else if (choice == "16")
            DepartmentSecretary::viewAccounts();
            else if (choice == "17")
            DepartmentSecretary::viewCashBook();
            else if (choice == "0")
            break;

            cout << "==============================================================" << endl;
    }
    
    return 0;
}