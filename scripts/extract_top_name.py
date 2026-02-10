import sys 
try:
    file = sys.argv[1]
except:
    print("Usage --> python extract_top_name.py <file>")
with open(file,"r") as fin,open("temp.txt","w") as fout:
    for line in fin:
        l = line.strip("#();")
        l = l.split()
        for i,w in enumerate(l):
            if(w=="module"):
                module_name = l[i+1]
                fout.write(module_name)
                break
