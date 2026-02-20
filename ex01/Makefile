# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME		= megaphone

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Iinc -std=c++98

# Source folders
SRC_DIR		= .

# Source files
SRC_FILES	= $(SRC_DIR)/megaphone.cpp

# Object files
OBJ_FILES	= $(SRC_FILES:.cpp=.o)

# **************************************************************************** #
#                                MAKE RULES                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re