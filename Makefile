objs = main.o manage.o
all:$(objs)
	gcc -o  book $(objs)

main.o:main.c
	gcc -c -g main.o main.c

manage.o:manage.c
	gcc -c -g manage.o manage.c

clean:
	@rm -rf $(objs)
	@rm -rf book
