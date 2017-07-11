CC = gcc
FILES = main.c steps.c
OUT_EXE = out_executable

build: $(FILES)
		$(CC) -o $(OUT_EXE) $(FILES) -lwiringPi
		
clean:
		rm -f *.o core
		
rebuild: clean rebuild
