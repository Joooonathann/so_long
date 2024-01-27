CC = gcc
CFLAGS = -I./include
LDFLAGS = -ldl -lglfw -pthread -lm
SOURCES = src/so_long.c $(wildcard src/map/parsing/*.c) $(wildcard src/basic/*.c)
OBJDIR = objs
OBJECTS = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(SOURCES)))
EXECUTABLE = so_long

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ -I ./include ./MLX42/build/libmlx42.a $(LDFLAGS)

$(OBJDIR)/%.o: src/map/parsing/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: src/basic/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/so_long.o: src/so_long.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)
