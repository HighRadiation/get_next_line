# get_next_line

A modular implementation of get_next_line function that reads a line from a file descriptor.

## 📁 Project Structure

```
get_next_line/
├── include/                  # Header files
│   ├── get_next_line.h
│   └── get_next_line_bonus.h
├── src/                      # Source files (modular structure)
│   ├── core/                 # Core functionality
│   │   ├── get_next_line.c
│   │   ├── gnl_read.c
│   │   ├── gnl_get_line.c
│   │   ├── gnl_trim_stash.c
│   │   └── bonus/            # Bonus version (multiple FD support)
│   │       ├── get_next_line_bonus.c
│   │       ├── gnl_read_bonus.c
│   │       ├── gnl_get_line_bonus.c
│   │       └── gnl_trim_stash_bonus.c
│   └── utils/                # Utility functions
│       ├── string/           # String manipulation
│       │   ├── ft_strlen.c
│       │   ├── ft_strchr.c
│       │   ├── ft_strjoin.c
│       │   └── ft_strdup.c
│       └── memory/           # Memory management
│           ├── ft_calloc.c
│           └── ft_bzero.c
├── Makefile
└── README.md
```

## 🔨 Building

### Mandatory version (single file descriptor):
```bash
make
```

### Bonus version (multiple file descriptors):
```bash
make bonus
```

### Clean build files:
```bash
make clean    # Remove object files
make fclean   # Remove object files and executables
make re       # Rebuild from scratch
```

## 📝 Modular Design

Each function is in its own file for:
- **Better organization**: Easy to find and maintain
- **Clear responsibility**: One function per file
- **Logical grouping**: Functions grouped by purpose (core, string utils, memory utils)
- **Easy testing**: Individual functions can be tested separately

### Function Organization:

- **Core functions** (`src/core/`): Main get_next_line logic
- **String utilities** (`src/utils/string/`): String manipulation helpers
- **Memory utilities** (`src/utils/memory/`): Memory allocation and initialization
- **Bonus** (`src/core/bonus/`): Multi-FD support version

## 💡 Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## ⚙️ Configuration

Change `BUFFER_SIZE` during compilation:
```bash
gcc -D BUFFER_SIZE=42 ...
```

Default is 61 bytes (defined in header files).

