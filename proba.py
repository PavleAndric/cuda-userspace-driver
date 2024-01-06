import subprocess ,sys ,ctypes ,re
def print_strgins(pid):
  result = subprocess.run(f"cat /proc/{pid[0]}/maps", shell=True, stdout=subprocess.PIPE, text=True)
  print(result.stdout)

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
  print(mapping)
  get_info(mapping.split("\n") ,sniff.split("\n"))
  
