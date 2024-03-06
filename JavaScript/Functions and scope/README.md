# Function Invocation and Varibale environment in JavaScript

![Screenshot (210)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/8d25da2c-98f4-46c2-8922-f9881851c434)

## Let us understand what actually happens behind ...

First of all , a global execution context will be created and memory creation phase (phase 1) occurs. The global execution context will be pushed into call stack (execution stack).

![WhatsApp Image 2024-03-06 at 22 19 12_e347f051](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/c1c9b231-e391-402c-a08f-3f4a3bfe5d50)

After memory creation phase is completed and global execution context is pushed into execution stack , the execution phase (phase 2) begins.

#### Execution of line 1

```

var x = 1;

```

Initially , during memory creation , x will be initialised as undefined. Now , after execution of this line , x will be set to 1. <br>
Now , the execution context looks like : <br>

![WhatsApp Image 2024-03-06 at 22 25 37_e7f8db6c](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/d713a9b3-5c00-4392-8d36-9ab3af708d25)

<br>

#### Execution of line 2

In line 2 , a function is invoked. When function is invoked , an entirely new execution context will be created which will be have scope of that function only. Memory creation occurs and then this execution context will be pushed into execution stack / call stack. <br>

![WhatsApp Image 2024-03-06 at 22 31 58_ae7f29da](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/c0261e15-68cf-40dc-a270-5972d6f6cef9)

Now, code execution phase starts and value of x in a's execution context will be initialised to 10. Then the console.log(x) will be executed and 10 will be printed. With this , the execution context of a will de deleted or popped out from call stack.

#### Execution of line 3

Like execution of line 2 , execution of line 3 also occurs , where a new execution context will be created for b , followed by memory creation phase . The execution context of b will be pushed into stack and code execution phase begins . Once, x's value of this execution context is changed to 1000 and console.log() statement is executed , the execution context of b will also be completed and will be popped out from call stack.

#### Execution of line 4
The value of x in global execution context is 1. So ,  1 will be printed and with this , entire execution is done and global execution context will be deleted from call stack / execution stack.
