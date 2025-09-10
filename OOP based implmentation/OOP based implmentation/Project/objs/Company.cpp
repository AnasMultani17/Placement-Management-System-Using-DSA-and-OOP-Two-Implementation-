#include <string>
#include "Company.h"

using namespace std;

Company::Company(const string &username, const string &password, const string &name, const string &location, const string &type, int minCtc, int maxCtc)
    : CompanySignup(username, password), name(name), location(location), type(type), minCtc(minCtc), maxCtc(maxCtc)
{
}

string Company::getName() const
{
    return name;
}

string Company::getLocation() const
{
    return location;
}

string Company::getType() const
{
    return type;
}

int Company::getMinCtc() const
{
    return minCtc;
}

int Company::getMaxCtc() const
{
    return maxCtc;
}