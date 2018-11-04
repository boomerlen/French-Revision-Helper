#ifndef ADJECTIVE_H
#define ADJECTIVE_H

#include <Word.h>
#include <string>

class Adjective : public Word
{
    public:
        Adjective(std::string eng, std::string fre, short int gen);
        virtual ~Adjective();

        short int getGender();
        void setGender(short int gen);

    protected:

    private:
        short int gender;
};

#endif // ADJECTIVE_H
