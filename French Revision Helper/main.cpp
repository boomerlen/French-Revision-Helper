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

// 4/11/2018 I am midway through the SQL Server integration. I still need to set that up, set up the password encryption and make some sort of user interface.

#include <stdio.h>
#include <stdlib.h>>
#include <string.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <tinyAES/aes.hpp>

#include "jdbc/mysql_connection.h"

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

#include "Word.h"
#include "Verb.h"

#define CONFIG_FILE_ADDR "config.conf"

#define VERBS 0
#define ADJECTIVES 1
#define OTHER 2

using namespace std;

string serv_addr, serv_user, serv_pass; // Global Vars

vector< vector<Word> > initialiseWordVector()
{
    // We do all connections in here for setup
    vector< vector<Word> > wordVector;
    try{
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = get_driver_instance();
        string *base = "tcp://";
        string *addr = base.append(serv_addr);
        con = driver->connect(addr, serv_user, serv_pass);

        con->setSchema("schema");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'english' FROM 'verbs'");
        while(res->next())
        {
            string something = res->getString(1);
        }
    }
    delete base;
    delete addr;
}

int main()
{
    cout << "Hello world!" << endl;

/*    Word nothing("nothing", "rien"); Testing functionality code
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
    char buf[256];
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

    // Connect to database using serv_addr, serv_user and serv_pass. Use a different function to do that
    // Take everything from it and store in vector for each class so that we can sort them easily.
    // Words added will be stored in their own (Word) vector (as well as the the vector for its type) and then added to the database at the end (or if the user "commit"s)
    // Words removed will be in their own vector also to be removed from the database at the end or upon commit

    vector< vector<Word> > WordList = initialiseWordVector();
    // Split it up etc

    return 0;
}
