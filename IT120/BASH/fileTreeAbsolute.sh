#! /usr/bin/bash

# Create the parent directory
mkdir /home/folderfun/

# Create the IceCream subdirectory, and touch the files within
mkdir /home/folderfun/IceCream/
touch /home/folderfun/IceCream/vanilla
touch /home/folderfun/IceCream/chocolate
touch /home/folderfun/IceCream/rum_raisin

# Create the Pizza subdirectory, and touch the files within
mkdir /home/folderfun/Pizza/
touch /home/folderfun/Pizza/cheese
touch /home/folderfun/Pizza/pepperoni
touch /home/folderfun/Pizza/mushroom

tree

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
