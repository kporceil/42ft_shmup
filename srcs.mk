SUBDIR := physics/ \
		  render/ \
		  render/ui/ \
		  render/ui/button/ \
		  scenes/ \
		  scenes/game/ \
		  scenes/game/entity/ \
		  scenes/main_menu/

BASENAME := physics/collision \
			physics/movement \
			render/ncurses_init_del \
			render/ui/button/ui_button_actions \
			render/ui/button/ui_button_extras \
			render/ui/button/ui_button_memory \
			render/ui/button/ui_button_utils \
			scenes/game/game \
			scenes/game/game_init_del \
			scenes/game/game_render \
			scenes/game/game_input \
			scenes/game/game_update \
			scenes/game/game_enemy \
			scenes/game/entity/entity \
			scenes/game/entity/entity_enemy_bomb \
			scenes/game/entity/entity_enemy_laser \
			scenes/game/entity/entity_enemy_ship \
			scenes/game/entity/entity_player_laser \
			scenes/game/entity/entity_player_ship \
			scenes/main_menu/main_menu \
			scenes/main_menu/main_menu_input \
			scenes/main_menu/main_menu_render \
			ft_shmup \
			main




SRCDIR := sources/

SRCFILE := $(addsuffix .c, $(BASENAME))

SRCS := $(addprefix $(SRCDIR), $(SRCFILE))

BUILDDIR := .build/

OBJDIR := $(addprefix $(BUILDDIR), objs/)

OBJSUBDIR := $(addprefix $(OBJDIR), $(SUBDIR))

OBJFILE := $(addsuffix .o, $(BASENAME))

OBJS := $(addprefix $(OBJDIR), $(OBJFILE))

DEPDIR := $(addprefix $(BUILDDIR), deps/)

DEPSUBDIR := $(addprefix $(DEPDIR), $(SUBDIR))

DEPFILE := $(addsuffix .d, $(BASENAME))

DEPS := $(addprefix $(DEPDIR), $(DEPFILE))



#COLOR

#grey
MKDIRCOLOR := \033[38;5;244m
#red
CLEANCOLOR := \033[38;5;1m 
#blue
OBJSCOLOR := \033[38;5;38m
#green
COMPILECOLOR := \033[38;5;112m
RESETCOLOR := \033[0m

# EMOJI

MKDIRICON := 🏗️
BUILDICON := 🛠️
CLEANICON := 🚮
COMPILEICON := ✅
