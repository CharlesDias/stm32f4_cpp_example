all: build
	@echo ""
	@echo "Done!"

board: clean
	@echo "----- Building for target board --------------------------"
	cmake -DCHOOSE_TARGET_PLATFORM=board -DCMAKE_TOOLCHAIN_FILE=../cmake/arm-none-eabi-gcc.cmake -DCMAKE_BUILD_TYPE=Debug -S . -B ./build
	cmake --build build -- -j4
	@echo "Done!"
	@echo "----------------------------------------------------------"

test: clean
	@echo "----- Build for test  ------------------------------------"
	cmake -DCHOOSE_TARGET_PLATFORM=test -S . -B ./build
	cmake --build build -- -j4
	cd build && pwd && ctest --verbose
	@echo "Done!"
	@echo "----------------------------------------------------------"

clean:
	@echo ""
	@echo "-------------------- Clean build folder ------------------"
	rm -rf build
	@echo "Done!"
	@echo "----------------------------------------------------------"

###############################################
# Phony
# 
.PHONY: all board test clean