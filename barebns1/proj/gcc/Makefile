PROJECT         = barebns1

DEMO_APP_ROOT   = ../..
CROCON_ROOT     = ../../../..

CROCON_DEBUG    =? false

PREFIX          = /usr/local
INC_DIRS        = $(DEMO_APP_ROOT)/include

SRC_DIR         = $(DEMO_APP_ROOT)/src
DEF_DIR         = $(DEMO_APP_ROOT)/def
RES_DIR         = $(DEMO_APP_ROOT)/res

SRC_DIRS        = $(SRC_DIR)

ifeq ($(CROCON_AOUT),true)
C_PIE           = -fno-pie
else
C_PIE           = -fPIC
endif

ifeq ($(CROCON_LEGACY),true)
C_LEGACY = -DUNIX_LEGACY
else
C_LEGACY = -fno-optimize-sibling-calls
endif

ifeq ($(CROCON_DEBUG),true)
C_FLAGS         =  -O0 $(C_PIE) -DUNIX $(C_LEGACY) -DHAVE_VPRINTF -g3 -fno-omit-frame-pointer
else
C_FLAGS         =  -O2 $(C_PIE) -DUNIX $(C_LEGACY) -DHAVE_VPRINTF
endif

BIN_DIR         = $(CROCON_ROOT)/out/demos/$(PROJECT)/bin
OBJ_DIR         = $(CROCON_ROOT)/out/demos/$(PROJECT)/obj

SOURCES         = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

OBJECTS         = $(OBJ_DIR)/main.o

all: prepare $(BIN_DIR)/$(PROJECT).bin

prepare:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(C_FLAGS) -I$(INC_DIRS) -I$(CROCON_ROOT)/library/include -c $< -o $@

$(BIN_DIR)/$(PROJECT).bin: $(OBJECTS)
	$(CC) $(LD_ARCH) $(OBJECTS) -DUNIX -L$(CROCON_ROOT)/out/library/bin -lcrocon -o $@ $(LD_FLAGS)

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

rebuild:
	clean all

.PHONY: 
	all clean rebuild
