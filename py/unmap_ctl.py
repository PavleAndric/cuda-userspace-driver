
def go(x):
  str = ""
  for i in range(len(x)):
    if x[i] != "-": str += x[i]
    else: break
  return len(str) >= len("200000000") 

def lmao(x):
  str = ""
  for y in x: 
    if y != " ": str += y 
    else:
      break
  return str

def get_last(x):
  str = ""
  for i in range(len(x)-1,0 , -1):
    if x[i] != " ":
      str += x[i]
    else: break
  return "".join(reversed(str))


t = open("../mapping.txt" , "r").read().split("\n")
t = [(x,get_last(x)) for x in t if ("/dev/nvidiactl" in x or "zero" in x or "nvidia" in x) and go(x)]

for x,name  in t:
  s ,e = lmao(x).split("-")
  if len(s) > len("204a00000"):
    str = f'munmap((void*)0x{s}, 0x{e}-0x{s});'
    pad = 61 - len(str)
    print(f"{str}  {' '*pad} //{hex(int(e, 16)-int(s, 16))} {name}")
  


