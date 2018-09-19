#include <iostream>
#include <vector>
#include "globalvar.h"
#include "parsetree.h"

using std::cout;
using std::endl;
using std::vector;

//Function Prototypes for the Language Rules
int is_SList(vector< vector <Token> > stmt_List, int index);  //Recursive
int is_Stmt(vector<Token> stmt);
int is_VarStmt(vector<Token> eval);
int is_SetStmt(vector<Token> eval);
int is_PrintStmt(vector<Token> eval);
int is_RepeatStmt(vector<Token> eval);
int is_Expr(Token t_Eval);
int is_Term();
int is_Factor();
int is_Primary();
int index = 0;

Token parser_GetNextToken(vector < vector<Token> > pList);
//NOTE: Make parse tree while parsing

//START: Is this a program?
//Program if there is a list of statements

Token parser_GetNextToken(vector< vector<Token> > pList)
{
    static int counter = 0;
    static vector<Token> *it;
    static Token *jt;

    //for plist
    static int size_of_List = pList.size();
    //for contents inside singular vector
    static unsigned int counter_2 = 0;

    if(counter < size_of_List)
    {
        it = &pList[counter];
        if(counter_2 < pList[counter].size())
        {
            jt = &it->at(counter_2);

            //for me to view
            Token debug = it->at(counter_2);

            counter_2++;
            return *jt;
        }
        else if(counter_2 >= pList[counter].size())
        {
            counter++;
            counter_2 = 0;
            Token lineViewer = *jt;
            int aLine = lineViewer.GetLinenum();
            Token fin(DONE, "DONE", aLine);
            return fin;
        }
    }

    Token fail;
    return fail;

}
