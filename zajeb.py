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

def rom(i):
  print(i)
  print((1055+(i)*64), (1024+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_ADDR_LOWER(i) 
  print((1072+(i)*64), (1056+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_ADDR_UPPER(i) 
  print((1073+(i)*64), (1073+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_RESERVED_ADDR(i) 
  print((1074+(i)*64), (1074+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_INVALIDATE(i)   
  print((1087+(i)*64), (1075+(i)*64)) # NVC5C0_QMDV02_03_CONSTANT_BUFFER_SIZE_SHIFTED4(i)


def see_diff():
  file = open("ide_gas.txt" , "r").read().split("\n")
  n = [int(x.replace(" " , ""),16) for x  in file]
  for x,y in zip(n, n[1:]):
    print(hex(y-x))
  
#see_diff()

#bar 6b497b80
#bar 6b49dd00
#69b8dda0->6b49ce40 
print(hex(0x6b49dd00-0x6b49ce40))

#bar  b9ae6040
#bar  b9aef040
#b76f5e60->b9aede00 
print(hex(0xb9aef040-0xb9aede00))




