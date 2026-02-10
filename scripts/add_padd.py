#!/usr/bin/env python3
import argparse
from PIL import Image
import math

def pad_image(input_path, output_path, pad_value):
    # Load image
    img = Image.open(input_path).convert("RGB")
    w, h = img.size

    # If user didn't give padding, compute 1.5× size
    if pad_value is None:
        new_w = int(w * 1.5)
        new_h = int(h * 1.5)

        # Padding computation
        pad_left = (new_w - w) // 2
        pad_top  = (new_h - h) // 2
    else:
        # padding given in pixels
        pad_left = pad_value
        pad_top  = pad_value
        new_w = w + 2 * pad_value
        new_h = h + 2 * pad_value

    print(f"Original width  : {w}")
    print(f"Original height : {h}")
    print(f"Padded width    : {new_w}")
    print(f"Padded height   : {new_h}")
    print(f"Left/Right pad  : {pad_left}")
    print(f"Top/Bottom pad  : {pad_top}")

    # Create black padded image
    padded = Image.new("RGB", (new_w, new_h), (0, 0, 0))

    # Paste original image at center
    padded.paste(img, (pad_left, pad_top))

    padded.save(output_path)
    print(f"Saved padded image → {output_path}")


def main():
    parser = argparse.ArgumentParser(description="Add zero-padding around an image.")
    parser.add_argument("input", help="Input image file")
    parser.add_argument("output", help="Output padded image file")
    parser.add_argument("--pad", type=int, default=None,
                        help="Padding in pixels. Default = 1.5x width & height")

    args = parser.parse_args()
    pad_image(args.input, args.output, args.pad)

if __name__ == "__main__":
    main()

