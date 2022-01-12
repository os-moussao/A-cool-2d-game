#
# names
#
NAME := so_long

RM := rm -rf

CC := cc

CFLAGS := -Wall -Werror -Wextra

MLX_FLAGS := -lmlx -framework OpenGL -framework AppKit

#
# rules not to mixed with similar file names
#
.PHONY: all clean fclean re bonus

#
# directories
#
INCLUDE := include/

SRC_DIR := src/

#
# necessary files
#
CFILES := main.c utils.c list_utils.c get_next_line.c render.c events.c
HFILES := $(INCLUDE)so_long.h

SRC := $(addprefix $(SRC_DIR), $(CFILES))

OBJ := $(SRC:.c=.o)
# OBJB := $(SRCB:.c=.o)

#
# rules
#
all: $(NAME)

rr: re clean run

run: 
	./so_long map/map2_valid.ber

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $@ $(OBJ)

%.o: %.c $(HFILES)
	$(CC) $(CFLAGS) -c $< -I$(INCLUDE) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all