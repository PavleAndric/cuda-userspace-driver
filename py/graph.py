file = open("../sve.txt" , "r").read().split("\n")
need = ["NV_ESC_RM_ALLOC" , "NV_ESC_RM_CONTROL"] # "NV_ESC_RM_MAP_MEMORY" ,
n = [x for x in file if any([y in x for y in need])]
need = ["hObject","pObjparent","pObjnew"]

glob_graph, cmnd_graph= {} , {}


class Object():
  def __init__(self , name:str , childern:list = [] ,type = None):
    self.name , self.childern , self.type = name, childern , type
    self.cmd  = None
  
  def print_all(self):
    self.pprint()
    for x in self.childern:
      x.print_all()

  def get_commands(self): print(self.cmd) if self.cmd else print(end ="")

  def pprint(self): 
    print(f"Object : {self.name}" , end=": children{")
    
    for i in range(len(self.childern)):
      if i % 4 == 0: print("\n\t\t   " ,end="")
      print(f"{self.childern[i].name} " , end="")
    print("}")

    if self.cmd:
      print(" " * 18 , "commands{")
      for i in range(len(self.cmd)):
        if i % 4 == 0: print("\n\t\t   " ,end="")
        print(f"{self.cmd[i]} " , end="")
      print("}")

def get_cmnd(x):
  str = ""
  for i in range(5, len(x)):
    if x[i] != " ": str += x[i]
    else: return str 
  
def make_graphs(n): # control
  for line in n:
    if "NV_ESC_RM_CONTROL" in line:
      split = line.split(",")
      romb = [x for x in split if any([y in x for y in need])] + [split[-1]] # ispravi ovo
      obj, cmnd = romb[0].split('=')[-1] , get_cmnd(romb[-1])
      if obj not in cmnd_graph:
        cmnd_graph[obj] = []
      cmnd_graph[obj].append(cmnd)
  
  for line in n:
    split = line.split(",")
    romb = [x for x in split if any([y in x for y in need])] + [split[-1]]

    if any(["pObjparent" in z for z in romb]):
      parent ,child, type = romb[0].split("=")[-1] ,romb[1].split("=")[-1] , romb[-1].split("=")[-1]
      if parent == "0" or child == "0":
        continue
      if parent not in glob_graph: glob_graph[parent] = []
      glob_graph[parent].append((child , type))

def make_rel(k , type):
  obj = Object(name = k , type = type)

  if obj.name in cmnd_graph: obj.cmd = cmnd_graph[obj.name] # cmnd
  if k in glob_graph: # parent child
    obj.childern = [make_rel(x[0] , x[1]) for x in glob_graph[k]]
  return obj

make_graphs(n)
root = make_rel(k := list(glob_graph.keys())[0] ,glob_graph[k][-1]) 
root.print_all()


