CC ?= gcc
CFLAGS_common ?= -O0 -Wall -ggdb -std=gnu99          #add -ggdb for more default information

#let perf to show the message we want
PERF = stat -r 5 -e cache-misses,cache-references,L1-dcache-load-misses,L1-dcache-store-misses,L1-dcache-prefetch-misses,L1-icache-load-misses

EXEC = phonebook_orig phonebook_opt
all: $(EXEC)

SRCS_common = main.c

phonebook_orig: $(SRCS_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_opt: $(SRCS_common) phonebook_opt.c phonebook_opt.h
	$(CC) $(CFLAGS_common) -DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

#execute phonebook_orig
perf_orig: $(EXEC)
	perf $(PERF) ./phonebook_orig

#execute phonebook_opt
perf_opt: $(EXEC)
	perf $(PERF) ./phonebook_opt

#clear the cache
perf_clear:
	echo "echo 1 > /proc/sys/vm/drop_caches" | sudo sh

run: $(EXEC)
	watch -d -t ./phonebook_orig

clean:
	$(RM) $(EXEC) *.o perf.*
