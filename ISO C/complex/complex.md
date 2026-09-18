# complex
## NAME
complex - basics of complex mathematics
## SYNOPSIS
`#include <complex.h>`
## DESCRIPTION
Complex  numbers  are  numbers of the form $z = a+b\cdot \mathrm{i}$, where a and b are real numbers and $\mathrm{i}=\sqrt{ -1 }$, so that $\mathrm{i}\cdot \mathrm{i}=-1$.

There are other ways to represent that number.  The pair $(a,b)$ of real numbers may be viewed as a point in the plane,  given  by X- and Y-coordinates.  This same point may also be described by giving the pair of real numbers $(r,\phi)$, where $r$ is the distance to the origin O, and $\phi$ is the angle between the X-axis and the  line  Oz. Now $z=r\cdot\exp(\mathrm{i}\cdot \phi)=r\cdot(\cos(\phi)+\mathrm{i}\cdot \sin(\phi))$.

The basic operations are defined on $z=a+b\mathrm{i}$ and $w=c+d\mathrm{i}$ as:

addition: $z+w=(a+c)+(b+d)\mathrm{i}$

multiplication: $z\cdot w=(ac-bd)+(ad+bc)\mathrm{i}$

division: $\frac{z}{w}=\frac{ac+bd}{cc+dd}+\frac{bc-ad}{cc+dd}\mathrm{i}$

Nearly all math function have a complex counterpart but there are some complex-only functions.
几乎所有实数数学函数，都有对应的“复数版本”；但也有一些函数只在复数理论里才存在。

## EXAMPLES
Your C-compiler can work with complex numbers if it supports the C99 standard.  The imaginary unit is represented by I.

