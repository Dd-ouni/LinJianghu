
#ifndef _ROLE_H
#define _ROLE_H
  #include <iostream>
  #include <string>
  #include "../common/common.h"
  #include "../skill/skill.h"
  #include <conio.h>
  #include <stdio.h>
  #include <iomanip>
  using namespace std;
  enum class RoleType: int{
    usr,
    npc
  };
  using RoleSkillStat = int[5][2];
  // 5个技能 每个技能的 0 是否可以使用 1 冷却时间
  using RoleSkillSys = Skill* [5];

  class Role{
    public:
      Role(string name, atr hp, atr mp, atr dam,Skill* role_skill, RoleType role_type = (RoleType)1)
      :m_name(name), m_max_hp(hp), m_hp(hp), m_max_mp(mp), m_mp(mp), m_dam(dam), m_role_type(role_type){
        this->m_skill_stat = (RoleSkillStat*) new RoleSkillStat{
          {1, 0},
          {1, 0},
          {1, 0},
          {1, 0},
          {1, 0}
        };
        this->m_max_lv = 100;
        this->m_lv = 1;
        this->m_max_ap = 100;
        this->m_ap = 0;
        this->m_skill_sys = role_skill;
      }
     
      void printRoleStat();
      void printLv();
      void printSkill();
      bool isGameOver();
      Skill& getSkill(size_t);
      string getRoleTypeDes();
    private:
      string m_name;
      atr m_max_lv;
      atr m_lv;
      atr m_max_hp;
      atr m_hp;
      atr m_max_mp;
      atr m_mp;
      atr m_max_ap;
      atr m_ap;
      atr m_dam;
      RoleType m_role_type;
      Skill* m_skill_sys;
      RoleSkillStat* m_skill_stat;
  };
#endif
