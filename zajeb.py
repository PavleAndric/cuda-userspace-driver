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


print(extract_values(0x20032080))


#static inline uint32_t
#NV04_FIFO_PKHDR_NI(int subc, int mthd, unsigned size)
#{
#   return 0x40000000 | (size << 18) | (subc << 13) | mthd;
#}

cigan  = """00000000 02054080 00000000 00000000
00000000 00000000 0000047f 3c000000
00000000 00000000 3af5e3b3 00000000
00000000 44010000 00000010 00000020
00000001 00000000 00000000 22240000
00010023 00010001 00121083 00000000
00000000 05607f7c 80000002 00000006
00000000 00000000 00000000 08000000
00000640 7300167f f4220000 0c4c7f3a 
f4010000 04107f3a 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
f4000000 80007f3a f5e3b300 00007f3a 
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000 00000000 00000000
00000000 00000000"""

l , l_ = 0, 0
for i, x in enumerate(cigan.split("\n")):
  i = i + 1
  l_ = len(x.split(" ")) * 32 + l_
  lol = f"{l}:{l_}"
  print(f"{lol + ' ' *( 9-len(lol))}  {x}" , end="")
  l = l_
  print()

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

#1024:1184  00000640 7300167f f4220000 0c4c7f3a 
#1184:1312  f4010000 04107f3a 00000000 00000000
