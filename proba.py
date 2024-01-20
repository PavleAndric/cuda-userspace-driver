import subprocess, re

def print_strgins(pid):
  result = subprocess.run(f"cat /proc/{pid[0]}/maps", shell=True, stdout=subprocess.PIPE, text=True)
  print(result.stdout)

def get_ranges(string , mapping_low,  names):
  ptrs = [x.split(" ") for x in string.split("\n")]
  ptrs = [x[1:] if len(x) ==3 else x for x in ptrs[:-1] if len(x) >= 2]
  all_ = set()

  for x,n in zip(mapping_low, names):
    y = x[:len("200000000-200200000")]
    r_1 , r_2 = y.split("-")
    for k in ptrs:
      if hex(int(r_1 , 16)) <= (lmao := hex(int(k[-1],16) + int("0x200000000",16))) < hex(int(r_2 , 16)):
        print(f"0x{r_1} {lmao} 0x{r_2}", n if "/" in n else ("" if r_1 != "200000000" else "\t Init"))
        all_.add(lmao)

  esketit = set([hex(int(x[-1], 16) + int("0x200000000",16)) for x in ptrs])
  assert all_ == esketit 

def all_params(string):
  params = re.compile(r'\b(?:[0-9a-fA-F]{8}|0x[0-9a-fA-F]{8,})\b')
  return [(k, string[i]) for i,x in enumerate(string) if (k := params.findall(x))] 

def get_info(maps, params):
  mem_range = re.compile(r'([0-9a-fA-F]+-[0-9a-fA-F]+)')
  lib = re.compile(r'([\/\[][^\s]+)')
  dont_want = ["[stack]" , "READ" , "WRITE"] 

  maps = [(*mem_range.findall(x) , lib.findall(x)[0] if bool(lib.findall(x)) else "") for x in maps[1:-2]]
  for x,comm in all_params(params):
    for y in x:
      for r in maps:
        range = r[0].split('-')
        if int(y ,16) >= int(range[0],16) and int(y, 16) <= int(range[1],16) and all([(r[-1] not in z) for z in dont_want]): # PROMENI VO ZA STEK ???
          print(y , r[-1])

def uporedi_meee(upod:list):
  l_1,l_2=  upod

  spl_1 , spl_2 = l_1.split("\n") , l_2.split("\n")

  for i,(x,y) in enumerate(zip(spl_1 , spl_2)):
    if x != y:
      j = i
      while True:
        if j < 0: break
        if "|" in spl_1[j]:
          print(f"{j} {spl_1[j]}" )
          break
        j -= 1
      print(f"{i} NIJE ISTO XD")
      print(f"\t {x}")
      print(f"\t {y}")
      
if __name__  == "__main__":

  i = 0
  j = 0
  k = """00000000 02054080 00000000 00000000
00000000 00000000 0000047f 3c000000
00000000 00000000 3af5e3b3 00000000
00000000 44010000 00000010 00000020
00000001 00000000 00000000 22240000
00010023 00010001 00121083 00000000
00000000 05607f7c 80000002 00000006
00000000 00000000 00000000 08000000
00000640 7300167f f4220000 0c4c7f3a 
f4010000 04107f3a 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
f4000000 80007f3a f5e3b300 00007f3a 
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000"""
  
  for x in k.split("\n"):
    j = len(x.split(" ")) * 32 + j 
    print(f"{i}:{j} {x}")
    i = j 