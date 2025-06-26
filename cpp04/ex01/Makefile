CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Animal.cpp Dog.cpp Cat.cpp Brain.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ex01

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
