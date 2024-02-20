nv_ctrl, nv_0 = open("krajnji_buffer.txt").read().split("\n\n")
jumps = []
i = 0

#hChannel  5c000017 	Put 2000
#hChannel  5c00001f 	Put 5000
#hChannel  5c000023 	Put 8000
#hChannel  5c000027 	Put b000
#hChannel  5c00002b 	Put e000
#hChannel  5c00002f 	Put 11000
#hChannel  5c000033 	Put 14000
#hChannel  5c000037 	Put 17000
  
manji = 0
k = True
i = 0

for (x,y) in zip(nv_ctrl.split("\n") , nv_ctrl.split("\n")[1:]):
  x, y = x.split(":")[0], y.split(":")[0]
  if k == True:
    manji = x
    k = False
  
  if int(k := hex(int(y,16)-int(manji,16)) , 16) > 0x3000:
    print(k,f": {hex(int(y,16)-int(k,16))[:len('0x200400')] + '000'}-{y}" , i); i+=1
    k = True


manji = 0
k = True
i = 0

for (x,y) in zip(nv_0.split("\n") , nv_0.split("\n")[1:]):
  x, y = x.split(":")[0], y.split(":")[0]
  if k == True:
    manji = x
    k = False
  if int(k := hex(int(y,16)-int(manji,16)) , 16) > 0x1000:
    print(f"{k + (6 - len(k)) * ' '} : {manji} {i}"); i +=1 
    k = True
