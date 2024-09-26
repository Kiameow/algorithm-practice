#!/bin/bash

# 获取当前脚本的完整路径
script_name=$(basename "$0")

# 查找当前目录下所有具有可执行权限的文件，但排除当前脚本
executables=$(find . -maxdepth 1 -type f -executable ! -name "$script_name")

# 如果没有找到可执行文件，则退出脚本
if [ -z "$executables" ]; then
  echo "没有找到可执行文件。"
  exit 0
fi

# 输出找到的可执行文件
echo "找到以下可执行文件："
echo "$executables"

# 询问用户是否要删除这些文件
read -p "你确定要删除这些可执行文件吗？(y/n): " confirm

# 检查用户输入
if [ "$confirm" = "y" ] || [ "$confirm" = "Y" ]; then
  # 删除可执行文件
  rm -v $executables
  echo "已删除可执行文件。"
else
  echo "操作取消。"
fi