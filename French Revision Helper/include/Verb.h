#ifndef VERB_H
#define VERB_H

#include <Word.h>
#include <string>

#define ERVERB 0
#define REVERB 1
#define IRVERB 2
#define IRREGULAR 3

class Verb : public Word
{
    public:
        Verb(string eng, string fre, short int vtype = IRREGULAR);
        virtual ~Verb();

        void addPresentConjugation(short int s1, std::string conj1, short int s2 = INVALID, std::string conj2 = "", short int s3 = INVALID, std::string conj3 = "", short int s4 = INVALID, std::string conj4 = "", short int s5 = INVALID, std::string conj5 = "", short int s6 = INVALID, std::string conj6 = "");
        void addImparfaitConjugation(short int s1, std::string conj1, short int s2 = INVALID, std::string conj2 = "", short int s3 = INVALID, std::string conj3 = "", short int s4 = INVALID, std::string conj4 = "", short int s5 = INVALID, std::string conj5 = "", short int s6 = INVALID, std::string conj6 = "");
        void setPastParticiple(std::string pp);
        void usesEtre();
        void doesntUseEtre();

        void getPresentConjugation(std::string (&conjugation)[6]);
        void getImparfaitConjugation(std::string (&conjugation)[6]);
        std::string getPastParticiple();
        bool getEtreUsage();

    protected:

    private:
        std::string present_conjugation[6];
        std::string imparfait_conjugation[6];
        std::string past_participle;
        bool usesEtreInPasseCompose;
        short int verb_type;
};

#endif // VERB_H
