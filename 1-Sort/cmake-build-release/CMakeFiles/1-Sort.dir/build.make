# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\github\AlgorithmWithCpp\1-Sort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles\1-Sort.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\1-Sort.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\1-Sort.dir\flags.make

CMakeFiles\1-Sort.dir\main.cpp.obj: CMakeFiles\1-Sort.dir\flags.make
CMakeFiles\1-Sort.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1-Sort.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1-Sort.dir\main.cpp.obj /FdCMakeFiles\1-Sort.dir\ /FS -c E:\github\AlgorithmWithCpp\1-Sort\main.cpp
<<

CMakeFiles\1-Sort.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-Sort.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\1-Sort.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\github\AlgorithmWithCpp\1-Sort\main.cpp
<<

CMakeFiles\1-Sort.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-Sort.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1-Sort.dir\main.cpp.s /c E:\github\AlgorithmWithCpp\1-Sort\main.cpp
<<

CMakeFiles\1-Sort.dir\Student.cpp.obj: CMakeFiles\1-Sort.dir\flags.make
CMakeFiles\1-Sort.dir\Student.cpp.obj: ..\Student.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/1-Sort.dir/Student.cpp.obj"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\1-Sort.dir\Student.cpp.obj /FdCMakeFiles\1-Sort.dir\ /FS -c E:\github\AlgorithmWithCpp\1-Sort\Student.cpp
<<

CMakeFiles\1-Sort.dir\Student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-Sort.dir/Student.cpp.i"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe > CMakeFiles\1-Sort.dir\Student.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\github\AlgorithmWithCpp\1-Sort\Student.cpp
<<

CMakeFiles\1-Sort.dir\Student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-Sort.dir/Student.cpp.s"
	C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\1-Sort.dir\Student.cpp.s /c E:\github\AlgorithmWithCpp\1-Sort\Student.cpp
<<

# Object files for target 1-Sort
1__Sort_OBJECTS = \
"CMakeFiles\1-Sort.dir\main.cpp.obj" \
"CMakeFiles\1-Sort.dir\Student.cpp.obj"

# External object files for target 1-Sort
1__Sort_EXTERNAL_OBJECTS =

1-Sort.exe: CMakeFiles\1-Sort.dir\main.cpp.obj
1-Sort.exe: CMakeFiles\1-Sort.dir\Student.cpp.obj
1-Sort.exe: CMakeFiles\1-Sort.dir\build.make
1-Sort.exe: CMakeFiles\1-Sort.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable 1-Sort.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\1-Sort.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1\2019\COMMUN~1\VC\Tools\MSVC\1426~1.288\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\1-Sort.dir\objects1.rsp @<<
 /out:1-Sort.exe /implib:1-Sort.lib /pdb:E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release\1-Sort.pdb /version:0.0  /machine:X86 /INCREMENTAL:NO /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\1-Sort.dir\build: 1-Sort.exe

.PHONY : CMakeFiles\1-Sort.dir\build

CMakeFiles\1-Sort.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1-Sort.dir\cmake_clean.cmake
.PHONY : CMakeFiles\1-Sort.dir\clean

CMakeFiles\1-Sort.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" E:\github\AlgorithmWithCpp\1-Sort E:\github\AlgorithmWithCpp\1-Sort E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release E:\github\AlgorithmWithCpp\1-Sort\cmake-build-release\CMakeFiles\1-Sort.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\1-Sort.dir\depend

