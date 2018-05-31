sort:sort.c
	gcc -o $@ $^
.PHONY:clean
clean:
	rm -f sort
