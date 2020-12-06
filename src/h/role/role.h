
#ifndef _ROLE_H
#define _ROLE_H
  #include <iostream>
  #include <string>
  #include <stdio.h>
  using namespace std;
  enum class RoleType: int{
    usr,
    npc
  };
  using ATR_TYPE = unsigned int; 
  class Role{
    public:
      Role(string n, ATR_TYPE hp, ATR_TYPE sp, ATR_TYPE a):name(n), MAX_HP(hp),HP(hp),MAX_SP(sp),SP(sp),A(a), ROLE_TYPE((RoleType)1){}
      Role(string n, ATR_TYPE hp, ATR_TYPE sp, ATR_TYPE a, RoleType type):name(n), MAX_HP(hp),HP(hp),MAX_SP(sp),SP(sp),A(a), ROLE_TYPE(type){}
      void printStatus();
      string attack(Role&);
      bool isGameOver();
      string getRoleType();
      string skill(Role&);
    private:
      string name;
      ATR_TYPE MAX_HP;
      ATR_TYPE HP;
      ATR_TYPE MAX_SP;
      ATR_TYPE SP;
      ATR_TYPE A;
      RoleType ROLE_TYPE;
      ATR_TYPE AC_BUFF;
      ATR_TYPE SUCK_SP_BUFF;
      ATR_TYPE SUCK_HP_BUFF;
      ATR_TYPE YJJ_BUFF;
  };
#endif
