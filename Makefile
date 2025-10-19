CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

# Core functions
CORE_SRCS = src/core/get_next_line.c \
			src/core/gnl_read.c \
			src/core/gnl_get_line.c \
			src/core/gnl_trim_stash.c

# String utilities
STRING_SRCS = src/utils/string/ft_strlen.c \
			  src/utils/string/ft_strchr.c \
			  src/utils/string/ft_strjoin.c \
			  src/utils/string/ft_strdup.c

# Memory utilities
MEMORY_SRCS = src/utils/memory/ft_calloc.c \
			  src/utils/memory/ft_bzero.c

# Bonus core functions
BONUS_CORE_SRCS = src/core/bonus/get_next_line_bonus.c \
				  src/core/bonus/gnl_read_bonus.c \
				  src/core/bonus/gnl_get_line_bonus.c \
				  src/core/bonus/gnl_trim_stash_bonus.c

# All source files (mandatory)
SRCS = $(CORE_SRCS) $(STRING_SRCS) $(MEMORY_SRCS)
OBJS = $(SRCS:.c=.o)

# Bonus source files
BONUS_SRCS = $(BONUS_CORE_SRCS) $(STRING_SRCS) $(MEMORY_SRCS)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: gnl

gnl: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

bonus: gnl_bonus

gnl_bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f gnl gnl_bonus

re: fclean all

.PHONY: all bonus clean fclean re
