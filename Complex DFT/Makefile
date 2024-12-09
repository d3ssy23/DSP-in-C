CC = gcc -Wall -Werror -Wextra

SRC = complexDFT.c waveforms.c

TARGET = complexDFT

$(TARGET) : $(SRC)
	$(CC) $(SRC) -o $(TARGET)
clean:
	rm -rf $(TARGET)