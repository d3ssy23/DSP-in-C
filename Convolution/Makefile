CC = gcc

TARGET = convolution

SRCS = ../waveforms.c convolution.c filter_kernel.c

$(TARGET) : $(SRCS)
	$(CC) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)