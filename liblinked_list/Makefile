# DA MIGLIORARE
all: main
	bin/main

test1: test
	bin/test

main:
	gcc main.c lib/data.c lib/list.c lib/list_util.c -o bin/main

test:
	gcc test.c lib/data.c lib/list.c lib/list_util.c -o bin/test

clean:
	rm bin/*