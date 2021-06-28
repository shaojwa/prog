## description
> Converts between types using a combination of implicit and user-defined conversions

what is implicit and user-defined?
## syntax
```
static_cast< new_type> (expression)
```
returns a value of type **new_type**

## Explanation
attention, **static_cast** can not cast away **constness** and **volatility**

1. if there is an implicit-conversion-sequence from **expression** to **new_type**, the `static_cast<new_type>(expression)` retyrn the **imaginary** variable Temp initialized as if by `new_type Temp(expression);`. in this way, the call to the constructor of new_type is called **implicit conversions**.


1. if overload resolution for a direct initialization of an object or reference of type new_type form expression would find at least one viable function, the `static_cast<new_type>(expression);` will return the imagenary variable Temp initialized as if by `new_type Temp(expression)`
