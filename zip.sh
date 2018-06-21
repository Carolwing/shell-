#！/bin/bash


F=$(ls -ups ./)
NewNum=$(whiptail --title "文件压缩" --inputbox "$F
输入想压缩的目录或文件数目" 0 0 3>&1 1>&2 2>&3)
exitstatus=$?
if [ $exitstatus = 0 ];
then
  ZipName=$(whiptail --title "文件压缩" --inputbox "$F
输入新的压缩文件名称" 0 0 3>&1 1>&2 2>&3)
  if [ $exitstatus = 0 ];
  then
    for ((i=1;i<=$NewNum;i++));
    do
      NewName=$(whiptail --title "文件压缩" --inputbox "$F
输入想压缩的第$i个目录或文件名" 0 0 3>&1 1>&2 2>&3)
      exitstatus=$?
      if [ $exitstatus = 0 ];
      then
        zip -r $ZipName ./$NewName
      fi
    done
    F=$(ls -ups ./)
    whiptail --title "压缩结果" --msgbox "$F" 0 0
  else echo "你选择取消压缩"
  fi
else echo "你选择取消压缩"
fi
