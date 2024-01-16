import re
"""
file = "strace.txt"
file = open(file , "r").read().split('\n') 

pattern = re.compile(r'0x[0-9a-fA-F]{3,}')
pattern_brack = re.compile(r'\((.*?)\)')
lmao = {}
ref_ = {}
"""
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

if __name__ == "__main__":  # void *mmap (void *address, size_t length, int protect, int flags, int filedes, off_t offset)
  #print("*******systemcall referecnting*******")
  #call()
  #print(f"{'*' * 40}mapping{'*' * 41}")
  #see_mapping()

  # ovi su svi 300 tj NVC5B5_LAUNCH_DMA
  lmao =  [0x200405c84,0x2004060a0,0x200406240,0x200406c70,0x200406e00,0x200406f00,0x200408a20,0x20040ade0,0x20040b5c0,0x20040e244,0x20040e3d4,0x20040e4d4,0x20040f644,0x200410250,0x200411544,0x2004122a4,0x2004123f4,0x200412654,0x200413374]
  for x,y in zip(lmao , lmao[1:]):
    print(y - x)