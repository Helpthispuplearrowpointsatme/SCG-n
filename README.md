# the function <br/>
This is the function that will be reffered to as 'the function'
x = (x ^ y >> s) * a + b;

## The 4 modes: <br/>
There are two modes: chaotic and counter.<br/>
In every mode there are two submodes: Univariable and multivariable.<br/>
In chaotic mode, the state updates repetetively.<br/>
In counter mode, the state is a counter and the output function the previosly described function.<br/>
## What is it? <br/>
The SCG is a rather fast generator that *can* have maximal period.

## How fast is it?  <br/>
It let this speak for itself:

Benchmarking RNGs for 1000000000 iterations: <br/>
RanQ: 15814570 microseconds <br/>
XSH32: 10333481 microseconds <br/>
XSH64: 8043890 microseconds <br/>
SCG32: 4007280 microseconds <br/> 
SCG64: 4936434 microseconds <br/>
SCG128: 7882034 microseconds <br/>
PCG64: 5790676 microseconds <br/>
PCG128: 17849948 microseconds <br/>
LCG32: 3358901 microseconds <br/>
LCG64: 3984579 microseconds <br/>

this was without compiler optimalizations.

## How does it work? <br/>
The meaty part is this line: `x = (x ^ x >> s) * m + a;`<br/>
you can choose all variables to be as big as you wish; i would reccomend 128 bits.
