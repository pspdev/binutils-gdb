# Based off of the default elf32 MIPS target.  However, we use a seperate
# script template because the PSP architecture defines sections that normally
# cannot be overriden here and would normally get absorbed (i.e.
# .rodata.sceModuleInfo would be absorbed into .rodata).

EMBEDDED=yes
source_sh ${srcdir}/emulparams/elf32lmip.sh
unset NONPAGED_TEXT_START_ADDR
unset SHLIB_TEXT_START_ADDR
unset COMMONPAGESIZE

SCRIPT_NAME=elf_psp
TEXT_START_ADDR=0x08804000
MAXPAGESIZE=256
ARCH="mips:allegrex"
MACHINE=
TEMPLATE_NAME=elf
GENERATE_SHLIB_SCRIPT=yes
DYNAMIC_LINK=false

# Discard the .comment and .pdr sections.
OTHER_SECTIONS="/DISCARD/ : { *(.comment) *(.pdr) }"
