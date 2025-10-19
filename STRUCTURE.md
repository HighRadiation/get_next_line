# Project Structure

```
get_next_line/
│
├── 📁 include/                          # Header files
│   ├── get_next_line.h                  # Mandatory version header
│   └── get_next_line_bonus.h            # Bonus version header
│
├── 📁 src/                              # Source files (modular)
│   │
│   ├── 📁 core/                         # Core get_next_line functionality
│   │   ├── get_next_line.c              # Main function (mandatory)
│   │   ├── gnl_read.c                   # Read from file descriptor
│   │   ├── gnl_get_line.c               # Extract line from buffer
│   │   ├── gnl_trim_stash.c             # Trim processed data
│   │   │
│   │   └── 📁 bonus/                    # Bonus version (multiple FD)
│   │       ├── get_next_line_bonus.c    # Main function (bonus)
│   │       ├── gnl_read_bonus.c         # Read (bonus version)
│   │       ├── gnl_get_line_bonus.c     # Get line (bonus version)
│   │       └── gnl_trim_stash_bonus.c   # Trim stash (bonus version)
│   │
│   └── 📁 utils/                        # Utility functions
│       │
│       ├── 📁 string/                   # String manipulation
│       │   ├── ft_strlen.c              # String length
│       │   ├── ft_strchr.c              # Find character in string
│       │   ├── ft_strjoin.c             # Join two strings
│       │   └── ft_strdup.c              # Duplicate string
│       │
│       └── 📁 memory/                   # Memory management
│           ├── ft_calloc.c              # Allocate and zero memory
│           └── ft_bzero.c               # Zero memory
│
├── 📁 .vscode/                          # VS Code configuration
│   └── c_cpp_properties.json            # IntelliSense settings
│
├── Makefile                             # Build configuration
└── README.md                            # Documentation

```

## File Count
- **Total files**: 16 C source files + 2 headers = 18 files
- **Mandatory version**: 10 files (4 core + 4 string + 2 memory)
- **Bonus version**: 10 files (4 core/bonus + 4 string + 2 memory)

## Design Principles
✅ **One function per file** - Easy to locate and maintain
✅ **Logical grouping** - Related functions in same directory
✅ **Clear naming** - File names match function names
✅ **Separation of concerns** - Core logic separated from utilities
✅ **Reusable utilities** - String and memory functions can be used by both versions
