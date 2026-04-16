#include <QCoreApplication>
#include <QDebug>
#include "test.h"

Test* makeTree()
{
    Test *root = new Test(nullptr,"root");

    //create children of the root which are parents to other children
    for (int i = 0; i < 5; ++i)
    {
        Test* child = new Test(root,"Parent"+QString::number(i));
        qInfo()<<"Creating a child at level 1: "<<child;

        for (int j = 0; j < 6; ++j)
        {
            Test *child1 = new Test(child,"Child"+QString::number(j)+"Parent"+QString::number(i));
            qInfo()<<"Creating a child at level 2:"<<child1;

            for(int k=0;k<3;++k)
            {
                Test *child2 = new Test(child1,"Child"+QString::number(k)+"ParentChild"+QString::number(j));
                qInfo()<<"Creating a child at level 3:"<<child2;

                Q_UNUSED(child2); //do not show warning for unused variable 'child2' anymore
            }
        }
    }

    return root;
}


void printTree(Test *tree, int level=0)
{
   //Defensive coding , verify it children exist
    if(tree->children().length()==0)
   {
       return;
    }

    QString line ="-";
    line.fill('-',level*5);

    foreach (QObject *obj,tree->children())
    {
        Test *object = qobject_cast<Test *>(obj);
        if(!object)
        {
            return;
        }

        qInfo()<<line<<object;

        printTree(object, level+1);
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test *root = makeTree();
    printTree(root,2);

    delete(root); //deleted pointer - manual memory manangement

    return QCoreApplication::exec();
}




/*

**1. Initialization**

```cpp
QString line = "-";
```

You create a `QString` object named `line` and initialize it with a single hyphen. At this moment, the string length is 1.

**2. The `fill()` Method**

```cpp
line.fill('i', level * 5);
```

This is where the magic (and the potential confusion) happens. The `fill()` function does two things:

  * **Resizes** the string to the length specified by the second argument (`level * 5`).
  * **Replaces** every single character in that string with the character provided in the first argument (`'i'`).

> [\!IMPORTANT]
> The original hyphen (`"-"`) is **completely overwritten**. `fill()` does not append; it resets the entire content of the string to the new character.

-----

### A Concrete Example

Let's assume the variable `level` is an integer representing a nesting level (like in a file directory or a tree structure).

If `level = 2`:

1.  `level * 5` equals **10**.
2.  `line.fill('i', 10)` turns `line` into a string of **10 "i" characters**.
3.  **Result:** `"iiiiiiiiii"`

### C++ vs. Qt: How would we do this in "Standard" C++?

In standard C++ (without Qt), you would likely use `std::string`. The logic is similar, but the syntax differs.

| Feature | Qt (`QString`) | Standard C++ (`std::string`) |
| :--- | :--- | :--- |
| **Method** | `.fill(char, size)` | `.assign(size, char)` |
| **Alternative** | `QString(size, char)` | `std::string(size, char)` |

-----

### Full Code Example

Here is a small, runnable example showing how this might be used to create an indented "tree" view in a console application.

```cpp
#include <QCoreApplication>
#include <QDebug>
#include <QString>

int main() {
    int level = 3;

    // 1. Initial state
    QString line = "-";
    qDebug() << "Before fill:" << line; // Output: "-"

    // 2. Fill state (creates 15 'i' characters)
    line.fill('i', level * 5);
    qDebug() << "After fill: " << line; // Output: "iiiiiiiiiiiiiii"

    // 3. Common use case: Creating visual indentation
    // Often, developers use spaces or dashes for hierarchy:
    QString indent;
    indent.fill(' ', level * 4);
    qDebug() << indent << "Level 3 Content";

    return 0;
}
```

### Documentation & Resources

  * [Official Qt Documentation: QString::fill()](https://www.google.com/search?q=https://doc.qt.io/qt-6/qstring.html%23fill)
  * [QString Class Reference](https://doc.qt.io/qt-6/qstring.html) - A "must-read" for any Qt developer.
  * [C++ std::string::assign](https://en.cppreference.com/w/cpp/string/basic_string/assign) - The standard C++ equivalent.

-----

### Recommendations for Further Learning

To deepen your understanding of how Qt handles strings and memory, you might want to ask:

1.  "What is the difference between `fill()` and `resize()` in QString?"
2.  "How does Qt's 'Implicit Sharing' (Copy-on-Write) make passing QStrings efficient?"
3.  "How can I append text to a string instead of overwriting it like `fill()` does?"


*/


/*
 * NOTES


Recursion can feel like a "brain-bender" at first, but it is the most natural way to navigate hierarchical structures like trees (or folders on your computer).

In this code, you are performing a **Depth-First Search (DFS)**. This means the code dives as deep as possible into one branch before coming back up to start the next one.

### The Visual Flow of Recursion

Think of recursion not as a loop, but as a **stack of tasks**. Each time `printTree` calls itself, it "pauses" the current level and starts a new, deeper level.

-----

### Step-by-Step Breakdown

#### 1\. The Indentation Logic

```cpp
QString line = "-";
line.fill('-', level * 5);
```

As we discussed before, `fill` replaces everything. Here, `level` acts as a multiplier.

  * At Level 0: 0 dashes (empty string).
  * At Level 1: 5 dashes (`-----`).
  * At Level 2: 10 dashes (`----------`).
    This creates the visual "nesting" in your console output so you can see which child belongs to which parent.

#### 2\. The Loop and the "Cast"

```cpp
foreach(QObject *obj, tree->children()) {
    Test *object = qobject_cast<Test *>(obj);
```

Qt's `children()` function returns a list of generic `QObject*` pointers. Since your function specifically needs a `Test*` type, you use `qobject_cast`.

  * **Safe Check:** If `obj` is not actually a `Test` class (or a subclass), `object` will become `nullptr`. (In a production environment, you should check `if(object)` before using it\!).

#### 3\. The Recursive Call (The "Dive")

```cpp
printTree(object, level + 1);
```

This is the heart of the function.

  * The function says: "I have printed this child. Now, I will **immediately** call `printTree` again to see if *this child* has children of its own."
  * Notice we pass `level + 1`. This ensures the next generation of children is indented further to the right.

-----

### A Concrete Walkthrough

Imagine a tree like this:

  * **Root**
      * **Child A**
          * **Grandchild A1**
      * **Child B**

<!-- end list -->

1.  **Call `printTree(Root, 0)`**:
      * It loops and finds **Child A**.
      * It prints `Child A` with 0 dashes.
      * It calls `printTree(Child A, 1)`. **(The function "Root" waits here)**.
2.  **Inside `printTree(Child A, 1)`**:
      * It loops and finds **Grandchild A1**.
      * It prints `----- Grandchild A1`.
      * It calls `printTree(Grandchild A1, 2)`.
3.  **Inside `printTree(Grandchild A1, 2)`**:
      * It checks `children().length() == 0`.
      * It prints "No other children exist" and **returns**.
4.  **Back in `printTree(Child A, 1)`**:
      * The loop for Child A is finished. It returns.
5.  **Back in `printTree(Root, 0)`**:
      * The loop moves to the next item: **Child B**.
      * It prints `Child B`... and so on.

-----

### Subtle Differences & Version Notes

  * **`foreach` vs. Range-based for:** The `foreach` keyword is a Qt-specific macro. While it still works in modern Qt (Qt 5/6), it is officially **deprecated**. In modern C++ (C++11 and later), you should use the standard range-based loop:
    ```cpp
    for(QObject *obj : tree->children()) { ... }
    ```
  * **`qInfo()`:** This is part of Qt's logging framework (`<QDebug>`). It's cleaner than `std::cout` because it automatically handles Qt types like `QString` without needing to call `.toStdString()`.

### Documentation & Resources

  * [Qt Documentation: Object Trees & Ownership](https://doc.qt.io/qt-6/objecttrees.html) - Crucial for understanding how `children()` works.
  * [Recursive Functions (MDN Guide)](https://developer.mozilla.org/en-US/docs/Glossary/Recursion) - General logic of recursion.
  * [qobject\_cast Explanation](https://www.google.com/search?q=https://doc.qt.io/qt-6/qobject.html%23qobject_cast)

-----

### Recommendations for Further Learning

1.  "Why is `qobject_cast` safer than a standard C-style cast or `static_cast`?"
2.  "What happens to the memory if I delete a parent 'Test' object in Qt?"
3.  "How would I rewrite the `foreach` loop using C++17 'Structured Bindings'?"

Do you want to see how to add a null-pointer check to make this code "crash-proof"?

*/