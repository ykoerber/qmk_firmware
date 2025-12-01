# make
your choc keyboard :)

```bash
make crkbd/rev1:ykoerber -j 4
```


```bash
qmk compile -kb crkbd -km ykoerber -j 8
```

Flashing
```bash
qmk flash -kb crkbd/rev1 -km ykoerber -bl dfu-split-right -j 4
```
