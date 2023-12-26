import string

file = open("nvidia_open.txt","r").read().split("\n")
def is_hex(s):
  s = "".join([x for x in s if x != " "]) 
  if s.startswith("0x"): s =s[2:]
  if s.endswith(")"): s = s[:-1]
  hex_digits = set(string.hexdigits)
  k = all([x in hex_digits for i, x in enumerate(s)])
  return k

if __name__ == "__main__":
  k = [[int((y[:-1] if y.endswith(")") else y) , 16) if is_hex(y) else y for y in x.split(",")] for x in file]
  for  x  in k:
    print(*x)
