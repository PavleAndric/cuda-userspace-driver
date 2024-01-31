def ide_gas():
  lmao = hex(73874)     #  0x12092
  ide_gas = hex(139360) #  0x22060
  i = 0

  ide_ = 1
  while ide_ != 0:
    ide_ = int(lmao,16) >> i
    ide_2 = int(ide_gas,16) >> i
    i += 1 
    print(hex(ide_) , ide_ , i)
    print(hex(ide_2) , ide_2 , i)
    print()

def go(size , subc , mthd): #return 0x20000000 | (size << 16) | (subc << 13) | (mthd >> 2);
  return 0x20000000 | (size << 16) | (subc  << 13) | (mthd >> 2) 

def reverse(final):
  kok = str(hex(final))
  size =  int(kok[5] + (len(kok[6:]) * "0"),16) >> 16
  subc = int(kok[6:8] +(len(kok[8:]) * "0"),16) >> 13
  mthd = int(kok[-2:],16) << 2
  return [hex(x) for x in [size ,subc ,mthd]]  

def extract_values(output):
  type =  output & 0xF0000000
  size = (output & 0x000FF000) >> 16
  subc = (output & 0x00000F00) >> 13
  mthd = (output & 0x000000FF) << 2

  return hex(type) , hex(size), hex(subc), hex(mthd)


print(extract_values(0x200426c0))

exit(1)
#static inline uint32_t
#NV04_FIFO_PKHDR_NI(int subc, int mthd, unsigned size)
#{
#   return 0x40000000 | (size << 18) | (subc << 13) | mthd;
#}

cigan  = """00000000 02054080 00000000 00000000
00000000 00000000 0000047f 3c000000
00000000 00000000 22f7e3b3 00000000
00000000 44010000 00000010 00000020
00000001 00000000 00000000 22240000
00010023 00010001 00121083 00000000
00000000 05607f7c 80000002 00000006
00000000 00000000 00000000 08000000
00000640 7300167f f6220000 0c4c7f22
f6010000 04107f22 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
f6000000 80007f22 f7e3b300 00007f22
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000"""


cigan_2=  """00000000 02054080 00000000 00000000
00000000 00000000 0000047f 3c000000
00000000 00000000 4fd5e3b3 00000000
00000000 44010000 00000020 00000010 x and y dims
00000001 00000000 00000000 22240000
00010023 00010001 00121083 00000000
00000000 05607f7c 80000002 00000006
00000000 00000000 00000000 08000000
00000640 7300127f d4220000 0c4c7f4f
d4010000 04107f4f 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
d4000000 80007f4f d5e3b300 00007f4f
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000"""



#1536:1664 = 128
#(1567,1536) = 31 + 1 = 32

# (1536 + 1) - 1567 = 0
#0 + 32

VC5C0_QMDV02_03_PROGRAM_ADDRESS_LOWER =  (1567,1536)
NVC5C0_QMDV02_03_PROGRAM_ADDRESS_UPPER = (1584,1568)

def ide_gas(replace = True):
  
  gas = []
  l , l_ = 0, 0
  for i, x in enumerate(cigan.split("\n")):
    l_ = len(x.split(" ")) * 32 + l_
    lol = ( l , l_)
    gas.append([lol ,x])
    gas[i][-1] = gas[i][-1].replace(" " , "") if replace  else  gas[i][-1]
    l = l_
  return gas
  if False:
    rom= "".join(cigan.replace(" " , "").replace("\n" , ""))
    lmao = ""
    for x in rom:
      k = bin(int(x , 16))[2:]
      lmao += (4 - len(k))*"0" + k 

    i = 0
    for x ,y in enumerate(lmao):
      x = x + 1
      print(f"{y}",end = "")
      if x % 32 == 0:
        print(f"\t{i}:{x}")
        i  = x
    print()

"""
for x in ide_gas(False): 
  print(x)

for x ,y in ide_gas():
  if x[0] <= 1536 and x[1] >= 1567:
    print(y[(x[0] - 1536):(1567-1536) // 4])
  if x[0] <= 1568 and x[1] >= 1584:
    k_1 = (1568 -x[0]) // 4
    k_2 = (1584-1568) // 4 + k_1
    print(y[k_1:k_2])
"""

def rom(i):
  print(i)
  print((1055+(i)*64), (1024+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_ADDR_LOWER(i) 
  print((1072+(i)*64), (1056+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_ADDR_UPPER(i) 
  print((1073+(i)*64), (1073+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_RESERVED_ADDR(i) 
  print((1074+(i)*64), (1074+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_INVALIDATE(i)   
  print((1087+(i)*64), (1075+(i)*64)) # NVC5C0_QMDV02_03_CONSTANT_BUFFER_SIZE_SHIFTED4(i)

k, k_1 = open("lolol.txt" ,"r").read().split("*************cuda_LacunhKernel*************")

k , k_1 = k.split() , k_1.split()

for x , y in zip(k , k_1):
  if x != y:
    print(x ,y)
#for  x ,y  in zip():
#  if x != y:
#    print(x ,y)
