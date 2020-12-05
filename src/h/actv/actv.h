#ifndef _ACTV_H
#define _ACTV_H
  #include <iostream>
  #include <bitset>
  
  namespace actv{
    // 硬件码类型
    using USR_DEV_CODE = unsigned long long;
    using ACRV_CODE = unsigned long long;
    using ACRV_GROUP_CODE = unsigned short;
    USR_DEV_CODE getDevCode();
    bool activation();
  }
#endif