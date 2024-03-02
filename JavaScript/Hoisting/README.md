# Hoisting in JavaScript

## Case 1 :
<br>

![Screenshot (203)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/cd52c9b7-04af-4471-9476-cf9097eb1d28)

Everything works as expected because the values of variables are lready declared and function is created. <br>

## Case 2 :
<br>

![Screenshot (202)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/42f156f2-b31f-4afb-9533-541b266da81a)

This gives error in many other programming languages as we are using variables and functions even before they are defined. <br>

<strong>How this works in JavaScript?  🤔</strong>

Well , we can get this solution by revising the execution context. In the first phase , memory creation occurs i.e memory is allocated for varibales and functions. Initially , variables are initialized as 
<strong>undefined</strong> and entire code of function is contained inside memory component.

![WhatsApp Image 2024-03-02 at 19 14 36_52c90591](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/05af07f1-b406-490d-8cd9-ed5db1686210)

After completion of phase 1 i.e memory creation phase , phase 2 starts where code execution occurs

##### First line of code

```

thala()

```

In memory , currently the entire function of thala is stored. The code is executed and "Thala for a reason" is printed on console. 

##### Second line of code

```

console.log(jerseyNumber);

```

Currently , in memory , the value of variable jerseyNumber is <strong>undefined</strong>. So, undefined is printed at this line.

##### Third line of code

```

var jerseyNumber = 7;

```

Now , the value of jerseyNumber in memory , which is currently undefined will be replaced by 7.

##### Fourth and remaining lines

```

function thala()
{
  console.log("Thala for a reason")
}

```

The function is already present in memory as memory allocation happens in first phase only. So, with this , the entire execution will be done and context execution will be deleted.
