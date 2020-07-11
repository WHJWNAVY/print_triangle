src_dir=$(pwd)
TARGET:=print_triangle
OBJECTS:=$(TARGET:%=%.o)
CC:=arm-926ejs-linux-gnueabi-gcc

$(TARGET):$(OBJECTS)

all:$(TARGET)

clean:
	rm $(TARGET) $(OBJECTS)

lint:
	find ${src_dir} -iname "*.[ch]" | xargs clang-format-6.0 -i

.PHONY:all clean
