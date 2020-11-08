# API Reference

## Data Types

``` doxygentypedef:: VTChar
```

``` doxygentypedef:: VTStr
```

``` doxygentypedef:: VTStrs
```

``` doxygentypedef:: VTSizes
```

``` doxygentypedef:: VTObjs
```

### Helper Macros

``` doxygendefine:: LTCHAR
```

``` doxygendefine:: LTSTR
```

``` doxygendefine:: LTSTRS
```

``` doxygendefine:: LTSIZES
```

``` doxygendefine:: LTOBJS
```

```eval_rst
.. warning:: VisualT requires ``uint8_t`` to be an alias of ``char`` to work. This is commonly true.
```

``` warning:: Currently, the library assumes a little-endian system, but endianness awareness can be implemented if requested.
```

## Miscellanous

``` doxygenfunction:: vtAbout
```

## Initializers

Initializer functions modify or initialize Objects; Be careful to not re-initialize Objects without releasing them before, or you'll cause memory leaks.

In practice, if available memory isn't an issue, it is often easier to initialize all the required Objects at the beginning of the program, and release them at the end.

``` doxygenfunction:: vtInitializeBlank
```
