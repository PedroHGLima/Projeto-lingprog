CC=g++
CFLAGS=-I/usr/include/python3.10 -I/usr/include/python3.10 -Wno-unused-result -Wsign-compare -g -fstack-protector-strong -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O2 -Wall
LDFLAGS=-L/usr/lib/python3.10/config-3.10-x86_64-linux-gnu -L/usr/lib/x86_64-linux-gnu -lpython3.10 -lcrypt -ldl  -lm -lm 

PROGRAM=trab
OBJS=test.o arvore.o pais.o mundo.o

all: $(PROGRAM)

exec: $(PROGRAM)
	./$(PROGRAM)

execlean: $(PROGRAM) clean
	./$(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(PROGRAM) $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -vf $(OBJS)

clean-all:
	rm -vf $(OBJS) $(PROGRAM) *.out
