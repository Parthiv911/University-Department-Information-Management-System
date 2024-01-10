#include <iostream>
#include <vector>

using namespace std;

class ResearchProject
{
public:
    string id;
    string professorNames;
    string funding;
    string studentNames;
    string duration;

    ResearchProject()
    {
    }
    ResearchProject(string id, string professorNames, string studentNames, string funding, string duration)
    {
        this->id = id;
        this->professorNames = professorNames;
        this->studentNames = studentNames;
        this->funding = funding;
        this->duration = duration;
    }

    void showDetails()
    {
        cout << "ID: " << id << endl;
        cout << "Professor Names: " << professorNames << endl;
        cout << "Student Names: " << studentNames << endl;
        cout << "Funding: " << funding << endl;
        cout << "Duration: " << duration << endl;

        cout << endl;
    }
};