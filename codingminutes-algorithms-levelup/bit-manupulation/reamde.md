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
void setIthBit(int &n, int i) {
    int setBit = 1 << i;
    n = n | setBit;
}
```

#### clear `i'th` bit

do `&` operation with a number whose `i'th` bit is set to 0 and rest is 1.

to create such number first left shift 1 to i'th times `1 << i`, then do not of this like `~ ( 1 << i)`.

```c++
void clearIthBit(int &n, int i) {
    int clearBit = ~(1 << i);
    n = n & clearBit;
}
```

#### update `i'th` bit with user provided value

here the challenge is the same function should set the bit to 1 as well as 0. so above two function can not be applied here.

to do this first clear the `i'th` bit and then do `or` `|` operation with whatever user provided value is. so if th user provided value is 1 it will set the bit again else i will stay as it is.

```c++
void clearIthBit(int &n, int i, int v) {
    int clearBit = ~(1 << i);
    n = n & clearBit;

    int setBit = (v << i);
    n = n | setBit;
}
```

#### remove last `i'th` bits of a number

do `&` operation of that number with a number whose last `i'th` bits are set to 0 and rest is 1.

to create such a number take `~0` which is `-1` because it has all the bit's set as 1 then do left shift with `-1 << i`.

```c++
void clearLastIBits(int &n, int i) {
    int clearBit = (~0) << i;
    n = n & clearBit;
}
```

#### clear bit in `i` to `j`

here `i` is from LSB.

first create number whose last `j` bits are 0 and rest is 1 like this `(~0) << (j+1)`, `+1` because the range is inclusive so we are going to clear the j'th bit as well. 

then another number whose last i'th bit is 1 and rest is 0 like this `(1<<i) - 1`, here `1 << i` put 1 at i'th position and subtracting 1 will make i'th bit 0 and all the bit's after that 1. 

now `or` `|` operation between theses two will give a number whose starting from MSB before j all bit's are set to 1 and j to i all bit's are set to 0 then after i to LSB all are set to 1 again. `&` operation with this number will clear out all the bits between i an j.

```c++
void clearInRange(int &n, int i, int j) {
    int msbSet = (~0) << (j+1);
    int lsbSet = (1 << i) - 1;
    int clearSet = msbSet | lsbSet;

    n = n & clearSet;
}
```