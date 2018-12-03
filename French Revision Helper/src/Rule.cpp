#include "Rule.h"

Rule::Rule(std::string n, std::string r)
{
    //ctor
    name = n;
    rule = r;
    return;
}

Rule::~Rule()
{
    //dtor
}

std::string Rule::get_name()
{
    return name;
}

std::string Rule::get_rule()
{
    return rule;
}

void Rule::set_name(std::string n)
{
    name = n;
}

void Rule::set_rule(std::rule r)
{
    rule = r;
}
