
STRIP = $(CROSS_COMPILE)strip
CC = $(CROSS_COMPILE)g++
CFLAGS += -Werror -Wfatal-errors -Wunused

OBJS+=$(filter %.o,$(SRC:.cpp=.o))


all: $(TARGET)

%.o: %.cpp  %.h
	@rm -f $@
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@
	$(STRIP) $(TARGET)

clean:
	@for i in $(OBJS); do (if test -e "$$i"; then ( rm $$i ); fi ); done
	@rm -f $(TARGET)
	@rm -f .stamp_built .stamp_target_installed .stamp_staging_installed

