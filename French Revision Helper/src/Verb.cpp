#include "Verb.h"
#include <string>

using namespace std;

Verb::Verb(string eng, string fre, short int vtype) // Maybe someday change this to assume its regular and try to detect and automate this process.
    : Word(eng, fre)
{
    //ctor

    usesEtreInPasseCompose = false;
    // Tricky bit
    // Auto conjugate!
    verb_type = vtype;
    if(vtype == IRREGULAR)
        return;

    string conjBase;
    string imparfaitStem;
    for(int i = 0; i < (fre.length() - 2); i++)
    {
        conjBase.at(i) = fre.at(i);
    }
    switch(vtype)
    {
    case IRREGULAR:
        return;
        break;
    case ERVERB:
        present_conjugation[JE] = conjBase;
        present_conjugation[TU] = conjBase.append("s");
        present_conjugation[ON] = conjBase;
        present_conjugation[NOUS] = conjBase.append("ons");
        present_conjugation[VOUS] = conjBase.append("ez");
        present_conjugation[ILS] = conjBase.append("ent");

        past_participle = conjBase.append("é");

        imparfaitStem = conjBase;
        imparfait_conjugation[JE] = imparfaitStem.append("ais");
        imparfait_conjugation[TU] = imparfaitStem.append("ais");
        imparfait_conjugation[ON] = imparfaitStem.append("ait");
        imparfait_conjugation[NOUS] = imparfaitStem.append("ions");
        imparfait_conjugation[VOUS] = imparfaitStem.append("iez");
        imparfait_conjugation[ILS] = imparfaitStem.append("aient");
        break;
    case IRVERB:
    case REVERB:
        break;
    }
}

Verb::~Verb()
{
    //dtor
}

void Verb::addPresentConjugation(short int s1, std::string conj1, short int s2, std::string conj2, short int s3, std::string conj3, short int s4, std::string conj4, short int s5, std::string conj5, short int s6, std::string conj6)
{
    present_conjugation[s1] = conj1;
    if(s2 != INVALID)
    {
        present_conjugation[s2] = conj2;
    }
    if(s3 != INVALID)
    {
        present_conjugation[s3] = conj3;
    }
    if(s4 != INVALID)
    {
        present_conjugation[s4] = conj4;
    }
    if(s5 != INVALID)
    {
        present_conjugation[s5] = conj5;
    }
    if(s6 != INVALID)
    {
        present_conjugation[s6] = conj6;
    }
    return;
}

void Verb::addImparfaitConjugation(short int s1, std::string conj1, short int s2, std::string conj2, short int s3, std::string conj3, short int s4, std::string conj4, short int s5, std::string conj5, short int s6, std::string conj6)
{
    imparfait_conjugation[s1] = conj1;
    if(s2 != INVALID)
    {
        imparfait_conjugation[s2] = conj2;
    }
    if(s3 != INVALID)
    {
        imparfait_conjugation[s3] = conj3;
    }
    if(s4 != INVALID)
    {
        imparfait_conjugation[s4] = conj4;
    }
    if(s5 != INVALID)
    {
        imparfait_conjugation[s5] = conj5;
    }
    if(s6 != INVALID)
    {
        imparfait_conjugation[s6] = conj6;
    }
    return;
}

void Verb::setPastParticiple(std::string pp)
{
    past_participle = pp;
    return;
}

void Verb::usesEtre()
{
    usesEtreInPasseCompose = true;
    return;
}

void Verb::doesntUseEtre()
{
    usesEtreInPasseCompose = false;
    return;
}

void Verb::getPresentConjugation(std::string (&conjugation)[6])
{
    for(int i = 0; i < 6; i++)
    {
        conjugation[i] = present_conjugation[i];
    }
    return;
}

void Verb::getImparfaitConjugation(std::string (&conjugation)[6])
{
    for(int i = 0; i < 6; i++)
    {
        conjugation[i] = imparfait_conjugation[i];
    }
    return;
}

std::string Verb::getPastParticiple()
{
    return past_participle;
}

bool Verb::getEtreUsage()
{
    return usesEtreInPasseCompose;
}
