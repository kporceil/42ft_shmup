include srcs.mk

NAME := ft_shmup

CC := cc

CFLAGS := -Wall -Wextra -Werror -g3

CPPFLAGS := -I

INCLUDES := includes

DEPSFLAGS := -MD -MP -MF

LIBFLAGS := -lncursesw -lm

MAKEFLAGS += --no-print-directory

SUBDIRSTATE := .subdirstate

.PHONY: all
all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c | $(SUBDIRSTATE)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@

$(SUBDIRSTATE): | $(OBJDIR) $(DEPDIR)
	@touch $@
	mkdir -p $(OBJSUBDIR) $(DEPSUBDIR)

$(OBJDIR) $(DEPDIR): | $(BUILDDIR)
	mkdir -p $@

$(BUILDDIR):
	mkdir -p $@

.PHONY: clean
clean:
	rm -rf $(BUILDDIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f $(SUBDIRSTATE)


.PHONY: re
re: fclean all

.PHONY: debug
debug:
	$(MAKE) $(NAME) CFLAGS="-Wall -Wextra -g3 -DDEBUG"

-include $(DEPS)
