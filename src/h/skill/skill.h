#ifndef _SKILL_H
#define _SKILL_H
#include <iostream>
#include <string>
#include "../common/common.h"

using namespace std;
class Skill{
  public:
    Skill(string name, string des, atr mp, atr ap, atr dam, atr db_base, atr cool)
    :m_name(name), m_des(des), m_mp(mp), m_ap(ap), m_dam(dam), m_db_base(db_base), m_cool(cool){
      
    }
    void printSkillInfo();
    
  private:
    string m_name;
    string m_des;
    atr m_mp;      // 消耗内力
    atr m_ap;      // 消耗愤怒
    atr m_dam;     // 伤害加成
    atr m_db_base; // 基础倍数
    atr m_cool;    // 冷却时间
    
};

using SkillSys = Skill [11];


Skill* InitSkillSys();

#endif  