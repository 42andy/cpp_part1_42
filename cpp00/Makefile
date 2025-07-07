NAME = launcher
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCDIR = .
OBJDIR = obj

SRCS = launcher.cpp
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME) ex00 ex01

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

ex00:
	@make -C ex00 --no-print-directory

ex01:
	@make -C ex01 --no-print-directory

clean:
	rm -rf $(OBJDIR)
	@make -C ex00 clean --no-print-directory
	@make -C ex01 clean --no-print-directory

fclean:
	rm -rf $(OBJDIR)
	rm -f $(NAME)
	@make -C ex00 fclean --no-print-directory
	@make -C ex01 fclean --no-print-directory

re: fclean all

.PHONY: all clean fclean re ex00 ex01
