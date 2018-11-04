#include "Word.h"
#include <string>

using namespace std;

Word::Word(string eng, string fre)
{
    //ctor
    english = eng;
    french = fre;
}

string Word::getEng()
{
    return english;
}

string Word::getFre()
{
    return french;
}

Word::~Word()
{
    //dtor
}

void Word::setComment(string com)
{
    comment = com;
}

string Word::getComment()
{
    return comment;
}
