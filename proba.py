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
        print(f"0x{r_1} {lmao} 0x{r_2}", n if "/" in n else ("" if r_1 != "200000000" else "Init"))
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

if __name__  == "__main__":
  file = open("ide_gas.txt", "r").read().split(":D :D :D")
  sniff, mapping = file
  mapping, ranges=  mapping.split("IDE_GAS")
  mapping_low = [x for x in mapping.split("\n") if x and x[0] == "2"]
  names = [x[-len("/dev/zero (deleted)"):] for x in mapping_low]

  get_ranges(ranges , mapping_low , names)
  #len("200000000-200200000")
  #get_info(mapping.split("\n") ,sniff.split("\n"))
  
