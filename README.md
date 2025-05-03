# My C++ CMake Project

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
### 1. C++ compiler (e.g., g++, clang++)
You need a C++17-compliant compiler. Options include:
#### Windows
##### a. MSVC (Visual Studio Build Tools) (Recommended):
- Download [Visual Studio Build Tools 2022](https://visualstudio.microsoft.com/visual-cpp-build-tools/)
- Installation:
   - Select Desktop development with C++ workload.
   - Install to default path (e.g., C:\Program Files\Microsoft Visual Studio\2022\BuildTools).
- PATH: No manual PATH setup needed if using Developer Command Prompt for VS 2022. Alternatively, add C:\Program Files\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\<version>\bin\Hostx64\x64 to PATH.
##### b. g++ (via MinGW-w64):
- Download: MinGW-w64 (e.g., via MSYS2)
- Installation (using MSYS2):
```bash
pacman -S mingw-w64-x86_64-gcc
```
- PATH: Add C:\msys64\mingw64\bin to PATH.
##### c. clang++:
- Download: LLVM
- Installation: Install to C:\Program Files\LLVM.
- PATH: Add C:\Program Files\LLVM\bin to PATH.
#### macOS
##### a. clang++ (via Xcode Command Line Tools):
- Installation: 
```bash
xcode-select --install
```
- PATH: Automatically configured.
##### b. g++ (homebrew):
- Install Homebrew: brew.sh
- Install g++: 
```bash
brew install gcc
```
- PATH: Automatically configured (e.g., /opt/homebrew/bin).
#### Linux
##### a. g++:
- Installation: 
```bash
sudo apt update
sudo apt install g++
```
- PATH: Automatically configured.
##### b. clang++:
- Installation:
```bash
sudo apt install clang
```
- PATH: Automatically configured.

### 2. CMake
CMake is used for build configuration.
#### Download CMake (version 3.10 or higher): [Download](https://cmake.org/download/).
#### Installation:
##### Windows
Install to C:\Program Files\CMake. Select Add CMake to the system PATH for all users.
##### macOS:
```homebrew
brew install cmake
```
##### Linux
```bash
sudo apt install cmake
```
#### Verify
```
cmake --version
```
Expected: Version 3.20 or higher.

### 3. Ninja
Ninja is the build system used with CMake.
#### Download Ninja: [Download](https://ninja-build.org/) 
#### Installation:
##### Windows
- Download ninja.exe from releases.
- Place in C:\Program Files\Ninja.
- Add C:\Program Files\Ninja to PATH.
##### macOS (homebrew):
```
brew install ninja
```
##### Linux (Ubuntu/Debian)
```
sudo apt install ninja-build
```
#### Path
add to `PATH` (optional, but recommended).
#### Verify
```
ninja --version
```
Expected: Version 1.10 or higher.

### 4. vcpkg (Optional)
vcpkg manages dependencies like fmt. You can skip vcpkg if you install dependencies manually. It will be installed locally if not available globally.
#### Download vcpkg
#### Installation:
- Clone vcpkg:
```
git clone https://github.com/microsoft/vcpkg.git
```
- Bootstrap:
##### Windows (cmd):
```
cd vcpkg
bootstrap-vcpkg.bat
```
##### macOS/Linux (bash):
```
cd vcpkg
./bootstrap-vcpkg.sh
```
- Recommended installation path:
   Windows: C:\Program Files\vcpkg
   macOS/Linux: ~/vcpkg
#### PATH
Set environment variable VCPKG_ROOT to the vcpkg directory (e.g., C:\Program Files\vcpkg or ~/vcpkg).
##### Windows:
- Open "System Properties" → "Environment Variables".
- Add VCPKG_ROOT=C:\Program Files\vcpkg.
##### macOS/Linux:
```
echo 'export VCPKG_ROOT=~/vcpkg' >> ~/.zshrc  # or ~/.bashrc
source ~/.zshrc
```
#### Verify
```
vcpkg version
```
### 5. Git (Optional)
Git is used for version control.
#### Download  Git: [Download](https://git-scm.com/downloads).
#### Installation
##### Windows:
Install to C:\Program Files\Git. Select Add Git to PATH.
##### macOS:
```
brew install git
```
#### Linix:
```
sudo apt install git
```
#### Verify
```
git --version
```
### 6. Python 3 (with Numpy, Matplotlib)
The project requires a 64-bit Python 3 interpreter with NumPy and Matplotlib.
#### Download Python (version 3.6 or higher)
#### Installation
##### Windows:
- Download Windows Installer (64-bit).
- Install to C:\Program Files\Python313.
- Check Add Python to PATH during installation.
##### macOS:
```
brew install python@3.13
```
##### Linux:
```
sudo apt install python3 python3-pip
```
#### Install packages
##### cmd:
```
python -m pip install numpy matplotlib
```
##### bash:
```
python3 -m pip install numpy matplotlib
```
#### PATH
- Windows: Ensure C:\Program Files\Python313 and C:\Program Files\Python313\Scripts are in PATH.
- macOS/Linux: Automatically configured (e.g., /opt/homebrew/bin or /usr/bin).
#### Verify
##### cmd:
```
python --version
python -c "import platform; print(platform.architecture())"
python -m pip show numpy matplotlib
```
##### bash:
```
python3 --version
python3 -c "import platform; print(platform.architecture())"
python3 -m pip show numpy matplotlib
```
Expected:
- Python version: 3.13 or higher.
- Architecture: ('64bit', ...).
- NumPy and Matplotlib versions displayed.

## Project Setup
### 1. Clone the repository:
   ```
git clone https://github.com/melifaroo/cppbox.git
cd cppbox
   ```
### 2. Install dependencies (via vcpkg):
   ```
vcpkg install --triplet x64-windows  # Windows
vcpkg install --triplet x64-linux   # Linux
vcpkg install --triplet x64-osx     # macOS
   ```
### 3. Configure CMake:
#### Windows (bash):
   ```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -DPython3_ROOT_DIR="C:/Program Files/Python313"
   ```
### macOS/Linux (bash):
```
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
```
#### OR using CMake Presets (bash):
```
cmake --preset default
cmake --preset release
```

### 4. Build the project (bash):
```
cmake --build build
cmake --build --preset default
cmake --build --preset release
```
### 5. Run the executable:
#### Windows (cmd):
```
build\bin\cppbox.exe
```
#### macOS/Linux (bash):
```
./build/bin/cppbox
```

## Troubleshooting
### Windows
#### Error: Could NOT find Python3 (missing: Python3_EXECUTABLE):
- Verify 64-bit Python (cmd):
```
python -c "import platform; print(platform.architecture())"
```
Expected: **('64bit', 'WindowsPE')**
- Ensure NumPy and Matplotlib are installed (cmd):
```
python -m pip install numpy matplotlib
```
- Update Python3_ROOT_DIR in CMakePresets.json to C:/Program Files/Python313
- Clear CMake cache (cmd):
```
rmdir /s /q build
cmake --preset default
```
#### Error: Could not find a package configuration file provided by "fmt":
- Install dependencies (cmd):
```
vcpkg install --triplet x64-windows
```
- Verify VCPKG_ROOT (cmd):
```
echo %VCPKG_ROOT%
```

### macOS/Linux
#### Error: Python3 not found:
- Verify Python (bash):
```
python3 --version
python3 -c "import platform; print(platform.architecture())"
```
- Install NumPy and Matplotlib (bash):
```
python3 -m pip install numpy matplotlib
```
#### Error: fmt not found:
- Install dependencies (bash):
```
vcpkg install --triplet x64-linux  # or x64-osx
```

## Contributing
1. Fork the repository.
2. Create a branch: 
```
git checkout -b feature/your-feature.
```
3. Commit changes: 
```
git commit -m "Add your feature".
```
4. Push: 
```
git push origin feature/your-feature.
```
5. Open a pull request.

## License

MIT License