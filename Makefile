INCLUDES= -I ./include
FLAGS= -g

OBJECTS=./build/chip8_memory.o

all: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.c ${OBJECTS} -L ./lib -lmingw32 -lSDL2main -lSDL2 -o ./bin/main

./build/chip8_memory.o:src/chip8_memory.c
	gcc ${FLGAS} ${INCLUDES} ./src/chip8_memory.c -c -o ./build/chip8_memory.o

clean:
	del build\*

run: 
	./bin/main.exe