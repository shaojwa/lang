```
class base1 {};
class derived : base1 {};
class base2 {};
class mostderived : derived, base2 {};

mostderived md;
```

The object `md` is of *most derived class* `mostderived`, although it is also of types `base1`, `derived` and `base1`.
When talking about `md`, there is a subobject of type `base1`, a subobject of type `derived` (that includes the subobject of type `base1)`,
and a subobject of type `base2`, but only one most derived object that is md of type `mostderived`.
