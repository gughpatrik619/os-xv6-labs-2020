// Format of an ELF executable file

#define ELF_MAGIC 0x464C457FU  // "\x7FELF" in little endian

// File header
struct elfhdr {
  uint magic;  // must equal ELF_MAGIC
  uchar elf[12];
  ushort type;
  ushort machine;
  uint version;
  uint64 entry;
  uint64 phoff;
  uint64 shoff;
  uint flags;
  ushort ehsize;
  ushort phentsize;
  ushort phnum;
  ushort shentsize;
  ushort shnum;
  ushort shstrndx;
};

// Program section header
struct proghdr {
  uint32 type;
  uint32 flags;
  uint64 off;
  uint64 vaddr;
  uint64 paddr;
  uint64 filesz;
  uint64 memsz;
  uint64 align;
};

// Values for Proghdr type
#define ELF_PROG_LOAD           1

// Flag bits for Proghdr flags
#define ELF_PROG_FLAG_EXEC      1
#define ELF_PROG_FLAG_WRITE     2
#define ELF_PROG_FLAG_READ      4

//TODO: finish machines
static const char* elfmachine[] = {
    [0x01]  "AT&T WE 32100",
    [0x02]  "SPARC",
    [0x03]  "x86",
    [0x04]  "",
    [0x05]  "AT&T WE 32100",
    [0x06]  "AT&T WE 32100",
    [0x07]  "AT&T WE 32100",
    [0x08]  "AT&T WE 32100",
    [0x09]  "AT&T WE 32100",
    [0x0A]  "AT&T WE 32100",
    [0x0E]  "AT&T WE 32100",
    [0x0F]  "AT&T WE 32100",
    [0x13]  "AT&T WE 32100",
    [0x14]  "AT&T WE 32100",
    [0x15]  "AT&T WE 32100",
    [0x16]  "AT&T WE 32100",
    [0x28]  "AT&T WE 32100",
    [0x2A]  "AT&T WE 32100",
    [0x32]  "AT&T WE 32100",
    [0x3E]  "AT&T WE 32100",
    [0x8C]  "AT&T WE 32100",
    [0xB7]  "AT&T WE 32100",
    [0xF3]  "AT&T WE 32100",
    [0x101]  "AT&T WE 32100",

};