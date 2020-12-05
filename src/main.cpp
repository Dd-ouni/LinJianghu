#include <iostream>
#include <string>
#include "h/actv/actv.h"
using namespace std;
using namespace actv;
int main()
{
  system("cls");
  string game_name{"麟江湖"};
  cout << "hello " << game_name << endl;
  cout << (activation()?"激活成功":"激活失败") << endl;
  return 0;
}
