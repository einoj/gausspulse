CC   = gcc
LD   = gcc
SIZE = size -d

SRC_DIR   = ./src
EX_DIR    = ./example
BUILD_DIR = ./build
INCLUDE   = -I $(SRC_DIR)

SRCS 	 = $(wildcard $(addsuffix /*.c, $(SRC_DIR)))
EXAMPLES = $(wildcard $(addsuffix /*.c, $(EX_DIR)))
OBJS = $(SRCS:.c=.o)
OBJS += $(EXAMPLES:.c=.o)
BUILD = $(addprefix $(BUILD_DIR)/, $(notdir $(OBJS)))

BIN = gauss_pulse

FLAGS += $(INCLUDE)
FLAGS += -lm
FLAGS += -std=c99
FLAGS += -Wall -Wextra

LDFLAGS += -lm
LDFLAGS += -fno-exceptions
LDFLAGS += -fno-rtti

all: $(BIN)

$(BIN): $(OBJS)
	$(LD) $(BUILD) $(LDFLAGS) -o $(BIN)
	$(SIZE) $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

%.o: %.c $(BUILD_DIR)
	$(CC) -c $(FLAGS) -o $(BUILD_DIR)/$(notdir $@) $<

plot: all
	./$(BIN)
	gnuplot -p ./plotcsv.gnuplot

clean:
	rm -r $(BUILD_DIR)
	rm $(BIN)
	rm $(BIN).csv
