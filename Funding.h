#include <iostream>
#include <vector>

using namespace std;

class Funding
{
public:
    string id;
    string name;
    string professorsInvolved;
    int amount;

    Funding()
    {
        ;
    }

    Funding(string id, string name, string professorsInvolved, int amount)
    {
        this->id = id;
        this->name = name;
        this->professorsInvolved = professorsInvolved;
        this->amount = amount;
    }
};