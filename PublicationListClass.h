#include <iostream>
#include <vector>
#include <unordered_map>
#include "Publication.h"
using namespace std;

class PublicationListClass
{
public:
    unordered_map<string, Publication> list;

    vector<Publication> searchByFaculty(string profName)
    {
        vector<Publication> facultyPublications;

        for (auto entry : list)
        {
            for (auto prof : entry.second.professorNames)
            {
                if (prof == profName)
                {
                    facultyPublications.push_back(entry.second);
                    break;
                }
            }
        }
        return facultyPublications;
    }
};