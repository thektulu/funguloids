musicinstall_DATA = playlist.lua MarylandInMay.ogg

EXTRA_DIST = playlist.lua.in

playlist.lua: playlist.lua.in
	cat playlist.lua.in | sed 's,%%musicinstalldir%%,@musicinstalldir@,' > playlist.lua

distclean: clean

clean:
	-rm -f playlist.lua *~
