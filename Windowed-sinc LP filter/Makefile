CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = ../waveforms.c LPWindowed-sinc.c 

TARGET = LPWindowed-sinc

$(TARGET) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(TARGET)