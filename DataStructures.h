#include<iostream>
#include<vector>
#include<unordered_map>
#include "Student.h"
#include "Equipment.h"
#include "PublicationListClass.h"
#include "ResearchProject.h"
#include "FundingDetails.h"

using namespace std;

unordered_map<string,Student>StudentDetails;

unordered_map<string,Equipment>EquipmentList;

PublicationListClass PublicationList;

unordered_map<string, ResearchProject> ResearchProjectList;

FundingDetails Accounts;