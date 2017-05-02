SUBDIRS = docs music icon
EXTRA_DIST = plugins.cfg.in resources.cfg.in hiscore.lst.in

dist_pixmapinstall_DATA = funguloids.png
dist_gameinstall_DATA = gamesettings.cfg
dist_docinstall_DATA = readme.html
gameinstall_DATA = plugins.cfg resources.cfg

plugins.cfg: plugins.cfg.in
	cat plugins.cfg.in | sed 's,%%ogreplugindir%%,@ogreplugindir@/,' > plugins.cfg

resources.cfg: resources.cfg.in
	cat resources.cfg.in | sed 's,%%gameinstalldir%%,@gameinstalldir@/,' > resources.cfg

# copy the exe into this dir only for developing, real installation is done directly in ../bin/Makefile
all: bootstrap.mpk funguloids.mpk
	cp -a ../src/funguloids .

bootstrap.mpk: $(top_srcdir)/src/makempk
	$(top_srcdir)/src/makempk add bootstrap.mpk $(top_srcdir)/mpk/bootstrap/*


funguloids.mpk: $(top_srcdir)/src/makempk
	$(top_srcdir)/src/makempk add funguloids.mpk $(top_srcdir)/mpk/funguloids/*


install-data-hook: bootstrap.mpk funguloids.mpk
	if test "x@highscoredir@" != "x"; then \
		mkdir -p "@highscoredir@"; \
		if test ! -e "@highscoredir@/hiscore.lst"; then cp hiscore.lst.in "@highscoredir@/hiscore.lst"; fi; \
		chgrp -R @highscoregroup@ "@highscoredir@"; \
		chmod -R g+w "@highscoredir@"; \
	fi; \
	cp bootstrap.mpk "@gameinstalldir@"
	cp funguloids.mpk "@gameinstalldir@"

uninstall-hook:
	rm -rf "@docinstalldir@"

distclean: clean

clean:
	-rm -f funguloids funguloids.sh plugins.cfg resources.cfg Ogre.log ogre.cfg bootstrap.mpk funguloids.mpk *~

