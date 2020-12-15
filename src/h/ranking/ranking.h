#ifndef _RANKING_H
#define _RANKING_H
#include <iostream>
#include <string>
using namespace std;
typedef struct UsrInfo
{
    string id;
    size_t exp;
} * PsrInfo;
void printRanking();
#endif