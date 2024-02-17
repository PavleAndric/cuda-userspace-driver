glob_graph, cmnd_graph, chrono = {}, {}, {}  

class Object():
  def __init__(self , name:str , type = None, childern:list = []):
    self.name , self.childern = name, childern
    self.cmd ,self.type = None, type
  
  def print_all(self):
    self.pprint()
    for x in self.childern: x.print_all()

  def get_commands(self): print(self.cmd) if self.cmd else print(end ="")

  def find_type(self,name):
    if self.name == name: return self.type
    
    for x in self.childern:
      vaild = x.find_type(name)
      if vaild: return vaild 

  def pprint(self): 
    t_print = " " * (5-len(self.type)) 
    print(f"Object {self.name}:{t_print}{self.type}" , end=": children{")
    
    # ovo je djubre
    for i in range(len(self.childern)):
      if i % 12 == 0: print("\n\t\t       " ,end="")
      print(f"{self.childern[i].name} " , end="")
    print("}")

    if self.cmd:
      print(" " * 22 , "commands{" , end ="")
      for i in range(len(self.cmd)):
        if i % 12 == 0: print("\n\t\t       " ,end="")
        print(f"{self.cmd[i]} " , end="")
      print("}")

def get_cmnd(x):
  str = ""
  for i in range(5, len(x)):
    if x[i] != " ": str += x[i]
    else: return str 

def make_graphs(n):
  for line in n:
    if "NV_ESC_RM_CONTROL" in line:
      split = line.split(",")
      romb = [x for x in split if "hObject" in x] + [split[-1]]
      obj, cmnd = romb[0].split('=')[-1] , get_cmnd(romb[-1])

      if obj not in cmnd_graph: cmnd_graph[obj] = []
      cmnd_graph[obj].append(cmnd)
  
  for line in n:
    split = line.split(",")
    romb = [x for x in split if any([y in x for y in need])] + [split[-1]]

    if any(["pObjparent" in z for z in romb]): #  in z or "hDevice"
      parent ,child, type = romb[0].split("=")[-1] ,romb[1].split("=")[-1] , romb[-1].split("=")[-1] 

      if parent == "0" or child == "0":continue
      if parent not in glob_graph: glob_graph[parent] = []
      glob_graph[parent].append((child , type))

def make_rel(k ,type, root = False):
  
  obj = Object(name = k ,type = "ROOT" if root else type)

  if obj.name in cmnd_graph: obj.cmd = cmnd_graph[obj.name] # cmnd
  if k in glob_graph: # parent child
    obj.childern = [make_rel(x[0], x[1] if len(x[1]) <= 7 else "MAPP" , root = False) for x in glob_graph[k]]
  return obj

def print_rm_map_mem(n , root):
  print("//NV_ESC_RM_MAP_MEMORY")
  for line in n:
    split = line.split(",")
    romb = [x for x in split if "hDevice" in x or "hmem_" in x or "len" in x] 
    parent ,lenght,child = romb[0].split("=")[-1] ,romb[1].split("=")[-1] , romb[-1].split("=")[-1]
    print(f"DEVICE: {parent} -> MEM: {child} // len = 0x{(droga := lenght)} {(10 - len(droga))*' '}CLASS = {root.find_type(child)}")

#djubre
def print_command_by_type(root):
  k = {}
  def go(node):
    if node.type not in k: k[node] = []

    if node.cmd not in k[node] and node.cmd:
      k[node].extend([x for x in node.cmd if x not in k[node]])
    for x in node.childern: go(x)
  go(root)

  print("    SAMO OVI POZIVAJU METODE")
  print(set([k.type for k ,v in  k.items() if v]))

def map_to_strace(n):
  ap = []
  for x in n:
    if "NV_ESC_RM_ALLOC" in x and "NV_ESC_RM_ALLOC_MEMORY," not in x:
      k = [y for y in x.split(",") if "pObjnew" in y]
      ap.append(k[0].split("=")[-1])

  f = open("../strace_out.txt" ,"r").read().split("\n")
  f = [x for x in f if "ioct" in x and "0x2b" in x]
  #assert len(f) == len(ap)
  for x, y  in  zip(ap,f):print(f"{x}: {y}")

if __name__ == "__main__":
  file = open("../sve_2_manje.txt" , "r").read().split("\n")
  n = [x for x in file if any([y in x for y in ["NV_ESC_RM_ALLOC" , "NV_ESC_RM_CONTROL" , "NV_ESC_RM_MAP_MEMORY"]])]
  need = ["hObject","pObjparent","pObjnew","hDevice","hmem_"]

  make_graphs(n)
  #map_to_strace(n)
  root = make_rel(list(glob_graph.keys())[0] , type = None, root = True) 
  root.print_all(); print()
  print_command_by_type(root) ; print()
  print_rm_map_mem([x for x in n if "NV_ESC_RM_MAP_MEMORY" in x] , root) ;print()
  #print_free(file , root)