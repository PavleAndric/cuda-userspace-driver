import re
file = "strace.txt"
file = open(file , "r").read().split('\n') 

pattern = re.compile(r'0x[0-9a-fA-F]{3,}')
pattern_brack = re.compile(r'\((.*?)\)')
lmao = {}
ref_ = {}

def get_sys(str):
  k = ""
  for i in range(len(str)):
    if str[i] == "(":
      return k
    k += str[i]  
  return k

def parse_map(string):
  lmao = ["add" , "len", "fd" , "off" , "out"]
  l = string.split("=")[-1]
  k = pattern_brack.search(string).group()
  k = [x.strip(" ").strip("(").strip(")") for x in k.split(",")]
  k = [x for x in k if x == "NULL" or x.isnumeric() or (x[0] == "-" and x[1:].isnumeric()) or bool(pattern.search(x))] + [l]
  return [f"{lmao[i]}: {hex(int(x)) if lmao[i] == 'len' else x} " for i,x in enumerate(k)]

def call():
  for i, x in enumerate(file):

    if x.startswith("newfstatat"): continue
    if x.startswith("brk"): continue
    if x.startswith("readlink"): continue
      
    if mat := pattern.search(x):
      if mat.group() not in lmao.values():
        lmao[(get_sys(x), i)] = mat.group()
      else:
        for k ,y in lmao.items():
          if y == mat.group():
            sys_ ,num = k
            ref_[i] = mat.group()
            print(f"{num} {sys_}","->", get_sys(x), i , mat.group())

def see_mapping():

  get_all = [[k] + [y for y in parse_map(x)] for x in file if "map" in (k := get_sys(x)) or "protect" in get_sys(x)] # max add + len = 139734165225472
  lmao = max([sum([len(y) for y in x]) for x in get_all])

  m_1,m_2,m_3,m_4,m_5 = 0,0,0,0,0
  for k in get_all:
    o = [len(x) for x in k]
    if len(o[1:]) == 5:
      p_1,p_2,p_3,p_4,p_5 = o[1:]
      m_1 = max(m_1 , p_1)
      m_2 = max(m_2 , p_2)
      m_3 = max(m_3 , p_3)
      m_4 = max(m_4 , p_4)
      m_5 = max(m_5 , p_5)
    else:
      p_1,p_2,p_3 = o[1:]
      m_1 = max(m_1 , p_1)
      m_2 = max(m_2 , p_2)
      m_3 = max(m_3 , p_3)

  maxes = (m_1,m_2,m_3,m_4,m_5)
  for x in get_all: 
    k = f" ".join([y + ' ' * (maxes[j] - len(y)) for j, y in enumerate(x[1:])])
    print(k , f"{' ' * (lmao - len(k)) + x[0]}")

if __name__ == "__main__":
  print("*******systemcall referecnting*******")
  call()
  print(f"{'*' * 40}mapping{'*' * 41}")
  see_mapping()

# void *mmap (void *address, size_t length, int protect, int flags, int filedes, off_t offset)



"""
5614ed0d0000-5614ed0d9000  7f1b4e5bd000-7f1b4e615000  7f1b502f9000-7f1b50312000  7f1b50502000-7f1b50503000  7f1b5050b000-7f1b5050c000  7f1b505f4000-7f1b505f5000  7f1b50619000-7f1b50643000
5614ed0d9000-5614ed147000  7f1b4e615000-7f1b4e619000  7f1b50312000-7f1b50418000  7f1b50503000-7f1b50504000  7f1b5050c000-7f1b5050d000  7f1b50610000-7f1b50611000  7f1b50643000-7f1b5064e000
5614ed147000-5614ed16e000  7f1b4e619000-7f1b4e61b000  7f1b504fd000-7f1b504fe000  7f1b50504000-7f1b50505000  7f1b5050d000-7f1b5050e000  7f1b50611000-7f1b50612000  7f1b5064f000-7f1b50651000
5614ed16f000-5614ed174000  7f1b4e800000-7f1b4e8e2000  7f1b504fe000-7f1b504ff000  7f1b50505000-7f1b50506000  7f1b5050e000-7f1b5051c000  7f1b50612000-7f1b50613000  7f1b50651000-7f1b50653000
5614ed174000-5614ed175000  7f1b4e8e2000-7f1b4ee02000  7f1b504ff000-7f1b50500000  7f1b50506000-7f1b50507000  7f1b5051c000-7f1b50598000  7f1b50613000-7f1b50614000
7f1b4e400000-7f1b4e428000  7f1b4ee02000-7f1b502f8000  7f1b50500000-7f1b50501000  7f1b50509000-7f1b5050a000  7f1b50598000-7f1b505f3000  7f1b50614000-7f1b50615000
7f1b4e428000-7f1b4e5bd000  7f1b502f8000-7f1b502f9000  7f1b50501000-7f1b50502000  7f1b5050a000-7f1b5050b000  7f1b505f3000-7f1b505f4000  7f1b50617000-7f1b50619000


add: NULL            len: 0x2000       fd: -1  off: 0          out:  0x7fd286ab3000  mmap
add: NULL            len: 0x1a83b      fd: 3   off: 0          out:  0x7fd286a98000  mmap
add: NULL            len: 0x1c837c0    fd: 3   off: 0          out:  0x7fd284e00000  mmap
add: 0x7fd284ee2000  len: 0x1a17000    fd:  0                                    mprotect
add: 0x7fd284ee2000  len: 0x520000     fd: 3   off: 0xe2000    out:  0x7fd284ee2000  mmap
add: 0x7fd285402000  len: 0x14f6000    fd: 3   off: 0x602000   out:  0x7fd285402000  mmap
add: 0x7fd2868f9000  len: 0x11f000     fd: 3   off: 0x1af8000  out:  0x7fd2868f9000  mmap
add: 0x7fd286a18000  len: 0x6b7c0      fd: -1  off: 0          out:  0x7fd286a18000  mmap
add: NULL            len: 0x227e50     fd: 3   off: 0          out:  0x7fd284a00000  mmap
add: 0x7fd284a28000  len: 0x195000     fd: 3   off: 0x28000    out:  0x7fd284a28000  mmap
add: 0x7fd284bbd000  len: 0x58000      fd: 3   off: 0x1bd000   out:  0x7fd284bbd000  mmap
add: 0x7fd284c15000  len: 0x6000       fd: 3   off: 0x214000   out:  0x7fd284c15000  mmap
add: 0x7fd284c1b000  len: 0xce50       fd: -1  off: 0          out:  0x7fd284c1b000  mmap
add: NULL            len: 0xe6108      fd: 3   off: 0          out:  0x7fd284d19000  mmap
add: 0x7fd284d27000  len: 0x7c000      fd: 3   off: 0xe000     out:  0x7fd284d27000  mmap
add: 0x7fd284da3000  len: 0x5b000      fd: 3   off: 0x8a000    out:  0x7fd284da3000  mmap
add: 0x7fd284dfe000  len: 0x2000       fd: 3   off: 0xe4000    out:  0x7fd284dfe000  mmap
add: NULL            len: 0x4028       fd: 3   off: 0          out:  0x7fd286a93000  mmap
add: 0x7fd286a94000  len: 0x1000       fd: 3   off: 0x1000     out:  0x7fd286a94000  mmap
add: 0x7fd286a95000  len: 0x1000       fd: 3   off: 0x2000     out:  0x7fd286a95000  mmap
add: 0x7fd286a96000  len: 0x2000       fd: 3   off: 0x2000     out:  0x7fd286a96000  mmap
add: NULL            len: 0x4028       fd: 3   off: 0          out:  0x7fd286a8e000  mmap
add: 0x7fd286a8f000  len: 0x1000       fd: 3   off: 0x1000     out:  0x7fd286a8f000  mmap
add: 0x7fd286a90000  len: 0x1000       fd: 3   off: 0x2000     out:  0x7fd286a90000  mmap
add: 0x7fd286a91000  len: 0x2000       fd: 3   off: 0x2000     out:  0x7fd286a91000  mmap
add: NULL            len: 0x2000       fd: -1  off: 0          out:  0x7fd286a8c000  mmap
add: NULL            len: 0x4038       fd: 3   off: 0          out:  0x7fd286a87000  mmap
add: 0x7fd286a88000  len: 0x1000       fd: 3   off: 0x1000     out:  0x7fd286a88000  mmap
add: 0x7fd286a89000  len: 0x1000       fd: 3   off: 0x2000     out:  0x7fd286a89000  mmap
add: 0x7fd286a8a000  len: 0x2000       fd: 3   off: 0x2000     out:  0x7fd286a8a000  mmap
add: NULL            len: 0x5000       fd: -1  off: 0          out:  0x7fd284d14000  mmap
add: 0x7fd284c15000  len: 0x4000       fd:  0                                    mprotect
add: 0x7fd286a8a000  len: 0x1000       fd:  0                                    mprotect
add: 0x7fd286a91000  len: 0x1000       fd:  0                                    mprotect
add: 0x7fd286a96000  len: 0x1000       fd:  0                                    mprotect
add: 0x7fd284dfe000  len: 0x1000       fd:  0                                    mprotect
add: 0x7fd2868f9000  len: 0x19000      fd:  0                                    mprotect
add: 0x55a5b947f000  len: 0x5000       fd:  0                                    mprotect
add: 0x7fd286aed000  len: 0x2000       fd:  0                                    mprotect
add: 0x7fd286a98000  len: 0x1a83b      fd:  0                                    munmap
add: NULL            len: 0x21000      fd: -1  off: 0          out:  0x7fd284cf3000  mmap
add: 0x7fd284cf3000  len: 0x21000      fd:  0                                    munmap
add: NULL            len: 0x801000     fd: -1  off: 0          out:  0x7fd2841ff000  mmap
add: 0x7fd284200000  len: 0x800000     fd:  0                                    mprotect
add: NULL            len: 0x10000      fd: 14  off: 0          out:  0x7fd286aa3000  mmap
add: NULL            len: 0x6000000    fd: -1  off: 0          out:  0x7fd27a000000  mmap
add: NULL            len: 0x25a000     fd: -1  off: 0          out:  0x7fd279da6000  mmap
add: NULL            len: 0xa1000      fd: -1  off: 0          out:  0x7fd284c73000  mmap
add: 0x200000000     len: 0x100200000  fd: -1  off: 0          out:  0x200000000     mmap
add: NULL            len: 0x1ffff000   fd: -1  off: 0          out:  0x7fd259da7000  mmap
add: 0x7fd259da7000  len: 0x6259000    fd:  0                                    munmap
add: 0x7fd270000000  len: 0x9da6000    fd:  0                                    munmap
add: NULL            len: 0x1021000    fd: -1  off: 0          out:  0x7fd278d85000  mmap


pa@pa-IdeaPad-Gaming-3-15IMH05:/proc/49191/task/49191$ cat stat
49191 (primer) S 49149 49149 41500 34818 49149 4194304 448 0 0 0 0 0 0 0 20 0 2 0 8198886 110379008 1568 c 94647876423680 94647876873409 140737067584032 0 0 0 0 0 0 1 0 0 17 4 0 0 0 0 0 94647877038080 94647877058696 94647883767808 140737067590311 140737067590320 140737067590320 140737067593711 0

"""