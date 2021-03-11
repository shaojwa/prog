```
{
  if [ ! -d /var/log/rc ]
  then
      mkdir /var/log/rc
      if [ `id -u` -eq 0 ]
      then
          chattr +a /var/log/rc
      fi
  fi

  file=/var/log/rc/`date '+%y-%m-%d'`.log
  if [ ! -f $file ]
  then
      touch $file
      chmod 777 $file
  fi
  echo $(date "+%y-%m-%d %T ## $(who am i |awk "{print \$1\" \"\$2\" \"\$5}") ## $(pwd) ## $(history 1 | sed 's/^[ \t]*//g' |cut -d " " -f2-)";) >> $file
} 2>/dev/null
```
在/etc/profile下添加：
```
readonly PROMPT_COMMAND=/opt/bin/rc.sh
```
