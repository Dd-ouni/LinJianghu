#include "ranking.h"
#include <vector>

void printRanking()
{
    string data{"id=TomyCkare;exp=9523;id=Sunny;exp=9523;id=DyBaby;exp=25301;id=Simple;exp=25301;id=Bkacs11;exp=2100;id=DumpX;exp=36520;"},
        idfield{"id="},
        expfield{"exp="};
    size_t idsize{(size_t)idfield.size()},
        expsize{(size_t)expfield.size()};
    vector<PUsrInfo> usrInfoList;

    size_t idpos = 0,
           idendpos = 0,
           exppos = 0,
           expendpos = 0;

    

    while (data[expendpos+1] != 0)
    {
        idpos = data.find(idfield, expendpos) + idsize;
        idendpos = (size_t)data.find(";", idpos);
        exppos = data.find(expfield, idendpos) + expsize;
        expendpos = (size_t)data.find(";", exppos);
        usrInfoList.push_back(new UsrInfo{data.substr(idpos, idendpos - idpos), stoul(data.substr(exppos, expendpos - exppos))});
    }


    for (size_t i = 0, count = usrInfoList.size(); i < count; i++)
    {
        
    }
    
    

    for(auto item: usrInfoList){
        cout << "id：" << item->id << " exp：" << item->exp << endl;
    }

  
}