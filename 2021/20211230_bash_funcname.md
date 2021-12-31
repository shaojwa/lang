```
FUNCNAME
An array variable containing the names of all shell functions currently in the execution call stack. 
The element with index 0 is the name of any currently-executing shell function. 
The bottom-most element (the one with the highest index) is "main". 
This variable exists only when a shell function is executing.
Assignments to FUNCNAME have no effect.
If FUNCNAME is unset, it loses its special properties, even if it is subsequently reset.

This variable can be used with BASH_LINENO and BASH_SOURCE.
Each element of FUNCNAME has corresponding elements in BASH_LINENO and BASH_SOURCE to describe the call stack.
For instance, ${FUNCNAME[$i]} was called from the file ${BASH_SOURCE[$i+1]} at line number ${BASH_LINENO[$i]}.
The caller builtin displays the current call stack using this information.
```
