NAME	=	ft_containers

CC		=	clang++
FLAGS	=	-Wall -Wextra -Werror -g -std=c++98
GCC		=	$(CC) $(FLAGS)

SRCS	=	main.cpp vector_test.cpp stack_test.cpp
HDRS	=	./containers/Vector.hpp ./containers/Stack.hpp ./utils/Iterator.hpp ./utils/Type_traits.hpp ./utils/Equal.hpp ./utils/Pair.hpp
OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

%.o:		%.cpp $(HDRS)
			$(GCC) -c -o $@ $<

$(NAME):	$(OBJS)
			$(GCC) $(OBJS) -o $(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
