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

[(0, 128), '00000000 02054080 00000000 00000000']
[(128, 256), '00000000 00000000 0000047f 3c000000']
[(256, 384), '00000000 00000000 22f7e3b3 00000000']
[(384, 512), '00000000 44010000 00000010 00000020']
[(512, 640), '00000001 00000000 00000000 22240000']
[(640, 768), '00010023 00010001 00121083 00000000']
[(768, 896), '00000000 05607f7c 80000002 00000006']
[(896, 1024), '00000000 00000000 00000000 08000000']
[(1024, 1152), '00000640 7300167f f6220000 0c4c7f22']
[(1152, 1280), 'f6010000 04107f22 00000000 00000000']
[(1280, 1408), '00000000 00000000 00000000 00000000']
[(1408, 1536), '00000000 00000000 00000000 00000000']
[(1536, 1664), 'f6000000 80007f22 f7e3b300 00007f22']
[(1664, 1792), '00000000 00000000 00000000 00000000']
[(1792, 1920), '00000000 00000000 00000000 00000000']
[(1920, 2048), '00000000 00000000 00000000 00000000']
[(2048, 2112), '00000000 00000000']

print(256 + 32 * 2) # 320
print(319-288+1)
# // 22f7e3b3      22 NVC5C0_QMDV02_03_CIRCULAR_QUEUE_ADDR_UPPER
#
print()
def rom(i):
  print((1055+(i)*64)-(1024+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_ADDR_LOWER(i) 00000640
  print((1072+(i)*64)-(1056+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_ADDR_UPPER(i) 167f
  print((1073+(i)*64)-(1073+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_RESERVED_ADDR(i) 
  print((1074+(i)*64)-(1074+(i)*64)) #define NVC5C0_QMDV02_03_CONSTANT_BUFFER_INVALIDATE(i)   
  print((1087+(i)*64)-(1075+(i)*64)) # NVC5C0_QMDV02_03_CONSTANT_BUFFER_SIZE_SHIFTED4(i)


lol="""
200000000-200200000 r--p 00000000 00:00 0 
200200000-200230000 rw-s 00000000 00:05 1020                             /dev/nvidia0
200435000-200436000 rw-s 00035000 00:05 1019                             /dev/nvidiactl
202c00000-203c00000 rw-s 02800000 00:05 1019                             /dev/nvidiactl
203c00000-204a00000 ---p 00000000 00:00 0 
204a00000-204c00000 rw-s 00000000 00:05 1019                             /dev/nvidiactl
205400000-205600000 ---p 00000000 00:00 0 
205600000-205800000 rw-s 00000000 00:05 1019                             /dev/nvidiactl
205800000-205a00000 ---p 00000000 00:00 0 
205a00000-205c00000 rw-s 00000000 00:01 551052                           /dev/zero (deleted)
205c00000-300200000 ---p 00000000 00:00 0 
10000000000-10004000000 ---p 00000000 00:00 0 
5605bc7f7000-5605bc800000 r--p 00000000 103:02 14287008                  /home/pa/cuda_primer/primer
5605bc800000-5605bc86f000 r-xp 00009000 103:02 14287008                  /home/pa/cuda_primer/primer
5605bc86f000-5605bc896000 r--p 00078000 103:02 14287008                  /home/pa/cuda_primer/primer
5605bc897000-5605bc89c000 r--p 0009f000 103:02 14287008                  /home/pa/cuda_primer/primer
5605bc89c000-5605bc89d000 rw-p 000a4000 103:02 14287008                  /home/pa/cuda_primer/primer
5605bc89d000-5605bc89e000 rw-p 00000000 00:00 0 
5605be418000-5605bee70000 rw-p 00000000 00:00 0                          [heap]
7fc226000000-7fc228000000 ---p 00000000 00:00 0 
7fc228000000-7fc228021000 rw-p 00000000 00:00 0 
7fc228021000-7fc22c000000 ---p 00000000 00:00 0 
7fc22e000000-7fc22e400000 ---p 00000000 00:00 0 
7fc22e400000-7fc22e600000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc22e600000-7fc22e800000 rw-s 00000000 00:01 551049                     /dev/zero (deleted)
7fc22e800000-7fc22ea00000 rw-s 00000000 00:01 551050                     /dev/zero (deleted)
7fc22ea00000-7fc22f000000 ---p 00000000 00:00 0 
7fc22f000000-7fc22f200000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc22f200000-7fc22f400000 rw-s 00000000 00:01 551053                     /dev/zero (deleted)
7fc22f400000-7fc22f577000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc22f577000-7fc240000000 ---p 00000000 00:00 0 
7fc242dbc000-7fc242fbc000 rw-s 00000000 00:01 551051                     /dev/zero (deleted)
7fc242fbc000-7fc242fbd000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fbd000-7fc242fbe000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fbe000-7fc242fbf000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fbf000-7fc242fc0000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc0000-7fc242fc1000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc1000-7fc242fc2000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc2000-7fc242fc3000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc3000-7fc242fc4000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc4000-7fc242fc5000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc5000-7fc242fc6000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc6000-7fc242fc7000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc7000-7fc242fc8000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc8000-7fc242fc9000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fc9000-7fc242fca000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fca000-7fc242fcb000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fcb000-7fc242fcc000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fcc000-7fc242fcd000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fcd000-7fc242fce000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fce000-7fc242fcf000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fcf000-7fc242fd0000 rw-s 00000000 00:05 1019                       /dev/nvidiactl
7fc242fd0000-7fc243fde000 ---p 00000000 00:00 0 
7fc243fde000-7fc2447de000 rw-p 00000000 00:00 0 
7fc2447de000-7fc2447df000 ---p 00000000 00:00 0 
7fc2447df000-7fc244fdf000 rw-p 00000000 00:00 0 
7fc244fdf000-7fc24c000000 ---p 00000000 00:00 0 
7fc24c000000-7fc24c021000 rw-p 00000000 00:00 0 
7fc24c021000-7fc250000000 ---p 00000000 00:00 0 
7fc250060000-7fc2505ff000 rw-p 00000000 00:00 0 
7fc2505ff000-7fc250600000 ---p 00000000 00:00 0 
7fc250600000-7fc250e00000 rw-p 00000000 00:00 0 
7fc250e00000-7fc250e28000 r--p 00000000 103:02 14026911                  /usr/lib/x86_64-linux-gnu/libc.so.6
7fc250e28000-7fc250fbd000 r-xp 00028000 103:02 14026911                  /usr/lib/x86_64-linux-gnu/libc.so.6
7fc250fbd000-7fc251015000 r--p 001bd000 103:02 14026911                  /usr/lib/x86_64-linux-gnu/libc.so.6
7fc251015000-7fc251016000 ---p 00215000 103:02 14026911                  /usr/lib/x86_64-linux-gnu/libc.so.6
7fc251016000-7fc25101a000 r--p 00215000 103:02 14026911                  /usr/lib/x86_64-linux-gnu/libc.so.6
7fc25101a000-7fc25101c000 rw-p 00219000 103:02 14026911                  /usr/lib/x86_64-linux-gnu/libc.so.6
7fc25101c000-7fc251029000 rw-p 00000000 00:00 0 
7fc251035000-7fc251119000 rw-p 00000000 00:00 0 
7fc251119000-7fc251127000 r--p 00000000 103:02 14026945                  /usr/lib/x86_64-linux-gnu/libm.so.6
7fc251127000-7fc2511a3000 r-xp 0000e000 103:02 14026945                  /usr/lib/x86_64-linux-gnu/libm.so.6
7fc2511a3000-7fc2511fe000 r--p 0008a000 103:02 14026945                  /usr/lib/x86_64-linux-gnu/libm.so.6
7fc2511fe000-7fc2511ff000 r--p 000e4000 103:02 14026945                  /usr/lib/x86_64-linux-gnu/libm.so.6
7fc2511ff000-7fc251200000 rw-p 000e5000 103:02 14026945                  /usr/lib/x86_64-linux-gnu/libm.so.6
7fc251200000-7fc2512e2000 r--p 00000000 103:02 14026869                  /usr/lib/x86_64-linux-gnu/libcuda.so.545.29.06
7fc2512e2000-7fc251802000 r-xp 000e2000 103:02 14026869                  /usr/lib/x86_64-linux-gnu/libcuda.so.545.29.06
7fc251802000-7fc252cf8000 r--p 00602000 103:02 14026869                  /usr/lib/x86_64-linux-gnu/libcuda.so.545.29.06
7fc252cf8000-7fc252cf9000 ---p 01af8000 103:02 14026869                  /usr/lib/x86_64-linux-gnu/libcuda.so.545.29.06
7fc252cf9000-7fc252d12000 r--p 01af8000 103:02 14026869                  /usr/lib/x86_64-linux-gnu/libcuda.so.545.29.06
7fc252d12000-7fc252e18000 rw-p 01b11000 103:02 14026869                  /usr/lib/x86_64-linux-gnu/libcuda.so.545.29.06
7fc252e18000-7fc252e84000 rw-p 00000000 00:00 0 
7fc252e9e000-7fc252f06000 rw-p 00000000 00:00 0 
7fc252f06000-7fc252f07000 r--p 00000000 103:02 14037365                  /usr/lib/x86_64-linux-gnu/librt.so.1
7fc252f07000-7fc252f08000 r-xp 00001000 103:02 14037365                  /usr/lib/x86_64-linux-gnu/librt.so.1
7fc252f08000-7fc252f09000 r--p 00002000 103:02 14037365                  /usr/lib/x86_64-linux-gnu/librt.so.1
7fc252f09000-7fc252f0a000 r--p 00002000 103:02 14037365                  /usr/lib/x86_64-linux-gnu/librt.so.1
7fc252f0a000-7fc252f0b000 rw-p 00003000 103:02 14037365                  /usr/lib/x86_64-linux-gnu/librt.so.1
7fc252f0b000-7fc252f0c000 r--p 00000000 103:02 14037363                  /usr/lib/x86_64-linux-gnu/libpthread.so.0
7fc252f0c000-7fc252f0d000 r-xp 00001000 103:02 14037363                  /usr/lib/x86_64-linux-gnu/libpthread.so.0
7fc252f0d000-7fc252f0e000 r--p 00002000 103:02 14037363                  /usr/lib/x86_64-linux-gnu/libpthread.so.0
7fc252f0e000-7fc252f0f000 r--p 00002000 103:02 14037363                  /usr/lib/x86_64-linux-gnu/libpthread.so.0
7fc252f0f000-7fc252f10000 rw-p 00003000 103:02 14037363                  /usr/lib/x86_64-linux-gnu/libpthread.so.0
7fc252f10000-7fc252f12000 rw-p 00000000 00:00 0 
7fc252f12000-7fc252f13000 r--p 00000000 103:02 14026941                  /usr/lib/x86_64-linux-gnu/libdl.so.2
7fc252f13000-7fc252f14000 r-xp 00001000 103:02 14026941                  /usr/lib/x86_64-linux-gnu/libdl.so.2
7fc252f14000-7fc252f15000 r--p 00002000 103:02 14026941                  /usr/lib/x86_64-linux-gnu/libdl.so.2
7fc252f15000-7fc252f16000 r--p 00002000 103:02 14026941                  /usr/lib/x86_64-linux-gnu/libdl.so.2
7fc252f16000-7fc252f17000 rw-p 00003000 103:02 14026941                  /usr/lib/x86_64-linux-gnu/libdl.so.2
7fc252f22000-7fc252f32000 -w-s 00000000 00:05 1020                       /dev/nvidia0
7fc252f32000-7fc252f33000 r--p 00000000 103:02 14287047                  /home/pa/cuda_primer/intercept.so
7fc252f33000-7fc252f35000 r-xp 00001000 103:02 14287047                  /home/pa/cuda_primer/intercept.so
7fc252f35000-7fc252f36000 r--p 00003000 103:02 14287047                  /home/pa/cuda_primer/intercept.so
7fc252f36000-7fc252f37000 ---p 00004000 103:02 14287047                  /home/pa/cuda_primer/intercept.so
7fc252f37000-7fc252f38000 r--p 00004000 103:02 14287047                  /home/pa/cuda_primer/intercept.so
7fc252f38000-7fc252f39000 rw-p 00005000 103:02 14287047                  /home/pa/cuda_primer/intercept.so
7fc252f39000-7fc252f3b000 rw-p 00000000 00:00 0 
7fc252f3b000-7fc252f3d000 r--p 00000000 103:02 14026896                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7fc252f3d000-7fc252f67000 r-xp 00002000 103:02 14026896                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7fc252f67000-7fc252f72000 r--p 0002c000 103:02 14026896                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7fc252f73000-7fc252f75000 r--p 00037000 103:02 14026896                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7fc252f75000-7fc252f77000 rw-p 00039000 103:02 14026896                  /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
7ffda66db000-7ffda66fc000 rw-p 00000000 00:00 0                          [stack]
7ffda6728000-7ffda672c000 r--p 00000000 00:00 0                          [vvar]
7ffda672c000-7ffda672e000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]
"""

print(len(lol))


cig ="""7ffda6728000-7ffda672c000 r--p 00000000 00:00 0                          [vvar]
7ffda672c000-7ffda672e000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]"""
print(len(cig) , 10149+243)