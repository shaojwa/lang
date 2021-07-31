https://google.github.io/styleguide/cppguide.html

`structs` should be used for passive objects that carry data, and may have associated constants. All fields must be public.

If more functionality or invariants are required, a `class` is more appropriate. If in doubt, make it a `class`.
