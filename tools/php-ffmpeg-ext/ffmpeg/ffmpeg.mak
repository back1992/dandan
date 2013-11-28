# Microsoft Developer Studio Generated NMAKE File, Based on ffmpeg.dsp
!IF "$(CFG)" == ""
CFG=ffmpeg - Win32 Release_TS
!MESSAGE No configuration specified. Defaulting to ffmpeg - Win32 Release_TS.
!ENDIF 

!IF "$(CFG)" != "ffmpeg - Win32 Release_TS" && "$(CFG)" != "ffmpeg - Win32 Debug_TS"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ffmpeg.mak" CFG="ffmpeg - Win32 Release_TS"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ffmpeg - Win32 Release_TS" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "ffmpeg - Win32 Debug_TS" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "ffmpeg - Win32 Release_TS"

OUTDIR=.\Release_TS
INTDIR=.\Release_TS
# Begin Custom Macros
OutDir=.\Release_TS
# End Custom Macros

ALL : "..\..\Release_TS\ffmpeg.dll" "$(OUTDIR)\ffmpeg.bsc"


CLEAN :
	-@erase "$(INTDIR)\ffmpeg.obj"
	-@erase "$(INTDIR)\ffmpeg.sbr"
	-@erase "$(INTDIR)\ffmpeg_frame.obj"
	-@erase "$(INTDIR)\ffmpeg_frame.sbr"
	-@erase "$(INTDIR)\ffmpeg_movie.obj"
	-@erase "$(INTDIR)\ffmpeg_movie.sbr"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ffmpeg.bsc"
	-@erase "$(OUTDIR)\ffmpeg.exp"
	-@erase "..\..\Release_TS\ffmpeg.dll"
	-@erase "..\..\Release_TS\ffmpeg.ilk"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MD /W3 /GX /O2 /I "..\.." /I "..\..\main" /I "..\..\Zend" /I "..\..\..\bindlib_w32" /I "..\..\TSRM" /D ZEND_DEBUG=0 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FFMPEG_EXPORTS" /D "COMPILE_DL_FFMPEG" /D ZTS=1 /D "ZEND_WIN32" /D "PHP_WIN32" /D HAVE_FFMPEG=1 /D "LIBZEND_EXPORTS" /FR"$(INTDIR)\\" /Fp"$(INTDIR)\ffmpeg.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c /Tc 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ffmpeg.bsc" 
BSC32_SBRS= \
	"$(INTDIR)\ffmpeg.sbr" \
	"$(INTDIR)\ffmpeg_frame.sbr" \
	"$(INTDIR)\ffmpeg_movie.sbr"

"$(OUTDIR)\ffmpeg.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib php4ts.lib /nologo /dll /incremental:yes /pdb:"$(OUTDIR)\ffmpeg.pdb" /machine:I386 /out:"..\..\Release_TS/ffmpeg.dll" /implib:"$(OUTDIR)\ffmpeg.lib" /libpath:"..\..\Release_TS" /libpath:"..\..\Release_TS_Inline" 
LINK32_OBJS= \
	"$(INTDIR)\ffmpeg.obj" \
	"$(INTDIR)\ffmpeg_frame.obj" \
	"$(INTDIR)\ffmpeg_movie.obj" \
	".\avcodec.lib" \
	".\avformat.lib" \
	"..\..\RELEASE_TS\php4ts.lib"

"..\..\Release_TS\ffmpeg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "ffmpeg - Win32 Debug_TS"

OUTDIR=.\Debug_TS
INTDIR=.\Debug_TS

ALL : "..\..\Debug_TS\ffmpeg.dll"


CLEAN :
	-@erase "$(INTDIR)\ffmpeg.obj"
	-@erase "$(INTDIR)\ffmpeg_frame.obj"
	-@erase "$(INTDIR)\ffmpeg_movie.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(OUTDIR)\ffmpeg.exp"
	-@erase "$(OUTDIR)\ffmpeg.lib"
	-@erase "..\..\Debug_TS\ffmpeg.dll"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MDd /W3 /GX /O2 /I "..\.." /I "..\..\main" /I "..\..\Zend" /I "..\..\..\bindlib_w32" /I "..\..\TSRM" /D ZEND_DEBUG=1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "FFMPEG_EXPORTS" /D "COMPILE_DL_FFMPEG" /D ZTS=1 /D "ZEND_WIN32" /D "PHP_WIN32" /D HAVE_FFMPEG=1 /D "LIBZEND_EXPORTS" /Fp"$(INTDIR)\ffmpeg.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\ffmpeg.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib php4ts_debug.lib /nologo /dll /incremental:no /pdb:"$(OUTDIR)\ffmpeg.pdb" /machine:I386 /out:"..\..\Debug_TS/ffmpeg.dll" /implib:"$(OUTDIR)\ffmpeg.lib" /libpath:"..\..\Debug_TS" 
LINK32_OBJS= \
	"$(INTDIR)\ffmpeg.obj" \
	"$(INTDIR)\ffmpeg_frame.obj" \
	"$(INTDIR)\ffmpeg_movie.obj" \
	".\avcodec.lib" \
	".\avformat.lib" \
	"..\..\RELEASE_TS\php4ts.lib"

"..\..\Debug_TS\ffmpeg.dll" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("ffmpeg.dep")
!INCLUDE "ffmpeg.dep"
!ELSE 
!MESSAGE Warning: cannot find "ffmpeg.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "ffmpeg - Win32 Release_TS" || "$(CFG)" == "ffmpeg - Win32 Debug_TS"
SOURCE=.\ffmpeg.c

!IF  "$(CFG)" == "ffmpeg - Win32 Release_TS"


"$(INTDIR)\ffmpeg.obj"	"$(INTDIR)\ffmpeg.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ffmpeg - Win32 Debug_TS"


"$(INTDIR)\ffmpeg.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ffmpeg_frame.c

!IF  "$(CFG)" == "ffmpeg - Win32 Release_TS"


"$(INTDIR)\ffmpeg_frame.obj"	"$(INTDIR)\ffmpeg_frame.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ffmpeg - Win32 Debug_TS"


"$(INTDIR)\ffmpeg_frame.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 

SOURCE=.\ffmpeg_movie.c

!IF  "$(CFG)" == "ffmpeg - Win32 Release_TS"


"$(INTDIR)\ffmpeg_movie.obj"	"$(INTDIR)\ffmpeg_movie.sbr" : $(SOURCE) "$(INTDIR)"


!ELSEIF  "$(CFG)" == "ffmpeg - Win32 Debug_TS"


"$(INTDIR)\ffmpeg_movie.obj" : $(SOURCE) "$(INTDIR)"


!ENDIF 


!ENDIF 

