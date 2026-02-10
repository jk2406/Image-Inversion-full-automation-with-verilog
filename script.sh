#!/bin/bash
orig_dir="$PWD"
script_dir="$PWD/scripts"
src_dir="$PWD/src"
img_dir="$PWD/image_in"
img_out_dir="$PWD/image_out"
mkdir -p "$img_out_dir"
cd $img_dir
file=$(ls|head -n 1)
cd $src_dir
verilog_file="design.sv"

cd "$script_dir"

echo "Do you want to add custom padding?"
read -r resp

if [ "$resp" == "y" ];then
    echo "Enter padding,will be added to all sides"
    read -r resp
   python add_padd.py "$img_dir/$file" pad_test.png --pad "$resp"
else 
   python add_padd.py "$img_dir/$file" pad_test.png
fi
sleep 0.5 
touch temp.txt
python converter.py "$script_dir/pad_test.png" test.hex >"$src_dir/temp.txt"
cd "$src_dir"
width=$(awk -F": " '/Image Width/ {print $2}' temp.txt)
height=$(awk -F": " '/Image Height/ {print $2}' temp.txt)
width=$(echo "$width"|head -n 1)
height=$(echo "$height"|head -n 1)
cd "$src_dir"
cp design.sv design_bk.sv
cd "$script_dir"
python update_params.py "$src_dir/$verilog_file" "$width" "$height"
echo "Width is $width"
python extract_top_name.py "$src_dir/$verilog_file"
top=$(cat "temp.txt")
rm temp.txt
# se/d -i "/^[[:space:]]*$width[[:space:]]*$/d" "$src_dir/$verilog_file"


rm -f "$src_dir/test.hex"
cp test.hex "$src_dir"
echo "Do you want to compile?y/n"
read -r resp
if [ "$resp" == "y" ]; then
cd  "$src_dir"
verilator -j $(nproc) --binary "$src_dir/$verilog_file" -top "$top"
sleep 1
fi
./obj_dir/V"$top"
sleep 0.5
mv output.hex "$script_dir"
cd "$script_dir"
python hex_to_bmp.py output.hex "$width" "$height" output.bmp
mv "output.bmp" "$img_out_dir"
rm "$src_dir/temp.txt"
cd "$src_dir"
rm test.hex
cd "$orig_dir"
echo "Keep hex file?y/n"
read -r resp
if [ "$resp" != "y" ];then
    cd "$script_dir"
    rm test.hex
fi
echo "Do you want to open the output file?y/n"
read -r resp
if [ "$resp" == "y" ];then
    explorer.exe "$(wslpath -w "$img_out_dir/output.bmp")"
fi
sleep 2
exit 0

