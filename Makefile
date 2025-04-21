LIBFT_DIR = libft
BONUS_DIR = bonus
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRV_SRC = server.c
CLI_SRC = client.c
SRV_SRC_BONUS = server_bonus.c
CLI_SRC_BONUS = client_bonus.c
SRV_OBJ = $(SRV_SRC:.c=.o)
CLI_OBJ = $(CLI_SRC:.c=.o)
SRV_BONUS_OBJ = $(SRV_SRC_BONUS:.c=.o)
CLI_BONUS_OBJ = $(CLI_SRC_BONUS:.c=.o)
SRV_BIN = server
CLI_BIN = client
SRV_BONUS_BIN = server_bonus
CLI_BONUS_BIN = client_bonus

all: $(SRV_BIN) $(CLI_BIN) 
$(LIBFT):
	@make -C $(LIBFT_DIR)
$(SRV_BIN): $(SRV_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_OBJ) $(LIBFT) -o $(SRV_BIN) 
$(CLI_BIN): $(CLI_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CLI_OBJ) $(LIBFT) -o $(CLI_BIN) 
bonus:  $(SRV_BONUS_BIN) $(CLI_BONUS_BIN)
$(SRV_BONUS_BIN): $(SRV_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRV_BONUS_OBJ) $(LIBFT) -o $(SRV_BONUS_BIN) 
$(CLI_BONUS_BIN): $(CLI_BONUS_OBJ)
	$(CC) $(CFLAGS) $(CLI_BONUS_OBJ) $(LIBFT) -o $(CLI_BONUS_BIN) 
%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(SRV_OBJ) $(CLI_OBJ) $(SRV_BONUS_OBJ) $(CLI_BONUS_OBJ)
	make -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(SRV_BIN) $(CLI_BIN) $(SRV_BONUS_BIN) $(CLI_BONUS_BIN)
	make -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all clean fclean re