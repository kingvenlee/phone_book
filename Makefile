objs = main.o manage.o
all:$(objs)
	gcc -o book $(objs)

main.o:main.c
#	gcc -c main.o main.c

manage.o:manage.c
#	gcc -c manage.o manage.c

clean:
	@rm -rf $(objs)
	@rm -rf book
