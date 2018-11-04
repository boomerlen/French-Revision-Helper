// French Revision Helper.
// Current Functionality:
// Add words
// Add verbs and specify conjugations for them in present and imparfait as well as sepcifying a past participle and whether or not they use Etre in the passe compose
// Auto conjugate regular ER, RE and IR verbs
// Adjectives with gender added
// TODO:
// Add file IO to store verb data and read for later - Maybe SQL Database?
// Create some sort of user interface for searching for words by definition or french word
// Create other useful ways to organise and output words
// Maybe implement GUI, but not until I have done everything I possibly can in CMD
// Implement SQL Database. Refer to https://www.codeguru.com/cpp/data/database-programming-with-cc.html

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>

#include <tinyAES/aes.hpp>

#include <jdbc/mysql_connection.h>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

#include "Word.h"
#include "Verb.h"

#define CONFIG_FILE_ADDR "config.conf"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

/*    Word nothing("nothing", "rien");
    cout << nothing.getEng() << " is: " << nothing.getFre() << endl;

    Verb aller("to go", "aller", IRREGULAR);
    aller.addPresentConjugation(JE, "vais", VOUS, "allez");
    string conj[6];
    aller.getPresentConjugation(conj);
    cout << conj[JE] << endl;
    cout << conj[TU] << endl;
    cout << conj[VOUS] << endl; */

    fstream config_file;
    config_file.open(CONFIG_FILE_ADDR, ios::in);
    if(!config_file.is_open())
    {
        cout << "ERROR: confile file not found!" << endl;
        return 1;
    }
    char serv_addr[256], serv_user[256], buf[256];
    string serv_pass;
    config_file.getline(buf, 256);
    if(strlen(buf) < 3)
    {
        // File is empty!
        cout << "Please enter SQL Server Configuration Information. Ask Hugo for them if you are unsure." << endl;
        char save_pass;
        cout << "Server Address: ";
        cin >> serv_addr;
        cout << "Your username: ";
        cin >> serv_user;
        cout << "Your password: ";
        cin >> serv_pass;
        cout << "Would you like your password to be saved? It will be encrypted (y/n): ";
        cin >> save_pass;
        // Write all this to file.
        config_file.close();
        config_file.open(CONFIG_FILE_ADDR, ios::out | ios::trunc);
        config_file << "CONFIGURATION FILE\n";
        config_file << serv_addr << "\n";
        config_file << serv_user << "\n";
        if(save_pass == 'y')
        {
            // Encryption
        }
    }


    // Connect to database using serv_addr, serv_user and serv_pass.


    return 0;
}
