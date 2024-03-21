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

In this case too , the let variable is initialized with a value in second line of code. So, anywhere before second line is temporal dead zone and since we are accessing let variable from first line ( < second line of code) , we get a reference error as we are trying to access let variable from temporal dead zone.

# Cases when we encounter a reference error

1) We get a reference error when we try to use a vriable that is no where present in the entire code. In this case , we get a reference error stating that the variable was not defined.

![Screenshot (228)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/92943a56-5c89-4507-8fe7-c87560a8a387)

2) When we try to access a let variable in temporal dead zone. In this case , the error states that the let variable cannot be accessed before it is initialized with a value.

![Screenshot (229)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/380f57d2-762f-4cd9-a173-18742eedfad9)

Although in both the cases , we get a reference error , the exact reason mentioned will be different. 

# Re-declaration of let variables

Re-declaration of let variables will give us a syntax error. JavaScript doesn't even begin second phase (code execution phase) , if it is found out that a let variable has been re-declared.

![Screenshot (230)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/d258d469-f81e-4655-a2ec-a2e1f6cf7f47)

The console.log() statement is not even executed by javaScript as it finds out that there is a re-declaration of let variable in memory creation phase only and gives syntax error before even code execution phase starts. <strong>We cannot use same variable name multiple times in a scope if atleast one of them is initialized as a let variable.</strong>

![Screenshot (231)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/e76288e4-c6cb-4332-bf95-e083000b0ff5)

Even though variables are of type let and var with same variable name , we get an error because both of them belong to same scope.

# Re-declaration of var variables

Unlike let variables , var variables can be re-declared in same scope. It will not give us any syntax error and even though a variable names are same , if all of them are of var type then we donot get any error. We get an error only when atleast one of them in the same scope is let or const.

![Screenshot (232)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/9966418e-b92a-4101-9249-34fded9e76b0)

# Similarities between let and const

Like let variables , even const variables are not globally scoped. Memory allocation of let and const variables doesnot happen in global space, instead their memory allocation occurs in different scope.

![Screenshot (233)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/f08ce7fa-5115-4879-b8c9-bbb38478ef0c)

Even const variables have concept of temporal dead zone like let variables and works similarly as let in case of ereference errors.

# Differences between let and const

let variables can be declared first and can be initialized with a value later on. This will not throw any error.

![Screenshot (234)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/18b0fa66-9884-438c-8260-63b5ba441e7d)

But , in case of const variables , it is not possible. Const variables must be initialized with a value during declaration only.

![Screenshot (235)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/de77e02d-e640-4b28-8598-39a81e5eafd8)

![Screenshot (236)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/fb74b69d-607c-4a99-b121-b5aa61276403)

This is the major difference between let and const as let variables can de initialized with a value later after initialization but it is not possible in the case of const variables.

# Type error in JavaScript

Const variables must be initialized with a value during declaration , otherwise it would lead to syntax error. If we try to change the value of const variable , then we get a type error

![Screenshot (237)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/ae9945e2-d98c-4999-9ee2-47e5efd105d1)

