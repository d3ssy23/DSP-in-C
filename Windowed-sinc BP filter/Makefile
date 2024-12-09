CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = ../waveforms.c bandpass_windowsinc.c 

TARGET = bandpass_windowsinc

$(TARGET) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -rf $(TARGET)