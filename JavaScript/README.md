### Execution Context in JavaScript

<li>Everything in JavaScript happens inside an execution context.</li>
<li>JavaScript is a synchronous single threaded language. Single threaded means that only one line of code can be executed at a time. Synchronous single threaded means that one line of code is executed at a time in a specific order.</li>
<li>When we run a javaScript program ,execution context is created.</li<br>

![alt text](<WhatsApp Image 2024-02-29 at 18.34.49_cca1086b.jpg>)

### Example of how execution context works

```

var n = 2;
function square(num)
{
    var ans = num * num;
    return ans;
}

var square2 = square(n);
var square4 = square(4);

```

<li>When we run this program , first of all a global execution context is created.</li>
<li>Execution context is created in two phases.
    <ol>
        <li>Creation / Memory creation phase.</li>
        <li>Code execution phase.</li>
    </ol>
</li>

##### Phase 1 :  Memory creation phase
<li>In this phase,JavaScript will allocate space to all variables and functions.</li>
<li>In this phase , JavaScript goes line by line and allocates memory to all variables and functions.</li>
<li>If it encounters a variable , memory is allocated to it and variables are initialized as <strong>undefined</strong> . If it encounters a function , then <strong>entire code of function</strong> will be stored.</li><br>

![alt text](<WhatsApp Image 2024-02-29 at 18.50.36_66814c5d.jpg>)


##### Phase 2 : Code execution phase

<li>JavaScript again goes line by line to execute code.</li>

```
var n = 2;
```

<li>
    After pahse 1 , variable n's memory allocation is being done and n was initialized as undefined. Now , in this phase the value of n will be set as 2 from undefined.
</li>

   ```
   function square(num)
    {
        var ans = num * num;
        return ans;
    }
   ```

<li>
    These lines of code are neglected by javaScript. Functions are inovked only when they are used.
</li>

    ```
    var square2 = square(n);
    ```

<li>

    As function is invoked , an entirely new execution context will be created for  function inside code component. <br>

    ![alt text](<WhatsApp Image 2024-02-29 at 23.23.14_b20c68ea.jpg>)

    The execution context created will be for that piece of code i.e function only. Again both the phases i.e memory creation and code execution phase will be done .
</li>

