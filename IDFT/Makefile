CC = gcc -Wall -Werror -Wextra 

TARGET = idft

SRCS = ../waveforms.c idft.c

$(TARGET) : $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) -lm

clean:
	rm -rf $(TARGET)	
	