COMPILE_OPTS= -g -Wall 

TESTER_OUTPUT_NAME=tester
TESTER_OUTPUT_BUILD=getpwnam.o test.c
TESTER_OUTPUT_DEPS=getpwnam.h $(TESTER_OUTPUT_BUILD)

ERREXIT_BUILD=errExit.c
ERREXIT_DEPS=$(ERREXIT_BUILD)

GETPWNAM_BUILD=getpwnam.c
GETPWNAM_DEPS=$(GETPWNAM_BUILD)

.PHONY: all
all: $(TESTER_OUTPUT_NAME)
	
test: $(TESTER_OUTPUT_NAME)
	./$(TESTER_OUTPUT_NAME)

memtest: $(TESTER_OUTPUT_NAME)
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./$(TESTER_OUTPUT_NAME)

$(TESTER_OUTPUT_NAME): $(TESTER_OUTPUT_DEPS)
	cc $(COMPILE_OPTS) -o $@ $(TESTER_OUTPUT_BUILD)

getpwnam.o: $(GETPWNAM_DEPS)
	cc $(COMPILE_OPTS) -c -o $@ $(GETPWNAM_BUILD)

clean:
	rm $(TESTER_OUTPUT_NAME) *.o
