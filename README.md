# C compiler

Just a c-compiler. It just could execute simplest calculation.

# USAGE
Execute with make command as below.
```
[root@localhost 9cc]# make test
cc     9cc.c   -o 9cc
./test.sh
1 + 2 + 3 + 4 => 10
5+20-4 => 21
0 => 0
42 => 42
[ OK ]
[root@localhost 9cc]#
```

If you want change formula, edit `test.sh`.  
You can find some `try` scripts at the end of the file.
```
try 10 '1 + 2 + 3 + 4'
try 21 '5+20-4'
try 0 0
try 42 42
```
To add your custom formula, add line to this try scripts as below.
```
try <the result you expect> <your formula>
```

If your `try` script fails, the result would be like as below.
```
[root@localhost 9cc]# make test
./test.sh
0 expected, but got 6
make: *** [test] エラー 1
[root@localhost 9cc]#
```


if you want to trail my understood, see my [blog](https://sota0113.hatenablog.com/entry/2019/05/15/201206?_ga=2.182939750.1736118601.1562130449-1791159529.1555991627).
