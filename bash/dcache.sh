#!/bin/bash


ip_pattern='[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}'

# functions
usage() {
  echo "usage: $0 rcache { stat | clear | restat }"
  echo "usage: $0 rcache { enable | disable | show }"
  echo "usage: $0 perfmode"
}


run_rcache_all_engines() {
  engines=$(ceph engine ls)
  # echo $engines
  for eng in $engines; do
    host_ip=$(ceph engine find $eng | grep curr_hostip |egrep -o $ip_pattern)
    hostname=node${host_ip: -2}
    echo run command "'$1'" on engine.$eng at $node_ip $hostname
    ssh -o LogLevel=ERROR $host_ip sudo ceph daemon dse.${hostname} engine $eng dcache rcache $1
  done
}


#
# $1 conf_key
# $2 conf_val
set_conf_all_engines() {
  conf_key=$1
  conf_val=$2
  engines=$(ceph engine ls)
  for eng in $engines; do
    host_ip=$(ceph engine find $eng | grep curr_hostip |egrep -o $ip_pattern)
    hostname=node${host_ip: -2}
    echo run command "config set $conf_key $conf_val'" on engine.$eng at $node_ip $hostname
    ssh -o Loglevel=ERROR $host_ip sudo ceph daemon dse.$hostname engine $eng config set $conf_key $conf_val
    continue;
  done
}


show_conf_all_engines() {
  conf_key=$1
  engines=$(ceph engine ls)
  for eng in $engines; do
    host_ip=$(ceph engine find $eng | grep curr_hostip |egrep -o $ip_pattern)
    echo $host_ip
    hostname=node${host_ip: -2}
    echo run command "config show $conf_key " on engine.$eng at $node_ip $hostname
    ssh -o Loglevel=ERROR $host_ip sudo ceph daemon dse.$hostname engine $eng config show | grep $conf_key
    continue;
  done
}
perfmode_osd() {
  osd_configs=(
  "debug_osd"
  "debug_bdev"
  "debug_bluestore"
  "debug_bluefs"
  "debug_rocksdb"
  )
  for conf in ${osd_configs[@]}; do
    echo "set $conf to -1"
    ceph tell osd.* config set $conf -1
    set_conf_all_engines $conf -1
  done
}


perfmode_dse() {
  dse_configs=(
  "debug_csd"
  "debug_cstore"
  "debug_dcache"
  "debug_engine"
  "debug_dse"
  "debug_dsefs"
  "debug_ms"
  "debug_dsegc"
  "debug_dserow"
  "debug_dedup"
  )
  for conf in ${dse_configs[@]}; do
    echo "set $conf to -1"
    ceph tell dse.* config set $conf -1
    set_conf_all_engines $conf -1
  done
}


perfmode() {
  perfmode_osd
  perfmode_dse
}

# run rcache cmd on all engines
rcache() {
  echo $@
  if [[ ! "$1" =~ ^(enable|disable|show|stat|clear|restat) ]]; then
    usage;
    return;
  fi
  if [[ "$1" == "enable" ]]; then
    echo "set dcache_rc_enable to true"
    set_conf_all_engines "dcache_rc_enable" true
    return
  elif [[ "$1" == "disable" ]]; then
    echo "set dcache_rc_enable to disable"
    set_conf_all_engines "dcache_rc_enable" false
    return
  elif [[ "$1" == "show" ]]; then
    echo "show dcache_rc_enable"
    show_conf_all_engines "dcache_rc_enable"
    return
  fi
  # run rcache cmds
  run_rcache_all_engines $1
}


main() {
  if [ $# -eq 0 ]; then
    usage;
    exit -1;
  fi




perfmode_dse() {
  dse_configs=(
  "debug_csd"
  "debug_cstore"
  "debug_dcache"
  "debug_engine"
  "debug_dse"
  "debug_dsefs"
  "debug_ms"
  "debug_dsegc"
  "debug_dserow"
  "debug_dedup"
  )
  for conf in ${dse_configs[@]}; do
    echo "set $conf to -1"
    ceph tell dse.* config set $conf -1
    set_conf_all_engines $conf -1
  done
}


perfmode() {
  perfmode_osd
  perfmode_dse
}

# run rcache cmd on all engines
rcache() {
  echo $@
  if [[ ! "$1" =~ ^(enable|disable|stat|clear|restat) ]]; then
    usage;
    return;
  fi
  if [[ "$1" == "enable" ]]; then
    echo "set dcache_rc_enable to true"
    set_conf_all_engines "dcache_rc_enable" true
    return
  elif [[ "$1" == "enable" ]]; then
    echo "set dcache_rc_enable to disable"
    set_conf_all_engines "dcache_rc_enable" false
    return
  fi
  # run rcache cmds
  run_rcache_all_engines $1
}


main() {
  if [ $# -eq 0 ]; then
    usage;
    exit -1;
  fi
    
  case $1 in
    (rcache)
    shift
    rcache $@
    ;;
    (perfmode)
    perfmode
    ;;
    (*)
    usage 
    ;;
  esac
}

main $@
