# STM32F4 CPP Project

[![Language](https://img.shields.io/badge/Made%20with-C/C++-blue.svg)](https://shields.io/)
![License](https://camo.githubusercontent.com/890acbdcb87868b382af9a4b1fac507b9659d9bf/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f6c6963656e73652d4d49542d626c75652e737667)

Development of a project model using the STM32F446ZE microcontroller programmed in C/C++. Some topics covered:

* Sample project using the NUCLEO-F446ZE board.
* Programming in C18 and C++20.
* Embedded system with FreeRTOS.
* Distinct folders for library, executable, and test code.
* Use of STM32CubeIDE for building and compiling the application project.
* Use of CMake for building the test code.
* Unit testing of C/C++ code using Google Test Framework.
* Use GMock for mocking the STM32 HAL functions.
* Code coverage with Github Actions and [Codecov](https://codecov.io).
* Code quality analysis with Lizard and Flawfinder tools.
* Assert verification and prints the failures via huart3.
* Use of Docker container.

## Running the tests

**Step 1**
Clone the project for your local machine.

```console
git clone https://github.com/CharlesDias/stm32f4_cpp_project.git
```

**Step 2**
Access the project folder **stm32f4_cpp_project**.

```console
cd  stm32f4_cpp_project
```

**Step 3.**
Run the image docker.

```console
docker run --rm -it -v $(pwd):/home/project -w /home/project charlesdias/stm32f4_build
```

**Step 4.**
Run the make command to build and run the tests.

```console
make test
```

