#！/bin/bash


FindDIR=$(whiptail --title "文件查找" --inputbox "输入查找文件查找路径" 10 60 3>&1 1>&2 2>&3)
exitstatus=$?
if [ $exitstatus = 0 ];
then
  FindName=$(whiptail --title "文件查找" --inputbox "输入查找文件名称" 10 60 3>&1 1>&2 2>&3)
  exitstatus=$?
  if [ $exitstatus = 0 ];
  then
    if [ $FindName ];
    then
      F=$(find $FindDIR -name "*$FindName*" -print)
      N=$(find $FindDIR -name "*$FindName*" |wc -l)
      whiptail --title "查找结果$N条记录" --msgbox "$F" 0 0
    fi
  else echo "你选择取消查找文件名"
  fi
else echo "你选择取消查找文件路径"
fi
#"$F"00这两个0代表不限制高度和宽带这样输出来的结果可以有下拉栏，如果1560的话多的就不显示出来
#0继续1退出查找

