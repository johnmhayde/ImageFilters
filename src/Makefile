# Output Config
TARGET :=executable
OBJDIR :=bin/

# Compiler bin
CC 		 :=g++
CFLAGS :=-Wall -Wextra -Weffc++ -pedantic -std=c++11 -g
LFLAGS :=-lm

# Find all possible source files
CPP_SRCS := $(shell find * -type f -name '*.cpp')
HDRS 		 := $(shell find * -type f -name '*.h')
OBJS     := $(filter %.o, $(patsubst %.cpp, $(OBJDIR)%.o, $(CPP_SRCS)))

# Link all built objects
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	$(CC) $(OBJS) -o $(TARGET) $(LFLAGS)

$(OBJDIR)%.o: %.cpp $(HDRS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run:
	./executable input.ppm

which:
	@echo "FOUND C++ SOURCES: ${CPP_SRCS}"
	@echo "FOUND HEADERS: ${HDRS}"
	@echo "TARGET OBJS: ${OBJS}"

clean:
	rm -f $(TARGET)
	rm -rf $(OBJDIR)
	rm blur_100.ppm
	rm sharpen_100.ppm
	rm horizontal_100.ppm
	rm vertical_100.ppm
	rm binary_100.ppm
	rm grayscale_100.ppm
	rm sepia_100.ppm
	rm shar_bin_hf_100.ppm
	rm blur_gs_vf_100.ppm
	rm shar_gs_hf_100.ppm
	rm shar_sep_vf_100.ppm
	rm blur_bin_hf_100.ppm
	rm blur_sep_vf_100.ppm
	rm stud_creation_100.ppm
