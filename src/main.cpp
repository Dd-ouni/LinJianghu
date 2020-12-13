#include <iostream>
#include <string>
#include "h/skill/skill.h"
#include "h/role/role.h"
#include "h/combat/combat.h"
#include <stdio.h>
using namespace std;
using namespace combat;

void testComBat()
{
  Skill* skillSys{ InitSkillSys() };
  Role SunWuKong{ "孙悟空", 3000, 1000, 50, new Skill[5]{
    skillSys[0],
    skillSys[1],
    skillSys[3],
    skillSys[5],
    skillSys[9]
  }, (RoleType) 0 };
  

  Role BiKe{"比克", 2600, 1000, 50, new Skill[5]{
    skillSys[0],
    skillSys[2],
    skillSys[4],
    skillSys[6],
    skillSys[10]
  }};

  OneVsOne(SunWuKong, BiKe);

  delete skillSys;
}

// void testInitSkillSys() {
//   SkillSys* skillSys{ InitSkillSys() };
//   (*skillSys[0])->printSkillInfo();

  
// }

int main()
{
  system("cls");
  string game_name{"Lin Jiang hu"};
  cout << "hello " << game_name << endl;
  testComBat();
  // testInitSkillSys();
  return 0;
}
