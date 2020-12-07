#include "combat.h"

namespace combat
{
  void printCombatInfo(string *info)
  {
    if (info[0].size())
    {
      cout << info[0] << endl;
    }

    if (info[1].size())
    {
      cout << info[1] << endl;
    }
  }
  void OneVsOne(Role &usr, Role &boss)
  {
    string combatInfo[2]{};
  combat:
    // system("clear");
    // 打印角色信息
    boss.printStatus();
    usr.printStatus();
    // 打印战斗信息
    printCombatInfo(combatInfo);
    // 开始战斗
    combatInfo[0] = usr.attack(boss);
    combatInfo[1] = boss.attack(usr);

    if (!usr.isGameOver() && !boss.isGameOver())
    {
      goto combat;
    }
  }
} // namespace combat