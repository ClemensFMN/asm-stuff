# -*- coding: utf-8 -*-
"""
Created on Fri Jan 23 13:54:37 2015

@author: ClNovak
"""

#hexdata = "40900000" # -> 4.5
# hexdata = "3fbae148" # -> 1.46
hexdata = "4095b22d" # -> 4.678


num_of_bits = 32

bin_rep = bin(int(hexdata, 16))[2:].zfill(num_of_bits)

print(bin_rep)

sign = bin_rep[0:1]
exp = bin_rep[1:9]
fraction = bin_rep[9:]

print sign, "...", exp, "...", fraction


sign_val = (-1)**(int(sign))

exp_val = 2**(int(exp,2) - 127)

fraction_val = int(fraction,2)/2.0**23

val = sign_val * (1.0 + fraction_val) * exp_val

print val

