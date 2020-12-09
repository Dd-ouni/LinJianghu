
#ifndef _ROLE_H
#define _ROLE_H
  #include <iostream>
  #include <string>
  #include <conio.h>
  #include <stdio.h>
  #include <iomanip>
  using namespace std;
  enum class RoleType: int{
    usr,
    npc
  };
  using ATR_TYPE = unsigned int; 
  class Role{
    public:
      Role(string n, ATR_TYPE hp, ATR_TYPE sp, ATR_TYPE a):name(n), MAX_HP(hp),HP(hp),MAX_SP(sp),SP(sp),A(a), ROLE_TYPE((RoleType)1){
        this->MB_BUFF = 0;
        this->SUCK_HP_BUFF = 0;
        this->SUCK_SP_BUFF = 0;
        this->YJJ_BUFF = 0;
        this->JGZ_BUFF = 0;
        this->JCFS_BUFF = 0;
        this->BSJ_BUFF = 0;
        this->MAX_LV = 100;
      }
      Role(string n, ATR_TYPE hp, ATR_TYPE sp, ATR_TYPE a, RoleType type):name(n), MAX_HP(hp),HP(hp),MAX_SP(sp),SP(sp),A(a), ROLE_TYPE(type){
        this->MB_BUFF = 0;
        this->SUCK_HP_BUFF = 0;
        this->SUCK_SP_BUFF = 0;
        this->YJJ_BUFF = 0;
        this->JGZ_BUFF = 0;
        this->JCFS_BUFF = 0;
        this->BSJ_BUFF = 0;
        this->MAX_LV = 100;
      }
      void printStatus();
      void printLv();
      string attack(Role&);
      bool isGameOver();
      string getRoleType();
      string skill(Role&);
      ATR_TYPE getA();
    private:
      string name;
      ATR_TYPE MAX_HP;
      ATR_TYPE HP;
      ATR_TYPE MAX_SP;
      ATR_TYPE SP;
      ATR_TYPE A;
      RoleType ROLE_TYPE;
      ATR_TYPE MB_BUFF;
      ATR_TYPE SUCK_SP_BUFF;
      ATR_TYPE SUCK_HP_BUFF;
      ATR_TYPE YJJ_BUFF;
      ATR_TYPE JGZ_BUFF;
      ATR_TYPE JCFS_BUFF;
      ATR_TYPE MAX_LV;
      ATR_TYPE BSJ_BUFF;
  };
#endif
