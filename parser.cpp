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
//bool channel_1 = false;
//
//static unsigned int counter = 0;
//Token parser_GetNextToken(vector < vector<Token> > pList);
Token parser_GetNextToken(vector < vector<Token> > pList);
//NOTE: Make parse tree while parsing

//START: Is this a program?
//Program if there is a list of statements

void start()
{
//
//    if(is_SList(SLIST, index) == -1)
//    {
//        //error
//    }
//    Token tok = parser_GetNextToken(SLIST);
//    cout << typeInString(tok.GetTokenType()) << endl;
//    cout << typeInString(tok.GetTokenType());
//        Token temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;
//        temp = parser_GetNextToken(SLIST);
//        cout << typeInString(temp.GetTokenType()) << ": " << temp.GetLinenum() << endl;

//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;
//        cout << typeInString(parser_GetNextToken(SLIST).GetTokenType()) << endl;




}


////Is this a statement list?
////Statement list if there is a statement or a list of statement
//int is_SList(vector < vector<Token> > stmt_List, int index)
//{
//    vector<Token> temp;
//    if(index != stmt_List.size())
//    {
//        temp = stmt_List[index];
//
//        if(is_Stmt(temp) == -1)
//        {
//            //error
//        }
//        else
//        {
//            return is_SList(stmt_List, index++);
//        }
//    }
//    //All goes well, we return 0;
//    return 0;
//}
//
//int is_Stmt(vector<Token> stmt)
//{
//    if( (is_VarStmt(stmt) == -1) && (is_SetStmt(stmt) == -1) && (is_PrintStmt(stmt) == -1) && (is_RepeatStmt(stmt) == -1))
//    {
//        //error
//        return -1;
//    }
//    return 0;
//}
//
//int is_VarStmt(vector<Token> eval)
//{
//    if((typeInString(eval[0]) == "VAR") && (typeInString(eval[1]) == "IDENT"))
//    {
//        if(is_Expr(eval[2]) == -1)
//        {
//            //error
//            return -1;
//        }
//    }
//
//    return 0;
//
//}
//
//int is_SetStmt(vector<Token> eval)
//{
//    if((typeInString(eval[0]) == "SET") && (typeInString(eval[1]) == "IDENT"))
//    {
//        if(is_Expr(eval[2]) == -1)
//        {
//            //error
//            return -1;
//        }
//    }
//}
//
//int is_PrintStmt(vector<Token> eval)
//{
//    if((typeInString(eval[0]) == "PRINT"))
//    {
//        if(is_Expr(eval[1]) == -1)
//        {
//            //error
//            return -1;
//        }
//    }
//
//}
//
//int is_RepeatStmt(vector<Token> eval)
//{
//    if((typeInString(eval[0]) == "REPEAT"))
//    {
//        if(is_Expr(eval[1]) == -1)
//        {
//            //error
//            return -1;
//        }
//
//        //HERE IS WHERE AN ERROR WILL OCCUR FIX LATER
//
//        if(is_Stmt(eval[1]) == -1)
//        {
//            //error
//            return -1;
//        }
//    }
//}
////LEFT OFF HERE
//int is_Expr(Token t_Eval)
//{
//    if(is_Term() || )
//}
//
//
//Token *parser_GetNextToken(vector< vector<Token> > *pVector)
//{
//    static pVector = SLIST.begin();
//    if(pVector != SLIST.end())
//    {
//        vector<Token> *temp = pVector->begin();
//        if(temp != pVector->end())
//        {
//            return temp;
//        }
//    }
//}


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
