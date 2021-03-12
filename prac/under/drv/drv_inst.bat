reg add HKLM\SYSTEM\CurrentControlSet\Services\wasadrv /v DispalyName /t REG_SZ /d wasadrv /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\wasadrv /v ErrorControl /t REG_DWORD /d 1 /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\wasadrv /v Group /t REG_SZ /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\wasadrv /v ImagePath /t REG_EXPAND_SZ /d %systemdrive%\wasadrv.sys /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\wasadrv /v Start /t REG_DWORD /d  3 /f
reg add HKLM\SYSTEM\CurrentControlSet\Services\wasadrv /v Type /t REG_DWORD /d 1 /f
