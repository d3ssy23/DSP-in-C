CC = gcc -Wall -Werror -Wextra 

TARGET = dft

SRCS = ../waveforms.c main.c

$(TARGET) : $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) -lm

clean:
	rm -rf $(TARGET)	
	