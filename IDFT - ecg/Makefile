CC = gcc -Wall -Werror -Wextra 

TARGET = ecg

SRCS = idft.c 

$(TARGET) : $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) 

clean:
	rm -rf $(TARGET)	
	