objects = debugger.o logger.o

debugger: $(objects)
	gcc -o debugger $(objects)
debugger.o: debugger.c logger.h
	gcc -g -c debugger.c
logger.o: logger.c logger.h
	gcc -g -c logger.c

.PHONY: clean
clean:
	-rm debugger $(objects)
