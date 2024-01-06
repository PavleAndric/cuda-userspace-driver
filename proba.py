import subprocess ,sys ,ctypes ,re




def print_strgins(pid):
  result = subprocess.run(f"cd /proc/{pid[0]}/map_files && ls", shell=True, stdout=subprocess.PIPE, text=True)

  print(result.stdout)

def all_params():
  params = re.compile(r'\b(?:[0-9a-fA-F]{8}|0x[0-9a-fA-F]{8,})\b')
  file = open("sniff.txt" , "r").read().split("\n")
  return [(k, file[i]) for i,x in enumerate(file) if (k := params.findall(x))]
  
def get_info(pid):
  mem_range = re.compile(r'([0-9a-fA-F]+-[0-9a-fA-F]+)')
  lib = re.compile(r'([\/\[][^\s]+)')
  result = subprocess.run(f"cd /proc/{pid[0]} && cat maps", shell=True, stdout=subprocess.PIPE, text=True)
  maps = result.stdout

  maps = [(*mem_range.findall(x)[0].split("-") , lib.findall(x)[0] if bool(lib.findall(x)) else "") for x in maps.split("\n")[:-1]]
  #lmao = set()
  #seen = set()
  
  for x,comm in all_params():
    for y in x:
      for r in maps:
        range = (int(r[0] , 16) , int(r[1] , 16))
        if int(y ,16) >= range[0] and int(y, 16) <= range[1]:
          print(y , r[-1])
          #lmao.add(y)

      #if y not in lmao and y not in seen:
      #  print(y, "???")
      #  seen.add(y)

if __name__  == "__main__":
  pid = sys.argv[1:]
  #get_info(pid)
  print_strgins(pid)
  
