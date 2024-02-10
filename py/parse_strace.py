file = open("../strace_out.txt" , "r").read().split("\n")
in_line = ["nvidia" , "ioctl" , "mmap" , "close" , "munmap"] 

for line in file:
  if any([x in line for x in in_line]) and ("-1" not in line and "stat" not in line):
    print(line)