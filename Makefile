CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -IUnity
UNITY_CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu99 -IUnity

BUILD = build

MAIN_SRCS = $(wildcard *-main.c)
MAIN_BINS = $(patsubst %.c, $(BUILD)/%, $(MAIN_SRCS))

SRC_ALL = $(wildcard *.c)
SRC = $(filter-out %-main.c, $(SRC_ALL))
UNITY_SRC = Unity/unity.c
TESTS = $(wildcard tests/test_*.c)
TEST_BINS = $(strip $(patsubst tests/%.c, $(BUILD)/%, $(TESTS)))

.PHONY: all clean test run-tests run-% help

all: $(MAIN_BINS) test

$(BUILD)/%: %.c $(SRC) | $(BUILD)
	$(CC) $(CFLAGS) $^ -o $@

test:
	@if [ -z "$(TESTS)" ]; then \
		echo "⚠️  No test files found. Only built main binaries."; \
	else \
		$(MAKE) run-tests; \
	fi

run-tests: $(TEST_BINS)
	@for bin in $(TEST_BINS); do \
		echo "Running $$bin..."; \
		if ./$$bin; then \
			echo "✅ $$bin passed"; \
		else \
			echo "❌ $$bin failed"; \
			exit 1; \
		fi; \
	done

$(BUILD)/%: tests/%.c $(SRC) $(UNITY_SRC) | $(BUILD)
	@echo "Building test binary for $< -> $@"
	$(CC) $(UNITY_CFLAGS) $^ -o $@

run-%: $(BUILD)/%
	./$<

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

help:
	@echo "Available targets:"
	@echo "  all    - Build all binaries"
	@echo "  clean  - Remove build files"
	@echo "  test   - Run unit tests"
	@echo "  run-%  - Run a specific test"

debug:
	@echo "SRC = $(SRC)"
	@echo "TESTS = $(TESTS)"
	@echo "TEST_BINS=[$(TEST_BINS)]"

