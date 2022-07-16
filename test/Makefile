NAME = testing
CXX = clang++
CXXFLAG = -Wall -Wextra -Werror -std=c++98
SRCS = getlineTest.cpp
OBJ = $(SRCS:.cpp=.o)

OBJS	= ${SRCS:%.cpp=%.o}

$(NAME)	: $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@ 

all		: $(NAME)

clean	: clean
			@rm -rf $(OBJ)

fclean	:
			@rm -rf $(NAME)

re		: fclean
		make all

.PHONY	: all clean fclean re