INCLUDES= -I ./include
FLAGS= -g

OBJECTS=./build/chip8_memory.o ./build/chip8_stack.o ./build/chip8_keyboard.o ./build/chip8.o

all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} -L ./lib -lmingw32 -lSDL2main -lSDL2 -o ./bin/main

./build/chip8_memory.o:src/chip8_memory.c
	gcc ${FLGAS} ${INCLUDES} ./src/chip8_memory.c -c -o ./build/chip8_memory.o

./build/chip8_stack.o:src/chip8_stack.c
	gcc ${FLGAS} ${INCLUDES} ./src/chip8_stack.c -c -o ./build/chip8_stack.o

./build/chip8_keyboard.o:src/chip8_stack.c
	gcc ${FLGAS} ${INCLUDES} ./src/chip8_keyboard.c -c -o ./build/chip8_keyboard.o

./build/chip8.o:src/chip8_stack.c
	gcc ${FLGAS} ${INCLUDES} ./src/chip8.c -c -o ./build/chip8.o
clean:
	del build\*

run: 
	./bin/main.exe