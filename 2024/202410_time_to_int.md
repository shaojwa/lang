in the defination of class `time_t`, add the member function
```
operation double() const {
return  (double)sec() + (double)nsec()) / 1000000000.0L); 
}
```
attention, there is no return type in the defination, but need return.
