#!/usr/bin/env python3
import argparse
from PIL import Image

# Converts image to HEX (row-wise, top-to-bottom)
def convert_to_hex(input_path, output_path):
    img = Image.open(input_path).convert("RGB")
    width, height = img.size

    total_lines = width * height * 3
    print(f"Image Width:  {width}")
    print(f"Image Height: {height}")
    print(f"Total HEX lines (R+G+B): {total_lines}")

    pixels = img.load()

    with open(output_path, "w") as f:
        # Row-wise scan: top to bottom, left to right
        for y in range(height):
            for x in range(width):
                r, g, b = pixels[x, y]
                f.write(f"{r:02X}\n")
                f.write(f"{g:02X}\n")
                f.write(f"{b:02X}\n")

    print(f"HEX file saved: {output_path}")

def main():
    parser = argparse.ArgumentParser(
        description="Convert image (JPG/PNG/BMP) to HEX for Verilog."
    )
    parser.add_argument("input", help="Input image file")
    parser.add_argument("output", help="Output HEX file")
    args = parser.parse_args()

    convert_to_hex(args.input, args.output)

if __name__ == "__main__":
    main()
