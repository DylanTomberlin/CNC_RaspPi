CC = gcc
FILES = main.c motor.c MotorControls.c
OUT_EXE = out_executable

build: $(FILES)
		$(CC) -o $(OUT_EXE) $(FILES) -lwiringPi -lm
		
clean:
		rm -f *.o core
		
rebuild: clean build
