TARGET = Bus 
SRC = file.c list.c main.c menu.c func.c
OBJS = file.o list.o main.o menu.o func.o
CC = gcc


$(TARGET) : $(OBJS)
	$(CC) $^ -o $(TARGET)
$(OBJS) : $(SRC)
	$(CC) -c $^

.PHONY : clean
clean :
	rm *.o $(TARGET)

