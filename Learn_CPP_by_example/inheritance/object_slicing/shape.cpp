#include "shape.h"

Shape::Shape()
{
    cout << "SHAPE: Inside of the no-argument constructor" << endl;
}

Shape::~Shape()
{
    cout << "SHAPE: Inside of the destructor" << endl;
}

void Shape::print() const
{
    cout << "SHAPE: My size is " << sizeof(*this) << " bytes" << endl;
}



/*
Theory: why sizeof(*this) and not sizeof(this)
this is a pointer — specifically a Shape* inside non-static member functions. That’s exactly why sizeof(this) is not what you want here.
What sizeof(this) means

    this has type Shape*
    so sizeof(this) is the size of a pointer, not the size of the object
    On most 64-bit systems, that will be 8 bytes (on many 32-bit systems, 4 bytes), regardless of how big Shape is.

So sizeof(this) answers: “how big is a Shape* pointer on this platform?”
What sizeof(*this) means

    *this dereferences the pointer
    *this is the actual object (an lvalue) of type Shape
    so sizeof(*this) is sizeof(Shape) — i.e., the size of the object in memory.

So sizeof(*this) answers: “how big is the current Shape object?”
*/
