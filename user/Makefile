
include ../Makefile.config

USER_PROGRAMS=ball.fapp clock.fapp copy.fapp livestat.fapp manager.fapp fractal.fapp procstat.fapp saver.fapp snake.fapp sysstat.fapp flarewin.fapp rgb_test.fapp

all: $(USER_PROGRAMS)

%.o: %.c
	${CC} ${KERNEL_CCFLAGS} -I ../include $< -o $@

%.fapp: %.o ../library/user-start.o ../library/baselib.a
	${LD} ${KERNEL_LDFLAGS} -Ttext 0x80000000 ../library/user-start.o $< ../library/baselib.a -o $@

clean:
	rm -rf *.fapp *.o
