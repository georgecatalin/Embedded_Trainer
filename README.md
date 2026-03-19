# Embedded Trainer

A hands-on embedded-systems training repository focused on learning by building. It collects practical exercises and small projects that guide you through core microcontroller and embedded Linux development concepts.

##  Purpose

The goal is to provide a clear progression from fundamentals to more complete, hardware-oriented applications, with code organized for readability and reuse. Along the way, it highlights common embedded best practices.

If you’re preparing for embedded interviews, refreshing firmware skills, or looking for structured practice that maps closely to real embedded development, this repo is intended to serve as a compact “trainer” you can clone, run, and extend.

##  Courses Covered

### 1. Microcontroller Embedded C Programming: Absolute Beginners
- **Platform**: Udemy
- **Link**: https://www.udemy.com/course/microcontroller-embedded-c-programming/
- **Target Hardware**: STM32F429ZI (ARM Cortex-M4)
- **Status**: Completed
- **Directory**: `Microcontroller Embedded C Programming Absolute Beginners/`

### 2. Advanced C Programming Course
- **Platform**: Udemy
- **Instructors**: Tim Buchalka's Learn Programming Academy and Jason Fedin
- **Link**: https://www.udemy.com/course/advanced-c-programming-course/
- **Skill Level**: Intermediate and Advanced
- **Status**: Completed
- **Directory**: `Advanced_C_Programming/`
- **Initial Learning Repository**: [Advanced-C-Programming-Course](https://github.com/georgecatalin/Advanced-C-Programming-Course/tree/main)

#### Key Topics Covered:
- Advanced control flow
- Advanced data types and structures
- Advanced pointers and memory management
- Bit manipulation
- Storage classes and type qualifiers
- Macros and the preprocessor
- Input/Output operations
- Interprocess communication
- Networking fundamentals
- Threading and concurrency
- Shared libraries and shared objects
- Advanced debugging and analysis
- Working with larger programs

### 3. Linux System Programming Techniques and Concepts
- **Platform**: Udemy
- **Link**: https://www.udemy.com/course/advance-programming-concepts/
- **Skill Level**: Advanced
- **Status**: In Progress
- **Directory**: `Linux_System_Programming_Techniques_and_Concepts/`

#### Key Topics Covered:
- Linux system architecture and internals
- Process management and inter-process communication (IPC)
- Memory management techniques
- File I/O and filesystem concepts
- Signal handling
- Multi-threading and synchronization
- Network programming on Linux
- System calls and kernel interfaces
- Performance optimization techniques

### 4. From 0 to 1: C Programming
- **Platform**: Udemy
- **Link**: https://www.udemy.com/course/from-0-to-1-c-programming/
- **Skill Level**: Beginner
- **Directory**: `From_0_to_1_Drill_Deep/`

#### Key Topics Covered:
- C fundamentals (types, operators, control flow)
- Functions and modular programming
- Pointers and memory basics
- Arrays and strings
- Bit manipulation exercises and drills

### 5. Multithreading & Thread Synchronization - Pthreads
- **Platform**: Udemy
- **Link**: https://www.udemy.com/course/multithreading_parta/
- **Skill Level**: Intermediate/Advanced
- **Status**: In progress
- **Directory**: `Multithreading_Thread_Synchronization_Pthreads/`

#### Key Topics covered:
- Multithreading is beneficial vs. processes in Linux applications
- Create and manage POSIX threads (`pthread_create`, `pthread_join`, `pthread_exit`, thread attributes)
- Practice safe data sharing between threads and identify common concurrency hazards (race conditions, deadlocks)
- Use synchronization primitives correctly:
  - Mutexes (`pthread_mutex_*`) and mutex attributes
  - Condition variables (`pthread_cond_*`) for signaling and coordination
  - Read-write locks (`pthread_rwlock_*`) for read-heavy workloads
  - Semaphores (`sem_*`) for counting/resource control
- Implement classic concurrency patterns/exercises (producer–consumer, readers–writers, dining philosophers) and analyze correctness
- Work with thread cancellation and cleanup handlers, and handle thread-safe resource management
- Measure and reason about thread performance (contention, context switching) and validate behavior with debugging/diagnostic tools (e.g., `gdb`, `strace`, `helgrind`/`drd`)

## 🛠️ Technologies & Tools

- **Microcontrollers**: STM32 (ARM Cortex-M series)
- **IDE**: STM32CubeIDE, Eclipse CDT, Visual Studio Code
- **Compilers**: GCC, ARM GCC
- **Languages**: C (+ embedded C)
- **Debugging**: SWD/JTAG, ITM (Instrumentation Trace Macrocell)
- **Hardware**: STM32 Nucleo-144 development boards, x86 or x86-64 PC
- **Operating System**: Linux (for system programming topics)

## Disclaimer

This repository contains **my own practice implementations** created while learning.  
It does **not** contain or redistribute paid course videos or proprietary course materials.

## Author

**George Calin**
- Email: george.calin [at] gmail.com
- LinkedIn: https://www.linkedin.com/in/cgeorge1978/
