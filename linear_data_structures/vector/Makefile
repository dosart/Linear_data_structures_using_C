CC 				:= gcc
CFLAGS 			:= -Wall -Wextra -Werror -pedantic-errors

SRCMODULES 		:= $(wildcard src/*.c)
OBJMODULES 		:= $(SRCMODULES:.c=.o)
DEPENDENCIES 	:= $(OBJMODULES:.o=.d)
TESTS			:= $(wildcard tests/*.c)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
%.d: %.c
	@$(CC) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

-include $(DEPENDENCIES)

test: $(TESTS) $(OBJMODULES)
	$(CC) $(CFLAGS)  $^ -o build/$@
	rm -f src/*.o
	rm -f src/*.d

