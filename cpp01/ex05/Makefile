NAME = harl
CXX = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Iinc

SRCDIR = src
INCDIR = inc
OBJDIR = obj

SRCS =	$(SRCDIR)/Harl.cpp \
		$(SRCDIR)/main.cpp \

OBJS = $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean: 
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re