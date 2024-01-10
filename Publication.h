#include <iostream>
#include <vector>

using namespace std;

class Publication
{
public:
    string id;
    string name;
    string date;
    string webPageLink;
    vector<string> professorNames;
    Publication()
    {
    }
    Publication(string id, string name, string date, string webPageLink, vector<string> professorNames)
    {
        this->id = id;
        this->name = name;
        this->date = date;
        this->webPageLink = webPageLink;
        this->professorNames = professorNames;
    }

    void showDetails()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Date: " << date << endl;
        cout << "Web Page Link: " << webPageLink << endl;
        cout << "Professors: " << endl;
        for (auto prof : professorNames)
        {
            cout << prof << endl;
        }
        cout << endl;
    }
};