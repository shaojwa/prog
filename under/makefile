

# 20140819 

app=udx.exe
srv=srv
common=common

CC_DEBUG = -DWIN32 -D_DEBUG -D_CONSOLE /MTd /Zi
CC_RELEASE = -DWIN32 -D_NDEBUG -D_CONSOLE /MT /Zi
LK =  /INCREMENTAL:YES /NOLOGO /subsystem:console

OUT_DEBUG=out_debug
OUT_RELEASE=out_release

!IFDEF debug
CC = $(CC_DEBUG)
OUTDIR=$(OUT_DEBUG)
!ELSE
CC = $(CC_RELEASE)
OUTDIR=$(OUT_RELEASE)
!ENDIF


all:$(OUTDIR) $(OUTDIR)\$(app)


$(OUTDIR):
    if not exist "$(OUTDIR)" mkdir $(OUTDIR) 

#link
$(OUTDIR)\udx.exe:$(OUTDIR)\srv_main.obj $(OUTDIR)\logger.obj
   link $(LK) /out:$(OUTDIR)\udx.exe /pdb:$(OUTDIR)\udx.pdb $(OUTDIR)\srv_main.obj  $(OUTDIR)\logger.obj kernel32.lib


#compile
$(OUTDIR)\srv_main.obj:$(srv)\srv_main.cpp
    cl /c -D_X86=1 $(CC) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(srv)\srv_main.cpp

$(OUTDIR)\logger.obj:$(common)\logger.cpp
    cl /c -D_X86=1 $(CC) /Fo"$(OUTDIR)\\" /Fd"$(OUTDIR)\\" $(common)\logger.cpp


clean:
    if exist $(OUT_DEBUG) del /f /q $(OUT_DEBUG)
    if exist $(OUT_RELEASE) del /f /q $(OUT_RELEASE)
