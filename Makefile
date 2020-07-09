src_dir=$(pwd)
target=print_triangle
objects=$(target:%=%.o)

$(target):$(objects)

all:$(target)

clean:
	rm $(target) $(objects)

lint:
	find ${src_dir} -iname "*.[ch]" | xargs clang-format-6.0 -i

.PHONY:all clean