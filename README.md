# get_next_line

A modular implementation of `get_next_line`, a function that reads a file line by line from a file descriptor.

## Project Structure

get_next_line/
├── include/
│   ├── get_next_line.h
│   └── get_next_line_bonus.h
├── src/
│   ├── core/
│   │   ├── get_next_line.c
│   │   ├── gnl_read.c
│   │   ├── gnl_get_line.c
│   │   ├── gnl_trim_stash.c
│   │   └── bonus/
│   │       ├── get_next_line_bonus.c
│   │       ├── gnl_read_bonus.c
│   │       ├── gnl_get_line_bonus.c
│   │       └── gnl_trim_stash_bonus.c
│   └── utils/
│       ├── string/
│       │   ├── ft_strlen.c
│       │   ├── ft_strchr.c
│       │   ├── ft_strjoin.c
│       │   └── ft_strdup.c
│       └── memory/
│           ├── ft_calloc.c
│           └── ft_bzero.c
├── Makefile
└── README.md

## Build

**Mandatory version** (single file descriptor):
```bash
make
```

**Bonus version** (multiple file descriptors):
```bash
make bonus
```

**Cleanup:**
```bash
make clean    # remove object files
make fclean   # remove object files and executables
make re       # rebuild from scratch
```

## Design

Each function lives in its own file:

| Aspect | Benefit |
|---|---|
| Organization | Easy to locate and maintain |
| Responsibility | One function per file |
| Grouping | Files grouped by purpose |
| Testing | Functions testable in isolation |

**Layout:**
- `src/core/` — main `get_next_line` logic
- `src/utils/string/` — string manipulation helpers
- `src/utils/memory/` — memory allocation helpers
- `src/core/bonus/` — multi-FD support

## Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;

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

## Configuration

Override `BUFFER_SIZE` at compile time:
```bash
gcc -D BUFFER_SIZE=42 ...
```

Default: 61 bytes (set in the header files).
