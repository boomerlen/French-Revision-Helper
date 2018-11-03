// French Revision Helper.
// Current Functionality:
// Add words
// Add verbs and specify conjugations for them in present and imparfait as well as sepcifying a past participle and whether or not they use Etre in the passe compose
// Auto conjugate regular ER verbs
// TODO:
// Add file IO to store verb data and read for later
// Create some sort of user interface for searching for words by definition or french word
// Create other useful ways to organise and output words
// Maybe implement GUI, but not until I have done everything I possibly can in CMD

#include <iostream>
#include <string>

#include "Word.h"
#include "Verb.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Word nothing("nothing", "rien");
    cout << nothing.getEng() << " is: " << nothing.getFre() << endl;

    Verb aller("to go", "aller", IRREGULAR);
    aller.addPresentConjugation(JE, "vais", VOUS, "allez");
    string conj[6];
    aller.getPresentConjugation(conj);
    cout << conj[JE] << endl;
    cout << conj[TU] << endl;
    cout << conj[VOUS] << endl;
    return 0;
}
