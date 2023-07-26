# Bit manipulation

## Things to remember

### Negative number representation

in a 32bit integer number by default first bit is signed bit and rest is magnitude. if sign bit is `1` then the number is negative. in most of the languages if the first bit is `1` then the magnitude is represented in `2's compliment` form.

so for example `~0`(not of 0) return `-1`, because not make all 32 bit 1 of which first bit is 1 so number is negative and rest 32 bit is set to `1` which is in `2's compliment form`. to convert a `2's complement` number into `1's complement` invert all the bits and add 1 to it with make the magnitude `1`. so the magnitude with the sign bit is `-1`.

### Left shift <<

`a << b` is same as `a * 2^b`. a is left shifted b number of bits. execs bit of the left will just discarded.

### Right shift >> 

`a >> b` is same as `a / 2^b`. a is right shifted b number of bits. execs bit of the right will just get discarded.
