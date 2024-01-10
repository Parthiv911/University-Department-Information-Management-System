#include <iostream>
#include <vector>

using namespace std;

class Equipment
{
public:
    string id;
    string name;
    string location;

    Equipment()
    {
    }
    Equipment(string id, string name, string location)
    {
        this->id = id;
        this->name = name;
        this->location = location;
    }

    void showDetails()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Location: " << location << endl;

        cout << endl;
    }
};
