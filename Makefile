include srcs.mk

NAME := ft_shmup

CC := cc

CFLAGS := -Wall -Wextra -Werror

CPPFLAGS := -I

INCLUDES := includes

DEPSFLAGS := -MD -MP -MF

LIBFLAGS := -lncursesw

MAKEFLAGS += --no-print-directory

SUBDIRSTATE := .subdirstate

.PHONY: all
all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@echo -n ""
	@echo -n "$(COMPILEICON)$(COMPILECOLOR)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(LIBFLAGS) $(OBJS) -o $(NAME)
	@echo -n "$(RESETCOLOR)"

$(OBJDIR)%.o: $(SRCDIR)%.c | $(SUBDIRSTATE)
	@echo -n "$(BUILDICON)$(OBJSCOLOR)"
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) $(DEPSFLAGS) $(DEPDIR)$*.d -c $< -o $@
	@echo -n "$(RESETCOLOR)"

$(SUBDIRSTATE): | $(OBJDIR) $(DEPDIR)
	@touch $@
	@echo -n "$(MKDIRICON)$(MKDIRCOLOR)"
	mkdir -p $(OBJSUBDIR) $(DEPSUBDIR)
	@echo -n "$(RESETCOLOR)"

$(OBJDIR) $(DEPDIR): | $(BUILDDIR)
	@echo -n "$(MKDIRICON)$(MKDIRCOLOR)"
	mkdir -p $@
	@echo -n "$(RESETCOLOR)"

$(BUILDDIR):
	@echo -n "$(MKDIRICON)$(MKDIRCOLOR)"
	mkdir -p $@
	@echo -n "$(RESETCOLOR)"

.PHONY: clean
clean:
	@echo -n "$(CLEANICON)$(CLEANCOLOR)"
	rm -rf $(BUILDDIR)
	@echo -n "$(RESETCOLOR)"

.PHONY: fclean
fclean: clean
	@echo -n "$(CLEANICON)$(CLEANCOLOR)"
	rm -f $(NAME)
	@rm -f $(SUBDIRSTATE)
	@echo -n "$(RESETCOLOR)"


.PHONY: re
re: fclean all

.PHONY: noflags
noflags:
	@$(MAKE) $(NAME) CFLAGS=""

-include $(DEPS)
