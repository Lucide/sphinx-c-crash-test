# Basic Concepts

The only graphic element in VisualT is the **Object**, which contain one or more possible **Sprites**. Of these, one and only one can be active at a time, and is called the **active Sprite**.

When Objects are passed to a function, their respective active Sprite determines which Sprite will be used. From now on, when we refer to the Sprite of an Object, we mean the active Sprite.

```eval_rst
.. tip:: If you're familiar with `Scratch <https://scratch.mit.edu/>`_, you're in luck! VisualT was modelled similarly, graphics-wise.
```

## Objects (obj)

Objects are graphic elements that can be drawn on the canvas.\
An Object contains:

* an array of Sprites *(plus a pointer to the active Sprite)*
* a visibility flag
* its **x** and **y** position
* its pen size

``` image:: static/images/object.png
    :align: center
    :alt: Object structure
```

``` tip:: Objects are behave similarly to a *Sprite* in Scratch.
```

## Sprites

Sprites are the text equivalent of a bitmap image. An Object's active Sprite determines its appearance and size. Sprites are always drawn centered with respect to the Object's position.

``` image:: static/images/sprite.png
    :align: center
    :alt: Sprite structure
```

``` tip:: Sprites are equivalent to a *Costume* in Scratch.
```

## Canvas

Objects can be composed and drawn on another Object that acts as a canvas.\
So, given two Objects, `a` and `b`, you can either:

* draw `a` on `b`
* draw `b` on `a`

Every Object can act either as a drawable element, or as a drawable surface.

Position [0,0] is placed at the center of the stage, so the maximum values of the **x** and **y** coordinates are respectively half its width and half its height (one half will be one unit greater, if the total is odd).

That does not mean that larger values can't be used: the area of the Object that exceeds the visible area of the canvas will simply not be drawn.

``` tip:: The canvas behaves equivalently to the *Stage* in Scratch.
```
