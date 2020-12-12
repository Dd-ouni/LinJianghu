#ifndef _SKILL_H
#define _SKILL_H

#include <string>
using namespace std;
class skill{
  public:
    skill(string name, string des, size_t mp, size_t ap, size_t dam, bool base, size_t db_base, size_t cool)
    :m_name(name), m_des(des), m_mp(mp), m_ap(ap), m_dam(dam), m_is_base(base), m_db_base(db_base), m_cool(cool){
      
    }
  private:
    string m_name;
    string m_des;
    size_t m_mp;      // 消耗内力
    size_t m_ap;      // 消耗愤怒
    size_t m_dam;     // 伤害加成
    bool m_is_base;   // 是否附带基础攻击
    size_t m_db_base; // 基础倍数
    size_t m_cool;    // 冷却时间
    
};

#endif  