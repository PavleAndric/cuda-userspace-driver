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

  get_all = [[k] + [y for y in parse_map(x)] for x in file if "map" in (k := get_sys(x)) or "protect" in get_sys(x)]
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
# add: 0x7f8135e28000  len: 0x195000     fd: 3   off: 0x28000    out:  0x7f8135e28000  mmap
# 0x7f8135e28000 + 0x195000 = 0x7f8135fbd000
#add: 0x200000000     len: 0x100200000  fd: -1  off: 0          out:  0x200000000     mmap
# 0x200000000 + 0x100200000 = 0x300200000
# add: 0x7f810a001000  len: 0x5fff000    fd:  0                                    munmap
#0x7f810a001000 + 0x5fff000 = 0x7f8110000000