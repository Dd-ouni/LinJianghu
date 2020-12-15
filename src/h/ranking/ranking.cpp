#include "ranking.h"
#include <vector>

void printRanking()
{
    string data{"id=TomyCkare;exp=9523;id=Sunny;exp=9523;id=DyBaby;exp=25301;id=Simple;exp=25301;id=Bkacs11;exp=2100;id=DumpX;exp=36520;"},
        idfield{"id="},
        expfield{"exp="};
    size_t idsize{(size_t)idfield.size()},
        expsize{(size_t)expfield.size()};
    vector<UsrInfo> usrInfoList;

    while (data.size())
    {
        size_t idpos = data.find(idfield) + idsize,
               idendpos = (size_t)data.find(";"),
               exppos = data.find(expfield) + expsize,
               expendpos = (size_t)data.find(";", exppos);

        cout << data.substr(idpos, idendpos - idpos) << endl;
        cout << data.substr(exppos, expendpos - exppos) << endl;

        data.erase(0, expendpos + 1);
        cout << data << endl;
    }
}