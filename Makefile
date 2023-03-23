# SPDX-FileCopyrightText: © Sebastián Mancilla <smancill@smancill.dev>
#
# SPDX-License-Identifier: MIT-0

BUILD_DIR ?= build

MAKEFLAGS += --no-print-directory

.PHONY: all
all:
	@$(MAKE) -C $(BUILD_DIR)

.PHONY: clean
clean:
	@$(MAKE) -C $(BUILD_DIR) clean
