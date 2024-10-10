NAME = ex01
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = WrongAnimal.cpp \
	main.cpp \
	Dog.cpp \
	Animal.cpp \
	Cat.cpp \
	WrongCat.cpp \
	Brain.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re