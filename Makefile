NAME = fractol
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I$(MLX_DIR)include

# Directories
OBJ_DIR = obj
LIBFT_DIR = ./libft/
INCLUDE = ./libft/libft.h
MLX_DIR = ./MLX42/
MLX_BUILD = $(MLX_DIR)build/

# Library
LIBFT = $(LIBFT_DIR)libft.a
MLX = $(MLX_BUILD)libmlx42.a

# Linking flags for MinilibX
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MLX_BUILD) -lmlx42 -ldl -lglfw -pthread -lm

# Source files
SRC = src/fractol.c src/fractol_utils.c src/parse_type.c src/ft_atof.c src/window.c src/algorithm.c\
	src/actions.c

# Object files (with obj/ prefix)
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default rule
all: $(NAME)

# Build main program
$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@echo "🔧 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME) && \
		echo "✅ Build successful!" || echo "❌ Build failed!"

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: src/%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "🟢 Compiled $<" || echo "🔴 Failed to compile $<"

# Compile libft with messages
$(LIBFT):
	@echo "📦 Compiling libft..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@if [ $$? -eq 0 ]; then \
		echo "✅ libft compiled successfully!"; \
	else \
		echo "❌ Failed to compile libft!"; \
		exit 1; \
	fi

# Compile MLX42 with messages
$(MLX):
	@echo "📦 Compiling MLX42..."
	@cmake -B $(MLX_BUILD) $(MLX_DIR) > /dev/null
	@cmake --build $(MLX_BUILD) > /dev/null
	@if [ -f $(MLX) ]; then \
		echo "✅ MLX42 compiled successfully!"; \
	else \
		echo "❌ Failed to compile MLX42!"; \
		exit 1; \
	fi
# Clean object files
clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@if [ -d $(MLX_BUILD) ]; then cmake --build $(MLX_BUILD) --target clean > /dev/null 2>&1; fi

# Clean everything
fclean: clean
	@echo "🧹 Removing binaries..."
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX_BUILD)

# Rebuild all
re: fclean all

.PHONY: all clean fclean re
