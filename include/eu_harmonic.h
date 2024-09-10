#ifndef EU_HARMONIC_H
#define EU_HARMONIC_H

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef EXTERNFUNC
#ifdef _WIN32
#define EXTERNFUNC __declspec(dllexport)
#else
#define EXTERNFUNC
#endif
#endif

#ifdef _WIN32
    typedef char hint8;
    typedef short hint16;
    typedef long hint24;
    typedef long hint32;
    typedef long long hint40;
    typedef long long hint48;
    typedef long long hint56;
    typedef long long hint64;
    typedef unsigned char huint8;
    typedef unsigned short huint16;
    typedef unsigned long huint24;
    typedef unsigned long huint32;
    typedef unsigned long long huint40;
    typedef unsigned long long huint48;
    typedef unsigned long long huint56;
    typedef unsigned long long huint64;
    typedef float hreal32;
    typedef double hreal64;
#else
typedef signed char hint8;
typedef signed short int hint16;
typedef signed int hint24;
typedef signed int hint32;
typedef signed long int hint40;
typedef signed long int hint48;
typedef signed long int hint56;
typedef signed long int hint64;
typedef unsigned int huint8 __attribute__((__mode__(__QI__)));
typedef unsigned int huint16 __attribute__((__mode__(__HI__)));
typedef unsigned int huint24 __attribute__((__mode__(__SI__)));
typedef unsigned int huint32 __attribute__((__mode__(__SI__)));
typedef unsigned int huint40 __attribute__((__mode__(__DI__)));
typedef unsigned int huint48 __attribute__((__mode__(__DI__)));
typedef unsigned int huint56 __attribute__((__mode__(__DI__)));
typedef unsigned int huint64 __attribute__((__mode__(__DI__)));
typedef float hreal32;
typedef double hreal64;
#endif

#define HARMONIC_SUCCESS (0)               /**< 执行成功 */
#define HARMONIC_FAILED_DEVICEDISABLED (1) /**< 执行失败，设备不存在 */
#define HARMONIC_FAILED_OPENFAILED (2)     /**< 执行失败，设备打开失败 */
#define HARMONIC_FAILED_UNKNOWN (3)        /**< 执行失败，未知原因 */

    /*!
        设备类型
    */
    enum harmonic_DeviceType
    {
        harmonic_DeviceType_USB2CAN = 4, /**< 创芯usb转can设备 */
        harmonic_DeviceType_Canable = 11 /**< 意优canable设备 */
    };

    /*!
        波特率
    */
    enum harmonic_Baudrate
    {
        harmonic_Baudrate_10 = 10,    /**< 波特率10 */
        harmonic_Baudrate_20 = 20,    /**< 波特率20 */
        harmonic_Baudrate_50 = 50,    /**< 波特率50 */
        harmonic_Baudrate_100 = 100,  /**< 波特率100 */
        harmonic_Baudrate_250 = 250,  /**< 波特率250 */
        harmonic_Baudrate_500 = 500,  /**< 500波特率 */
        harmonic_Baudrate_1000 = 1000 /**< 1000波特率 */
    };

    /*!
        NMT状态
    */
    enum harmonic_NMTState
    {
        harmonic_NMTState_Start_Node = 0x01,
        harmonic_NMTState_Stop_Node = 0x02,
        harmonic_NMTState_Enter_PreOperational = 0x80,
        harmonic_NMTState_Reset_Node = 0x81,
        harmonic_NMTState_Reset_Comunication = 0x82
    };

    /*!
        节点状态
    */
    enum harmonic_NodeState
    {
        harmonic_NodeState_Initialisation = 0x00,  /**< 初始化状态 */
        harmonic_NodeState_Disconnected = 0x01,    /**< 掉线状态 */
        harmonic_NodeState_Connecting = 0x02,      /**< 在线状态 */
        harmonic_NodeState_Preparing = 0x02,       /**< 准备状态 */
        harmonic_NodeState_Stopped = 0x04,         /**< 停止状态 */
        harmonic_NodeState_Operational = 0x05,     /**< 操作状态 */
        harmonic_NodeState_Pre_operational = 0x7F, /**< 预操作状态 */
        harmonic_NodeState_Unknown_state = 0x0F    /**< 未知状态 */
    };

    /*!
        数据类型
    */
    enum harmonic_DataType
    {
        harmonic_DataType_boolean = 0x01, /**< 布尔类型 */
        harmonic_DataType_int8 = 0x02,    /**< 1字节有符号整形 */
        harmonic_DataType_int16 = 0x03,   /**< 2字节有符号整形 */
        harmonic_DataType_int32 = 0x04,   /**< 4字节有符号整形 */
        harmonic_DataType_uint8 = 0x05,   /**< 1字节无符号整形 */
        harmonic_DataType_uint16 = 0x06,  /**< 2字节无符号整形 */
        harmonic_DataType_uint32 = 0x07,  /**< 4字节无符号整形 */
        harmonic_DataType_real32 = 0x08   /**< 4字节浮点型 */
    };

    enum harmonic_QuickStopOption
    {
        harmonic_QuickStopOption_Disable_Drive = 0,
        harmonic_QuickStopOption_Slow_Down_On_Slow_Down_Ramp = 1,
        harmonic_QuickStopOption_Slow_Down_On_Quick_Stop_Ramp = 2,
        harmonic_QuickStopOption_Slow_Down_On_the_Current_Limit = 3,
        harmonic_QuickStopOption_Slow_Down_On_the_Voltag_Limit = 4,
        harmonic_QuickStopOption_Slow_Down_On_Quick_Stop_Ramp_And_Stay_In_Quick_Stop = 5,
        harmonic_QuickStopOption_Slow_Down_On_Slow_Down_Ramp_And_Stay_In_Quick_Stop = 6,
        harmonic_QuickStopOption_Slow_Down_On_the_Current_Limit_And_Stay_In_Quick_Stop = 7,
        harmonic_QuickStopOption_Slow_Down_On_the_Voltag_Limit_And_Stay_In_Quick_Stop = 8
    };

    enum harmonic_ShutdownOption
    {
        harmonic_ShutdownOption_Disable_Drive_Function = 0,
        harmonic_ShutdownOption_Slown_With_Slow_Down_Ramp = 1
    };

    enum harmonic_DisableOperationOption
    {
        harmonic_DisableOperationOption_Disable_Drive_Function = 0,
        harmonic_DisableOperationOption_Slow_Down_With_Slow_Down_Ramp = 1
    };

    enum harmonic_HaltOption
    {
        harmonic_HaltOption_Disable_Drive = 0,
        harmonic_HaltOption_Slow_Down_On_Slow_Down_Ramp = 1,
        harmonic_HaltOption_Slow_Down_On_Quick_Stop_Ramp = 2,
        harmonic_HaltOption_Slow_Down_On_the_Current_Limit = 3,
        harmonic_HaltOption_Slow_Down_On_the_Voltag_Limit = 4
    };

    enum harmonic_FaultReactionOption
    {
        harmonic_FaultReactionOption_Disable_drive_function = 0,
        harmonic_FaultReactionOption_Slow_down_on_slow_down_ramp = 1,
        harmonic_FaultReactionOption_Slow_down_on_quick_stop_ramp = 2,
        harmonic_FaultReactionOption_Slow_down_on_current_limit = 3,
        harmonic_FaultReactionOption_Slow_down_on_voltage_limit = 4
    };

    /*!
        操作模式
    */
    enum harmonic_OperateMode
    {
        harmonic_OperateMode_AutoTuning = -4,
        harmonic_OperateMode_INLCalibration = -3,
        harmonic_OperateMode_RotorAligning = -2,
        harmonic_OperateMode_Reserve = 0,              /**< 保留的 */
        harmonic_OperateMode_ProfilePosition = 1,      /**< 轮廓位置模式 */
        harmonic_OperateMode_Velocity = 2,             /**< 速度模式 */
        harmonic_OperateMode_ProfileVelocity = 3,      /**< 轮廓速度模式 */
        harmonic_OperateMode_ProfileTorque = 4,        /**< 轮廓力矩模式 */
        harmonic_OperateMode_Homing = 6,               /**< 归航模式 */
        harmonic_OperateMode_InterpolatedPosition = 7, /**< 内插位置模式 */
        harmonic_OperateMode_CyclicSyncPosition = 8,   /**< 同步位置模式 */
        harmonic_OperateMode_CyclicSyncVelocity = 9,   /**< 同步速度模式 */
        harmonic_OperateMode_CyclicSyncTorque = 10     /**< 同步力矩模式 */
    };

    /*!
        can数据结构
    */
    typedef struct _harmonic_CanMsg
    {
        huint16 cob_id; /**< message's ID */
        huint8 rtr;     /**< remote transmission request. (0 if not rtr message, 1 if rtr message) */
        huint8 len;     /**< message's length (0 to 8) */
        huint8 data[8]; /**< message's datas */
    } harmonic_CanMsg;

    /*!
        发送数据回调函数
    */
    typedef void (*harmonic_SendDataCallBack)(const harmonic_CanMsg &msg);

    /*!
        接收数据回调函数
    */
    typedef void (*harmonic_ReceiveDataCallBack)(const harmonic_CanMsg &msg);

    /*!
        设置发送数据回调函数
        \param callFunc 回调函数.
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSendDataCallBack(harmonic_SendDataCallBack callFunc);

    /*!
        设置接收数据回调函数
        \param callFunc
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setReceiveDataCallBack(harmonic_ReceiveDataCallBack callFunc);

    /*!
        初始化dll，在调用所有函数前，必须先调用该函数进行初始化，该函数会打开设备。
        \param devType 设备类型，参见harmonic_DeviceType
        \param baudrate 波特率，参见harmonic_Baudrate
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_initDLL(harmonic_DeviceType devType, harmonic_Baudrate baudrate);

    /*!
        关闭设备，释放资源，设备打开成功后需要在适当时机释放资源
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_freeDLL();

    /*!
        读从节点状态
        \param id 从节点id
        \param state 保存读取的从节点的节点状态
        \param timeout 最大等待时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getNodeState(huint8 id, harmonic_NodeState *state, huint32 timeout = 100);

    /*!
        设置本地节点状态
        \param state 节点状态
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalNodeState(harmonic_NodeState state);

    /*!
        设置从节点状态
        \param id 从节点id
        \param state 节点状态
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setNodeState(huint8 id, harmonic_NMTState state);

    /*!
        读本地字典
        \param index 主索引
        \param subIndex 子索引
        \param dataType 数据类型
        \param readData 保存读取的数据
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_readLocalDirectory(huint16 index, huint8 subIndex, harmonic_DataType dataType, void *readData);

    /*!
        读从节点字典
        \param id 从节点id
        \param index 主索引
        \param subIndex 子索引
        \param dataType 数据类型
        \param readData 保存读取的数据
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_readDirectory(huint8 id, huint16 index, huint8 subIndex, harmonic_DataType dataType, void *readData, huint32 timeout = 100);

    /*!
        写本地字典
        \param index 主索引
        \param subIndex 子索引
        \param writeData 写入的数据
        \param sendLen 写入字节长度
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_writeLocalDirectory(huint16 index, huint8 subIndex, void *writeData, huint32 sendLen);

    /*!
        写从节点字典
        \param id 从节点id
        \param index 主索引
        \param subIndex 子索引
        \param dataType 数据类型
        \param writeData 写入的数据
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_writeDirectory(huint8 id, huint16 index, huint8 subIndex, harmonic_DataType dataType, void *writeData, huint32 timeout = 100);

    /*!
        发送原始can数据
        \param cobId can帧id
        \param data 发送的can数据
        \param len 数据长度
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_writeCanData(huint32 cobId, const huint8 *const data, huint8 len);

    /*!
        轮廓位置控制，该模式下电机内部根据给定参数生成轨迹并执行
        \param id 从节点id
        \param targetPos 目标位置，单位脉冲
        \param vel 速度，单位脉冲
        \param acc 加速度，单位脉冲
        \param dec 减速度，单位脉冲
        \param isRelative 是否采用相对位置，true:采用相对位置，false:采用绝对位置
        \param isImmediately 该函数的调用是否立即生效，true:立即生效，false:如果前一次指令没有运行到位，继续执行前一次指令，执行完毕后再执行当前指令
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_profilePositionControl(huint8 id, hint32 targetPos, huint32 vel, huint32 acc, huint32 dec, bool isRelative = false, bool isImmediately = true, bool isUpdate = false);

    /*!
        轮廓速度控制，该模式下电机内部根据给定参数生成轨迹并执行
        \param id 从节点id
        \param targetVel 目标速度，单位脉冲
        \param acc 加速度，单位脉冲
        \param dec 减速度，单位脉冲
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_profileVelocityControl(huint8 id, hint32 targetVel, huint32 acc, huint32 dec, bool isUpdate = false);

    /*!
        轮廓力矩控制，该模式下电机内部根据给定参数生成轨迹并执行
        \param id 从节点id
        \param targetTorque 目标力矩，单位千分之
        \param slope 增长斜率，单位千分之/s
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_profileTorqueControl(huint8 id, huint16 targetTorque, hint16 slope, bool isUpdate = false);

    /*!
        插补位置模式，该模式下，软件内部根据给定参数生成轨迹，并按照设定的插补周期，不断下发给电机。如果想要自己规划轨迹，该函数不适用，需要自行配置pdo通信参数等
        \param id 从节点id
        \param targetPos 目标位置，单位脉冲
        \param vel 速度，单位脉冲
        \param acc 加速度，单位脉冲
        \param dec 减速度，单位脉冲
        \param itpv 插补周期，单位ms
        \param isSync 是否采用同步模式 true:同步模式，false:非同步模式
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_interpolatePositionControl(huint8 id, hint32 targetPos, huint32 vel, huint32 acc, huint32 dec, huint8 itpv = 20, bool isSync = false, bool isUpdate = false);

    /*!
        同步位置模式，该模式下，软件内部根据更定参数生成轨迹，并按照设定的插补周期，不断下发给电机。如果想要自己规划轨迹，该函数不适用，需要自行配置pdo通信参数等
        \param id 从节点id
        \param targetPos 目标位置，单位脉冲
        \param vel 速度，单位脉冲
        \param acc 加速度，单位脉冲
        \param dec 减速度，单位脉冲
        \param itpv 插补周期，单位ms
        \param isSync 是否采用同步模式 true:同步模式，false:非同步模式
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_syncPositionControl(huint8 id, hint32 targetPos, hint32 vel, huint32 acc, huint32 dec, huint8 itpv = 20, bool isSync = false, bool isUpdate = false);

    /*!
        同步速度模式，该模式下，软件内部根据更定参数生成轨迹，并按照设定的插补周期，不断下发给电机。如果想要自己规划轨迹，该函数不适用，需要自行配置pdo通信参数等
        \param id 从节点id
        \param targetVel 目标速度，单位脉冲
        \param vel 速度，单位脉冲
        \param acc 加速度，单位脉冲
        \param dec 减速度，单位脉冲
        \param itpv 插补周期，单位ms
        \param isSync 是否采用同步模式 true:同步模式，false:非同步模式
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_syncVelocityControl(huint8 id, hint32 targetVel, huint32 acc, huint32 dec, huint8 itpv = 20, bool isSync = false, bool isUpdate = false);

    /*!
        同步力矩模式，该模式下，软件内部根据更定参数生成轨迹，并按照设定的插补周期，不断下发给电机。如果想要自己规划轨迹，该函数不适用，需要自行配置pdo通信参数等
        \param id 从节点id
        \param targetTor 目标力矩，单位脉冲
        \param slope 增长斜率
        \param itpv 插补周期，单位ms
        \param isSync 是否采用同步模式 true:同步模式，false:非同步模式
        \param isUpdate 是否采用更新模式(更新模式下，pdo通信参数不会再次配置，一般相同模式下的第一次控制设为false，后面的多次控制设为true)。true:采用更新模式，false:不采用更新模式
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_syncTorqueControl(huint8 id, hint16 targetTor, hint16 slope, huint8 itpv = 20, bool isSync = false, bool isUpdate = false);

    /*!
        停止控制
        \param id 从节点id
        \return 成功返回0，失败返回其他
     */
    EXTERNFUNC int harmonic_stopControl(huint8 id);

    /*!
        读本地字典1005-0
        \param cobId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalSyncCOBID(huint32 *cobId);

    /*!
        写本地字典，1005-0
        \param cobId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalSyncCOBID(huint32 cobId);

    /*!
        读本地字典1006-0
        \param cycle 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalSyncCycle(huint32 *cycle);

    /*!
        写本地字典1006-0
        \param cycle 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalSyncCycle(huint32 cycle);
    /*!
        读本地字典1007-0
        \param sWindow 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalSyncWindow(huint32 *sWindow);

    /*!
        写本地字典1007-0
        \param sWindow 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalSyncWindow(huint32 sWindow);

    /*!
        读本地字典[1200+sdoServerIndex]-0
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param num 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalServerSDONumberOfEntries(huint16 sdoServerIndex, huint8 *num);

    /*!
        写本地字典[1200+sdoServerIndex]-0
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param num 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalServerSDONumberOfEntries(huint16 sdoServerIndex, huint8 num);

    /*!
        读本地字典[1200+sdoServerIndex]-1
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param cobId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalServerSDOCobIdClientToServer(huint16 sdoServerIndex, huint32 *cobId);

    /*!
        写本地字典[1200+sdoServerIndex]-1
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param cobId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalServerSDOCobIdClientToServer(huint16 sdoServerIndex, huint32 cobId);

    /*!
        读本地字典[1200+sdoServerIndex]-2
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param cobId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalServerSDOCobIdServerToClient(huint16 sdoServerIndex, huint32 *cobId);

    /*!
        写本地字典[1200+sdoServerIndex]-2
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param cobId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalServerSDOCobIdServerToClient(huint16 sdoServerIndex, huint32 cobId);

    /*!
        读本地字典[1200+sdoServerIndex]-3
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param nodeId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalServerSDONodeIdOfClient(huint16 sdoServerIndex, huint8 *nodeId);

    /*!
        写本地字典[1200+sdoServerIndex]-3
        \param sdoServerIndex sdo索引，为0时主索引为1200，为1时主索引为1201，以此类推
        \param nodeId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalServerSDONodeIdOfClient(huint16 sdoServerIndex, huint8 nodeId);

    /*!
        读本地字典[1280+sdoClientIndex]-0
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param number 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalClientSDONumberOfEntries(huint16 sdoClientIndex, huint8 *number);

    /*!
        写本地字典[1280+sdoClientIndex]-0
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param number 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalClientSDONumberOfEntries(huint16 sdoClientIndex, huint8 number);

    /*!
        读本地字典[1280+sdoClientIndex]-1
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param cobId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalClientSDOCobIdClientToServer(huint16 sdoClientIndex, huint32 *cobId);

    /*!
        写本地字典[1280+sdoClientIndex]-1
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param cobId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalClientSDOCobIdClientToServer(huint16 sdoClientIndex, huint32 cobId);

    /*!
        读本地字典[1280+sdoClientIndex]-2
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param cobId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalClientSDOCobIdServerToClient(huint16 sdoClientIndex, huint32 *cobId);

    /*!
        写本地字典[1280+sdoClientIndex]-2
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param cobId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalClientSDOCobIdServerToClient(huint16 sdoClientIndex, huint32 cobId);

    /*!
        读本地字典[1280+sdoClientIndex]-3
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param nodeId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalClientSDONodeIdOfSDOServer(huint16 sdoClientIndex, huint8 *nodeId);

    /*!
        写本地字典[1280+sdoClientIndex]-3
        \param sdoClientIndex sdo索引，为0时主索引为1280，为1时主索引为1281，以此类推
        \param nodeId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalClientSDONodeIdOfSDOServer(huint16 sdoClientIndex, huint8 nodeId);

    /*!
        读本地字典[1400+pdoIndex]-0
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param count 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOMaxParasCount(huint16 pdoIndex, huint8 *count);

    /*!
        写本地字典[1400+pdoIndex]-0
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param count 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOMaxParasCount(huint16 pdoIndex, huint8 count);

    /*!
        读本地字典[1400+pdoIndex]-1
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param cobId 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOCobId(huint16 pdoIndex, huint32 *cobId);

    /*!
        写本地字典[1400+pdoIndex]-1
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param cobId 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOCobId(huint16 pdoIndex, huint32 cobId);

    /*!
        读本地字典[1400+pdoIndex]-2
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param type 存放读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOTransmitType(huint16 pdoIndex, huint8 *type);

    /*!
        写本地字典[1400+pdoIndex]-2
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param type 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOTransmitType(huint16 pdoIndex, huint8 type);

    /*!
        读本地字典[1400+pdoIndex]-3
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param time 保存读取的inhibitTime
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOInhibitTime(huint16 pdoIndex, huint16 *time);

    /*!
        写本地字典[1400+pdoIndex]-3
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param time 写入的inhibitTime
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOInhibitTime(huint16 pdoIndex, huint16 time);

    /*!
        读本地字典[1400+pdoIndex]-5
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param timer 读取的事件定时器周期
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOEventTimer(huint16 pdoIndex, huint16 *timer);

    /*!
        写本地字典[1400+pdoIndex]-5
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param timer 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOEventTimer(huint16 pdoIndex, huint16 timer);

    /*!
        读本地字典[1400+pdoIndex]-6
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param value 保存读取的值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOSYNCStartValue(huint16 pdoIndex, huint8 *value);

    /*!
        写本地字典[1400+pdoIndex]-6
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param value 写入值
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOSYNCStartValue(huint16 pdoIndex, huint8 value);

    /*!
        读本地字典[1600+pdoIndex]-0
        \param pdoIndex pdo索引，为0时主索引为1400，为1时主索引为1401，以此类推
        \param count
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOMaxMappedCount(huint16 pdoIndex, huint8 *count);

    /*!
        写本地字典[1600+pdoIndex]-0
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOMaxMappedCount(huint16 pdoIndex, huint8 count);

    /*!
        读本地字典1600-1
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalRPDOMapped(huint16 pdoIndex, huint8 mapIndex, huint32 *value);

    /*!
        写本地字典1600-1
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalRPDOMapped(huint16 pdoIndex, huint8 mapIndex, huint32 value);

    /*!
        读本地字典1800-0
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOMaxParasCount(huint16 pdoIndex, huint8 *count);

    /*!
        写本地字典1800-0
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOMaxParasCount(huint16 pdoIndex, huint8 count);

    /*!
        读本地字典1800-1
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOCobId(huint16 pdoIndex, huint32 *cobId);

    /*!
        写本地字典1800-1
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOCobId(huint16 pdoIndex, huint32 cobId);

    /*!
        读本地字典1800-2
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOTransmitType(huint16 pdoIndex, huint8 *type);

    /*!
        写本地字典1800-2
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOTransmitType(huint16 pdoIndex, huint8 type);

    /*!
        读本地字典1800-3
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOInhibitTime(huint16 pdoIndex, huint16 *time);

    /*!
        写本地字典1800-3
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOInhibitTime(huint16 pdoIndex, huint16 time);

    /*!
        读本地字典1800-5
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOEventTimer(huint16 pdoIndex, huint16 *timer);

    /*!
        写本地字典1800-5
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOEventTimer(huint16 pdoIndex, huint16 timer);

    /*!
        读本地字典1800-6
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOSYNCStartValue(huint16 pdoIndex, huint8 *value);
    /*!
        写本地字典1800-6
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOSYNCStartValue(huint16 pdoIndex, huint8 value);

    /*!
        读本地字典1A00-0
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOMaxMappedCount(huint16 pdoIndex, huint8 *count);

    /*!
        写本地字典1A00-0
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOMaxMappedCount(huint16 pdoIndex, huint8 count);

    /*!
        读本地字典1A00-1
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTPDOMapped(huint16 pdoIndex, huint8 mapIndex, huint32 *value);

    /*!
        写本地字典1A00-1
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTPDOMapped(huint16 pdoIndex, huint8 mapIndex, huint32 value);

    /*!
        读本地字典0x2016-0x01
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalServoTemperature(hint8 *tem);

    /*!
        读本地字典0x5000
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalMutiMotorPos(huint16 index, hint32 *pos);

    /*!
        读本地字典5001
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalMutiMotorVel(huint16 index, hint32 *vel);

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalMutiMotorTorque(huint16 index, hint16 *tor); // 5002

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalMutiMotorSetPos(huint16 index, hint32 pos); // 5003

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalMutiMotorSetVel(huint16 index, hint32 vel); // 5004

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalMutiMotorSetTorque(huint16 index, hint16 torque); // 5005

    EXTERNFUNC int harmonic_getLocalMutiMotorStatusWord(huint16 index, huint16 *status); // 5006

    EXTERNFUNC int harmonic_getLocalMutiMotorErrorCode(huint16 index, huint16 *error); // 5007

    EXTERNFUNC int harmonic_getLocalServoErrorCode(huint16 *err);

    /*!
        读本地字典0x6040-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalControlword(huint16 *word);
    /*!
        写本地字典0x6040-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalControlword(huint16 word);

    EXTERNFUNC int harmonic_getLocalStatusWord(huint16 *word);

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalActualPos(hint32 *pos); // 6064-0

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalActualVelocity(hint32 *velocity); // 606c-0

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTargetTorque(hint16 *torque); // 6071-0

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTargetTorque(hint16 torque); // 6071-0

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalActualTorque(hint16 *torque); // 6077-0

    /*!
        读本地字典0x6079-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalDCLinkCircuitVoltage(huint32 *voltage);

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTargetPos(hint32 *pos); // 607A-0

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTargetPos(hint32 pos); // 607A-0

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalInterpolationDataRecord(hint32 *value); // 60C1-1

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalInterpolationDataRecord(hint32 value); // 60C1-1

    /*!
        读本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalInterpolationTimePeriodValue(huint8 *value); // 60C2-1

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalInterpolationTimePeriodValue(huint8 value); // 60C2-1

    /*!
        读本地字典0x60FF
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLocalTargetVelocity(hint32 *vel); // 60FF-0

    /*!
        写本地字典
        \param
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLocalTargetVelocity(hint32 vel); // 60FF-0

    /*!
        读从站字典0x1000-0
        \param id 从节点id
        \param deviceType 保存读取的设备类型
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDeviceType(huint8 id, huint32 *deviceType, huint32 timeout = 100);

    /*!
        读从站字典0x1001-0
        \param id 从节点id
        \param errReg 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getErrorRegister(huint8 id, huint8 *errReg, huint32 timeout = 100);

    /*!
        读从站字典0x1003-0
        \param id 从节点id
        \param number 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getErrorFieldNumber(huint8 id, huint8 *number, huint32 timeout = 100);

    /*!
        写从站字典0x1003-0
        \param id 从节点id
        \param number 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setErrorFieldNumber(huint8 id, huint8 number, huint32 timeout = 100); // 0x1003-0

    /*!
        读从站字典0x1003-subIndex
        \param id 从节点id
        \param subIndex 字典子索引(取值范围0x01~0x7f)
        \param err 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getErrorField(huint8 id, huint8 subIndex, huint32 *err, huint32 timeout = 100);

    /*!
        读从站字典0x1005-0
        \param id 从节点id
        \param cobid 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSyncCobid(huint8 id, huint32 *cobid, huint32 timeout = 100);

    /*!
        写从站字典0x1005-0
        \param id 从节点id
        \param cobid 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSyncCobid(huint8 id, huint32 cobid, huint32 timeout = 100);

    /*!
        读从站字典0x1006-0
        \param id 从节点id
        \param syncCycle 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSyncCycle(huint8 id, huint32 *syncCycle, huint32 timeout = 100);

    /*!
        写从站字典0x1006-0
        \param id 从节点id
        \param syncCycle 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSyncCycle(huint8 id, huint32 syncCycle, huint32 timeout = 100);

    /*!
        读从站字典0x1007-0
        \param id 从节点id
        \param syncWindow 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSyncWindow(huint8 id, huint32 *syncWindow, huint32 timeout = 100);

    /*!
        写从站字典0x1007-0
        \param id 从节点id
        \param syncWindow 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSyncWindow(huint8 id, huint32 syncWindow, huint32 timeout = 100);

    /*!
        读从站字典0x1008-0
        \param id 从节点id
        \param devName 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDeviceName(huint8 id, char *devName, huint32 timeout = 100);

    /*!
        读从站字典0x1009-0
        \param id 从节点id
        \param hVersion 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getHardwareVersion(huint8 id, char *version, huint32 timeout = 100);

    /*!
        读从站字典0x100a-0
        \param id 从节点id
        \param version 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSoftwareVersion(huint8 id, char *version, huint32 timeout = 100);

    /*!
        读从站字典0x100c-0
        \param id 从节点id
        \param time 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getGuardTime(huint8 id, huint16 *time, huint32 timeout = 100);

    /*!
        写从站字典0x100c-0
        \param id 从节点id
        \param time 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setGuardTime(huint8 id, huint16 time, huint32 timeout = 100);

    /*!
        读从站字典0x100d-0
        \param id 从节点id
        \param factor 保存读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getLifeTimeFactor(huint8 id, huint8 *factor, huint32 timeout = 100);

    /*!
        写从站字典0x100d-0
        \param id 从节点id
        \param factor 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setLifeTimeFactor(huint8 id, huint8 factor, huint32 timeout = 100);

    /*!
        读从站字典0x1010-0
        \param id 从节点id
        \param number 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getStoreParametersNumber(huint8 id, huint8 *number, huint32 timeout = 100);

    /*!
        读从站字典0x1010-0x01
        \param id 从节点id
        \param value 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getStoreParameters(huint8 id, huint32 *value, huint32 timeout = 100);

    /*!
        写从站字典0x1010-0x01
        \param id 从节点id
        \param value 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setStoreParameters(huint8 id, huint32 value, huint32 timeout = 100);

    /*!
        读从站字典0x1011-0
        \param id 从节点id
        \param number 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRestoreDefaultParametersNumber(huint8 id, huint8 *number, huint32 timeout = 100);

    /*!
        读从站字典0x1011-0x01
        \param id 从节点id
        \param value 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRestoreDefaultParameters(huint8 id, huint32 *value, huint32 timeout = 100);

    /*!
        写从站字典0x1011-0x01
        \param id 从节点id
        \param subIndex 子索引
        \param value 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRestoreDefaultParameters(huint8 id, huint32 value, huint32 timeout = 100);

    /*!
        读从站字典0x1014-0
        \param id 从节点id
        \param cobid 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getEmergencyCobid(huint8 id, huint32 *cobid, huint32 timeout = 100);

    /*!
        写从站字典0x1014-0
        \param id 从节点id
        \param cobid 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setEmergencyCobid(huint8 id, huint32 cobid, huint32 timeout = 100);

    /*!
        读从站字典0x1015-0
        \param id 从节点id
        \param time 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getEmergencyInhibitTime(huint8 id, huint16 *time, huint32 timeout = 100);

    /*!
        写从站字典0x1015-0
        \param id 从节点id
        \param time 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setEmergencyInhibitTime(huint8 id, huint16 time, huint32 timeout = 100);

    /*!
        读从站字典0x1016-0
        \param id 从节点id
        \param number 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getHearbeatConsumerTimeParasNum(huint8 id, huint8 *number, huint32 timeout = 100);

    /*!
        读从站字典0x1016-subIndex
        \param id 从节点id
        \param subIndex 子索引
        \param time 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getHearbeatConsumerTime(huint8 id, huint8 subIndex, huint32 *time, huint32 timeout = 100);

    /*!
        写从站字典0x1016-subIndex
        \param id 从节点id
        \param subIndex 子索引
        \param time 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setHearbeatConsumerTime(huint8 id, huint8 subIndex, huint32 time, huint32 timeout = 100);

    /*!
        读从站字典0x1017-0
        \param id 从节点id
        \param time 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getProducerHeartbeatTime(huint8 id, huint16 *time, huint32 timeout = 100);

    /*!
        写从站字典0x1017-0
        \param id 从节点id
        \param time 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setProducerHeartbeatTime(huint8 id, huint16 time, huint32 timeout = 100);

    /*!
        读从站字典0x1018-0
        \param id 从节点id
        \param number 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getIdentityObjectNumber(huint8 id, huint8 *number, huint32 timeout = 100);

    /*!
        读从站字典0x1018-1
        \param id 从节点id
        \param vId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getVendorID(huint8 id, huint32 *vId, huint32 timeout = 100);

    /*!
        读从站字典0x1018-2
        \param id 从节点id
        \param pCode 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getProductCode(huint8 id, huint32 *pCode, huint32 timeout = 100);

    /*!
        读从站字典0x1018-3
        \param id 从节点id
        \param revisionNum 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getIdentityObjectRevisionNumber(huint8 id, huint32 *revisionNum, huint32 timeout = 100);

    /*!
        读从站字典0x1018-4
        \param id 从节点id
        \param serialNum 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSerialNumber(huint8 id, huint32 *serialNum, huint32 timeout = 100);

    /*!
        读从站字典0x1019-0
        \param id 从节点id
        \param counter 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSyncCounter(huint8 id, huint8 *counter, huint32 timeout = 100);

    /*!
        写从站字典0x1019-0
        \param id 从节点id
        \param counter 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSyncCounter(huint8 id, huint8 counter, huint32 timeout = 100);

    /*!
        读从站字典0x1200+sdoServerIndex-0x00
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param num 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getServerSDONumberOfEntries(huint8 id, huint16 sdoServerIndex, huint8 *num, huint32 timeout = 100);

    /*!
        写从站字典0x1200+sdoServerIndex-0x00
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param num 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setServerSDONumberOfEntries(huint8 id, huint16 sdoServerIndex, huint8 num, huint32 timeout = 100);

    /*!
        读从站字典0x1200+sdoServerIndex-0x01
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param cobId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getServerSDOCobIdClientToServer(huint8 id, huint16 sdoServerIndex, huint32 *cobId, huint32 timeout = 100);

    /*!
        写从站字典0x1200+sdoServerIndex-0x01
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param cobId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setServerSDOCobIdClientToServer(huint8 id, huint16 sdoServerIndex, huint32 cobId, huint32 timeout = 100);

    /*!
        读从站字典0x1200+sdoServerIndex-0x02
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param cobId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getServerSDOCobIdServerToClient(huint8 id, huint16 sdoServerIndex, huint32 *cobId, huint32 timeout = 100);

    /*!
        写从站字典0x1200+sdoServerIndex-0x02
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param cobId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setServerSDOCobIdServerToClient(huint8 id, huint16 sdoServerIndex, huint32 cobId, huint32 timeout = 100);

    /*!
        读从站字典0x1200+sdoServerIndex-0x03
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param nodeId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getServerSDONodeIdOfClient(huint8 id, huint16 sdoServerIndex, huint8 *nodeId, huint32 timeout = 100);

    /*!
        写从站字典0x1200+sdoServerIndex-0x03
        \param sdoServerIndex sdo索引，设为0代表从站字典主索引0x1200，设为1代表从站字典主索引0x1201,以此类推
        \param nodeId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setServerSDONodeIdOfClient(huint8 id, huint16 sdoServerIndex, huint8 nodeId, huint32 timeout = 100);

    /*!
        读从站字典0x1280+sdoClientIndex-0x00
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param number 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getClientSDONumberOfEntries(huint8 id, huint16 sdoClientIndex, huint8 *number, huint32 timeout = 100);

    /*!
        写从站字典0x1280+sdoClientIndex-0x00
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param number 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setClientSDONumberOfEntries(huint8 id, huint16 sdoClientIndex, huint8 number, huint32 timeout = 100);

    /*!
        读从站字典0x1280+sdoClientIndex-0x01
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param cobId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getClientSDOCobIdClientToServer(huint8 id, huint16 sdoClientIndex, huint32 *cobId, huint32 timeout = 100);

    /*!
        写从站字典0x1280+sdoClientIndex-0x01
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param cobId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setClientSDOCobIdClientToServer(huint8 id, huint16 sdoClientIndex, huint32 cobId, huint32 timeout = 100);

    /*!
        读从站字典0x1280+sdoClientIndex-0x02
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param cobId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getClientSDOCobIdServerToClient(huint8 id, huint16 sdoClientIndex, huint32 *cobId, huint32 timeout = 100);

    /*!
        写从站字典0x1280+sdoClientIndex-0x02
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param cobId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setClientSDOCobIdServerToClient(huint8 id, huint16 sdoClientIndex, huint32 cobId, huint32 timeout = 100);

    /*!
        读从站字典0x1280+sdoClientIndex-0x03
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param nodeId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getClientSDONodeIdOfSDOServer(huint8 id, huint16 sdoClientIndex, huint8 *nodeId, huint32 timeout = 100);

    /*!
        写从站字典0x1280+sdoClientIndex-0x03
        \param id 从节点id
        \param sdoClientIndex sdo索引，设为0代表从站字典主索引0x1280，设为1代表从站字典主索引0x1281,以此类推
        \param nodeId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setClientSDONodeIdOfSDOServer(huint8 id, huint16 sdoClientIndex, huint8 nodeId, huint32 timeout = 100);

    /*!
        读从站字典0x1400+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param count 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOMaxParasCount(huint8 id, huint16 pdoIndex, huint8 *count, huint32 timeout = 100);

    /*!
        写从站字典0x1400+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param count 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOMaxParasCount(huint8 id, huint16 pdoIndex, huint8 count, huint32 timeout = 100);

    /*!
        读从站字典0x1400+pdoIndex-0x01
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param cobId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOCobId(huint8 id, huint16 pdoIndex, huint32 *cobId, huint32 timeout = 100);

    /*!
        写从站字典0x1400+pdoIndex-0x01
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param cobId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOCobId(huint8 id, huint16 pdoIndex, huint32 cobId, huint32 timeout = 100);

    /*!
        读从站字典0x1400+pdoIndex-0x02
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param type 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOTransmitType(huint8 id, huint16 pdoIndex, huint8 *type, huint32 timeout = 100);

    /*!
        写从站字典0x1400+pdoIndex-0x02
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param type 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOTransmitType(huint8 id, huint16 pdoIndex, huint8 type, huint32 timeout = 100);

    /*!
        读从站字典0x1400+pdoIndex-0x03
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param time 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOInhibitTime(huint8 id, huint16 pdoIndex, huint16 *time, huint32 timeout = 100);

    /*!
        写从站字典0x1400+pdoIndex-0x03
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param time 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOInhibitTime(huint8 id, huint16 pdoIndex, huint16 time, huint32 timeout = 100);

    /*!
        读从站字典0x1400+pdoIndex-0x05
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param timer 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOEventTimer(huint8 id, huint16 pdoIndex, huint16 *timer, huint32 timeout = 100);

    /*!
        写从站字典0x1400+pdoIndex-0x05
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param timer 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOEventTimer(huint8 id, huint16 pdoIndex, huint16 timer, huint32 timeout = 100);

    /*!
        读从站字典0x1400+pdoIndex-0x06
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1400，设为1代表从站字典主索引0x1401,以此类推
        \param value 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOSYNCStartValue(huint8 id, huint16 pdoIndex, huint8 *value, huint32 timeout = 100);

    /*!
        写从站字典
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOSYNCStartValue(huint8 id, huint16 pdoIndex, huint8 value, huint32 timeout = 100); // 1400-6

    /*!
        读从站字典0x1600+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1600，设为1代表从站字典主索引0x1601,以此类推
        \param count 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOMaxMappedCount(huint8 id, huint16 pdoIndex, huint8 *count, huint32 timeout = 100);

    /*!
        写从站字典0x1600+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1600，设为1代表从站字典主索引0x1601,以此类推
        \param count 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOMaxMappedCount(huint8 id, huint16 pdoIndex, huint8 count, huint32 timeout = 100);

    /*!
        读从站字典0x1600+pdoIndex-0x01+mapIndex
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1600，设为1代表从站字典主索引0x1601,以此类推
        \param mapIndex 映射地址索引，设为0代表从站字典子索引0x01, 设为1代表子索引0x02,以此类推
        \param value 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getRPDOMapped(huint8 id, huint16 pdoIndex, huint8 mapIndex, huint32 *value, huint32 timeout = 100);

    /*!
        写从站字典0x1600+pdoIndex-0x01+mapIndex
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1600，设为1代表从站字典主索引0x1601,以此类推
        \param mapIndex 映射地址索引，设为0代表从站字典子索引0x01, 设为1代表子索引0x02,以此类推
        \param value 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setRPDOMapped(huint8 id, huint16 pdoIndex, huint8 mapIndex, huint32 value, huint32 timeout = 100);

    /*!
        读从站字典0x1800+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param count 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOMaxParasCount(huint8 id, huint16 pdoIndex, huint8 *count, huint32 timeout = 100);

    /*!
        写从站字典0x1800+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param count 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOMaxParasCount(huint8 id, huint16 pdoIndex, huint8 count, huint32 timeout = 100);

    /*!
        读从站字典0x1800+pdoIndex-0x01
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param cobId 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOCobId(huint8 id, huint16 pdoIndex, huint32 *cobId, huint32 timeout = 100);

    /*!
        写从站字典0x1800+pdoIndex-0x01
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param cobId 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOCobId(huint8 id, huint16 pdoIndex, huint32 cobId, huint32 timeout = 100);

    /*!
        读从站字典0x1800+pdoIndex-0x02
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param type 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOTransmitType(huint8 id, huint16 pdoIndex, huint8 *type, huint32 timeout = 100);

    /*!
        写从站字典0x1800+pdoIndex-0x02
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param type 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOTransmitType(huint8 id, huint16 pdoIndex, huint8 type, huint32 timeout = 100);

    /*!
        读从站字典0x1800+pdoIndex-0x03
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param time 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOInhibitTime(huint8 id, huint16 pdoIndex, huint16 *time, huint32 timeout = 100);

    /*!
        写从站字典0x1800+pdoIndex-0x03
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param time 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOInhibitTime(huint8 id, huint16 pdoIndex, huint16 time, huint32 timeout = 100);

    /*!
        读从站字典0x1800+pdoIndex-0x05
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param timer 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOEventTimer(huint8 id, huint16 pdoIndex, huint16 *timer, huint32 timeout = 100);

    /*!
        写从站字典0x1800+pdoIndex-0x05
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param timer 写入值
        \param timeout 等待确认时间，单位
    */
    EXTERNFUNC int harmonic_setTPDOEventTimer(huint8 id, huint16 pdoIndex, huint16 timer, huint32 timeout = 100);

    /*!
        读从站字典0x1800+pdoIndex-0x06
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param value 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOSYNCStartValue(huint8 id, huint16 pdoIndex, huint8 *value, huint32 timeout = 100);

    /*!
        写从站字典0x1800+pdoIndex-0x06
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1800，设为1代表从站字典主索引0x1801,以此类推
        \param value 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOSYNCStartValue(huint8 id, huint16 pdoIndex, huint8 value, huint32 timeout = 100);

    /*!
        读从站字典0x1a00+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1a00，设为1代表从站字典主索引0x1a01,以此类推
        \param count 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOMaxMappedCount(huint8 id, huint16 pdoIndex, huint8 *count, huint32 timeout = 100);

    /*!
        写从站字典0x1a00+pdoIndex-0x00
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1a00，设为1代表从站字典主索引0x1a01,以此类推
        \param count 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOMaxMappedCount(huint8 id, huint16 pdoIndex, huint8 count, huint32 timeout = 100);

    /*!
        读从站字典0x1a00+pdoIndex-0x01+mapIndex
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1a00，设为1代表从站字典主索引0x1a01,以此类推
        \param mapIndex 映射索引，设为0代表从站字典子索引0x01,设为1代表从站字典子索引0x02,以此类推
        \param value 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTPDOMapped(huint8 id, huint16 pdoIndex, huint8 mapIndex, huint32 *value, huint32 timeout = 100);

    /*!
        写从站字典0x1a00+pdoIndex-0x01+mapIndex
        \param id 从节点id
        \param pdoIndex pdo索引，设为0代表从站字典主索引0x1a00，设为1代表从站字典主索引0x1a01,以此类推
        \param mapIndex 映射索引，设为0代表从站字典子索引0x01,设为1代表从站字典子索引0x02,以此类推
        \param value 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTPDOMapped(huint8 id, huint16 pdoIndex, huint8 mapIndex, huint32 value, huint32 timeout = 100); // 1A00-1

    EXTERNFUNC int harmonic_getServoParametersNumber(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoParametersNumber(huint8 id, huint8 num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoID(huint8 id, huint8 *servoID, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoID(huint8 id, huint8 servoID, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoCanBaudrate(huint8 id, huint16 *baudrate, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoCanBaudrate(huint8 id, huint16 baudrate, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoSoftwareLimitState(huint8 id, huint32 *state, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoSoftwareLimitState(huint8 id, huint32 state, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoCurrentLoopPINum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getDefaultServoCurrentLoopKP(huint8 id, huint16 *kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setDefaultServoCurrentLoopKP(huint8 id, huint16 kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getDefaultServoCurrentLoopKI(huint8 id, huint16 *ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setDefaultServoCurrentLoopKI(huint8 id, huint16 ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoCurrentLoopKP(huint8 id, huint16 *kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoCurrentLoopKP(huint8 id, huint16 kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoCurrentLoopKI(huint8 id, huint16 *ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoCurrentLoopKI(huint8 id, huint16 ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityLoopPINum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getDefaultServoVelocityLoopKP(huint8 id, huint16 *kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setDefaultServoVelocityLoopKP(huint8 id, huint16 kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getDefaultServoVelocityLoopKI(huint8 id, huint16 *ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setDefaultServoVelocityLoopKI(huint8 id, huint16 ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityLoopKP(huint8 id, huint16 *kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoVelocityLoopKP(huint8 id, huint16 kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityLoopKI(huint8 id, huint16 *ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoVelocityLoopKI(huint8 id, huint16 ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoPositionLoopPINum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getDefaultServoPositionLoopKP(huint8 id, huint16 *kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setDefaultServoPositionLoopKP(huint8 id, huint16 kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getDefaultServoPositionLoopKI(huint8 id, huint16 *ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setDefaultServoPositionLoopKI(huint8 id, huint16 ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoPositionLoopKP(huint8 id, huint16 *kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoPositionLoopKP(huint8 id, huint16 kp, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoPositionLoopKI(huint8 id, huint16 *ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoPositionLoopKI(huint8 id, huint16 ki, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBrakeParaNum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBrakeControl(huint8 id, huint8 *status, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoBrakeControl(huint8 id, huint8 status, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getBrakeState(huint8 id, huint8 *state, huint32 timeout = 100);
    /*!
        写从站字典0x2014(设置抱闸状态)
        \param id 从节点id
        \param state true:为打开抱闸 false:关闭抱闸
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setBrakeState(huint8 id, huint8 state, huint32 timeout = 100);

    EXTERNFUNC int harmonic_getServoTemperatureParasNum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoTemperature(huint8 id, hint8 *tem, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoTemperatureLimit(huint8 id, hint8 *tem, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoTemperatureLimit(huint8 id, huint8 tem, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoTemperatureLimitTime(huint8 id, huint16 *time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoTemperatureLimitTime(huint8 id, huint16 time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityIntLimit(huint8 id, huint16 *limit, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoVelocityIntLimit(huint8 id, huint16 limit, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBlockParasNum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBlockTorque(huint8 id, huint16 *torque, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoBlockTorque(huint8 id, huint16 torque, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBlockTime(huint8 id, huint16 *time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoBlockTime(huint8 id, huint16 time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBlockVelocity(huint8 id, huint32 *velocity, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoBlockVelocity(huint8 id, huint32 velocity, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityFlowingErrorParasNum(huint8 id, huint8 *num, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityFlowingErrorWindows(huint8 id, huint32 *error, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoVelocityFlowingErrorWindows(huint8 id, huint32 error, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoVelocityFlowingErrorTime(huint8 id, huint16 *time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoVelocityFlowingErrorTime(huint8 id, huint16 time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoTorqueWindow(huint8 id, huint16 *window, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoTorqueWindow(huint8 id, huint16 window, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoTorqueWindowTime(huint8 id, huint16 *window, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoTorqueWindowTime(huint8 id, huint16 window, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoOverSpeedThreshold(huint8 id, huint32 *thre, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoOverSpeedThreshold(huint8 id, huint32 thre, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoOverSpeedTime(huint8 id, huint16 *time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoOverSpeedTime(huint8 id, huint16 time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoBrakeDelayTime(huint8 id, huint8 *time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setServoBrakeDelayTime(huint8 id, huint8 time, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getI2tOverLoadLimit(huint8 id, huint16 *value, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setI2tOverLoadLimit(huint8 id, huint16 value, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getI2tOverLoadValue(huint8 id, huint16 *value, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoFirstEncoderValue(huint8 id, hint32 *value, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoSecondEncoderValue(huint8 id, hint32 *value, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getServoThetaBiasValue(huint8 id, hint32 *value, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getFindPointDoneFlag(huint8 id, huint32 *flag, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setFindPointDoneFlag(huint8 id, huint32 flag, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getFindPointStart(huint8 id, huint32 *status, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setFindPointStart(huint8 id, huint32 status, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getFindPointMoveMax(huint8 id, huint32 *angle, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setFindPointMoveMax(huint8 id, huint32 angle, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getFindPointMoveAcc(huint8 id, huint32 *acc, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setFindPointMoveAcc(huint8 id, huint32 acc, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getFindPointMoveDec(huint8 id, huint32 *dec, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setFindPointMoveDec(huint8 id, huint32 dec, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getFindPointMoveVelocity(huint8 id, huint32 *vel, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setFindPointMoveVelocity(huint8 id, huint32 vel, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getTorqueFactor(huint8 id, huint16 *factor, huint32 timeout = 100);
    EXTERNFUNC int harmonic_setTorqueFactor(huint8 id, huint16 factor, huint32 timeout = 100);
    /*!
        读从站字典0x603F-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getServoErrorCode(huint8 id, huint16 *err, huint32 timeout = 100);

    /*!
        读从站字典0x6040-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getControlword(huint8 id, huint16 *word, huint32 timeout = 100);
    /*!
        写从站字典0x6040-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setControlword(huint8 id, huint16 word, huint32 timeout = 100);

    /*!
        读从站字典0x6041-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getStatusWord(huint8 id, huint16 *word, huint32 timeout = 100);

    /*!
        读从站字典0x605A-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getQuickStopOption(huint8 id, harmonic_QuickStopOption *option, huint32 timeout = 100);

    /*!
        写从站字典0x605A-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setQuickStopOption(huint8 id, harmonic_QuickStopOption option, huint32 timeout = 100);

    /*!
        读从站字典0x605B-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getShutdownOptionCode(huint8 id, harmonic_ShutdownOption *code, huint32 timeout = 100);

    /*!
        写从站字典0x605B-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setShutdownOptionCode(huint8 id, harmonic_ShutdownOption code, huint32 timeout = 100);

    /*!
        读从站字典0x605C-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDisableOperationOptionCode(huint8 id, harmonic_DisableOperationOption *code, huint32 timeout = 100);

    /*!
        写从站字典0x605C-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setDisableOperationOptionCode(huint8 id, harmonic_DisableOperationOption code, huint32 timeout = 100);

    /*!
        读从站字典0x605D-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getHaltOption(huint8 id, harmonic_HaltOption *option, huint32 timeout = 100);

    /*!
        写从站字典0x605D-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setHaltOption(huint8 id, harmonic_HaltOption option, huint32 timeout = 100);

    /*!
        读从站字典0x605E-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getFaultReactionOption(huint8 id, harmonic_FaultReactionOption *option, huint32 timeout = 100);

    /*!
        写从站字典0x605E-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setFaultReactionOption(huint8 id, harmonic_FaultReactionOption option, huint32 timeout = 100);

    /*!
        读从站字典0x6060-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getOperateMode(huint8 id, harmonic_OperateMode *mode, huint32 timeout = 100);

    /*!
        写从站字典0x6060-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setOperateMode(huint8 id, harmonic_OperateMode mode, huint32 timeout = 100);

    /*!
        读从站字典0x6061-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDisplayOperateMode(huint8 id, harmonic_OperateMode *mode, huint32 timeout = 100);

    /*!
        读从站字典0x6062-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDemandPos(huint8 id, hint32 *pos, huint32 timeout = 100);

    /*!
        写从站字典0x6062-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setDemandPos(huint8 id, hint32 pos, huint32 timeout = 100);

    /*!
        读从站字典0x6064-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getActualPos(huint8 id, hint32 *pos, huint32 timeout = 100);

    /*!
        写从站字典0x6064-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setActualPos(huint8 id, hint32 pos, huint32 timeout = 100);

    /*!
        读从站字典0x6065-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getFollowingErrorWindow(huint8 id, huint32 *eWindow, huint32 timeout = 100);

    /*!
        写从站字典0x6065-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setFollowingErrorWindow(huint8 id, huint32 eWindow, huint32 timeout = 100);

    /*!
        读从站字典0x6067-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getPositionWindow(huint8 id, huint32 *pWindow, huint32 timeout = 100);

    /*!
        写从站字典0x6067-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setPositionWindow(huint8 id, huint32 pWindow, huint32 timeout = 100);

    /*!
        读从站字典0x6068-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getPositionWindowTime(huint8 id, huint16 *pWindowTime, huint32 timeout = 100);

    /*!
        写从站字典0x6068-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setPositionWindowTime(huint8 id, huint16 pWindowTime, huint32 timeout = 100);

    /*!
        读从站字典0x606B-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDemandVelocity(huint8 id, hint32 *dVel, huint32 timeout = 100);

    /*!
        写从站字典0x606B-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setDemandVelocity(huint8 id, hint32 dvel, huint32 timeout = 100);

    /*!
        读从站字典0x606C-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getActualVelocity(huint8 id, hint32 *vel, huint32 timeout = 100);

    /*!
        写从站字典0x606C-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setActualVelocity(huint8 id, hint32 vel, huint32 timeout = 100);

    /*!
        读从站字典0x606D-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getVelocityWindow(huint8 id, huint16 *vWindow, huint32 timeout = 100);

    /*!
        写从站字典0x606D-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setVelocityWindow(huint8 id, huint16 vWindow, huint32 timeout = 100);

    /*!
        读从站字典0x606E-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getVelocityWindowTime(huint8 id, huint16 *wTime, huint32 timeout = 100);

    /*!
        写从站字典0x606E-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setVelocityWindowTime(huint8 id, huint16 wTime, huint32 timeout = 100);

    /*!
        读从站字典0x606F-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getVelocityThreshold(huint8 id, huint16 *thres, huint32 timeout = 100);

    /*!
        写从站字典0x606F-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setVelocityThreshold(huint8 id, huint16 thres, huint32 timeout = 100);

    /*!
        读从站字典0x6070-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getVelocityThresholdTime(huint8 id, huint16 *tTime, huint32 timeout = 100);
    /*!
        写从站字典0x6070-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setVelocityThresholdTime(huint8 id, huint16 tTime, huint32 timeout = 100);

    /*!
        读从站字典0x6071-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTargetTorque(huint8 id, hint16 *torque, huint32 timeout = 100);

    /*!
        写从站字典0x6071-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTargetTorque(huint8 id, hint16 torque, huint32 timeout = 100);

    /*!
        读从站字典0x6072-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTorqueLimit(huint8 id, hint16 *torque, huint32 timeout = 100);

    /*!
        写从站字典0x6072-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTorqueLimit(huint8 id, hint16 torque, huint32 timeout = 100);

    /*!
        读从站字典0x6074-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDemandTorque(huint8 id, hint16 *torque, huint32 timeout = 100);

    /*!
        写从站字典0x6074-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setDemandTorque(huint8 id, hint16 torque, huint32 timeout = 100);

    /*!
        读从站字典0x6076-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getMotorRatedTorque(huint8 id, huint32 *torque, huint32 timeout = 100);

    /*!
        写从站字典0x6076-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setMotorRatedTorque(huint8 id, huint32 torque, huint32 timeout = 100);

    /*!
        读从站字典0x6077-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getActualTorque(huint8 id, hint16 *torque, huint32 timeout = 100);

    /*!
        写从站字典0x6077-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setActualTorque(huint8 id, hint16 torque, huint32 timeout = 100);

    /*!
        读从站字典0x6079-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getDCLinkCircuitVoltage(huint8 id, huint32 *voltage, huint32 timeout = 100);

    /*!
        写从站字典0x6079-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setDCLinkCircuitVoltage(huint8 id, huint32 voltage, huint32 timeout = 100);

    /*!
        读从站字典0x607A-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTargetPos(huint8 id, hint32 *pos, huint32 timeout = 100);

    /*!
        写从站字典0x607A-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTargetPos(huint8 id, hint32 pos, huint32 timeout = 100);

    /*!
        读从站字典0x607C-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getHomeOffset(huint8 id, hint32 *offSet, huint32 timeout = 100);

    /*!
        写从站字典0x607C-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setHomeOffset(huint8 id, hint32 offSet, huint32 timeout = 100);
    /*!
        读从站字典0x607D-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSoftwareMinimumPosition(huint8 id, hint32 *pos, huint32 timeout = 100);

    /*!
        写从站字典0x607D-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSoftwareMinimumPosition(huint8 id, hint32 pos, huint32 timeout = 100);

    /*!
        读从站字典0x607D-2
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getSoftwareMaxmumPosition(huint8 id, hint32 *pos, huint32 timeout = 100);

    /*!
        写从站字典0x607D-2
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setSoftwareMaxmumPosition(huint8 id, hint32 pos, huint32 timeout = 100);

    /*!
        读从站字典0x607F-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getMaxProfileVelocity(huint8 id, huint32 *vel, huint32 timeout = 100);

    /*!
        写从站字典0x607F-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setMaxProfileVelocity(huint8 id, huint32 vel, huint32 timeout = 100);

    /*!
        读从站字典0x6081-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getProfileVelocity(huint8 id, huint32 *vel, huint32 timeout = 100);

    /*!
        写从站字典0x6081-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setProfileVelocity(huint8 id, huint32 vel, huint32 timeout = 100);

    /*!
        读从站字典0x6083-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getProfileAcceleration(huint8 id, huint32 *acc, huint32 timeout = 100);

    /*!
        写从站字典0x6083-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setProfileAcceleration(huint8 id, huint32 acc, huint32 timeout = 100);

    /*!
        读从站字典0x6084-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getProfileDeceleration(huint8 id, huint32 *dec, huint32 timeout = 100);

    /*!
        写从站字典0x6084-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setProfileDeceleration(huint8 id, huint32 dec, huint32 timeout = 100);

    /*!
        读从站字典0x6085-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getQuickStopDeceleration(huint8 id, huint32 *dec, huint32 timeout = 100);

    /*!
        写从站字典0x6085-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setQuickStopDeceleration(huint8 id, huint32 dec, huint32 timeout = 100);

    /*!
        读从站字典0x6087-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getTorqueSlope(huint8 id, huint32 *slope, huint32 timeout = 100);

    /*!
        写从站字典0x6087-0
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTorqueSlope(huint8 id, huint32 slope, huint32 timeout = 100);

    /*!
        读从站字典0x6091-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getGearRatioMotorRevolutions(huint8 id, huint32 *rev, huint32 timeout = 100);

    /*!
        写从站字典0x6091-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setGearRatioMotorRevolutions(huint8 id, huint32 rev, huint32 timeout = 100);

    /*!
        读从站字典0x6091-2
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getGearRatioShaftRevolutions(huint8 id, huint32 *rev, huint32 timeout = 100);
    /*!
        写从站字典0x6091-2
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setGearRatioShaftRevolutions(huint8 id, huint32 rev, huint32 timeout = 100);

    /*!
        读从站字典0x60C1-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getInterpolationDataRecord(huint8 id, hint32 *value, huint32 timeout = 100);

    /*!
        写从站字典0x60C1-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setInterpolationDataRecord(huint8 id, hint32 value, huint32 timeout = 100);

    /*!
        读从站字典0x60C2-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getInterpolationTimePeriodValue(huint8 id, huint8 *value, huint32 timeout = 100);

    /*!
        写从站字典0x60C2-1
        \param
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setInterpolationTimePeriodValue(huint8 id, huint8 value, huint32 timeout = 100);

    /*!
        读从站字典0x60F4-0
        \param id 从节点id
        \param error 存放读取的值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_getActualFollowingError(huint8 id, hint32 *error, huint32 timeout = 100);

    /*!
        写从站字典0x60f4-0
        \param id 从节点id
        \error 写入值
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setActualFollowingError(huint8 id, hint32 error, huint32 timeout = 100);

    /*!
        读从站字典0x60ff-0
        \param id 从节点id
        \param targetVel 保存读取的目标速度
        \param timeout 等待确认时间，单位ms
        \return 成功返回0,失败返回其他
    */
    EXTERNFUNC int harmonic_getTargetVelocity(huint8 id, hint32 *targetVel, huint32 timeout = 100);

    /*!
        写从站字典0x60FF-0
        \param id 从节点id
        \param targetVel 写入值,目标速度
        \param timeout 等待确认时间，单位ms
        \return 成功返回0，失败返回其他
    */
    EXTERNFUNC int harmonic_setTargetVelocity(huint8 id, hint32 targetVel, huint32 timeout = 100);
    EXTERNFUNC int harmonic_getSupportedDriveModes(huint8 id, huint32 *modes, huint32 timeout = 100);

#ifdef __cplusplus
}
#endif

#endif // EU_HARMONIC_H
