
#include <NTDDK.h> 

VOID drv_unload(PDRIVER_OBJECT pdrvobj);


/*****************************************************************************
 函 数 名  : DirverEntry
 功能描述  : 初始化驱动程序
 输入参数  : pDriverObject
             pRegistryPath
 输出参数  : 无
 返 回 值  : NTSTATUS
------------------------------------------------------------------------------
 最近一次修改记录  : 
 修改作者  : w00525
 修改目的  :
 修改日期  : 2015年4月26日
*****************************************************************************/
NTSTATUS DriverEntry(IN PDRIVER_OBJECT pdrvobj,
                       IN PUNICODE_STRING pregpath)
{
    NTSTATUS status = STATUS_SUCCESS;
    DbgPrint("wasadrv:driverentry:begin");
    pdrvobj->DriverUnload = drv_unload; 
    DbgPrint("wasadrv:driverentry:end");
    return status;
}

VOID drv_unload(PDRIVER_OBJECT pdrvobj)
{
    DbgPrint("wasadrv:drv_unload");
}

