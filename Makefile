all: build
	@echo ""
	@echo "Done!"

build:
	@echo "-------------------- Configure and Build CMake -----------"
	cmake -S . -B build
	cmake --build build -- -j4
	@echo ""

test: build
	@echo "-------------------- Run CTest ---------------------------"
	cd build && pwd && ctest --verbose
	@echo ""

clean:
	@echo ""
	@echo "-------------------- Clean build folder ------------------"
	rm -rf build
	@echo ""