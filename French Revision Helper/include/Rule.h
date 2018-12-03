#ifndef RULE_H
#define RULE_H

#include <string>

class Rule
{
    public:
        Rule(std::string n, std::string r);
        virtual ~Rule();

        std::string get_name();
        std::string get_rule();

        int set_name(std::string n);
        int set_rule(std::string r);

    protected:

    private:
        std::string name;
        std::string rule;
};

#endif // RULE_H
