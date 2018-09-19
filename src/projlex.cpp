/*
 * projlex.cpp
 *
 * program for lex here
 *
 * main.cpp to test
 *
*/
#include "globalvar.h"
#include "projlex.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <stdlib.h>
using std::string;
using std::istream;
using std::ostream;

////////////////GLOBAL VARS & FUNCTION PROTOTYPES/////////////////
void spitAllTokens(std::vector<Token> tokenVector);
string typeInString(int enumeratorVal);
bool errInString = false;
bool found_error = false;
string stringInterpreter(string theString);
std::vector<Token> tokenCollector;
int commonCount = 0;
std::vector<string> countCollector;
std::vector<string> stringCollector;
std::vector< std::vector<Token> > SLIST;
std::vector<Token> to_SLIST;
int linenumber;
int stringCounter = 0;
//////////////////////////////////////////////////////////////////

Token getNextToken(istream *in, int *linenum)
{
    linenumber = 0;

//////////////////////////////////////////////////////////////////
    //Obtain the entire file content and put into a string
    string content = "";
    char c;
    while(in->get(c))
    {
        content += c;
    }
//////////////////////////////////////////////////////////////////

    //Go through the entire file and analyze its contents
    unsigned int i;
    string temp;
    char character;
    //IGNORE -> char characterForDebug;
    for(i = 0; i < content.length(); i++)
    {
        character = content[i];

        //This will handle strings -- Indicated with a beginning "
        if(character == '"')
        {
            //Ignore the current " and loop till you reach ERR or ending "
            i = i + 1;
            while(content[i] != '"' && content[i] != '\n' && content[i] != '\000')
            {
                temp += content[i];
                i++;
            }
            
            //Once breaking out of this while loop, determine why
            if(content[i] == '"')
            {
                //Successfully obtained a string token
                linenum = &linenumber;
                Token sTok(SCONST, temp, *linenum);
                stringCollector.push_back(temp);
                temp = "";
                stringCounter++;
                tokenCollector.push_back(sTok);
                to_SLIST.push_back(sTok);
                continue;
            }

            //If it so happens that a new line has been detected while in "string", an error is thrown
            if(content[i] == '\n')
            {
                temp += content[i];
                linenumber = linenumber + 1;
                linenum = &linenumber;
                errInString = true;
                Token errTok(ERR, temp, *linenum);
                tokenCollector.push_back(errTok);
                break;
            }
        }

        //This will handle integers
        else if(isdigit(character))
        {
            //If it's a negative number
            if(content[i-1] == '-')
            {
                temp += content[i-1];
            }
            while(isdigit(content[i]))
            {
                temp += content[i];
                i++;
            }
            //Once out of loop, figure out why
            //If a letter has been found, an error is raised, this is not an ICONST nor IDENT
            if(isalpha(content[i]))
            {
                linenum = (&linenumber);
                temp += content[i];
                Token errorTok(ERR, temp, *linenum+1);
                temp = "";
                tokenCollector.push_back(errorTok);
                break;
            }
            else if(isspace(content[i]))
            {

                if(isspace(content[i]) == '\n')
                {
                    linenumber = linenumber + 1;
                }
            
                //Successfully obtained an integer value
                Token intToken(ICONST, temp, *linenum);
                temp = "";
                tokenCollector.push_back(intToken);
                to_SLIST.push_back(intToken);
            }
            else
            {
                if(content[i] == '\n')
                {
                    linenumber = linenumber + 1;
                }
                Token intToken(ICONST, temp, *linenum);
                temp = "";
                tokenCollector.push_back(intToken);
                to_SLIST.push_back(intToken);
                i--;
            }
        }

        //This will handle newlines
        else if(character == '\n')
        {
            linenumber = linenumber + 1;
            linenum = &linenumber;
            continue;
        }

        //This will handle IDENTS
        //If a letter has been detected while it is not within quotes, it must be an IDENT -- can be letters and numbers
        else if(isalpha(character))
        {
            while(isalnum(content[i]))
            {
                temp += content[i];
                i++;
            }
            
            //Once out of loop, must mean obtained identifier lexeme -- Important to identify if it's a keyword
            if(temp == "set")
            {
                Token identTok(SET, temp, *linenum);
                temp = "";
                tokenCollector.push_back(identTok);
                to_SLIST.push_back(identTok);
                i--;
            }
            else if(temp == "print")
            {
                Token identTok(PRINT, temp, *linenum);
                temp = "";
                tokenCollector.push_back(identTok);
                to_SLIST.push_back(identTok);
                i--;
            }
            else if(temp == "var")
            {
                Token identTok(VAR, temp, *linenum);
                temp = "";
                tokenCollector.push_back(identTok);
                to_SLIST.push_back(identTok);
                i--;
            }
            else if(temp == "repeat")
            {
                Token identTok(REPEAT, temp, *linenum);
                temp = "";
                tokenCollector.push_back(identTok);
                to_SLIST.push_back(identTok);
                i--;
            }
            else    //If none of those keywords, then it's an IDENT
            {
                Token identTok(IDENT, temp, *linenum);
                countCollector.push_back(temp);
                temp = "";
                tokenCollector.push_back(identTok);
                to_SLIST.push_back(identTok);
                i--;
            }
        }

        //Handles all miscellaneous tokens
        else if(character == '+')
        {
            Token plusTok(PLUS, "", *linenum);
            tokenCollector.push_back(plusTok);
            to_SLIST.push_back(plusTok);
            continue;
        }
        else if((character == '-') && (!isdigit(content[i+1])))
        {
            Token minusTok(MINUS, "", *linenum);
            tokenCollector.push_back(minusTok);
            to_SLIST.push_back(minusTok);
            continue;
        }
        else if(character == '*')
        {
            Token starTok(STAR, "", *linenum);
            tokenCollector.push_back(starTok);
            to_SLIST.push_back(starTok);
            continue;
        }
        else if(character == ':')
        {
            Token colonTok(COLON, "", *linenum);
            tokenCollector.push_back(colonTok);
            to_SLIST.push_back(colonTok);
            continue;
        }
        else if(character == '[')
        {
            Token lsqTok(LSQ, "", *linenum);
            tokenCollector.push_back(lsqTok);
            to_SLIST.push_back(lsqTok);
            continue;
        }
        else if(character == ']')
        {
            Token rsqTok(RSQ, "", *linenum);
            tokenCollector.push_back(rsqTok);
            to_SLIST.push_back(rsqTok);
            continue;
        }
        else if(character == '(')
        {
            Token lparenTok(LPAREN, "", *linenum);
            tokenCollector.push_back(lparenTok);
            to_SLIST.push_back(lparenTok);
            continue;
        }
        else if(character == ')')
        {
            Token rparenTok(RPAREN, "", *linenum);
            tokenCollector.push_back(rparenTok);
            to_SLIST.push_back(rparenTok);
            continue;
        }
        else if(character == ';')
        {
            Token scTok(SC, "", *linenum);
            tokenCollector.push_back(scTok);

            to_SLIST.push_back(scTok);
            SLIST.push_back(to_SLIST);

            to_SLIST.clear();

            continue;
        }
        
        //Handles spaces
        else if(character == ' ' || character == '\0')
        {
            continue;
        }
        
        //Handles comments
        else if(character == '#')
        {
            i = i + 1;
            while(content[i] != '\n' && content[i] != '\000')
            {
                temp += content[i];
                i++;
            }
            if(content[i] == '\n')
            {
                linenumber = linenumber + 1;
            }
            //Once out of this loop, we have reached the end of the line and so this comment must be discarded
            temp = "";
            continue;

        }

        //take all tokens before it and put it
        else if(character == ';')
        {

        }
    }
    spitAllTokens(tokenCollector);
    //Some default token to return -- doesn't have any value but function requires a token return
    Token defaultTok(DONE, "", *linenum);
    return defaultTok;
}

ostream& operator<<(ostream& out, const Token& tok)
{
    Token printTok;
    out << printTok.GetLexeme();
    out << printTok.GetLinenum();
    out << printTok.GetTokenType();

    //This will never be used, it's here because the function requires a return of out
    return out;
}

void spitAllTokens(std::vector<Token> tokenVector)
{
    if(vFlag)
    {

        unsigned int i;
        Token temp;
        for(i = 0; i < tokenVector.size(); i++)
        {
            temp = tokenVector[i];
            if(typeInString(temp.GetTokenType()) == "ERR")
            {
                if(errInString == true)
                {
                    std::cout << "Error on line " << temp.GetLinenum() << " (\"" << temp.GetLexeme() << ")\n";
                    return;
                }
                else
                {
                    std::cout << "Error on line " << temp.GetLinenum() << " (" << temp.GetLexeme() << ")\n";
                    return;
                }
            }
            if(i != tokenVector.size()-1)
            {
                if(typeInString(temp.GetTokenType()) == "ICONST" || typeInString(temp.GetTokenType()) == "SCONST" || typeInString(temp.GetTokenType()) == "IDENT")
                {
                    std::cout << typeInString(temp.GetTokenType()) << "(" << temp.GetLexeme() << ")\n";
                }
                if((typeInString(temp.GetTokenType())== "VAR")||
                   (typeInString(temp.GetTokenType())== "SET")||
                   (typeInString(temp.GetTokenType())== "PRINT")||
                   (typeInString(temp.GetTokenType())== "REPEAT")||
                   (typeInString(temp.GetTokenType()) == "PLUS")||
                   (typeInString(temp.GetTokenType()) == "MINUS")||
                   (typeInString(temp.GetTokenType()) == "STAR")||
                   (typeInString(temp.GetTokenType()) == "COLON")||
                   (typeInString(temp.GetTokenType()) == "LSQ")||
                   (typeInString(temp.GetTokenType()) == "RSQ")||
                   (typeInString(temp.GetTokenType()) == "LPAREN")||
                   (typeInString(temp.GetTokenType()) == "RPAREN")||
                   (typeInString(temp.GetTokenType()) == "SC")
                  )
                {
                    std::cout << typeInString(temp.GetTokenType()) << "\n";
                }

            }
            else
            {
                if((typeInString(temp.GetTokenType())== "VAR")||
                   (typeInString(temp.GetTokenType())== "SET")||
                   (typeInString(temp.GetTokenType())== "PRINT")||
                   (typeInString(temp.GetTokenType())== "REPEAT")
                  )
                {
                    std::cout << typeInString(temp.GetTokenType()) << "\n";
                }
                else
                {
                    std::cout << typeInString(temp.GetTokenType()) << "(" << temp.GetLexeme() << ")\n";
                }
            }
        }
    }
    if(mciFlag)
    {
        unsigned int i;
        int wordcount;
        int highestWordCount = 0;
        string wordtoFind;
        string mostCommonWord;
        for(i = 0; i < countCollector.size(); i++)
        {
            wordtoFind = countCollector[i];
            wordcount = std::count(countCollector.begin(), countCollector.end(), wordtoFind);
            if(wordcount > highestWordCount)
            {
                highestWordCount = wordcount;
            }
        }

        std::cout << "Most Common Identifier: ";
        unsigned int p;
        string foo;
        int countFoo;
        std::vector<string> word_met_criteria;
        for(p = 0; p < countCollector.size(); p++)
        {
            foo = countCollector[p];
            countFoo = std::count(countCollector.begin(), countCollector.end(), foo);
            if(countFoo == highestWordCount)
            {
                word_met_criteria.push_back(foo);
            }
        }
        std::sort(word_met_criteria.begin(), word_met_criteria.end());
        std::set<string> s(word_met_criteria.begin(), word_met_criteria.end());
        std::set<string>::iterator is;
        std::set<string>::iterator ahead;
        for(is = s.begin(); is!= s.end(); is++)
        {
            ahead = std::next(is);
            if(is!= s.end())
            {
                std::cout << *is;
            }
            if(ahead != s.end())
            {
                std::cout << ", ";
            }
        }
        std::cout << "\n";
    }
    if(sumFlag)
    {
        std::cout << "Total lines: "<< linenumber+1;
        if(tokenCollector.size() != 0)
        {
            std::cout << "\nTotal tokens: " << tokenCollector.size();
        }
        else
        {
            return;
        }
        std::cout << "\nTotal strings: " << stringCounter;
        if(stringCounter == 0)
        {
            return;
        }
        unsigned int g;
        unsigned int largest_str = 0;
        string temp_str;
        for(g = 0; g < stringCollector.size(); g++)
        {
            temp_str = stringCollector[g];
            if(temp_str.length() > largest_str)
            {
                largest_str = temp_str.length();
            }
        }
        std::cout << "\nLength of longest string: " << largest_str << "\n";
    }
    
    //If no flags
    if(!vFlag && !mciFlag && !sumFlag)
    {
        unsigned int i;
        Token temp;

        for(i = 0; i < tokenVector.size(); i++)
        {
            temp = tokenVector[i];
            if(typeInString(temp.GetTokenType()) == "ERR")
            {
                if(errInString == true)
                {
                    std::cout << "Error on line " << temp.GetLinenum() << " (\"" << temp.GetLexeme() << ")\n";
                    found_error = true;
                    break;
                }
                else
                {
                    std::cout << "Error on line " << temp.GetLinenum() << " (" << temp.GetLexeme() << ")";
                    found_error = true;
                    break;
                }
            }
        }
    }
}

string typeInString(int enumeratorVal)
{
    switch(enumeratorVal)
    {
    case 0:
        return "SET";
        break;
    case 1:
        return "PRINT";
        break;
    case 2:
        return "VAR";
        break;
    case 3:
        return "REPEAT";
        break;
    case 4:
        return "IDENT";
        break;
    case 5:
        return "ICONST";
        break;
    case 6:
        return "SCONST";
        break;
    case 7:
        return "PLUS";
        break;
    case 8:
        return "MINUS";
        break;
    case 9:
        return "STAR";
        break;
    case 10:
        return "COLON";
        break;
    case 11:
        return "LSQ";
        break;
    case 12:
        return "RSQ";
        break;
    case 13:
        return "LPAREN";
        break;
    case 14:
        return "RPAREN";
        break;
    case 15:
        return "SC";
        break;
    case 16:
        return "ERR";
        break;
    case 17:
        return "DONE";
        break;
    }
    return "";
}
