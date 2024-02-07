def get_nums(k):
  nums , name = "" , ""
  for i in range(len(k)):
    if k[i] != ' ': nums += k[i]
    else: break

  for i in range(len(k)-1 , 1 , -1):
    if k[i] != ' ':name += k[i]
    else:break 
  return name[::-1] , nums

if __name__ == "__main__":
  include = ["nvidia0" , "nvidiactl" ,"nvidia-uvm" , "dev/zero"]
  result = open("mapping.txt" , "r").read().split("\n") # ASLR turned off
  nvidia_maps = [x for x in result if any([y in x for y in include])]

  print("#include <stdint.h>\n#include <stdio.h>\n#include <string.h>")
  print("#define SIZE 2\n#define ARR_SIZE 0x3800000")

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

