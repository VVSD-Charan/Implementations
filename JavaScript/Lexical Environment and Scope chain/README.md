# Lexical Environment 

When an execution context is created, a lexical environment is also established, which contains a reference pointer to its parent's lexical environment. The scope chain operates based on this lexical environment. If a variable is not found within the local memory or memory of the current execution context, JavaScript traverses the scope chain using the pointer to access the parent's lexical environment and search for the variable there. This process continues recursively until the variable is found in some lexical environment or until the global execution context is reached. The global execution context, being the top-level context, does not have a parent, and thus its reference pointer is NULL. <br><br>
<strong>Lexical environment is combination of current memory component and a pointer which references parent's lexical environment.</strong><br>

![Screenshot (220)](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/718eb4cc-c841-4af6-a500-f4cb965abd96)

Even if the lexical environment of function a does not contain variable b , we can still get the value as 1000. <br><br>

# Working of scope chain

### Step 1 : Creation of global execution context and completion of phase-1 (memory creation)

![WhatsApp Image 2024-03-08 at 23 17 54_6af42ae3](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/10d0f4e3-7d22-4e20-bcf2-c79275bc67f8)

Global execution context will be created , followed by memory creation. Initially , the value of variable b will be set of undefined and entire code of function a will be stored.

### Step 2 : Code execution phase (Execution of line 6)

![WhatsApp Image 2024-03-08 at 23 17 53_dcd30525](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/1f4bc86b-50ba-48d8-a821-de759cc95bd0)

The value of variable b will be set to 1000 after execution of line 6 of the code. The value will be updated in memory component of global execution context.

### Step 3 : Code execution of line 7

![WhatsApp Image 2024-03-08 at 23 17 53_14e9fd6e](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/5a33f2e6-72d0-4872-91aa-55218ac2b92a)

Since function is invoked , a new execution context of function a will be created and since it doesn't have any variables or functions inside it , there will be nothing to store in memory of a's execution context. The memory component only contains a pointer which references parent's lexical environment . <br>

When code execution phase of function a begins , we need access to variable b. But, currently there is not variable named b in execution context of a.

### Step 4 : Accessing parent's lexical environment

![WhatsApp Image 2024-03-08 at 23 17 53_7d6513a6](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/6d132900-248d-4303-b168-36c1b961e8fc)

With the help of pointer , we can access lexical environment of parent i.e global execution context. There , we can find variable b in memory with a value of 1000. So, function a prints this value of b as 1000 in console. <br>


# Example of chaining

```

function a()
{
    function b()
    {
        
    }
    b();
}
a();

```

<br>

![WhatsApp Image 2024-03-08 at 23 37 39_9e5167f1](https://github.com/VVSD-Charan/Striver-A-Z-sheet-and-learning/assets/105978561/c7fb1ab4-2bd8-4b0b-af33-e6f02f2a48d3)

<br>
The chaining looks like :

Lexical environment of b  ->  Lexical environment of a  ->  Lexical environment of global execution context -> NULL <br>

<strong>Global execution context will not have a parent so , the pinter will always reference NULL.</strong> <br>

Scope chain is like a singly linked list where each lexical environment can access lexical environment of it's parent , but the reverse is not possible i.e a parent lexical environment cannot access lexical environment of its child.


# Closure in JavaScript

<li>Closure is the concept of function + lexical environment in which function it was created. so every function declared within another function then it has access to the scope chain of the outer function and the variables created within the scope of the outer function will not get destroyed.</li>
<li>JavaScript closure is a feature that allows inner functions to access the outer scope of a function. Closure helps in binding a function to its outer boundary and is created automatically whenever a function is created.</li>



