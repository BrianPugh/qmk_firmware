# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

QMK (Quantum Mechanical Keyboard) is keyboard firmware for AVR and ARM microcontrollers. It's based on TMK and supports 1000+ keyboards.

## Build Commands

QMK uses GNU Make with a Python CLI (`qmk`). The format is:
```bash
make <keyboard>:<keymap>[:<target>]
```

### Common Commands
```bash
# Compile firmware
make planck/rev6:default

# Compile and flash
make planck/rev6:default:flash

# Compile all keymaps for a keyboard
make planck/rev6:all

# Clean build artifacts
make clean
make distclean  # Also removes .bin/.hex/.uf2 files

# List available keyboards
make list-keyboards

# List keymaps for a keyboard
make planck/rev6:list-keymaps
```

### Using QMK CLI
```bash
qmk compile -kb planck/rev6 -km default
qmk flash -kb planck/rev6 -km default
qmk new-keyboard
qmk new-keymap
```

## Testing

Unit tests use Google Test (C++). Tests are in `tests/` directory.

```bash
# Run all tests
make test:all

# Run specific test
make test:basic

# Run tests matching pattern
make test:encoder
```

Python tests:
```bash
qmk pytest
```

## Code Formatting

```bash
# Format C code (core only)
qmk format-c --core-only

# Format Python code
qmk format-python

# Docker-based formatting (matches CI)
make format-core
make format-and-pytest
```

## Architecture

### Key Directories
- `keyboards/` - Keyboard definitions (vendor/keyboard/revision structure)
- `quantum/` - Core firmware features (keycodes, layers, tap-hold, RGB, audio)
- `platforms/` - Platform-specific code (AVR via LUFA, ARM via ChibiOS)
- `tmk_core/` - Original TMK codebase (protocol handling)
- `builddefs/` - Build system Makefiles
- `drivers/` - Hardware drivers (displays, sensors, LEDs)
- `lib/python/qmk/` - Python CLI tools
- `tests/` - Unit tests organized by feature
- `docs/` - VitePress documentation

### Keyboard Structure
Each keyboard has:
- `info.json` - Data-driven configuration (matrix, pins, layouts, features)
- `<keyboard>.c/.h` - Keyboard-specific code
- `keymaps/<name>/keymap.c` - Keymap definitions
- Optional: `rules.mk` for build options

### Build Flow
1. `Makefile` parses `keyboard:keymap:target`
2. `builddefs/build_keyboard.mk` orchestrates compilation
3. `info.json` is processed by Python to generate headers
4. Output: `.hex`, `.bin`, or `.uf2` in project root

## Coding Conventions

### C Code
- 4-space indentation (soft tabs)
- Modified One True Brace Style (opening brace on same line)
- Always include optional braces
- Use `#pragma once` for header guards
- Prefer `#if defined(X)` over `#ifdef X`
- Use `/* */` comments to explain "why"
- Wrap LAYOUT macros in `// clang-format off/on`

### Python Code
- Python 3.9+ compatibility
- 4-space indentation
- PEP8 with local modifications
- Printf-style format strings preferred (`'Hello, %s!' % (name,)`)
- Docstrings required for all functions
- No type annotations

## Key Patterns

### Feature Flags
Features are enabled via `rules.mk` or `info.json`:
```makefile
# In rules.mk
RGBLIGHT_ENABLE = yes
```
```json
// In info.json
"features": {
    "rgblight": true
}
```

### Custom Keycodes
```c
enum my_keycodes {
    MY_KEY = SAFE_RANGE,  // Start after built-in keycodes
};
```

### Layer Enums
```c
enum my_layers {
    _BASE,
    _LOWER,
    _RAISE,
};
```

### Callbacks
Many features use `*_user()` callbacks that can be overridden in keymaps:
```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Custom keycode handling
    return true;  // Continue processing
}
```

## Important Notes

- Features are disabled by default to save memory on small MCUs
- New features should work on both AVR and ARM, or auto-disable on unsupported platforms
- User keymaps/userspace contributions are not accepted upstream
- Core changes require unit tests
- Run `make keyboard:keymap` to verify changes compile before submitting PRs
