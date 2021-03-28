.ONESHELL:
.DEFAULT_GOAL := help
.PHONY: help

BASE_DIRECTORY := "$$(realpath .)"
VIRTUAL_ENVIRONMENT_PATH := "$(BASE_DIRECTORY)/venv"
QMK_CONFIG_FILE := "$(BASE_DIRECTORY)/qmk.ini"
QMK_HOME := "$(BASE_DIRECTORY)/qmk_firmware"

init: ## Makes initial setup and installs dependencies into virtual environment
	@echo "Update git sub-modules..."
	@git submodule sync --recursive
	@git submodule update --init --recursive --progress
	@echo "Initialize Python setup..."
	@python -m venv $(VIRTUAL_ENVIRONMENT_PATH)
	@source $(VIRTUAL_ENVIRONMENT_PATH)/bin/activate
	@pip install --quiet --upgrade pip
	@pip install --quiet qmk
	@pip install --quiet --requirement $(QMK_HOME)/requirements.txt

setup: ## Should be evaluated like `eval "$(make setup)"` to setup shell for development
	@echo "export QMK_HOME=$(QMK_HOME)"
	@echo "source $(VIRTUAL_ENVIRONMENT_PATH)/bin/activate"
	@echo "alias qmk='qmk --config-file $(QMK_CONFIG_FILE)'"

link: ## Links layouts and keymaps into the firmware submodule (required to compile)
	@for layout in $(BASE_DIRECTORY)/layouts/*; do \
		layout_name="$$(basename "$$layout")"; \
		layout_target="$(QMK_HOME)/layouts/community/$$layout_name"; \
		if [[ ! -e $$layout_target ]]; then \
			ln --symbolic $$layout $$layout_target; \
			echo "Linked new layout '$$layout_name'"; \
		else \
			for keymap in $$layout/*; do \
				keymap_name="$$(basename "$$keymap")"; \
				keymap_target="$$layout_target/$$keymap_name"; \
				if [[ ! -e $$keymap_target ]]; then \
					ln --symbolic $$keymap $$keymap_target; \
					echo "Linked new keymap '$$keymap_name' for layout '$$layout_name'"; \
				else \
					if grep --quiet '$(BASE_DIRECTORY)' <<< $$(readlink $$keymap_target); then
						echo "Keymap '$$keymap_name' does already exist for layout '$$layout_name'!"; \
					fi \
				fi \
			done \
		fi \
	done

check: ## Validates if the setup is available and the 'init' target was run before
	@if [[ ! -d $(VIRTUAL_ENVIRONMENT_PATH) ]] || [[ ! -d $(QMK_HOME) ]]; then \
		echo "Setup is not fully available! Please make sure you have run 'make init' before."; \
		exit 1; \
	fi
	# TODO: extend check...

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "Usage: make \033[36m<target>\033[0m\n"} /^[a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2 }' $(MAKEFILE_LIST)
