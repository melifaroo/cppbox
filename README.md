# My C++ Sanbox Project

This project is a simple C++ application that demonstrates the use of CMake for building C++ projects. It includes utility functions that can be used throughout the application. Also it use Vcpkg for dependency management and Ninja as the build system. It is cross-platform and supports Windows, macOS, and Linux.

## Project Structure

```
cppbox
├── src                # Source code (C++ files).
│   ├── main.cpp       # Entry point of the application
│   └── utils.cpp      # Implementation of utility functions
├── include            # Include folder (Header files).
│   └── utils.h        # Header file for utility functions
├── CMakeLists.txt     # CMake configuration file
├── CMakePresets.json  # CMake presets for cross-platform build configurations.
├── vcpkg.json         # Dependency manifest for vcpkg.
└── README.md          # Project documentation
└── .gitignore         # Excludes temporary files and local vcpkg installations.
```

## Requirements
To build and run the project, ensure you have the following tools installed:
1. Git - _the version control system_
2. Python 3 (with Numpy, Matplotlib) - _Python 3 interpreter with NumPy and Matplotlib_
3. C++ compiler (e.g., g++, clang++, MSVC) - _C++17-compliant compiler_
4. CMake - _the build configuration tool_
5. Ninja - _the build system used with CMake_
6. Vcpkg - _the dependency manager_

## Setup
<details>
<summary><strong>Windows</strong></summary>

_option a - via Visual Studio Installer. Recommended_<br/>
_option b/c - Separately install Build Tools. Alternatively_
#### 1. Git
   - [Download Git](https://git-scm.com/downloads)
   - **Install** to default path (e.g. C:\Program Files\Git)
   - Select 'Add Git to **PATH**' during installation.
#### 2. Python 3 
   - [Download Python](https://www.python.org/downloads/) (64-bit)
   - **Install** to default path (e.g. C:\Program Files\Python3)
   - Check 'Add Python to **PATH**' during installation.
   - Install packages, via cmd:
```shell
python -m pip install numpy matplotlib
```
#### 3.a. Visual Studio Build Tools
   - [Download MSVS Installer](https://visualstudio.microsoft.com/visual-cpp-build-tools/) and run Installer
   - Select ***Desktop development with C++ workload*** or _next minimal list of components_:
      + MSVC v143 - VS 2022 C++-x64/x86-Buildtools _(C++ Compiler)_
      + C++-CMake-Tools for Windows
      + vcpkg-Paket-Manager
      + _other necessary dependent components_
   - **Install** to default path (e.g., C:\Program Files\Microsoft Visual Studio\2022\Community)
   - No manual **PATH** setup needed if using Developer Command Prompt for VS 2022.
   - Select architecture corresponding to python x64, via cmd:
```shell
"C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
```
#### 3.b. g++
   - [Download MSYS2](https://www.msys2.org/#installation) 
   - **Install** MSYS2 to default path (e.g. C:\msys64)
   - **Install** MinGW-w64 (using MSYS2 bash):<br/> `pacman -S mingw-w64-x86_64-gcc`
   - Add `C:\msys64\mingw64\bin` to **PATH** 
      + via GUI: Win+R / SystemPropertiesAdvanced / Environment Variables (Recommended)
      + via cmd:<br/> `setx /M PATH "%PATH%;C:\msys64\mingw64\bin"`
#### 3.c. clang++
   - [Download LLVM](https://releases.llvm.org/) 
   - **Install** LLVM to default path (e.g. C:\Program Files\LLVM)
   - Add `C:\Program Files\LLVM\bin` to **PATH**
      + via GUI: Win+R / SystemPropertiesAdvanced / Environment Variables (Recommended)
      + via cmd:<br/> `setx /M PATH "%PATH%;C:\Program Files\LLVM\bin"`

_4.-6. only for separately installation (option b/c):_
#### 4. CMake
   - [Download CMake](https://cmake.org/download/) (version 3.10 or higher)
   - **Install** CMake to default path (e.g. C:\Program Files\CMake) 
   - Select 'Add CMake to the system **PATH** for all users'.
#### 5. Ninja
   - [Download Ninja](https://ninja-build.org/)
   - **Install** Ninja to default path (e.g. C:\Program Files\Ninja)
   - Add `C:\Program Files\Ninja` to **PATH**
      + via GUI: Win+R / SystemPropertiesAdvanced / Environment Variables (Recommended)
      + via cmd:<br/> `setx /M PATH "%PATH%;C:\Program Files\Ninja"`
#### 6. vcpkg (global setup)
   - **Install**: clone and bootstrap (install path e.g. C:\vcpkg)
```shell
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
bootstrap-vcpkg.bat
vcpkg integrate install
```
   - Set path in environment variable **VCPKG_ROOT** ( `C:\vcpkg` )
      + via GUI: Win+R / SystemPropertiesAdvanced / Environment Variables / Add `VCPKG_ROOT`=`C:\vcpkg` (Recommended)
      + via cmd:<br/> `setx /M VCPKG_ROOT "C:\vcpkg"`

</details>
<details>
<summary><strong>macOS</strong></summary>

#### **Install** Homebrew<br/>
`/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`
#### 1. Git
```bash
brew install git
```
#### 2. Python 3
```bash
brew install python@3.13
python3 -m pip install numpy matplotlib
```
#### 3.a. clang++ (via Xcode):
```bash
xcode-select --install
```
#### 3.b. g++:
```bash
brew install gcc
```
#### 4. CMake
```bash
brew install cmake
```
#### 5. Ninja
```bash
brew install ninja
```
#### 6. vcpkg (global setup)<br/>
   - **Install**: clone and bootstrap (install path e.g. ~/vcpkg)
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
vcpkg integrate install
```
   - Set path in environment variable **VCPKG_ROOT** (`~/vcpkg`) <br/>***Make sure to use >> (append), if you use a single > you will overwrite the file***
```bash
echo 'export VCPKG_ROOT=~/vcpkg' >> ~/.zshrc  # or ~/.bashrc 
source ~/.zshrc
```
</details>
<details>
<summary><strong>Linux</strong></summary>

#### 1. Git
```bash
sudo apt install git
```
#### 2. Python 3
```bash
sudo apt install python3 python3-pip
python3 -m pip install numpy matplotlib
```
#### 3.a. g++:
```bash
sudo apt update
sudo apt install g++
```
#### 3.b. clang++:
```bash
sudo apt install clang
```
#### 4. CMake
```bash
sudo apt install cmake
```
#### 5. Ninja
```bash
sudo apt install ninja-build
```
#### 6. vcpkg (global setup)<br/>
   - **Install**: clone and bootstrap (install path e.g. ~/vcpkg)
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
vcpkg integrate install
```
   - Set path in environment variable **VCPKG_ROOT** (`~/vcpkg`) <br/>***Make sure to use >> (append), if you use a single > you will overwrite the file***
```bash
echo 'export VCPKG_ROOT=~/vcpkg' >> ~/.zshrc  # or ~/.bashrc 
source ~/.zshrc
```
</details>

<details>
<summary><strong>Verify</strong></summary>

```bash
cl --version
gcc --version
g++ --version
clang --versoin
cmake --version # Expected: Version 3.20 or higher.
ninja --version # Expected: Version 1.10 or higher.
git --version
vcpkg version
python --version # Expected: Python version: 3.13 or higher.
python -c "import platform; print(platform.architecture())" # Expected: Architecture: ('64bit', ...).
python -m pip show numpy matplotlib # Expected: NumPy and Matplotlib versions displayed.
```
</details>

## Project Setup
### 1. Clone project:
```bash
git clone https://github.com/melifaroo/cppbox.git
cd cppbox
```
### 2. Clone vcpkg (local setup):
```bash
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh
cd ..
```
### 3. Configure CMake and build:
#### 3.1 using command line, **global** vcpkg installation
```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```
#### 3.2 using command line, **local** vcpkg installation
```bash
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="${sourceDir}/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```
#### 3.3. using CMake Presets, **global** vcpkg installation:
```bash
cmake --preset default
cmake --build --preset default
```
#### 3.4. using CMake Presets, **local** vcpkg installation:
```bash
cmake --preset default-vcpkg-local
cmake --build --preset default-vcpkg-local
```
### 4. Run the executable:
#### Windows (cmd):
```bash
build\bin\cppbox.exe
```
#### macOS/Linux (bash):
```bash
./build/bin/cppbox
```

## License

MIT License