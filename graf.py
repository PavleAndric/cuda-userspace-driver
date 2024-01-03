import re
file = "strace.txt"
file = open(file , "r").read().split('\n') 

pattern = re.compile(r'0x[0-9a-fA-F]{11,}')
lmao = {}

def get_sys(str):
  k = ""
  for i in range(len(str)):
    if str[i] == "(":
      return k
    k += str[i]  

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
            print(f"{num} {sys_}","->", get_sys(x), i , mat.group())

if __name__ == "__main__":
  call()