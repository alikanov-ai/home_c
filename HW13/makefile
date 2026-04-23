ifeq ($(OS),Windows_NT)
	# Команды для Windows
	RM = del
	EXE = .exe
else
	# Команды для Unix-подобных систем
	RM = rm -f
	EXE =
endif
TARGET = prog$(EXE)

all: $(TARGET)

$(TARGET): main.o temp_functions.o
	gcc -o $(TARGET) main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c temp_functions.h
	gcc -c -o temp_functions.o temp_functions.c

clean:
	$(RM) *.o $(TARGET)