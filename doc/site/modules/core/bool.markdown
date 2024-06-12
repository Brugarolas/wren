^title Bool Class

Boolean [values][]. There are two instances, `true` and `false`.

[values]: ../../values.html

## Methods

### **&**(other) operator

Performs bitwise and on the boolean. The result is `true` only when both inputs
were `true`, and `false` otherwise.

It is a runtime error if `other` is not a boolean.

### **|**(other) operator

Performs bitwise or on the boolean. The result is `true` when one of the input
is `true`, and `false` otherwise.

It is a runtime error if `other` is not a boolean.

### **^**(other) operator

Performs bitwise exclusive or on the boolean. The result is `true` when only
one of the input is `true`, and `false` otherwise.

It is a runtime error if `other` is not a boolean.

### **!**, **~** operators

Returns the logical complement of the value.

<pre class="snippet">
System.print(!true) //> false
System.print(!false) //> true
</pre>

### toString

The string representation of the value, either `"true"` or `"false"`.

### **toCNum**

Converts the value to a Num using the C99 language's notion of truth i.e. false corresponds to `0` and true to `1`.

Note that this differs from Wren's notion of truth where every number (including ±0) is considered to be true