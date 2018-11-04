#include "Adjective.h"

Adjective::Adjective(string eng, string fre, short int gen) // Maybe someday change this to assume its regular and try to detect and automate this process.
    : Word(eng, fre)
{
    //ctor
    gender = gen;
}

short int Adjective::getGender()
{
    return gender;
}

void Adjective::setGender(short int gen)
{
    gender = gen;
    return;
}

Adjective::~Adjective()
{
    //dtor
}
