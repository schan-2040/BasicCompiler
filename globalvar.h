#ifndef GLOBALVAR_H_INCLUDED
#define GLOBALVAR_H_INCLUDED

#include <vector>
#include "projlex.h"

extern bool vFlag;
extern bool mciFlag;
extern bool sumFlag;
extern std::vector<Token> tokenCollector;
extern string typeInString(int enumeratorVal);
extern void start();
extern std::vector< std::vector<Token> > SLIST;
#endif // GLOBALVAR_H_INCLUDED
