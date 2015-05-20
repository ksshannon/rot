
require("librotate")

function usage()
  print("test file\n");
  print("\n");
  print("where the file contains two strings, input and expected result\n");
  os.exit(1);
end


-- Read arg[1] as the file
fin = io.open(arg[1])
if fin == nil then
  os.exit(1)
end

i = fin:read("*line")
e = fin:read("*line")
n = fin:read("*line")
fin:close()

r = rotate(i,n)

if r ~= e then
  os.exit(1)
end
os.exit(0)

