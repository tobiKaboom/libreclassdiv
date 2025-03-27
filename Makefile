SOURCE1 = src/libreclassdiv.c

TARGET1 = bin/libreclassdiv.bin

all: create_bin_dir
	cc -o $(TARGET1) $(SOURCE1)

clean:
	rm -rf $(TARGET1)

create_bin_dir:
	mkdir -p bin
