#include "skill.h"


void Skill::printSkillInfo() {
  cout << this->m_name << "\t";
  cout << this->m_des << endl;
}

Skill* InitSkillSys() {
  Skill* skillSys = new Skill[11]{
    Skill("普通攻击","每个角色都用的生存技能",0,0,10,1,0),
    Skill("大力金刚指","少林绝学",10,0,50,1,1),
    Skill("云龙三观","泰山绝学",10,0,60,1,1),
    Skill("一阳指","一灯大师绝学",30,0,0,2,3),
    Skill("迎风破浪","铁掌水上漂",30,0,300,0,3),
    Skill("八卦掌","道门绝学",50,0,0,5,4),
    Skill("六合八荒","蓬莱绝学",50,0,500,0,4),
    Skill("仙人指路","仙道绝学",100,0,0,10,6),
    Skill("横扫千军","武极绝学",100,0,50,2,6),
    Skill("气吞山河","必杀",0,100,500,5,0),
    Skill("秋风刀法","必杀",0,100,200,10,0),
  };

  return skillSys;
}