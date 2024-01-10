#include <iostream>
#include <vector>
#include <unordered_map>
#include "Funding.h"
using namespace std;

class FundingDetails
{
public:
    unordered_map<string, Funding> fundingList;
    int totalFunding;
    int universityFunding;
};