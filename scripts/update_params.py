import sys
import os
import shutil
import re
import time
def main():
    if len(sys.argv) != 4:
        print("Usage: python update_params.py <design.sv> <width> <height>")
        sys.exit(1)

    design_file = sys.argv[1]
    new_width = sys.argv[2]
    new_height = sys.argv[3]

    base_dir = os.path.dirname(os.path.abspath(design_file))
    backup_file = os.path.join(base_dir, "design_bk.sv")
    copy_file   = os.path.join(base_dir, "design_cp.sv")

    shutil.copyfile(design_file, backup_file)

    width_pat  = re.compile(r'^(\s*parameter\s+int\s+WIDTH\s*=\s*)\d*\s*,')
    height_pat = re.compile(r'^(\s*parameter\s+int\s+HEIGHT\s*=\s*)\d*')
    line_counter = 0
    with open(design_file) as fin, open(copy_file, "w") as fout:
        for line in fin:
            line_counter+=1
            if width_pat.match(line):
                prefix = width_pat.match(line).group(1)
                fout.write(f"{prefix}{new_width},\n")
                continue

            if height_pat.match(line):
                prefix = height_pat.match(line).group(1)
                fout.write(f"{prefix}{new_height}")
                fout.write("\n")
                continue

            fout.write(line)

    os.remove(design_file)
    os.rename(copy_file, design_file)

if __name__ == "__main__":
    main()
