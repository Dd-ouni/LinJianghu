#include "role.h"

string Role::getRoleType()
{
  return this->ROLE_TYPE == (RoleType)0 ? "玩家" : "NPC";
}

void Role::printStatus()
{
  cout << "角色：";
  cout << "\t";
  cout << this->getRoleType();
  cout << "\t";
  cout << "名称：" << this->name;
  cout << "\t";
  cout << "[" << this->MAX_HP << "/" << this->HP << "]";
  cout << "\t";
  cout << "[" << this->MAX_SP << "/" << this->SP << "]";
  cout << "\t";
  cout << "A：" << this->A << endl;
}

bool Role::isGameOver()
{
  if (this->HP <= 0)
  {
    cout << "游戏结束：";
    cout << "\t";
    cout << this->getRoleType();
    cout << "\t";
    cout << this->name << "阵亡" << endl;
    return true;
  }
  return false;
}

string Role::attack(Role &that)
{
  // 根据角色发动不一样的攻击
  /*
    玩家可以选技能攻击
    NPC只能已攻击力攻击
  */
  if (this->ROLE_TYPE == (RoleType)0)
  {
    // 玩家攻击
    int harm{};
    string skillStr{};

    cout << "请选择释放的技能：" << endl;
    cout << "0 普通攻击" << endl;
    cout << "1 治愈\t"
         << "消耗100内里声明回复最大生命值的10%" << endl;
    cout << "2 金刚掌\t"
         << "消耗50内力对目标造成基础攻击+50的伤害" << endl;
    cout << "3 麻痹术\t"
         << "消耗50内力进制目标攻击三个回合" << endl;
    cout << "4 鹰抓功\t"
         << "10个回合内，对目标造成伤害将回复伤害量25%的内力伤害量50%的生命" << endl;
    cout << "5 绝处逢生\t"
         << "消耗100内力对目标造成基础攻击+已损失血量的伤害" << endl;
    cout << "6 易筋经\t"
         << "消耗300内力 内力和生命值互换 攻击力提高 1000%" << endl;

    int skillVal = getchar();
    getchar();
    // 主要作用清除getchar 回车
    cout << "skillVal " << skillVal << endl;

    switch (skillVal)
    {
    case 48:
      skillStr = "普通攻击";
      that.HP = that.HP < this->A ? 0 : that.HP - this->A;
      harm = this->A;
      break;
    case 49:
      if (this->SP >= 100)
      {
        skillStr = "治愈";
        this->SP -= 100;
        this->HP += this->HP / 10;
        this->HP = this->HP > this->MAX_HP ? this->MAX_HP : this->HP;
      }
      else
      {
        skillStr = "治愈失败";
      }
      harm = 0;
      break;
    case 50:
      if (this->SP >= 50)
      {
        skillStr = "金刚掌";
        this->SP -= 50;
        that.HP = that.HP < (this->A + 50) ? 0 : that.HP - (this->A + 50);
        harm = this->A + 50;
      }
      else
      {
        skillStr = "金刚掌失败";
        harm = 0;
      }
      break;
    case 51:
      if (this->SP >= 50)
      {
        skillStr = "麻痹术";
        this->SP -= 50;
        that.AC_BUFF = 3;
      }
      else
      {
        skillStr = "麻痹术失败";
      }
      harm = 0;
      break;
    case 52:
      skillStr = "鹰抓功";
      this->SUCK_HP_BUFF = 10;
      this->SUCK_SP_BUFF = 10;
      harm = 0;
      break;
    case 53:
      if (this->SP >= 100)
      {
        skillStr = "绝处逢生";
        this->SP -= 100;
        that.HP = that.HP < (this->A + (this->MAX_HP - this->HP)) ? 0 : that.HP - (this->A + (this->MAX_HP - this->HP));
        harm = this->A + (this->MAX_HP - this->HP);
      }
      else
      {
        skillStr = "绝处逢生失败";
        harm = 0;
      }
      break;
    case 54:
      if (this->SP >= 300 || this->YJJ_BUFF == 0)
      {
        skillStr = "易筋经";
        this->SP -= 300;
        ATR_TYPE temp = this->HP;
        this->HP = this->SP;
        this->HP = temp;
        this->A *= 1000;
      }
      else
      {
        skillStr = "易筋经失败";
      }
      harm = 0;
      break;
    }

    return "玩家：" + this->name + "发动技能[" + skillStr + "]," + that.name + " 损失HP：" + to_string(harm);
  }
  else
  {
    // NPC攻击
    cout << "NPC 攻击1 " << this->A << " " << that.HP << endl;
    if (that.HP < this->A)
    {
      that.HP = 0;
    }
    else
    {
      that.HP -= this->A;
    }
    cout << "NPC 攻击2 " << that.HP << endl;
    // that.HP = that.HP < this->A ? 0 : that.HP - this->A;
    return "NPC：" + this->name + "发动攻击，" + that.name + " 损失HP：" + to_string(this->A);
  }
}