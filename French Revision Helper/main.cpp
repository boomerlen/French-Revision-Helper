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

#include <jdbc/mysql_connection.h>

#include <jdbc/cppconn/driver.h>
#include <jdbc/cppconn/exception.h>
#include <jdbc/cppconn/resultset.h>
#include <jdbc/cppconn/statement.h>

#include "Word.h"
#include "Verb.h"
#include "Adjective.h"
#include "Rule.h"

#define VERBS 0
#define ADJECTIVES 1
#define OTHER 2

#define VERSION 1.0

using namespace std;

string CONFIG_FILE_ADDR = "config.conf";

string serv_addr, serv_user, serv_pass; // Global Vars

sql::Connection* initialiseSQLConnection()
{
    try{
        sql::Driver *driver;
        sql::Connection *con;

        driver = get_driver_instance();
        string *base = "tcp://";
        string *addr = base.append(serv_addr);
        con = driver->connect(addr, serv_user, serv_pass);

        delete base;
        delete addr;

        return con;
}

vector< vector<Word> > initialiseWordVector(sql::Connection *con)
{
    // We do all connections in here for setup
    vector< vector<Word> > wordVector;
    try{
        sql::Statement *stmt;
        sql::ResultSet *res;

        con->setSchema("schema");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'english' FROM 'verbs'");
        while(res->next())
        {
            string something = res->getString(1);
        }
    }
}

vector<Rule> initialiseRuleVector(sql::Connection *con)
{
    // Do things
}

// Functions for displaying UI text
void openingMessage()
{
    cout << "Welcome to Hugo's French Revision Helper." << endl;
    cout << "If you need any support, ask Hugo." << endl;
}

void mainMenu()
{
    cout << "French Revision Helper v" << VERSION << endl;
    cout << "Commands:" << endl;
    cout << "help/?/h - displays command list" << endl;
    cout << "addw - dialogue for adding a word" << endl;
    cout << "addr - dialogue for adding a grammar rule" << endl;
    cout << "search - search for words or grammar rules by name (beta)" << endl;
    cout << "list - dialogue for listing words or grammar rules" << endl;
    cout << "display - dialogue for displaying details and/or comments with words" << endl;
    cout << "delete - dialogue for removing words or grammar rules" << endl;
    cout << "All commands are not case-sensitive." << endl;
}

void helpMenu()
{
    cout << "Commands:" << endl;
    cout << "help/?/h - displays command list" << endl;
    cout << "addw - dialogue for adding a word" << endl;
    cout << "addr - dialogue for adding a grammar rule" << endl;
    cout << "search - search for words or grammar rules by name (beta)" << endl;
    cout << "list - dialogue for listing words or grammar rules" << endl;
    cout << "display - dialogue for displaying details and/or comments with words" << endl;
    cout << "delete - dialogue for removing words or grammar rules" << endl;
    cout << "All commands are not case-sensitive." << endl;
}

int addWord(sql::Connection *con, vector< vector<Word> > &wordList)
{
    // Dialogue with user,
    // Get word details,
    // Add to database
    // Return 1 if failure, 0 if success
}

int addRule(sql::Connection *con, vector<Rule> &ruleList)
{
    // Dialogue with user,
    // Get rule details,
    // Add to database
    // Return 1 if failure, 0 if success
}

int func_search(vector< vector<Word> > &wordList, vector<Rule> &ruleList)
{
    // Dialogue with user for search terms
    // Check english, french and rule names
}

int func_list(vector< vector<Word> > &wordList, vector<Rule> &ruleList)
{
    // Dialoge with user for specific things to list
    // List them
}

// Do the rest of the commands

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
    openingMessage();

    cout << "If your config file is not at config.conf, enter a new address. Otherwise press enter.";
    string in;
    cin >> in;
    if(in != "")
    {
        CONFIG_FILE_ADDR = in;
    }

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

    sql::Connection con* = initialiseSQLConnection();

    vector< vector<Word> > WordList = initialiseWordVector(con);
    vector<Rule> ruleList = initialiseRuleVector(con);
    // Split it up etc

    // Console UI
    mainMenu();
    string in;
    while(1)
    {
        cout << "FRH v" << VERSION << endl;
        cout << "> ";
        cin in;
        if(in == "h" || in == "?" || in == "help")
        {
            helpMenu();
        }
        else if(in == "addw")
        {
            // Add word to database
        }
        else if(in == "addr")
        {
            // Add grammar rule to database
        }
        else if(in == "search")
        {
            // Search function (should be interesting to implemenet)
        }
        else if(in == "list")
        {
            // List contents of database
        }
        else if(in == "display")
        {
            // Display details of a word (e.g. conjugation of verbs)
        }
        else if(in == "delete")
        {
            // Remove something from database
        }
        else
        {
            cout << "Unknwon command." << endl;
        }
    }

    return 0;
}
