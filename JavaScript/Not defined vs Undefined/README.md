# Undefined in JavaScript

<strong>undefined</strong> is a special value provided by javaScript for variables that are not initialized with a value. During first phase (memory creation) of execution context , memory is allocated for all variables and functions . For functions , entire code of functions will be stored and in case of variables , they are initially initialized with <strong>undefined</strong>. Undefined acts like a placeholder for variables. <br>

<strong>undefined</strong> is not same as null and undefined takes up some space as well. It acts like a placeholder for variable for time being, until the variable is assigned some value during code execution phase (phase 2).<br>

![Screenshot (214)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/7bc1be01-7703-408e-81db-ad76b57b7c47)

<li>In the first phase (memory creation phase) , the value of a will be initialised by <strong>undefined</strong>.</li>
<li>So, during second phase (code execution phase) , we get value of variable a as undefined when first line of code is executed.</li>
<li>During execution of second line , the value of variable a in the memory will be changed to 100.</li>
<li>During execution of third line , since value of variable a in memory is 100 , we get output as 100 in console.</li>
<br>

If a variable is declared but not given any value throughout the program , the value of variable will remain undefined throughout the code.<br>

![Screenshot (215)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/5ee5d0e8-979c-4e3e-9dab-52b71704942c)

<br>

# What do we mean when we say that JavaScript is a loosely typed language

In JavaScript, if a variable is initialized with one data type , it can be assigned with another data type as well in future i.e variables can hold values of any data type and can be reassigned to different data types without explicit type declarations. This flexibility provided by javaScript for usage of variables is the reason behind javaScript being considered as loosely typed language.
