# **************************************************************************** #
#                               MAKEFILE CONFIG                                #
# **************************************************************************** #

NAME		= myAwesomePhoneBook

# Compiler and flags
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Iinc -std=c++98

# Source folders
SRC_DIR		= src

# Source files
SRC_FILES	= \
	$(SRC_DIR)/Contact.cpp \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/PhoneBook.cpp \

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