/*Variable eclaration in C/C++
------------------------------------------
[auto|extern|static|register] [volatile|const] dataType varName[=initialValue];
----------------------------------------------------------------------
Note: words written in [] are optional. [] is not part of current syntax
| represents OR

Is auto|extern|static|register not specified, the auto will be default

volatile|const defines the type of variable.

volatile variable's values can be changed.

const variable's values can't be changed.
so. const variable must be initialized.

const variable is also known as READ ONLY Variable.

if volatile|const not specified, the vaolatile will be default value.
*/

 int main()
{
	int a;
	auto int b;
	auto volatile int c;
	const int  d=10;
	auto const int e=20;
	a=10;
	b=30;
	c=90;
	d=4;//error
	e=9;//error
}