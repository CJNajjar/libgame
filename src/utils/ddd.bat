@echo off
SET DISPLAY=127.0.0.1:0.0

SET CYGWIN_ROOT=\

SET RUN=%CYGWIN_ROOT%\sbin\run -p /usr/X11R6/bin

SET PATH=.;%CYGWIN_ROOT%\bin;%CYGWIN_ROOT%\usr\X11R6\bin;%PATH%

SET XAPPLRESDIR=/usr/X11R6/lib/X11/app-defaults
SET XCMSDB=/usr/X11R6/lib/X11/Xcms.txt
SET XKEYSYMDB=/usr/X11R6/lib/X11/XKeysymDB
SET XNLSPATH=/usr/X11R6/lib/X11/locale

D:
chdir D:\work\libgame

rhc XWin -multiwindow -clipboard -silent-dup-error
rhc %CYGWIN_ROOT%\bin\ddd src/utils/hde32
