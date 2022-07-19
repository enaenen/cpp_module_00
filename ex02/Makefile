NAME = Account
CXX = clang++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
SRCS = Account.cpp tests.cpp
OBJ = $(SRCS:.cpp=.o)

OBJS	= ${SRCS:%.cpp=%.o}

$(NAME)	: $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@ 

all		: $(NAME)

clean	: 
			@rm -rf $(OBJ)

fclean	: clean
			@rm -rf $(NAME)

re		: fclean
		make all

.PHONY	: all clean fclean re