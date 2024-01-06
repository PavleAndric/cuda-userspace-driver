#!/usr/bin/env python
import ctypes, re, sys

c_ptrace = ctypes.CDLL("libc.so.6").ptrace
c_pid_t = ctypes.c_int32 # This assumes pid_t is int32_t
c_ptrace.argtypes = [ctypes.c_int, c_pid_t, ctypes.c_void_p, ctypes.c_void_p]
def ptrace(attach, pid):
  op = ctypes.c_int(16 if attach else 17) #PTRACE_ATTACH or PTRACE_DETACH
  c_pid = c_pid_t(pid)
  null = ctypes.c_void_p()
  err = c_ptrace(op, c_pid, null, null)
  if err != 0:
    assert False, "greska"

def maps_line_range(line):
    m = re.match(r'([0-9A-Fa-f]+)-([0-9A-Fa-f]+) ([-r])', line)
    return [int(m.group(1), 16), int(m.group(2), 16), m.group(3)]

def cat_proc_mem(pid):
    ## Apparently we need to ptrace(PTRACE_ATTACH, $pid) to read /proc/$pid/mem
    ptrace(True, int(pid))
    ## Read the memory maps to see what address ranges are readable
    maps_file = open("/proc/" + pid + "/maps", 'r')  #maps_cuda = [x for x  in maps_file.read().split('\n') if "libcuda.so" in x]
    ranges = [maps_line_range(x) for x  in maps_file.read().split('\n') if "libcuda.so" in x]
    maps_file.close()
    ## Read the readable mapped ranges
    mem_file = open(f'/proc/{pid}/mem', 'rb')
    for r in ranges:
      if r[2] == 'r':
        mem_file.seek(r[0])
        chunk = mem_file.read(r[1] - r[0])
        #print(chunk)
    mem_file.close()
    ptrace(False, int(pid))
if __name__ == "__main__":
  for pid in sys.argv[1:]:
    cat_proc_mem(pid)