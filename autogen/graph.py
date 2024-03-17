import graphviz 
import os, tempfile

spl = lambda x: x.split("=")[-1].replace(" " , "")

class Object():
  def __init__(self , name:str , type = None, childern:list = []):
    self.name , self.childern = name, childern
    self.cmd ,self.type ,self.mapped = [], type, False

  def get_object(self , name):
    if self.name == name: return self
    for x in self.childern:
      k = x.get_object(name) 
      if k and  k.name == name:
        return k

  def print_all(self):
    self.pprint()
    for x in self.childern: x.print_all()

  def pprint(self): 
    t_print = " " * (5-len(self.type)) 
    print(f"Object {self.name}:{t_print}{self.type}")
    self.pprint_(8 , self.childern ,"children:" , 22)
    self.pprint_(8 , self.cmd ,"commands:" , 22)

  def pprint_(self, num, l, desc, spc = 0):
    print(f'{spc * " "} {desc}'  ,end = "")
    for i,x in enumerate(l):
      if i % num == 0:print("\n\t\t\t", end="")
      print(f"{x.name if isinstance(x, Object) else x} " , end="")
    print()

def make_graphs(n):
  for line in n:

    if "NV_ESC_RM_CONTROL" in line:
      obj, cmnd = [spl(x) for x in line.split(",") if  "cmd" in x or "hObject" in x]
      if obj not in cmnd_graph:
        cmnd_graph[obj] = []
      cmnd_graph[obj].append(cmnd)

    if "NV_ESC_RM_ALLOC" in line:
      parent ,child, type = [spl(x) for x in line.split(",") if any([y in x for y in need])]
      if parent == "0" or child == "0": continue

      if parent not in glob_graph:
        glob_graph[parent] = []
      glob_graph[parent].append((child , type))

def make_rel(k ,type, root = False):
  obj = Object(name = k ,type = "ROOT" if root else type)
  if obj.name in cmnd_graph: obj.cmd = cmnd_graph[obj.name] # cmnd
  if k in glob_graph:
    obj.childern = [make_rel(x[0], x[1] if len(x[1]) <= 7 else "MAPP" , root = False) for x in glob_graph[k]]
  return obj

#OVO JE SMECE 
def mapped_objs(n , root:Object):
  for line in n:
    if "hMemory__" in line:
      hmem = line.split("__")[-1].replace(" " ,"")
      obj = root.get_object(hmem)
      obj.mapped = True

def get_color(obj):
  if obj.type == "c46f": return 'lightpink'                       #TURING_CHANNEL_GPFIFO_A
  elif obj.type  == "c5b5": return "lightyellow"                  #TURING_DMA_COPY_A
  elif obj.type  == "c5c0": return "turquoise"                    #TURING_COMPUTE_A
  elif obj.type in {"40", "3e"} or obj.mapped: return "lightgrey" #mapping objects
  else: return "lightblue2"                                       

def make_g(root_ , f):
  for x in root_.childern:
    f.attr('node', style='filled', color=get_color(x), shape="circle")
    f.edge(root_.name, x.name)
    make_g(x ,f)

# ovaj fajl moze da se napise samo dictom ,ne moras da pravis Object klasu
if __name__ == "__main__":
  glob_graph, cmnd_graph, chrono = {}, {}, {}  
  file = open("../driver/sve.txt" , "r").read().split("\n")
  n = [x for x in file if any([y in x for y in ["NV_ESC_RM_ALLOC" , "NV_ESC_RM_CONTROL" , "hMemory__"]])] #TODO: regex
  need = ["hObject","pObjparent","pObjnew","hDevice","hMemory__","hclass"]
  make_graphs(n)
  root = make_rel(list(glob_graph.keys())[0] , type = None, root = True) 
  mapped_objs(n , root)

  root.print_all()
  # TODO: ovo popravi 
  if k := os.environ.get('GRAPH'):
     with tempfile.NamedTemporaryFile(prefix="gpu_graph",  suffix=".dot", delete=False) as temp_file:
      f = graphviz.Digraph('gpu_objects')
      f.attr(rankdir='TB', size='8,5')
      make_g(root , f)
      f.render(temp_file.name, cleanup=True)
      f.view()
      os.remove(temp_file.name)