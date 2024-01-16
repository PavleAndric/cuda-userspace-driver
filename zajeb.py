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