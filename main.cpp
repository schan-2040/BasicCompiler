#include <iostream>
#include <fstream>
#include <sstream>
#include "projlex.h"
#include "globalvar.h"
using namespace std;

bool vFlag;
bool mciFlag;
bool sumFlag;
bool file_exists;

Token getNextToken(istream *in, int* linenum);
int main(int argc, char* argv[])
{
    vFlag = false;
    mciFlag = false;
    sumFlag = false;
    file_exists = false;

    ifstream file;
    if (argc < 2)
    {
        cout <<"Nothing has been entered." << endl;
    }
    else
    {
        string arg;
        for(int i = 1; i < argc; i++)
        {
            arg = argv[i];
            if(arg == "-v")
            {
                vFlag = true;
            }
            else if(arg == "-mci")
            {
                mciFlag = true;
            }
            else if(arg == "-sum")
            {
                sumFlag = true;
            }
            else
            {
                if(arg[0] == '-')
                {
                    cout << "INVALID FLAG " << arg << endl;
                    return -1;
                }
                else
                {
                    file.open(arg);
                    if(file.is_open() == false)
                    {
                        cout << "COULD NOT OPEN " << arg << endl;
                        return -1;
                    }
                    else if(file.is_open() == true)
                    {
                        if(file_exists == false)
                        {
                            file_exists = true;
                        }
                        else
                        {
                            cout << "TOO MANY FILENAMES\n";
                            return -1;
                        }
                    }
                }
            }
        }
    }
        istream *in = &file;
        int line = 0;
        int* lineNumber = &line;

        getNextToken(in, lineNumber);
        start();
        return 0;
}
