NAME = f.test

SRC = *.c

TMP_MAIN = test_main.c

all: $(NAME)

test: $(NAME) lldb fclean

$(NAME):
#	cc -g $(SRC) -o $(NAME)
	@cc -g -o $(NAME) $(SRC) > /dev/null 2>&1 || { \
		echo "Compilation failed!"; \
		exit 1; \
	}

lldb: $(NAME)
	lldb -o "b main" -o "r" $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all
