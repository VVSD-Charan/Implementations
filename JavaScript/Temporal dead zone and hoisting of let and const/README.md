# Hoisting of var vs Hoisting of let

For the same code with just change in keywords var and let will change the entire concepts of how hoisting occurs. Let us look at an example.

##### Hoisting of var variable

![Screenshot (223)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/0b44d264-98c7-4582-ad2c-0fdb78810aab)

##### Hoisting of let variable

![Screenshot (224)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/4eadbb48-03a2-469f-a74e-6370659a6bca)

Using var variable before initialization will give us a special placeholder provided by javaScript (undefined). But , using let variable before initialization will give us an error. Let us check out what actually happens in the case of let and how it is hoisted.

# Memory allocation of var vs let and const

During the initialization phase, all variables declared with var, let, and const are assigned a value of undefined. However, since let and const variables are stored in a separate memory space, attempting to access them before their declaration results in a ReferenceError. This is because they are not available in the global space like var variables, hence they cannot be accessed until their declaration statement is executed.

![Screenshot (225)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/5e326a39-b864-4ee9-b2a8-e9c37037ad0e)

Here , when we place debugger before line 1 , then we can observe that memory allocation of var variable b happens in global space while memory allocation of let variable a happens in different space.

# Temporal dead zone in javaScript

The "temporal dead zone" refers to the period in the code where a variable declared with the let keyword exists but isn't yet initialized with a value. During this time, if we try to access the variable, we'll get a reference error because it's not yet ready for use.<br><br>
In simpler terms, if we've declared a variable using let, but haven't assigned a value to it yet. During this "dead zone," attempting to use the variable will result in an error because it's like trying to use something before it's fully set up and ready to go.

### Example of temporal dead zone

![Screenshot (226)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/3371a87c-0be3-4b00-9bca-a09d1ea97bb2)

In the above code , the let variable is initialized with a value in second line. So, anywhere before second line of code is considered as temporal dead zone of variable thala. Since , let variable is accessed after it is initialized with a value , we get desired result.

![Screenshot (227)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/10fdf0a9-79d0-49ed-9b61-8b76d053f7e7)

In this case , too the let variable is initialized with a value in second line of code. So, anywhere before second line is temporal dead zone and since we are accessing let variable from first line ( < second line of code) , we get a reference error as we are trying to access let variable from temporal dead zone.
