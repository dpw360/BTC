#! /usr/bin/bash

# Create the parent directory
mkdir folderfun/

# Create the IceCream subdirectory, and touch the files within
mkdir folderfun/IceCream/
touch folderfun/IceCream/vanilla
touch folderfun/IceCream/chocolate
touch folderfun/IceCream/rum_raisin

# Create the Pizza subdirectory, and touch the files within
mkdir folderfun/Pizza/
touch folderfun/Pizza/cheese
touch folderfun/Pizza/pepperoni
touch folderfun/Pizza/mushroom

# ~/folderfun
# |
# +-IceCream+
# |         +vanilla
# |         +chocolate
# |         +rum_raisin
# |
# +-Pizza---+
#         +cheese
#         +pepperoni
#         +mushroom
