#include "role.h"

string Role::getRoleTypeDes()
{
  return this->m_role_type == (RoleType)0 ? "玩家" : "NPC";
}

Skill& Role::getSkill(size_t i) {
  return this->m_skill_sys[i];
}

void Role::printSkill() {
  cout << "角色：" << this->getRoleTypeDes() << " 技能：";
  for (size_t i = 0; i < 5; i++)
  {
    cout << endl;
    this->m_skill_sys[i].printSkillInfo();
  }
  cout << endl;
}

void Role::printRoleStat()
{
  cout << "角色：";
  cout << "\t";
  cout << this->getRoleTypeDes();
  cout << "\t";
  cout << "名称：" << this->m_name;
  cout << "\t";
  cout << "HP：[" << this->m_max_hp << "/" << this->m_hp << "]";
  cout << "\t";
  cout << "MP：[" << this->m_max_mp << "/" << this->m_mp << "]";
  cout << "\t";
  cout << "AP：[" << this->m_max_ap << "/" << this->m_ap << "]";
  cout << "\t";
  cout << "DAM：" << this->m_dam << endl;
}

bool Role::isGameOver()
{
  if (this->m_hp <= 0)
  {
    cout << "游戏结束：";
    cout << "\t";
    cout << this->getRoleTypeDes();
    cout << "\t";
    cout << this->m_name << "阵亡" << endl;
    return true;
  }
  return false;
}


void Role::printLv() {
  for (size_t lv{1}; lv <= this->m_max_lv; lv++)
  {
    cout << setfill(' ');
    cout << "\n等级：" << setw(3) << lv << "\t" << setw(10) << lv * lv * 100;
  }
  cout << endl;
  system("pause");
}

// string Role::attack(Role &that)
// {
//   // 根据角色发动不一样的攻击
//   /*
//     玩家可以选技能攻击
//     NPC只能已攻击力攻击
//   */
//   if (this->ROLE_TYPE == (RoleType)0)
//   {
//     // 玩家攻击
//     ATR_TYPE harm{};
//     string skillStr{};
//     int skillVal;

// reHandle:
//     cout << "请选择释放的技能：" << endl;
//     cout << "0 普通攻击" << endl;
//     cout << "1 治愈\t"
//          << "消耗100内里声明回复最大生命值的10%" << endl;
//     cout << "2 金刚掌\t"
//          << "消耗50内力对目标造成基础攻击+50的伤害" << endl;
//     cout << "3 麻痹术\t"
//          << "消耗50内力进制目标攻击三个回合" << endl;
//     cout << "4 鹰抓功\t"
//          << "10个回合内，对目标造成伤害将回复伤害量20%的内力伤害量60%的生命" << endl;
//     cout << "5 绝处逢生\t"
//          << "消耗100内力对目标造成基础攻击+已损失血量的伤害" << endl;
//     cout << "6 易筋经\t"
//          << "消耗300内力 内力和生命值互换 攻击力提高 1000%" << endl;
//     cout << "b 必杀技\t"
//          << "绝命连招" << endl;
//     cout << "l 等级信息\t" << endl;
//     // int skillVal = _getch();
//     // 不用清除回车键

//     skillVal = getchar();
//     getchar();
//     // 主要作用清除getchar 回车
//     cout << "skillVal " << skillVal << endl;

//     switch (skillVal)
//     {
//     case 48:
//       skillStr = "普通攻击";
//       harm = this->getA();
//       cout << harm << endl;
//       that.HP = that.HP < harm ? 0 : that.HP - harm;
      
//       break;
//     case 49:
//       if (this->SP >= 100)
//       {
//         skillStr = "治愈";
//         this->SP -= 100;
//         this->HP += this->HP / 10;
//         this->HP = this->HP > this->MAX_HP ? this->MAX_HP : this->HP;
//       }
//       else
//       {
//         skillStr = "治愈失败";
//       }
//       harm = 0;
//       break;
//     case 50:
//       if (this->SP >= 50)
//       {
//         skillStr = "金刚掌";
//         this->SP -= 50;
//         this->JGZ_BUFF = 1;
//         harm = this->getA();
//         that.HP = that.HP < harm ? 0 : that.HP - harm;
//       }
//       else
//       {
//         skillStr = "金刚掌失败";
//         harm = 0;
//       }
//       break;
//     case 51:
//       if (this->SP >= 50)
//       {
//         skillStr = "麻痹术";
//         this->SP -= 50;
//         that.MB_BUFF = 3;
//       }
//       else
//       {
//         skillStr = "麻痹术失败";
//       }
//       harm = 0;
//       break;
//     case 52:
//       skillStr = "鹰抓功";
//       this->SUCK_HP_BUFF = 10;
//       this->SUCK_SP_BUFF = 10;
//       harm = 0;
//       break;
//     case 53:
//       if (this->SP >= 100)
//       {
//         skillStr = "绝处逢生";
//         this->SP -= 100;
//         this->JCFS_BUFF = 1;
//         harm = this->getA();
//         that.HP = that.HP < harm ? 0 : that.HP - harm;
        
//       }
//       else
//       {
//         skillStr = "绝处逢生失败";
//         harm = 0;
//       }
//       break;
//     case 54:
//       if (this->SP >= 300 || this->YJJ_BUFF == 0)
//       {
//         skillStr = "易筋经";
//         this->SP -= 300;
//         ATR_TYPE temp = this->HP;
//         this->HP = this->SP;
//         this->HP = temp;
//         this->YJJ_BUFF = 1;
//       }
//       else
//       {
//         skillStr = "易筋经失败";
//       }
//       harm = 0;
//       break;
//     case 'b':
//         skillStr = "必杀技";
//         this->BSJ_BUFF = 1;
//         harm = this->getA();
//         that.HP = that.HP < harm ? 0 : that.HP - harm;
//       break;

//     case 'L':
//       this->printLv();
//       goto reHandle;
//     case 'l':
//       this->printLv();
//       goto reHandle;
//     default:
//       skillStr = "操作失败";
//       harm = 0;
//     }

//     return "玩家：" + this->name + "发动技能[" + skillStr + "]," + that.name + " 损失HP：" + to_string(harm);
//   }
//   else
//   {
//     // NPC攻击
//     ATR_TYPE harm{this->getA()};
//     that.HP = that.HP < harm ? 0 : that.HP - harm;
//     return "NPC：" + this->name + "发动攻击，" + that.name + " 损失HP：" + to_string(harm);
//   }
// }