# C++ 类 & 对象

C++ 在 C 语言的基础上增加了面向对象编程，C++ 支持面向对象程序设计。类是 C++ 的核心特性，通常被称为用户定义的类型。

类用于指定对象的形式，它包含了数据表示法和用于处理数据的方法。类中的数据和方法称为类的成员。函数在一个类被称为类的成员。

## C++ 类定义

定义一个类，本质上是定义一个数据类型的蓝图。

类定义是以关键字 **class** 开头，后跟类的名称。类的主体是包含在一对花括号中。类定义后必须跟着一个分号或一个声明列表。

```c++
class Box
{
   public:
      double length;   // Length of a box
      double breadth;  // Breadth of a box
      double height;   // Height of a box
};
```

关键字 **public** 确定了类成员的访问属性。在类对象作用域内，公共成员在类的外部是可访问的。您也可以指定类的成员为 **private** 或 **protected**，私有的成员和受保护的成员不能使用直接成员访问运算符 (.) 来直接访问。

## 定义 C++ 对象

类提供了对象的蓝图，所以基本上，对象是根据类来创建的。声明类的对象，就像声明基本类型的变量一样。

## 访问数据成员

类的对象的公共数据成员可以使用直接成员访问运算符 (.) 来访问。

# 类 & 对象详解

| 概念                                                         | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| 类成员函数 | 类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。 |
| 类访问修饰符 | 类成员可以被定义为 public、private 或 protected。默认情况下是定义为 private。 |
| 构造函数 & 析构函数 | 类的构造函数是一种特殊的函数，在创建一个新的对象时调用。类的析构函数也是一种特殊的函数，在删除所创建的对象时调用。 |
| C++ 拷贝构造函数 | 拷贝构造函数，是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。 |
| C++ 友元函数 | **友元函数**可以访问类的 private 和 protected 成员。         |
| C++ 内联函数 | 通过内联函数，编译器试图在调用函数的地方扩展函数体中的代码。 |
| C++ 中的 this 指针 | 每个对象都有一个特殊的指针 **this**，它指向对象本身。        |
| C++ 中指向类的指针 | 指向类的指针方式如同指向结构的指针。实际上，类可以看成是一个带有函数的结构。 |
| C++ 类的静态成员 | 类的数据成员和函数成员都可以被声明为静态的。                 |

## C++ 类成员函数

类的成员函数是指那些把定义和原型写在类定义内部的函数，就像类定义中的其他变量一样。类成员函数是类的一个成员，它可以操作类的任意对象，可以访问对象中的所有成员。

成员函数可以定义在类定义内部，或者单独使用**范围解析运算符 ::** 来定义。在类定义中定义的成员函数把函数声明为**内联**的，即便没有使用 inline 标识符。

```c++
class Box
{
   public:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
   
      double getVolume(void)
      {
         return length * breadth * height;
      }
};

// Or
double Box::getVolume(void)
{
    return length * breadth * height;
}
```

## C++ 类访问修饰符

数据隐藏是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。类成员的访问限制是通过在类主体内部对各个区域标记 **public、private、protected** 来指定的。关键字 public、private、protected 称为访问说明符。

一个类可以有多个 public、protected 或 private 标记区域。每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。**成员和类的默认访问修饰符是 private**。

实际操作中，我们一般会在私有区域定义数据，在公有区域定义相关的函数，以便在类的外部也可以调用这些函数。

```c++
class Base {
    public:
    // public members go here
    protected:
    // protected members go here
    private:
    // private members go here
};
```

### 公有（public）成员

**公有**成员在程序中类的外部是可访问的。

### 私有（private）成员

**私有**成员变量或函数在类的外部是不可访问的，甚至是不可查看的。只有类和友元函数可以访问私有成员。**默认情况下，类的所有成员都是私有的。**

### 保护（protected）成员

**保护**成员变量或函数与私有成员十分相似，但有一点不同，保护成员在派生类（即子类）中是可访问的。

## C++ 类构造函数 & 析构函数

类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

构造函数的名称与类的名称是完全相同的，并且不会返回任何类型，也不会返回 void。构造函数可用于为某些成员变量设置初始值。

### 带参数的构造函数

默认的构造函数没有任何参数，但如果需要，构造函数也可以带有参数。这样在创建对象时就会给对象赋初始值

### 使用初始化列表来初始化字段

使用初始化列表来初始化字段

```c++
Box::Box(double length, double breadth, double height)
	: mLength(length)
	, mBreadth(breadth)
	, mHeight(height)
{
    cout << "Object is being created, length = " << len << endl;
}
```

### 类的析构函数

类的**析构函数**是类的一种特殊的成员函数，它会在每次删除所创建的对象时执行。

析构函数的名称与类的名称是完全相同的，只是在前面加了个波浪号（~）作为前缀，它不会返回任何值，也不能带有任何参数。析构函数有助于在跳出程序（比如关闭文件、释放内存等）前释放资源。

```c++
Box::~Box()
{
    cout << "Object is being deleted" << endl;
}
```

## C++ 拷贝构造函数

类对象与普通对象不同，类对象内部结构一般较为复杂，存在各种成员变量。

**拷贝构造函数**是一种特殊的构造函数，它在创建对象时，是使用同一类中之前创建的对象来初始化新创建的对象。拷贝构造函数通常用于：

- 通过使用另一个同类型的对象来初始化新创建的对象。
- 复制对象把它作为参数传递给函数。
- 复制对象，并从函数返回这个对象。

**如果在类中没有定义拷贝构造函数，编译器会自行定义一个。如果类带有指针变量，并有动态内存分配，则它必须有一个拷贝构造函数。**

```c++
classname (const classname &obj) {
   // 构造函数的主体
}
```

```c++
#include <iostream>

using namespace std;
class Line
{
public:
    int getLength(void);
    Line(int len);             // 简单的构造函数
    Line(const Line& obj);     // 拷贝构造函数
    ~Line();                   // 析构函数

private:
    int* ptr;
};

Line::Line(int len)
{
    cout << "Normal constructor allocating ptr" << endl;
    // 为指针分配内存
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj)
{
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr; // copy the value
}

Line::~Line(void)
{
    cout << "Freeing memory!" << endl;
    delete ptr;
}

int Line::getLength(void)
{
    return *ptr;
}

int main()
{
    std::cout << "Hello World!\n";
	Line line(10);
	cout << line.getLength() << endl;

	// 此处不是赋值，而是调用 "拷贝构造函数"
	Line another = line;
	cout << another.getLength() << endl;
    return 0;
}
```

## C++ 友元函数

类的友元函数是定义在类外部，但有权访问类的所有私有（private）成员和保护（protected）成员。尽管友元函数的原型有在类的定义中出现过，但是友元函数并不是成员函数。

友元可以是一个函数，该函数被称为友元函数；友元也可以是一个类，该类被称为友元类，在这种情况下，整个类及其所有成员都是友元。

如果要声明函数为一个类的友元，需要在类定义中该函数原型前使用关键字 **friend**。

```c++
#include <iostream>
 
using namespace std;
 
class Box
{
   double width;
public:
   friend void printWidth( Box box );
   void setWidth( double wid );
};

// 成员函数定义
void Box::setWidth( double wid )
{
    width = wid;
}

// 请注意：printWidth() 不是任何类的成员函数
void printWidth( Box box )
{
   /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
   cout << "Width of box : " << box.width <<endl;
}
 
// 程序的主函数
int main( )
{
   Box box;
 
   // 使用成员函数设置宽度
   box.setWidth(10.0);
   
   // 使用友元函数输出宽度
   printWidth( box );
 
   return 0;
}
```

## C++ 内联函数

调用函数比求解等价表达式要慢得多。在大多数的机器上，调用函数都要做很多工作：调用前要先保存寄存器，并在返回时恢复，复制实参，程序还必须转向一个新位置执行。

在C++中可以使用**内联函数，**其目的是为了提高函数的执行效率**，**通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。

对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。

如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 **inline**，在调用函数之前需要对函数进行定义。**如果已定义的函数多于一行，编译器会忽略 inline 限定符**。

**在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符**。

有了内联函数，就能像调用一个函数那样方便地**高性能重复使用一段代码**，而不需要付出执行函数调用的额外开销。很显然，**使用内联函数会是最终可执行程序的体积增加**。

内联函数中的代码应该只是很简单、执行很快的几条语句。如果一个函数较为复杂，它执行的时间可能上万倍于函数调用的额外开销，那么将其作为内联函数处理的结果是付出让代码体积增加不少的代价，却只使速度提高了万分之一，这显然是不划算的，而且有些函数即使声明为内联的也不一定会被编译器内联。

有时函数看上去很简单，例如只有一个包含一两条语句的循环，但该循环的执行次数可能很多，要消耗大量时间，那么这种情况也不适合将其实现为内联函数。

另外需要注意的是，调用内联函数的语句前必须已经出现内联函数的定义（即整个函数体），而不能只出现内联函数的声明。

## C++ this 指针

在 C++ 中，每一个对象都能通过 **this** 指针来访问自己的地址。**this 指针是所有成员函数的隐含参数**。因此，在成员函数内部，它可以用来指向调用对象。

友元函数没有 **this** 指针，因为友元不是类的成员。只有成员函数才有 **this** 指针。

```c++
#include <iostream>

using namespace std;

class Box
{
   public:
      // 构造函数定义
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
      int compare(Box box)
      {
         return this->Volume() > box.Volume();
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2

   if(Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" <<endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   return 0;
}
```

## C++ 指向类的指针

一个指向 C++ 类的指针与指向结构的指针类似，访问指向类的指针的成员，需要使用成员访问运算符 **->**，就像访问指向结构的指针一样。与所有的指针一样，您必须在使用指针之前，对指针进行初始化。

## C++ 类的静态成员

我们可以使用 **static** 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。

静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，所有的静态数据都会被初始化为零。我们不能把静态成员放置在类的定义中，但是可以在类的外部通过使用范围解析运算符 **::** 来重新声明静态变量从而对它进行初始化。

### 静态函数成员

如果把函数成员声明为静态的，就可以把函数与类的任何特定对象独立开来。静态成员函数即使在类对象不存在的情况下也能被调用，**静态函数**只要使用类名加范围解析运算符 **::** 就可以访问。

静态成员函数只能访问静态数据成员，不能访问其他静态成员函数和类外部的其他函数。

静态成员函数有一个类范围，他们不能访问类的 this 指针。您可以使用静态成员函数来判断类的某些对象是否已被创建。

```c++
#include <iostream>
using namespace std;

class Box
{
    public:
    Box()
    {
        objectCount++;
    }
    static int getCount()
    {
        return objectCount;
    }
    private:
	    static int objectCount;
};

// 初始化类 Box 的静态成员
int Box::objectCount = 0;

int main(void)
{
    // 在创建对象之前输出对象的总数
    cout << "Inital Stage Count: " << Box::getCount() << endl;

    Box Box1();    // 声明 box1
    Box Box2();    // 声明 box2

    // 在创建对象之后输出对象的总数
    cout << "Final Stage Count: " << Box::getCount() << endl;
    return 0;
}
```

# C++ 继承

面向对象程序设计中最重要的一个概念是继承。继承允许我们依据另一个类来定义一个类，这使得创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行时间的效果。

当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为**基类**，新建的类称为**派生类**。

## 基类 & 派生类

一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。定义一个派生类，我们使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名，形式如下：

```
class derived-class: access-specifier base-class
```

其中，访问修饰符 access-specifier 是 **public、protected** 或 **private** 其中的一个，base-class 是之前定义过的某个类的名称。如果未使用访问修饰符 access-specifier，则默认为 private。

```c++
#include <iostream>
using namespace std;

// 基类
class Shape 
{
    public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
    protected:
    int width;
    int height;
};

// 派生类
class Rectangle: public Shape
{
    public:
    int getArea()
    { 
        return (width * height); 
    }
};

int main(void)
{
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);

    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    return 0;
} 
```

## 访问控制和继承

派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 private。

| 访问     | public | protected | private |
| :------- | :----- | :-------- | :------ |
| 同一个类 | yes    | yes       | yes     |
| 派生类   | yes    | yes       | no      |
| 外部的类 | yes    | no        | no      |

一个派生类继承了所有的基类方法，但下列情况除外：

- 基类的构造函数、析构函数和拷贝构造函数。
- 基类的重载运算符。
- 基类的友元函数。

## 继承类型

当一个类派生自基类，该基类可以被继承为 **public、protected** 或 **private** 几种类型。继承类型是通过上面讲解的访问修饰符 access-specifier 来指定的。

我们几乎不使用 **protected** 或 **private** 继承，通常使用 **public** 继承。当使用不同类型的继承时，遵循以下几个规则：

- **公有继承（public）：**当一个类派生自**公有**基类时，基类的**公有**成员也是派生类的**公有**成员，基类的**保护**成员也是派生类的**保护**成员，基类的**私有**成员不能直接被派生类访问，但是可以通过调用基类的**公有**和**保护**成员来访问。
- **保护继承（protected）：** 当一个类派生自**保护**基类时，基类的**公有**和**保护**成员将成为派生类的**保护**成员。
- **私有继承（private）：**当一个类派生自**私有**基类时，基类的**公有**和**保护**成员将成为派生类的**私有**成员。

## 多继承

多继承即一个子类可以有多个父类，它继承了多个父类的特性。

C++ 类可以从多个类继承成员，语法如下：

```c++
class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
{
<派生类类体>
};
```

其中，访问修饰符 access 是 **public、protected** 或 **private** 其中的一个，用来修饰每个基类，各个基类之间用逗号分隔。

```c++
#include <iostream>
using namespace std;

// 基类 Shape
class Shape 
{
public:
    void setWidth(int w)
    {
        width = w;
    }
    void setHeight(int h)
    {
        height = h;
    }
protected:
    int width;
    int height;
};

// 基类 PaintCost
class PaintCost 
{
public:
    int getCost(int area)
    {
        return area * 70;
    }
};

// 派生类
class Rectangle
    : public Shape
    , public PaintCost
{
public:
    int getArea()
    { 
        return (width * height); 
    }
};

int main(void)
{
    Rectangle Rect;
    int area;

    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;
    // 输出总花费
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;
    return 0;
}
```

# C++ 重载运算符和重载函数

C++ 允许在同一作用域中的某个**函数**和**运算符**指定多个定义，分别称为**函数重载**和**运算符重载**。

重载声明是指一个与之前已经在该作用域内声明过的函数或方法具有相同名称的声明，但是它们的参数列表和定义（实现）不相同。

当您调用一个**重载函数**或**重载运算符**时，编译器通过把您所使用的参数类型与定义中的参数类型进行比较，决定选用最合适的定义。选择最合适的重载函数或重载运算符的过程，称为**重载决策**。

## 可重载运算符/不可重载运算符

下面是可重载的运算符列表：

| +    | -    | *    | /      | %      | ^         |
| ---- | ---- | ---- | ------ | ------ | --------- |
| &    | \|   | ~    | !      | ,      | =         |
| <    | >    | <=   | >=     | ++     | --        |
| <<   | >>   | ==   | !=     | &&     | \|\|      |
| +=   | -=   | /=   | %=     | ^=     | &=        |
| \|=  | *=   | <<=  | >>=    | []     | ()        |
| ->   | ->*  | new  | new [] | delete | delete [] |

下面是不可重载的运算符列表：

| ::   | .*   | .    | ?:   |
| ---- | ---- | ---- | ---- |

## C++ 中的函数重载

在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数（指参数的个数、类型或者顺序）必须不同。您不能仅通过返回类型的不同来重载函数。

```c++
#include <iostream>
using namespace std;

class printData 
{
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }

      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }

      void print(string c) {
        cout << "Printing character: " << c << endl;
      }
};

int main(void)
{
   printData pd;
 
   // Call print to print integer
   pd.print(5);
   // Call print to print float
   pd.print(500.263);
   // Call print to print character
   pd.print("Hello C++");
 
   return 0;
}
```

## C++ 中的运算符重载

您可以重定义或重载大部分 C++ 内置的运算符。这样，您就能使用自定义类型的运算符。

重载的运算符是带有特殊名称的函数，函数名是由关键字 operator 和其后要重载的运算符符号构成的。与其他函数一样，重载运算符有一个返回类型和一个参数列表。

```c++
Box operator+(const Box&);
Box operator+(const Box&, const Box&);
```

### 重载输入运算符>>

下面我们以全局函数的形式重载`>>`，使它能够读入两个 double 类型的数据，并分别赋值给复数的实部和虚部：

```c++
istream & operator>>(istream &in, complex &A){
    in >> A.m_real >> A.m_imag;
    return in;
}
```

### 重载输出运算符<<

同样地，我们也可以模仿上面的形式对输出运算符`>>`进行重载，让它能够输出复数，请看下面的代码：

```c++
ostream & operator<<(ostream &out, complex &A){
    out << A.m_real <<" + "<< A.m_imag <<" i ";
    return out;
}
```

### 重载运算符 ++ 和 --

递增运算符（ ++ ）和递减运算符（ -- ）是 C++ 语言中两个重要的一元运算符

```c++
class Time
{
    private:
    int hours;             // 0 到 23
    int minutes;           // 0 到 59
    public:
    Time(){
        hours = 0;
        minutes = 0;
    }
    // 显示时间的方法
    void displayTime()
    {
        cout << "H: " << hours << " M:" << minutes <<endl;
    }
    // 重载前缀递增运算符（ ++ ）
    Time operator++ ()
    {
        ++minutes;          // 对象加 1
        if(minutes >= 60)  
        {
            ++hours;
            minutes -= 60;
        }
        return Time(hours, minutes);
    }
    // 重载后缀递增运算符（ ++ ）
    Time operator++( int )         
    {
        // 保存原始值
        Time T(hours, minutes);
        // 对象加 1
        ++minutes;                    
        if(minutes >= 60)
        {
            ++hours;
            minutes -= 60;
        }
        // 返回旧的原始值
        return T; 
    }
}；
```

### 重载赋值运算符 =

就像其他运算符一样，您可以重载赋值运算符（ = ），用于创建一个对象，比如拷贝构造函数。

```c++
class Distance
{
private:
    int feet;             // 0 到无穷
    int inches;           // 0 到 12
public:
    // 所需的构造函数
    Distance(){
        feet = 0;
        inches = 0;
    }
    Distance(int f, int i){
        feet = f;
        inches = i;
    }
    void operator=(const Distance &D )
    { 
        feet = D.feet;
        inches = D.inches;
    }
    // 显示距离的方法
    void displayDistance()
    {
        cout << "F: " << feet <<  " I:" <<  inches << endl;
    }
};

int main()
{
   Distance D1(11, 10), D2(5, 11);
   D1 = D2;    // 调用赋值运算符
   return 0;
}
```

### 重载函数调用运算符 ()

```c++
class Distance
{
   private:
      int feet;             // 0 到无穷
      int inches;           // 0 到 12
   public:
      // 所需的构造函数
      Distance(){
         feet = 0;
         inches = 0;
      }
      // 重载函数调用运算符
      Distance operator()(int a, int b, int c)
      {
         Distance D;
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;
         return D;
      }      
};

int main()
{
   Distance D1(11, 10), D2;
   D2 = D1(10, 10, 10); // 调用 operator()
   cout << "Second Distance :"; 
   D2.displayDistance();

   return 0;
}
```

### 重载下标运算符 [] 

下标操作符 [] 通常用于访问数组元素。重载该运算符用于增强操作 C++ 数组的功能。

```c++
const int SIZE = 10;

class safearay
{
   private:
      int arr[SIZE];
   public:
      safearay() 
      {
         register int i;
         for(i = 0; i < SIZE; i++)
         {
           arr[i] = i;
         }
      }
      int& operator[](int i)
      {
          if( i > SIZE )
          {
              return arr[0];
          }
          return arr[i];
      }
};

int main()
{
   safearay A;

   cout << "A[2] 的值为 : " << A[2] <<endl;
   cout << "A[5] 的值为 : " << A[5]<<endl;
   cout << "A[12] 的值为 : " << A[12]<<endl;
   return 0;
}
```

## 重载类成员访问运算符 -> 

类成员访问运算符（ -> ）可以被重载，但它较为麻烦。它被定义用于为一个类赋予"指针"行为。运算符 -> 必须是一个成员函数。如果使用了 -> 运算符，返回类型必须是指针或者是类的对象。

运算符 -> 通常与指针引用运算符 * 结合使用，用于实现"智能指针"的功能。这些指针是行为与正常指针相似的对象，唯一不同的是，当您通过指针访问对象时，它们会执行其他的任务。比如，当指针销毁时，或者当指针指向另一个对象时，会自动删除对象。

```c++
class X{
public:
    int Value;
}
class Ptr{
	// Ptr->Value; Ptr上的一元运算符后缀->返回X的指针类型，所以(Ptr->)可以直接访问X类型的成员
    X * operator->();
};
```

# C++ 多态

**多态**按字面的意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。

C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。

## 虚函数

**虚函数** 是在基类中使用关键字 **virtual** 声明的函数。在派生类中重新定义基类中定义的虚函数时，会告诉编译器不要静态链接到该函数。

我们想要的是在程序中任意点可以根据所调用的对象类型来选择调用的函数，这种操作被称为**动态链接**，或**后期绑定**。

```c++
class Rectangle: public Shape{
    public:
    Rectangle( int a=0, int b=0):Shape(a, b) { }
    int area ()
    { 
        cout << "Rectangle class area :" <<endl;
        return (width * height); 
    }
};

class Triangle: public Shape{
    public:
    Triangle( int a=0, int b=0):Shape(a, b) { }
    int area ()
    { 
        cout << "Triangle class area :" <<endl;
        return (width * height / 2); 
    }
};

class Shape {
    protected:
    int width, height;
    public:
    Shape( int a=0, int b=0)
    {
        width = a;
        height = b;
    }
    virtual int area()
    {
        cout << "Parent class area :" <<endl;
        return 0;
    }
};
```

## 纯虚函数

您可能想要在基类中定义虚函数，以便在派生类中重新定义该函数更好地适用于对象，但是您在基类中又不能对虚函数给出有意义的实现，这个时候就会用到纯虚函数。

= 0 告诉编译器，函数没有主体，上面的虚函数是**纯虚函数**。

```c++
class Shape {
   protected:
      int width, height;
   public:
      Shape( int a=0, int b=0)
      {
         width = a;
         height = b;
      }
      // pure virtual function
      virtual int area() = 0;
};
```

