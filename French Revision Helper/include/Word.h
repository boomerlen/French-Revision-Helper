#ifndef WORD_H
#define WORD_H

#include <string>

#define JE 0
#define TU 1
#define ON 2
#define NOUS 3
#define VOUS 4
#define ILS 5
#define INVALID 6

#define MASCULINE 0
#define FEMININE 1
#define PLURAL 2

using namespace std;

class Word
{
    public:
        Word(string eng, string fre);
        virtual ~Word();

        string getEng();
        string getFre();

        void setComment(string com);
        string getComment();

    protected:

    private:
        string english;
        string french;
        string comment;
};

#endif // WORD_H
