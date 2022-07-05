NAME	=	ft_containers

CC		=	clang++
FLAGS	=	-Wall -Wextra -Werror -std=c++98
GCC		=	$(CC) $(FLAGS)

SRCS	=	main.cpp vector_test.cpp stack_test.cpp
CONT_HDRS	=	./containers/Vector.hpp ./containers/Stack.hpp ./containers/Map.hpp \
UTIL_HDRS	=	./utils/Iterator.hpp ./utils/Type_traits.hpp ./utils/Equal.hpp ./utils/Pair.hpp ./utils/RBTree.hpp \
					./utils/RBTree_iterator.hpp ./utils/Node.hpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

%.o:		%.cpp $(CONT_HDRS) $(UTIL_HDRS)
			$(GCC) -c -o $@ $<

$(NAME):	$(OBJS)
			$(GCC) $(OBJS) -o $(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
