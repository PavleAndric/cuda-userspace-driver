import sys
import subprocess

def get_nums(k):
  nums , name = "" , ""
  for i in range(len(k)):
    if k[i] != ' ': nums += k[i]
    else: break

  for i in range(len(k)-1 , 1 , -1):
    if k[i] != ' ':name += k[i]
    else:break 
  return name[::-1] , nums

include = ["nvidia0" , "nvidiactl" ,"nvidia-uvm"] 
pid = sys.argv[-1] 
result = subprocess.run(f"cat /proc/{pid}/maps", shell=True, stdout=subprocess.PIPE, text=True)
maps = result.stdout.split("\n")
nvidia_maps = [x for x in maps if any([y in x for y in include])]

print("#include <stdint.h>")
print("#include <stdio.h>")
print("#include <string.h>")
print("#define SIZE 2")
print("#define ARR_SIZE 0x3800000")

print("\nuint32_t A[ARR_SIZE];")
print("uint32_t B[ARR_SIZE];\n")
print("struct parse { uint32_t *str; uint32_t *end; };")
print("struct parse parseArray[] = {\n")


for i, x in enumerate(nvidia_maps): 
  name , nums = get_nums(x)
  name = name.replace("/" , "_")
  s_ , e_ =nums.split('-')
  print(k := f"  {'{'} .str = (uint32_t*)0x{s_}, .end = (uint32_t*)0x{e_} {'}'}{',' if i != len(nvidia_maps)-1 else ''}" , end="")
  print(f"{' ' * (70 - len(k))} //{name}")
print("\n};")



#print(f"struct parse {name +'_'+str(i)} {'={'}\n  .str = (uint64_t*)0x{s_},\n  .end = (uint64_t*)0x{e_}\n{'};'}")

"""
void clear_arrs(){
  memset(&A , 0x0 , ARR_SIZE);
  memset(&B , 0x0 , ARR_SIZE);
}

void make_arr(int broj){
  for(int i = 0 ; i < SIZE; i ++){
    int j = 0;
    for(uint32_t* start = parseArray[i].str; start < parseArray[i].end ; start++){
      if (start != NULL) { 
        if (broj == 0){A[j] = (uint32_t)*start; j++;}
        if (broj == 1){B[j] = (uint32_t)*start; j++;}
      }
    } 
  } 
}
void compare(){
  for(int i = 0 ; i < ARR_SIZE ;  i ++){
      if (B[i] != A[i]){
        printf("%x->%x \n" , A[i] , B[i]);
    }
  }
}"""