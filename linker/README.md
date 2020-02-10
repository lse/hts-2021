My small linker
===============

* repository: `git@git.cri.epita.fr:p/${promo}-sys/hts-${login}.git`
* directory: linker

You need to be able to build all the binaires in the `tests` directory:

```shellsession
$ make my_ld
$ make -C tests MY_LD=../my_ld
```

### Binaries descriptions

There are 3 samples:

* simple: a really simple hello world with no relocation
* hello: a relocation in the .rodata
* vars: multiple relocations

And 2 variants, one with debug symbols, and one without.

Time Constrain: the debug versions are not mandatory.

### Command line usage

```shellsession
$ my_ld -o output_file input_file.o
```

### Hints

* instead of trying to handle all cases, assert that your are in a known code
  path. (for example, don't try to handle all the relocations, but write an
  error message for unhandled ones)

* there is only 3 relocation types to handle:

	* `R_X86_64_32`
	* `R_X86_64_64`
	* `R_X86_64_PC32`

* `entry_point` address must be the address of `_start`
* look into: `elf.h` header (`/usr/include/elf.h`)

* we only need at most 3 PHDR:

    - one with RX permissions (for the section marked with `AX` flags)
    - one with R permissions (for the section marked with `A` flags)
    - one with RW permissions (for the section marked with `AW` flags)
    - drop every other sections.
