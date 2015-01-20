EXEC = book
OBJS = main.o manage.o

all: $(EXEC)
$(EXEC): $(OBJS)
	gcc -o  $@ $(OBJS)


clean:
	@rm -rf $(OBJS)
	@rm -rf $(EXEC)
