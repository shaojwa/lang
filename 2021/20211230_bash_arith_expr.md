#### 一个奇怪的问题
昨天写脚本，在一个while循环中，循环变量从0开始，结果每次只循环一次就返回，`i++`改成`++i`就没问题，代码如下：
```
osd_perf()
{
  #echo "run $FUNCNAME $@"
  i=0
  while [[ $i -lt $dump_loops_max ]]; do
    echo -n "#$i "; date
    for osd_id in $@; do
      date >> $osd_perf_out.$osd_id
      sudo ceph daemon osd.$osd_id  perf dump >> $osd_perf_out.$osd_id
      if [[ $? -ne 0 ]]; then
        echo exit
        exit
      fi
    done
    sleep $dump_interval
    ((i++))
    echo $?
  done
}
```
后来发现，和自己设置的`-e` option开关有关系，man了下发现`-e`:
```
Exit immediately if a pipeline,  a subshell command enclosed in parentheses,
or one of the commands executed as part of a command list enclosed by braces (see SHELL GRAMMAR above) exits with a non-zero status. 
```
原来是因为`-e`设置之后，如果一个命令的`return status`返回非零，就会退出，而这个算术表达式i++就会返回非0（因为这个表达式的值是0）：

[https://www.gnu.org/software/bash/manual/html_node/Conditional-Constructs.html]
```
The arithmetic expression is evaluated according to the rules described below (see Shell Arithmetic).
If the value of the expression is non-zero, the return status is 0; otherwise the return status is 1. 
```
