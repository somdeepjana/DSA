# Bit manipulation

## Things to remember

### Negative number representation

in a 32bit integer number by default first bit is signed bit and rest is magnitude. if sign bit is `1` then the number is negative. in most of the languages if the first bit is `1` then the magnitude is represented in `2's compliment` form.

so for example `~0`(not of 0) return `-1`, because not make all 32 bit 1 of which first bit is 1 so number is negative and rest 32 bit is set to `1` which is in `2's compliment form`. to convert a `2's complement` number into `1's complement` invert all the bits and add 1 to it with make the magnitude `1`. so the magnitude with the sign bit is `-1`.

### Shifting operation

#### Left shift <<

`a << b` is same as `a * 2^b`. a is left shifted b number of bits. execs bit of the left will just discarded.

#### Right shift >> 

`a >> b` is same as `a / 2^b`. a is right shifted b number of bits. execs bit of the right will just get discarded.

### Getting and setting bit

#### get `i'th` bit from a number

do `&` operation with the number by another number whose `i'th` bit is 1 and rest to 0.

for creating such number whose `i'th` bit is 1 and rest is 0 left shift number 1 to `i'th` times like this `1 << i`. this put the 1 that is present at LSB to `i'th` position.

```c++
int getIthBit(int n, int i) {
    int maskBit = 1 << i;
    int maskNumb = n & maskBit;

    return maskNumb > 0 ? 1 : 0;
}
```

#### set `i'th` bit of a number

do `or` `|` operation of the number with a number whose `i'th` bit is set and rest are 0. for creating such number see the previous topic.

```c++
int setIthBit(int n, int i) {
    int setBit = 1 << i;
    int setNumb = n | setBit;

    return setNumb;
}
```