CC = gcc
CFLAGS = -Wall

all: image_manipulation

image_manipulation: src/main.c src/image.c src/filters.c src/utils.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f image_manipulation
