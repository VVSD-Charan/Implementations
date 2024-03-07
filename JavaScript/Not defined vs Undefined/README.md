# Undefined in JavaScript

<strong>undefined</strong> is a special value provided by javaScript for variables that are not initialized with a value. During first phase (memory creation) of execution context , memory is allocated for all variables and functions . For functions , entire code of functions will be stored and in case of variables , they are initially initialized with <strong>undefined</strong>. Undefined acts like a placeholder for variables. <br>

![Screenshot (214)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/7bc1be01-7703-408e-81db-ad76b57b7c47)

<li>In the first phase (memory creation phase) , the value of a will be initialised by <strong>undefined</strong>.</li>
<li>So, during second phase (code execution phase) , we get undefined when first line of code is executed.</li>
<li>During execution of second line , the value of a in memory will be changed to 100.</li>
<li>During execution of third line , since value of a in memory is 100 , we get output as 100 in console.</li>
