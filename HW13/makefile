CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = temp_app
OBJS = main.o temp_api.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c temp_api.h
	$(CC) $(FLAGS) -c main.c

temp_api.o: temp_api.c temp_api.h
	$(CC) $(FLAGS) -c temp_api.c

clean:
	del /q /f $(OBJS) $(TARGET).exe 2>nul || exit 0
