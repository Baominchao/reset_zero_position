#include "../include/eu_harmonic.h"
#include <iostream>
#include <vector>

// 重新上电后标零步骤
bool setOriginalPoint(int id) {
    hint32 pos = 0;
    if (HARMONIC_SUCCESS != harmonic_setHomeOffset(id, 0)) // 第一步：设置当前偏移值为0
        return false;
    if (HARMONIC_SUCCESS != harmonic_getActualPos(id, &pos)) // 第二步：获取当前位置
        return false; 
    if (HARMONIC_SUCCESS != harmonic_setHomeOffset(id, -pos)) // 第三步：写入当前位置的相反数
        return false;           
    return HARMONIC_SUCCESS == harmonic_setStoreParameters(id, 0x65766173);   // 第四步：保存至EEROM
}

int main() {
    
    if (HARMONIC_SUCCESS != harmonic_initDLL(harmonic_DeviceType_USB2CAN, harmonic_Baudrate_1000))
    {
        std::cout << "[error]test open failed!" << std::endl;
        return -1;
    }

    std::vector<int> ArmIDs = {1, 2, 3, 4, 5, 6, 7};

    for (const auto& id : ArmIDs) {
        if (!setOriginalPoint(id)) {
            std::cout << "电机置零错误，ID：" << id << std::endl;
            return 0;
        }
    }

    std::cout << "电机全部置零成功" << std::endl;

    return 0;  // main 函数返回整数
}
