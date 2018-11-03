#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word
{
    public:
        Word(string eng, string fre);
        virtual ~Word();

        string getEng();
        string getFre();

    protected:

    private:
        string english;
        string french;
};

#endif // WORD_H
