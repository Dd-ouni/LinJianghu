#include <iostream>
#include <string>
#include "h/role/role.h"
#include "h/combat/combat.h"
#include <stdio.h>
using namespace std;
using namespace combat;

void testComBat()
{
  Role SunWuKong{"孙悟空", 3000, 1000, 50, (RoleType)0};
  Role BiKe{"比克", 10000, 10000, 200};
  OneVsOne(SunWuKong, BiKe);
}

int main()
{

  string game_name{"Lin Jiang hu"};
  cout << "hello " << game_name << endl;
  testComBat();
  return 0;
}
