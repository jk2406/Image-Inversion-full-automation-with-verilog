#!/usr/bin/env python3
import argparse
from PIL import Image


def hex_to_bmp(hexfile, width, height, outfile):
    total_pixels = width * height

    # Read all bytes
    with open(hexfile, "r") as f:
        data = [int(line.strip(), 16) for line in f.readlines()]

    expected = total_pixels * 3
    if len(data) < expected:
        raise ValueError(f"HEX file too small. Need {expected} bytes.")

    # Create blank image
    img = Image.new("RGB", (width, height))
    pix = img.load()

    index = 0

    # Row-wise reconstruction: top to bottom, left to right
    for y in range(height):
        for x in range(width):
            r = data[index]
            g = data[index + 1]
            b = data[index + 2]
            index += 3
            pix[x, y] = (r, g, b)

    img.save(outfile, format="BMP")
    print(f"Saved: {outfile}")


def main():
    parser = argparse.ArgumentParser(
        description="Convert HEX (RGB row-wise format) back to BMP."
    )
    parser.add_argument("hexfile", help="Input HEX file")
    parser.add_argument("width", type=int, help="Image width")
    parser.add_argument("height", type=int, help="Image height")
    parser.add_argument("output", help="Output BMP filename")

    args = parser.parse_args()
    hex_to_bmp(args.hexfile, args.width, args.height, args.output)


if __name__ == "__main__":
    main()
