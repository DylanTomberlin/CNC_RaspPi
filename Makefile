CC = gcc
FILES = main.c motor.c MotorControls.c debug.c
OUT_EXE = main

build: $(FILES)
		$(CC) -o $(OUT_EXE) $(FILES) -lwiringPi -lm
		
clean:
		rm -f *.o core
		
rebuild: clean build
