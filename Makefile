# vim: ts=8 sw=8

CC	=ccache gcc -march=i686
CFLAGS	=-pipe -Os -g -Wall -Werror -pedantic
LDFLAGS	=-g
LDLIBS	=

all::	sissy

clean::
	${RM} *.o a.out core.* lint tags

distclean clobber:: clean
	${RM} sissy

check::	sissy
	./sissy
