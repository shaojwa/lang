#!/bin/bash

#configs
osd_perf_out=osd_perf_output.txt
dump_interval=2
dump_loops_max=10

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
    let i++
  done
}

main()
{
  if [ $# -lt 2 ]; then
    help
    exit -1
  fi
  case $1 in
  (osd)
    func=osd_perf
    ;;
  (help)
    func=help
    ;;
  (*)
    func=help
       func=help
    ;;
  esac
  shift
  $func $@
}

help()
{
  echo "usage:"
  echo -e "\t$0 osd <osd_id...> \t\t# eg: $0 osd 1 4 7 10"
}

main $@

