#include "actv.h"
using namespace std;

namespace actv{
  // 本地验证码，用户硬件码 异或 激活码的结果
  ACRV_CODE locCode{0x15c77f3e675e3e99};
  USR_DEV_CODE getDevCode() {
    // 用户的硬件码，从硬件获取 占时定为
    return 930529060092641281;
  }
  bool activation() {
    using namespace actv;
    USR_DEV_CODE ucode{getDevCode()};

    ACRV_GROUP_CODE acode_arr[6]{ 0x192E, 0x987E, 0x675E, 0x3E98, 0x9172, 0x972E };
    // size_t len = sizeof(acode_arr) / sizeof(acode_arr[0]);
    // for (size_t i = 0; i < len;)
    // {
    //   cout << "请输入激活段" << i + 1 << endl;
    //   cin >> hex >> acode_arr[i];
    //   ++i;
    // }

    ACRV_CODE acode{};
    ACRV_CODE tempcode{};
    // 激活码组合
    tempcode |= acode_arr[0];
    tempcode <<= 48;
    acode |= tempcode;
    tempcode = 0;
    tempcode |= acode_arr[1];
    tempcode <<= 32;
    acode |= tempcode;
    tempcode = 0;
    tempcode |= acode_arr[2];
    tempcode <<= 16;
    acode |= tempcode;
    acode |= acode_arr[3];

    // 激活结果
    bool is_acrv = (locCode ^ acode) == ucode;


    // 获取礼包
    // 金币 幸运值 武器 护甲 首饰 武器强化 护甲强化 首饰强化
    if(is_acrv) {
      // 激活成功即获取礼包
      unsigned int giftTemp{};
      giftTemp |= acode_arr[4];
      giftTemp >>= 12;
      cout << "获取礼包金币：" << giftTemp * 1000 << endl;

      giftTemp = 0;
      giftTemp |= acode_arr[4];
      giftTemp >>= 8;
      cout << "获取幸运等级：" <<  (giftTemp & 0xF) << endl;

      giftTemp = 0;
      giftTemp |= acode_arr[4];
      giftTemp >>= 4;
      cout << "获取武器等级：" <<  (giftTemp & 0xF) << endl;

      cout << "获取护甲等级：" <<  (acode_arr[4] & 0xF) << endl;

      giftTemp = 0;
      giftTemp |= acode_arr[5];
      giftTemp >>= 12;
      cout << "获取首饰等级：" << (giftTemp & 0xF) << endl;

      giftTemp = 0;
      giftTemp |= acode_arr[5];
      giftTemp >>= 8;
      cout << "获取武器强化等级：" <<  (giftTemp & 0xF) << endl;

      giftTemp = 0;
      giftTemp |= acode_arr[5];
      giftTemp >>= 4;
      cout << "获取护甲强化等级：" <<  (giftTemp & 0xF) << endl;

      cout << "获取首饰华强等级：" <<  (acode_arr[5] & 0xF) << endl;
    }
   
    
    // 激活码验证
    return is_acrv;
  }
}



